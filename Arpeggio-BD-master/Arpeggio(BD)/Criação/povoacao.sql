-- usar a base de dados arpeggio

USE arpeggio;

-- verificar a tabela

SET FOREIGN_KEY_CHECKS=0;

-- ver os tipos de dados da tabela pais

-- 3paises

DESCRIBE pais;

SELECT * FROM pais;

INSERT INTO pais
(IdPais,nome)
VALUES
('PT','Portugal'),
('RUS','Russia'),
('CHE','Switzerland');


-- ver os tipos de dados da tabela utilizador
-- 10 utilizadores
DESCRIBE utilizador;

SELECT * FROM utilizador;

INSERT INTO utilizador
(IdUtilizador, Username, DataNascimento,telemovel, email, Tipo,Pais)
VALUES
(1,'TinTin','1929-01-10',null,'omeucaomilu@gmail.com','Free','CHE'),
(2,'Donatello','2005-09-20',912568988,'apizzarianaoatartaruga@gmail.com','Free','RUS'),
(3,'David Raposa','1990-01-10',968987524,'devrant@gmail.com','Premium','PT'),
(4,'Taylor Suave','1989-12-13',125789864,'ihatekanye@gmail.com','Free','PT'),
(5,'Super Luigi','1995-03-15',null,'luiginumberone@gmail.com','Free','RUS'),
(6,'Geralt','1996-10-26',545679321,'garythefruitcake@gmail.com','Premium','RUS'),
(7,'Swatch Toblerone','1960-08-01',891885612,'temosqueijo@gmail.com','Free','CHE'),
(8,'Lucas Skywalker','1995-06-19',987854365,'mestreverde@gmail.com','Free','RUS'),
(9,'Pai Natal','1940-12-25',null,'presentesparatodos@gmail.com','Premium','RUS'),
(10,'Francisco Obikwelu',536987858,'1978-11-22','orelampago@gmail.com','Premium','PT');
 
-- --------------


-- ver os tipos de dados da tabela artista
-- 5 artistas

DESCRIBE artista;

SELECT * FROM artista;

INSERT INTO artista
(IdArtista,Nome,Biografia,Ranking)
VALUES
(1, 'Cage The Elephant', 'Conhecido pela sua fantastica carreira em rock', 1),
(2, 'Malteser', 'Conhecido pelo seu liricismo, é um percursor no mundo do rap', 2),
(3,'Frederico Mercúrio','Um músico que mudou o mundo, conhecido pelos seus diversos sucessos, We Were The Champions',3),
(4,'HotPlay', 'Uma grande banda que ficou conhecida pela música Viva la Muerte', 4),
(5, 'Big Shaq', 'Outro grande músico que ficou conhecido pelo seu single Homem Com Frio, onde falou sobre a perda do seu aquecedor no mês de Dezembro', 5);


-- ------------------
-- ver os tipos de dados da tabela album
-- 5 albuns
DESCRIBE album;

SELECT * FROM album;

INSERT INTO album
(IdAlbum,Nome,`Data`,DuracaoTotal,Artista)
VALUES
(1,'Esquece','1995-11-07','00:02:55',1),
(2,'12.875 Km','2007-05-05','00:6:50',2),
(3,'Rainha','1970-05-10','00:11:25',3),
(4,'Milu Xyloto','2004-10-20','1:02:00',4),
(5,'Reputation','2010-03-20','00:27:00',5);

-- ------------------
-- ver os tipos de dados da tabela faixa
-- 10 faixas

DESCRIBE faixa;

SELECT * FROM faixa;

INSERT INTO faixa
(IdFaixa,Nome,Genero,`Data`,Duracao,Reproducoes,Album,Artista)
VALUES
(1,'Shake Me Down','Rock','2004-10-22','00:03:11',500,null,1),
(2,'Aint No Rest For The Wicked ','Rock','2007-03-16','00:02:55',250,1,1),
(3,'Spider Man','Rock','2002-05-15','00:01:25',100,3,3),
(4,'Imperial March','Orchestral','1996-06-03','00:10:00',250,3,3),
(5,'Mr.Blue Sky','Eletronic','2012-12-10','00:04:20',125,null,5),
(6,'Days','Rap','2010-01-30','00:04:50',420,2,2),
(7,'Humble','Rap','2000-10-30','00:25:00',620,5,5),
(8,'Work','Chill','2016-03-16','01:02:00',400,4,4),
(9,'Juliett','Alternative','1999-02-01','00:02:00',100,2,2),
(10,'Christmas Carol','Pot','1900-01-01','00:02:00',10,5,5);

-- ------------------
-- ver os tipos de dados da tabela playlist
-- 10 playlists
DESCRIBE playlist;

SELECT * FROM playlist;

INSERT INTO playlist
(IdPlaylist,Nome,Descricao,DuracaoTotal,NrFaixas,Utilizador)
VALUES
(1,'BDCHill','Para ouvir enquanto se trabalha','00:07:31',3,1),
(2,'Humanz','Músicas para as nossas reuniões ativistas','00:09:10',2,2),
(3,'SuperNerd','Soundtracks de filmes, jogos e séries','00:01:25',1,3),
(4,'Workout','Ginásio sem música é tipo queijo sem marmelada','00:04:00',2,4),
(5,'Intimissi','Perfeita para aqueles momentos mais quentes','00:02:00',1,5),
(6,'Indie','Para ir ouvindo quando vou ao Starbucks','01:02:00',1,6),
(7,'Disney','Música para voltar atrás no tempo','00:11:25',2,7),
(8,'Gaming','Para quando estiver a relaxar','00:31:10',3,8),
(9,'Woodstock','Ouvir enquanto faço coisas pouco legais(221b baker street)','00:01:25',1,9),
(10,'Sleepzone','Para quando quero ir dormir e não consigo','00:06:06',2,10);

-- ------------------
-- ver os tipos de dados da tabela utilizador_follows_Artista

SELECT * FROM utilizador_follows_artista;

INSERT INTO Utilizador_follows_Artista
(IdUtilizador,IdArtista)
VALUES(1,1),(2,2),(3,3),(4,4),(5,5);


SELECT * FROM utilizador_follows_playlist;

INSERT INTO Utilizador_follows_Playlist
(IdUtilizador,IdPlaylist)
VALUES(6,1),(7,2),(8,3),(9,4),(10,5);


SELECT * FROM playlist_has_faixa ORDER BY IdPlaylist;

INSERT INTO playlist_has_faixa
(IdPlaylist,IdFaixa)
VALUES(1,1),(1,2),(1,3),
(2,5),(2,6),
(3,3),
(4,9),(4,10),
(5,10),
(6,8),
(7,3),(7,4),
(8,5),(8,6),(8,7),
(9,1),
(10,1),(10,2);

