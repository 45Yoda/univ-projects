# Descrição
Implementação do protocolo Station_to_Station com o uso de certificados X509, utilizando para isso os dois últimos guiões (7 e 8)

# Justificação das decisões tomadas
A implementação desta funcionalidade dependia da correta junção dos dois guiões anteriores. O guião 7 já continha o protocolo Station_to_Station e o guião 8 a validação dos certificados, basta então que o Servidor envie o seu certificado ao Cliente (para este o confirmar) e o Cliente ao Servidor. 

# Instruções de uso
Para executar este guião é necessário ter o python3 instalado, a seguir usam-se os seguintes comandos (pela ordem que aparecem):

- python3 servidor.py - Executa o servidor
- python3 cliente.py - Executa um cliente

# Dificuldades encontradas
Dificuldades na comunicação dos certificados entre o Cliente e o Servidor
