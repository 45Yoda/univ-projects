USING PERIODIC COMMIT
LOAD CSV FROM "file:///album.csv" AS line
CREATE (alb:Album { AlbumID: (line[0]),
Nome: (line[1]),
Data: (line[2]),
DuracaoTotal: (line[3]),
Artista:(line[4])});

USING PERIODIC COMMIT
LOAD CSV FROM "file:///artista.csv" AS line
CREATE (art:Artista { ArtistaID: (line[0]),
Nome: (line[1]),
Biografia: (line[2]),
Ranking:(line[3])});

USING PERIODIC COMMIT
LOAD CSV FROM "file:///faixa.csv" AS line
CREATE (fai:Faixa {FaixaID: (line[0]),
Nome: (line[1]),
Genero: (line[2]),
Data: (line[3]),
Duracao:(line[4]),
Reproducoes:(line[5]),
Album:(line[6]),
Artista:(line[7])});

USING PERIODIC COMMIT
LOAD CSV FROM "file:///pais.csv" AS line
CREATE (pa:Pais {PaisID: (line[0]),
Nome: (line[1])});

USING PERIODIC COMMIT
LOAD CSV FROM "file:///playlist.csv" AS line
CREATE (play:Playlist {PlaylistID: (line[0]),
Nome: (line[1]),
Descricao:(line[2]),
DuracaoTotal:(line[3]),
NrFaixas:(line[4]),
Utilizador:(line[5])});

USING PERIODIC COMMIT
LOAD CSV FROM "file:///utilizador.csv" AS line
CREATE (uti:Utilizador {UtilizadorID: (line[0]),
Username: (line[1]),
DataNascimento: (line[2]),
Telemovel: (line[3]),
Email:(line[4]),
Tipo:(line[5]),
Pais:(line[6])});


CREATE INDEX ON :Album(AlbumID);
CREATE INDEX ON :Artista(ArtistaID);
CREATE INDEX ON :Faixa(FaixaID);
CREATE INDEX ON :Pais(PaisID);
CREATE INDEX ON :Playlist(PlaylistID);
CREATE INDEX ON :Utilizador(UtilizadorID);


USING PERIODIC COMMIT
LOAD CSV FROM "file:///album.csv" AS row
MATCH (alb:Album {AlbumID: row[0]})
MATCH (art:Artista {ArtistaID: row[4]})
MERGE (art)-[:POSSUI]->(alb);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///faixa.csv" AS row
MATCH (fai:Faixa {FaixaID:row[0]})
MATCH (alb:Album {AlbumID:row[6]})
MERGE (alb) -[:TEM]->(fai);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///faixa.csv" AS row
MATCH (fai:Faixa {FaixaID:row[0]})
MATCH (art:Artista {ArtistaID:row[7]})
MERGE (art) -[:PRODUZIU]->(fai);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///playlist.csv" AS row
MATCH (play:Playlist {PlaylistID:row[0]})
MATCH (uti:Utilizador {UtilizadorID:row[5]})
MERGE (uti) -[:CRIOU]-> (play);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///utilizador.csv" AS row
MATCH (uti:Utilizador {UtilizadorID:row[0]})
MATCH (pai:Pais {PaisID:row[6]})
MERGE (uti) -[:PERTENCE]-> (pai);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///utilizador_follows_artista.csv" AS row
MATCH (uti:Utilizador {UtilizadorID:row[0]})
MATCH (art:Artista {ArtistaID:row[1]})
MERGE (uti) -[:SEGUE]-> (art);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///utilizador_follows_playlist.csv" AS row
MATCH (uti:Utilizador {UtilizadorID:row[0]})
MATCH (play:Playlist {PlaylistID:row[1]})
MERGE (uti) -[:SEGUE]-> (play);

USING PERIODIC COMMIT
LOAD CSV FROM "file:///playlist_has_faixa.csv" AS row
MATCH (play:Playlist {PlaylistID:row[0]})
MATCH (fai:Faixa {FaixaID:row[1]})
MERGE (play) -[:CONSTITUIDA]-> (fai);
