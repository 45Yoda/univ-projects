# Descrição
Implementação da funcionalidade de assinatura digital (RSA) análoga ao protocolo Station-to-Station utilizando como base o guião 6.

# Justificação das decisões tomadas
No inicio da ligação entre o Servidor e o Cliente os ficheiros de chave privada e pública usados nas assinaturas digitais são criados. Estes ficheiros são depois reutilizados pelos Clientes que pretenderem aceder ao Servidor (os Clientes escrevem os seus pares de chaves mas o Servidor mantém os ficheiros)
De forma a conseguir assinar os diferentes parâmetros do protocolo foi necessário serializar a chave privada.

# Instruções de uso
Para executar este guião é necessário ter o python3 instalado, a seguir usam-se os seguintes comandos (pela ordem que aparecem):

- python3 servidor.py - Executa o servidor
- python3 cliente.py - Executa um cliente

# Dificuldades encontradas
Dificuldades na análise da documentação do protocolo de assinaturaas RSA.
