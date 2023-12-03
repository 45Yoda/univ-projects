# Descrição

Implentação de uma função passwd() de forma a criar uma chave aleatória baseada numa password. Para isto, foi usado o mecanismo PBKDF2-HMAC. De seguida a mensagem é cifrada utilizando o método criptográfico AES block cipher com o modo EAX

# Justificação das opções tomadas

Foi usado o modo EAX devido à garantia de autenticação e privacidade da mensagem. O mecanismo PBKDF2-HMAC já tinha sido utilizado nos guiões anteriores e como tal foi utilizado para gerar a chave aleatória.

# Instruções de uso

Para executar este guião é necessário ter o python3 instalado, a seguir usam-se os seguintes comandos (pela ordem que aparecem):
- python3 servidor.py - Executa o servidor
- python3 cliente.py - Executa um cliente

# Dificuldades encontradas

Numa fase inicial foi necessário entender o processo de comunicação entre o servidor e o cliente de forma a começar com o processo de encriptação e consequente desencriptadação das mensagens enviadas.
Devido a utilização da documentação das bibliotecas cryptography e pycryptodome não foram sentidas dificuldades quanto à implementação dos mecanismos propriamente ditos.

