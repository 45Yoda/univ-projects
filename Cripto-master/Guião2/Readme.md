# Descrição

Refinamento do Guião1 (Processo de cifra do conteúdo de um ficheiro).

# Justificação das opções tomadas

Para a implementação foi utilizado o ChaCha20 como cifra , o HMAC-Sha256 como MAC e o PBKDF2 como mecanismo de Password Based Key Derivation Function (PBKDF).

# Instruções de uso

Escrever o conteúdo a ser encriptado no ficheiro com nome file, abrir o ficheiro Guião2.ipynbno jupyter notebook e executar as funções de encriptação e a seguir de desencriptação.

# Dificuldades encontradas

Utilização da documentação do Cryptography e do PyCryptodome
