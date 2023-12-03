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

DELIMITER ;

SET @id = 2;
CALL NrFaixasPlaylist (@id);
DROP PROCEDURE NrFaixasPlaylist;

