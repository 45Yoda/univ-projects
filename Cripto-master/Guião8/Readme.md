# Descrição

Utilização do OpenSSL para validação de cadeias de certificados. Este guião requer o uso da biblioteca PyOpenSSL para esse efeito.

# Justificação das opções tomadas

Inicialmente são criados os ficheiros com formato PEM para ser possível realizar a verificação dos certificados.
A flag -inform DER especifica o formato do input (DER encoding). -in indica o filename de input e -out o filename de output.

# Instruções de uso

Para executar este guião é necessário ter a biblioteca openSSL instalada e é necessário realizar alguns comandos antes de fazer a verificação do certificado (neste caso os ficheiros já estão contidos nas pastas adequadas não sendo necessário executar estes comandos iniciais).

Dentro da diretoria certificados/ fazer o seguinte comando:
- openssl x509 -inform DER -in CA.cer -out CA.pem

Dentro da diretoria p12/ fazer o seguinte comando:
- openssl pkcs12 -in Cliente.p12 -out Cliente.pem

Colocar o ficheiro resultante (Cliente.pem) na pasta certificados

A seguir basta abrir o ficheiro openssl.ipynb usando o Jupyter e correr.

# Dificuldades encontradas

Através das referências fornecidas no enunciado no guião não foram sentidas grandes dificuldades na implementação.
