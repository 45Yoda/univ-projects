USE arpeggio;

DELIMITER $$

CREATE TRIGGER NrFaixas_update -- atualiza o número de faixas da playlist onde foi inserida a faixa
AFTER INSERT ON Playlist_Has_Faixa -- é ativado após uma inserção na tabela que possui a associacao das playlists com faixas
FOR EACH ROW -- executado uma vez para cada linha afetada pelo evento
BEGIN

	UPDATE Playlist AS P
		INNER JOIN Playlist_Has_Faixa AS PF
		ON P.IdPlaylist = NEW.IdPlaylist
    SET P.NrFaixas = P.NrFaixas+1;

END $$


DELIMITER ;
DROP TRIGGER NrFaixas_update;