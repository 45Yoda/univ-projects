USE arpeggio;

-- ---QUERY 1---
-- Número de utilizadores, de um determinado país, que seguem um artista específico
DELIMITER $$
CREATE PROCEDURE UtilizadoresDePaisSegArtista(IN nomeP VARCHAR(45), IN nomeA VARCHAR(45) )
BEGIN
SELECT Count(Utilizador.IdUtilizador) AS Numero_Utilizadores,nomeA AS Nome_Artista,nomeP AS Nome_Pais
	FROM Pais
		INNER JOIN Utilizador
		ON IdPais = Pais
			INNER JOIN utilizador_follows_artista
            ON 
            (SELECT IdArtista FROM Artista WHERE Artista.Nome = nomeA) = utilizador_follows_artista.IdArtista
    WHERE nomeP = Pais.Nome;
END $$

DELIMITER ;

SET @nomeP = "Portugal";
SET @nomeA = "HotPlay";

CALL UtilizadoresDePaisSegArtista(@nomeP,@nomeA);
DROP Procedure UtilizadoresDePaisSegArtista;

-- ---QUERY 2---
-- Procura o número de faixas de uma playlist
DELIMITER $$

CREATE PROCEDURE NrFaixasPlaylist ( IN ID_P INT)
BEGIN
SELECT Count(Faixa.IdFaixa) AS NúmeroFaixas, Playlist.Nome AS NomePlaylist
	FROM Playlist_has_Faixa
    INNER JOIN Faixa
    ON Faixa.IdFaixa = Playlist_has_Faixa.IdFaixa
    INNER JOIN playlist
    ON playlist.IdPlaylist=ID_P
    WHERE playlist_has_faixa.IdPlaylist=ID_P;
END $$

DELIMITER;

SET @id = 2;
CALL NrFaixasPlaylist (@id);
DROP PROCEDURE NrFaixasPlaylist;

-- ---QUERY 3---
-- Procura quais são os álbuns de um determinado artista
	
DELIMITER $$
CREATE procedure AlbunsArtista ( IN ID_Art INT)
BEGIN
SELECT IdAlbum AS ID_Album, Album.Nome AS Album, Artista.Nome AS Artista
	FROM Album
	INNER JOIN artista
    ON IdArtista = Artista
    WHERE Artista = ID_Art;
END $$

DELIMITER ;

SET @id = 2;

CALL AlbunsArtista (@id);
DROP PROCEDURE AlbunsArtista;


-- ---QUERY 4---
-- Procura as faixas, de um dado artista, que foram lançadas entre duas datas
DELIMITER $$
CREATE PROCEDURE FaixasEntreDatas ( IN ID_Art INT, IN data_ini DATE, IN data_fim DATE )
BEGIN
SELECT IdFaixa, Faixa.Nome FROM Faixa
	INNER JOIN Artista
    ON faixa.artista = artista.IdArtista
    WHERE faixa.artista = ID_Art AND faixa.`Data` BETWEEN data_ini AND data_fim;
END $$

DELIMITER ;

SELECT * FROM ARTista;
SELECT * FROM Faixa;

SET @id = 1;	
SET	@data_ini = '2002-10-22';
SET @data_fim = '2012-03-16';

CALL FaixasEntreDatas( @id, @data_ini, @data_fim );
DROP PROCEDURE FaixasEntreDatas ;