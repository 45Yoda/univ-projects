USE arpeggio;

-- View dos Utilizadores

CREATE VIEW vwUtilizador AS
SELECT Pais, Nome ,IdUtilizador, Username, Email
	FROM Utilizador
	INNER JOIN Pais
		ON Pais = IdPais
ORDER BY IdPais;

SELECT * FROM vwUtilizador;

DROP VIEW vwUtilizador;

-- Mostra todas as playlists,e suas faixas, possuídas pelos Utilizadores

CREATE VIEW vwPlayUtilizador AS
SELECT IdUtilizador, Username, P.IdPlaylist,P.Nome AS Playlist, F.IdFaixa,F.Nome AS Faixa
	FROM Utilizador 
	INNER JOIN Playlist AS P
		ON Utilizador = IdUtilizador
		INNER JOIN playlist_has_faixa AS PF
			ON P.IdPlaylist = PF.IdPlaylist
			INNER JOIN Faixa AS F
            ON PF.IdFaixa = F.IdFaixa
    ORDER BY IdUtilizador;
    
SELECT * FROM vwPlayUtilizador;

DROP VIEW vwPlayUtilizador;

-- Mostra os albuns, e faixas desses albuns, de todos os artistas

CREATE VIEW vwArtista AS
SELECT IdArtista,Art.Nome AS Artista, IdAlbum,Al.Nome AS Album, IdFaixa,F.Nome AS Faixa
	FROM Artista AS Art
    INNER JOIN Faixa AS F
        ON IdArtista = Artista
		INNER JOIN Album AS Al
			ON IdAlbum = Album
	ORDER BY IdArtista;
    
SELECT * FROM vwArtista;

-- Mostra os artistas seguidos por Utilizadores e mostra as faixas ordenadas pelas suas Reproducoes

CREATE VIEW vwSeguidor AS
SELECT Reproducoes,IdFaixa,F.Nome AS Faixa, Art.IdArtista, Art.Nome AS Artista, Uti.IdUtilizador, Uti.Username AS Utilizador
	FROM Utilizador AS Uti
    INNER JOIN utilizador_follows_artista AS UFA
		ON Uti.IdUtilizador = UFA.IdUtilizador
		INNER JOIN Artista AS Art
			ON UFA.IdArtista = Art.IdArtista
			INNER JOIN Faixa AS F
				ON Art.IdArtista = F.Artista
	ORDER BY Reproducoes DESC;

SELECT * FROM vwSeguidor;

DROP VIEW vwSeguidor;
