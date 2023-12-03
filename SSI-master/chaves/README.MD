Gerar chaves privadas através do comando: 

	openssl genrsa -aes128 -out private.pem 1024



Exportar chave pública através do comando: 

	openssl rsa -in private.pem -outform PEM -pubout -out public.pem

Passwords atuais são sempre "1234"
