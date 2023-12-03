import asyncio
import os
import sys
from Crypto.Cipher import ChaCha20
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import dh
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives.asymmetric import padding
from OpenSSL import crypto
from cryptography import utils
from cryptography.hazmat.primitives.asymmetric import dsa, ec
from cryptography.x509.extensions import Extension, ExtensionType
from cryptography.x509.name import Name
from cryptography import x509
from cryptography.hazmat.primitives import hmac


class Client:
    """ Classe que implementa a funcionalidade de um CLIENTE. """
    def __init__(self, name=b''):
        """ Construtor da classe. Recebe o nome do cliente """
        self.name = name
    def initmsg(self):
        """ Mensagem inicial """
        str = "Hello from %r!" % (self.name)
        return str.encode()
    def respond(self, msg):
        """ Processa uma mensagem (enviada pelo SERVIDOR)
        Imprime a mensagem recebida e lê do teclado a
        resposta. """
        print('Received: %r' % msg.decode())
        new = input().encode()
        return new



@asyncio.coroutine
def tcp_echo_client(loop=None):
    if loop is None:
        loop = asyncio.get_event_loop()

    reader, writer = yield from asyncio.open_connection('127.0.0.1', 8828,
                                                        loop=loop)
    
#Certificados
    passwd=b"1234"
#ler pkcs12 Cliente
    p12C = crypto.load_pkcs12(open("p12/Cliente.p12", 'rb').read(), passwd)
    private_keyC2 =crypto.dump_privatekey(crypto.FILETYPE_PEM, p12C.get_privatekey())
   
    private_keyC = serialization.load_pem_private_key(
            private_keyC2,
            password=None,
            backend=default_backend()
        )

#ler certificado Cliente
    certificadoC = crypto.dump_certificate(crypto.FILETYPE_PEM,p12C.get_certificate())
  

# --------------------------------- Diffie Hellman --------------------------------- #
    a_pr, msg_pk, private_key = dhPK()

    writer.write(b'y' + msg_pk[0])
    data = yield from reader.read(100)
    writer.write(b'p' + msg_pk[1])
    data = yield from reader.read(100)
    writer.write(b'g' + msg_pk[2])
    data = yield from reader.read(100)

    if data[:1]==b'K':
        servidor_public_key = data[1:]
        #Recebe Assinaturas
        data = yield from reader.read(513)
        if data[:1]==b'S':
            sig_cliente = data[1:257]
            sig_servidor = data[257:]
            sig_verify(sig_servidor, servidor_public_key)
            sig_verify(sig_cliente, msg_pk[0])
        
        data = yield from reader.read(1268)
        if data[:1]==b'c':
            certificadoS = data[1:]
            #public key do certificado
            cert = x509.load_der_x509_certificate(certificadoS, default_backend())

            #public Key
            pk = cert.public_key()
            serialized_public_key = pk.public_bytes(serialization.Encoding.DER, serialization.PublicFormat.SubjectPublicKeyInfo)

            #validação
            with open('certificados/CA.pem', 'r') as cert_file:
                cert = cert_file.read()
    
            trusted_certs = (cert, cert)
            verified = verify_chain_of_trust(certificadoS, trusted_certs)

            if verified:
                print('\n \n Certificate verified \n \n')

            else:
                print('Certificado não é válido \n')     
      


        #Shared Key e envia assinaturas
        shared_key = dhShared(a_pr, int.from_bytes(servidor_public_key,'big'),private_key)
        sig_cliente = sig_create(msg_pk[0])
        sig_servidor = sig_create(servidor_public_key)

        writer.write(b's' + sig_cliente + sig_servidor)

        #Envia certificado
        writer.write(b'c' + certificadoC)
# ----------------------------------------------------------------------------------- #
    data = b'S'
    client = Client("Cliente 1")
    msg = client.initmsg()
    while len(data)>0:
        if msg:
            #cipher = ChaCha20.new(key=shared_key)
            #msg = cipher.nonce + cipher.encrypt(msg)
            msg = b'M' + msg
            writer.write(msg)
            if msg[:1] == b'E': break
            data = yield from reader.read(100)
            if len(data)>0 :
               # msg = client.respond(cipher.decrypt(data[1:]))
               msg = client.respond(data[1:])
            else:
                break
        else:
            break
    writer.write(b'E')
    print('Socket closed!')
    writer.close()


def run_client():
    #Assinatura RSA
    sig()
    loop = asyncio.get_event_loop()
    loop.run_until_complete(tcp_echo_client())

def dhPK():
    parameters = dh.generate_parameters(generator=2, key_size=512, backend=default_backend())

    a_private_key = parameters.generate_private_key()
    a_peer_public_key = a_private_key.public_key()

    a_pn = a_peer_public_key.public_numbers()
    a_pr = parameters.parameter_numbers()
    a_y = a_pn.y
    a_p = a_pr.p
    a_g = a_pr.g

    num = [a_y.to_bytes(99, 'big'), a_p.to_bytes(99, 'big'), a_g.to_bytes(99, 'big')]

    return a_pr, num, a_private_key

def dhShared(a_pr, servidor_public_key, private_key):
    b_public_numbers = dh.DHPublicNumbers(servidor_public_key, a_pr)
    b_public_key = b_public_numbers.public_key(default_backend())

    shared_key = private_key.exchange(b_public_key)
    shared_key = shared_key[:32]

    return shared_key

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
    
    f = open('pkey_Cliente.pem','wb')
    f.write(pem)
    f.close()

    public_key = private_key.public_key()

    pem = public_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )

    f = open('pubkey_Cliente.pem','wb')
    f.write(pem)
    f.close()

def sig_create(msg):
	with open("pkey_Cliente.pem", 'rb') as key_file:
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

def sig_verify(signature,message):

    with open("pubkey_Servidor.pem", "rb") as key_file:
        public_key = serialization.load_pem_public_key(
		    key_file.read(),
		    backend=default_backend()
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


run_client()