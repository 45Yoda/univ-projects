# Descrição
Implementação do protocolo Diffie-Hellman na comunicação entre Servidor e Cliente, onde são distribuídas as informações das chaves necessárias para a criação de uma chave em comum (shared key).

# Justificação das decisões tomadas
Na comunicação entre o servidor e o cliente foram enviados em separado os números dos parâmetros e da chave pública para a recriação das chaves pois não foi possível o envio da chave pública já criada.



# Instruções de uso

Para executar este guião é necessário ter o python3 instalado, a seguir usam-se os seguintes comandos (pela ordem que aparecem):

- python3 servidor.py - Executa o servidor
- python3 cliente.py - Executa um cliente

# Dificuldades encontradas

Dificuldade em entender a documentação da biblioteca e no envio de informação relativa à chave pública
