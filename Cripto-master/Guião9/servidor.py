import asyncio
import os
import sys
from Crypto.Cipher import ChaCha20
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from OpenSSL import crypto
from cryptography import utils
from cryptography.hazmat.primitives.asymmetric import dsa, ec
from cryptography.x509.extensions import Extension, ExtensionType
from cryptography.x509.name import Name
from cryptography import x509
from cryptography.hazmat.primitives import hmac



conn_cnt = 0


class ServerWorker(object):
    """ Classe que implementa a funcionalidade do SERVIDOR. """
    def __init__(self, cnt):
        """ Construtor da classe. """
        self.id = cnt
    def respond(self, msg, peername):
        """ Processa uma mensagem (enviada pelo CLIENTE)"""
        assert len(msg)>0, "mensagem vazia!!!"
        print('%d :%r' % (self.id,msg.decode()))
        return msg


@asyncio.coroutine
def handle_echo(reader, writer):
    global conn_cnt
    conn_cnt +=1
    srvwrk = ServerWorker(conn_cnt)

#Certificados
    passwd=b"1234"
#ler pkcs12 Servidor
    p12S = crypto.load_pkcs12(open("p12/Servidor.p12", 'rb').read(), passwd)
    private_keyS2 =crypto.dump_privatekey(crypto.FILETYPE_PEM, p12S.get_privatekey())
   
    private_keyS = serialization.load_pem_private_key(
            private_keyS2,
            password=None,
            backend=default_backend()
        )

#ler certificado Servidor
    certificadoS = crypto.dump_certificate(crypto.FILETYPE_PEM,p12S.get_certificate())

    while True:
        data = yield from reader.read(100)
        if data[:1]==b'E': break

  
# --------------------------------- Diffie Hellman --------------------------------- #
        if data[:1]==b'y':
            y = data[1:]
            writer.write(b'OK')
            continue

        if data[:1]==b'p':
            p = data[1:]
            writer.write(b'OK')
            continue

        if data[:1]==b'g':
            g = data[1:]
            shared_key, b_y = dhPK(int.from_bytes(y, 'big'), int.from_bytes(g, 'big'), int.from_bytes(p, 'big'))
            #Envio das assinaturas, de g^x e g^y
            sig_servidor = sig_create(b_y)
            sig_cliente = sig_create(y)
            writer.write(b'K' + b_y)
            writer.write(b'S' + sig_cliente + sig_servidor)
            data = yield from reader.read(513)
            #Recebe as assinaturas
            if data[:1]==b's':
                sig_cliente = data[1:257]
                sig_servidor = data[257:]
                sig_verify(sig_cliente,y)
                sig_verify(sig_servidor,b_y)
                #continue
            data = yield from reader.read(1268)
            if data[:1]==b'c':
                certificadoC = data[1:]
                #public key do certificado
                cert = x509.load_der_x509_certificate(certificadoC, default_backend())

                #public Key
                pk = cert.public_key()
                serialized_public_key = pk.public_bytes(serialization.Encoding.DER, serialization.PublicFormat.SubjectPublicKeyInfo)

                #validação
                with open('certificados/CA.pem', 'r') as cert_file:
                    cert = cert_file.read()
        
                trusted_certs = (cert, cert)
                verified = verify_chain_of_trust(certificadoC, trusted_certs)

                if verified:
                    print('\n \n Certificate verified \n \n')

                else:
                    print('Certificado não é válido \n')   
                continue

        # -------------------------------------
        if not data: continue
        addr = writer.get_extra_info('peername')
        #nonce = data[1:9]
        #cipher = ChaCha20.new(key=shared_key, nonce=nonce)
        #msg = cipher.decrypt(data[9:])
        res = srvwrk.respond(data[1:], addr)
        if not res: break
        #res = b'M' + cipher.encrypt(res)
        res = b'M' + res
        writer.write(res)
        yield from writer.drain()
    print("[%d]" % srvwrk.id)
    writer.close()


def run_server():
    #Assinatura RSA
    sig()
    loop = asyncio.get_event_loop()
    coro = asyncio.start_server(handle_echo, '127.0.0.1', 8828, loop=loop)
    server = loop.run_until_complete(coro)
    # Serve requests until Ctrl+C is pressed
    print('Serving on {}'.format(server.sockets[0].getsockname()))
    try:
        loop.run_forever()
    except KeyboardInterrupt:
        pass
    # Close the server
    server.close()
    loop.run_until_complete(server.wait_closed())
    loop.close()
    print('FINISHED!')

def dhPK(y, g, p):
    parameters_numbers = dh.DHParameterNumbers(p, g)
    parameters = parameters_numbers.parameters(default_backend())

    b_private_key = parameters.generate_private_key()
    b_peer_public_key = b_private_key.public_key()

    a_public_numbers = dh.DHPublicNumbers(y, parameters_numbers)
    a_public_key = a_public_numbers.public_key(default_backend())
    shared_key = b_private_key.exchange(a_public_key)

    b_pn = b_peer_public_key.public_numbers()        
    b_y = b_pn.y

    shared_key = shared_key[:32]

    return shared_key, b_y.to_bytes(99, 'big')

def sig():
    private_key = rsa.generate_private_key(
        public_exponent=65537,
        key_size=2048,
        backend=default_backend()
    )

    pem = private_key.private_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PrivateFormat.PKCS8,
        encryption_algorithm=serialization.NoEncryption()
    )

    f = open('pkey_Servidor.pem','wb')
    f.write(pem)
    f.close()

    public_key = private_key.public_key()

    pem = public_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )

    f = open('pubkey_Servidor.pem','wb')
    f.write(pem)
    f.close()



def sig_verify(signature, message):

    with open("pubkey_Cliente.pem", "rb") as key_file:
        public_key = serialization.load_pem_public_key(
            key_file.read(),
            backend = default_backend()
        )

    public_key.verify(
        signature,
        message,
        padding.PSS(
            mgf=padding.MGF1(hashes.SHA256()),
            salt_length=padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256()
    )

def sig_create(msg):
    with open("pkey_Servidor.pem", 'rb') as key_file:
        private_key = serialization.load_pem_private_key(
            key_file.read(),
            password=None,
            backend=default_backend()
        )

    sig_y = private_key.sign(
        msg,
        padding.PSS(
            mgf=padding.MGF1(hashes.SHA256()),
            salt_length=padding.PSS.MAX_LENGTH
        ),
        hashes.SHA256()
    )

    return sig_y

def verify_chain_of_trust(cert_pem, trusted_cert_pems):
    
    certificate = crypto.load_certificate(crypto.FILETYPE_PEM, cert_pem)

    # Create and fill a X509Sore with trusted certs
    store = crypto.X509Store()
    for trusted_cert_pem in trusted_cert_pems:
        trusted_cert = crypto.load_certificate(crypto.FILETYPE_PEM, trusted_cert_pem)
        store.add_cert(trusted_cert)

    # Create a X590StoreContext with the cert and trusted certs
    # and verify the the chain of trust
    store_ctx = crypto.X509StoreContext(store, certificate)
    # Returns None if certificate can be validated
    result = store_ctx.verify_certificate()

    if result is None:
        return True
    else:
        return False

run_server()