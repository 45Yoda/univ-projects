use arpeggio;

SELECT * FROM album
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/album.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM artista
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/artista.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM faixa
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/faixa.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM pais
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/pais.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM playlist
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/playlist.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM utilizador
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/utilizador.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM playlist_has_faixa
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/playlist_has_faixa.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM utilizador_follows_artista
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/utilizador_follows_artista.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

SELECT * FROM utilizador_follows_playlist
into outfile 'C:/ProgramData/MySQL/MySQL Server 5.7/Uploads/utilizador_follows_playlist.csv'
fields enclosed by '"' terminated by ',' escaped by '' 
lines terminated by '\r\n';

