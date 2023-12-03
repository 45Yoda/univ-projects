USE arpeggio;

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

