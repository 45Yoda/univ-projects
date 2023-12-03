USE arpeggio;

DELIMITER $$

CREATE PROCEDURE insereFaixa (IN play_id INT, 
							  IN faixa_id INT)
BEGIN
	DECLARE Erro BOOL DEFAULT 0;
    DECLARE CONTINUE HANDLER FOR SQLEXCEPTION SET Erro = 1;
    START TRANSACTION;
    

INSERT INTO playlist_has_faixa -- inserir faixa em playlist
    (IdPlaylist,IdFaixa)
    VALUES
    (play_id, faixa_id);


IF Erro
	THEN ROLLBACK; -- caso ocorra um erro, anula todas as instruções MySQL que executou
ELSE COMMIT;
END IF;


END $$

DELIMITER ;

SET @play_id = 9;
SET @faixa_id = 2;
CALL insereFaixa(@play_id,@faixa_id);

SELECT * FROM playlist_has_faixa ORDER BY IdPlaylist;

SELECT IdPlaylist,NrFaixas FROM playlist WHERE IdPlaylist = 9 ORDER BY IdPlaylist;

DROP PROCEDURE insereFaixa;

SELECT * FROM playlist_has_faixa ORDER BY IdPlaylist;

UPDATE Playlist
SET NrFaixas = 1
WHERE IdPlaylist = 9;

DELETE FROM playlist_has_faixa
WHERE IdPlaylist = 9 and IdFaixa = 2;
