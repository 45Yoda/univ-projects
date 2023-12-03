USE arpeggio;

-- Agrupa as faixas pelo genero apresentando o identificador da faixa e o nome
SELECT Genero, IdFaixa, Nome
	FROM Faixa
GROUP BY Genero;

-- Indice para ajudar no agrupamento 
CREATE INDEX by_genero ON Faixa (`Genero`);

DROP INDEX by_genero ON Faixa
