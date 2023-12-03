# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import random
from math import sqrt


f = open("out.txt",'w')

teams = ["FC Porto","Sporting CP","UD Oliveirense","SL Benfica",
        "OC Barcelos", "A Juventude Viana","HC Braga","Riba d'Ave HC",
        "AD Valongo","CD Paço de Arcos","HC Turquel","AD Oeiras", 
        "SC Tomar", "SC Marinhense"]

listaApelidos = ["Silva","Santos","Ferreira","Pereira","Oliveira","Costa"
                "Rodrigues","Martins","Jesus","Sousa","Fernandes","Goncalves"
                ,"Gomes","Lopes","Marques","Alves","Almeida","Ribeiro","Pinto"
                ,"Carvalho","Teixeira","Moreira","Correia","Mendes","Nunes"
                ,"Soares","Vieira","Monteiro","Cardoso","Rocha","Raposo","Neves"
                ,"Coelho","Cruz","Cunha","Pires","Ramos","Reis","Simoes"
                ,"Antunes","Matos","Fonseca","Machado","Araujo","Barbosa"
                ,"Tavares","Lourenco","Castro","Figueiredo","Azevedo","Freitas"
                ,"Magalhaes","Henriques","Lima","Guerreiro","Batista","Pinheiro"
                ,"Faria","Miranda","Barros","Morais","Nogueira","Esteves","Anjos"
                ,"Baptista","Campos","Mota","Andrade","Brito","Sa","Nascimento"
                ,"Leite","Abreu","Borges","Melo","Vaz","Pinho","Vicente"
                ,"Gaspar","Assuncao","Maia","Moura","Valente","Domingues"
                ,"Garcia","Carneiro","Loureiro","Neto","Amaral","Branco","Leal"
                ,"Pacheco","Macedo","Paiva","Matias","Amorim","Torres"
                ]

listaNomes = ["Aarao","Abdenago","Abdul","Abel","Abelamio","Abelardo","Abigail"
  ,"Abilio","Abna","Abraao","Abraim","Abrao","Absalao","Acacio"
  ,"acil","Acilino","Acilio","Acucena","Acursio","Ada","Adail"
  ,"Adalberto","Adalgisa","Adalia","Adalsindo","Adalsino","Adamantino","Adamastor"
  ,"Adao","Adelaide","Adelia","Adelio","Adelindo","Adelina","Adelmo"
  ,"Ademar","Adeodato","Aderio","Aderito","Adiel","adila","Adilia"
  ,"Adilio","Adner","Adolfo","Adonai","Adonias","Adonilo","Adonis"
  ,"Adorino","Adosinda","Adriana","Adriano","Adriel","Adrien","Adrualdo"
  ,"Adruzilo","Afonsino","Afonsina","Afonso","Afra","Afranio","Afre"
  ,"Africana","Africano","agata","Agenor","Agna","Agnelo","Agnes"
  ,"Agostinho","agueda","Aida","Aide","Aires","Airiza","Airton"
  ,"Aitor","Aisha","Aladino","Alaide","Alamiro","Alan","Alana"
  ,"Alano","Alao","Alba","Albano","Alberico","Alberta","Albertina"
  ,"Alberto","Alcibiades","Alcides","Alcina","Alcindo","Alcino","Alcione"
  ,"Aldair","Aldara","Aldemar","Aldenir","Aldenora","Alder","Aldo"
  ,"Aldo","Aldonio","Aldora","Alegria","Aleixa","Aleta","Aleu"
  ,"Alex","Alexa","Alexandra","Alexandre","Alexandrina","Alexandrino","Alexandro"
  ,"Alexia","Alexina","Alexio","Alexis","Alfeu","Alfreda","alia"
  ,"Aliana","Alica","Alice","Alicia","Alida","Alina","Aline"
  ,"Alipio","Alirio","Alisande","alison","Alita","Alitio","Alito"
  ,"Alivar","Alix","Alma","Almara","Almesinda","Almira","Almiro"
  ,"Alois","Aloisio","Alpoim","Altina","Altino","Alva","Alvarim"
  ,"Alvarina","Alvarino","Alvario","alvaro","Alvino","Alzira","Amadeu"
  ,"Amadis","Amado","Amador","Amalia","Amanda","Amandina","Amara"
  ,"Amarildo","Amarilio","Amarilis","Amaro","Amauri","Amavel","Amelia"
  ,"Amelina","America","Americo","Aminadabe","Amor","Amora","Amorim"
  ,"Amorina","Amorzinda","Amos","Ana","Anabel","Anabela","Anael"
  ,"Anaice","Anaide","Anaim","Anair","Anais","Anaisa","Anaisa"
  ,"Analdina","Analia","Analice","Analide","Analisa","Anamar","Anania"
  ,"Ananias","Anas","Anatilde","Andre","Andrea","Andreia","Andreas"
  ,"Andreina","Andrelina","Andreo","Andres","Andresa","Andria","Aneide"
  ,"Anesia","Anfilito","Anfiloco","Angel","Angela","Angelica","Angelico"
  ,"Angelina","Angelita","Angelo","Ania","Aniana","Anicia","Anielo"
  ,"Aniria","Anisia","Anisio","Anita","Anolido","Anquita","Anselmo"
  ,"Anteia","Antelmo","Antera","Antero","Antonela","Antonelo","Antonia"
  ,"Antonieta","Antonina","Antonio","Anunciacao","Anunciada","Anuque","Anusca"
  ,"Aparecida","Aparicio","apio","Apolinario","Apolo","Aprigio","Aquil"
  ,"Aquila","aquila","Aquiles","Aquilino","Aquira","Arabela","Araci"
  ,"Aradna","Aramis","Arao","Arcadio","Arcanjo","Arcelino","Arcelio"
  ,"Arcilio","Ardingue","Argemiro","Argentina","Argentino","Ari","aria"
  ,"Ariadna","Ariadne","Ariana","Ariane","Ariel","Ariele","Arinda"
  ,"Arine","Ariosto","Arisberto","Aristides","Aristoteles","Arlanda","Arlete"
  ,"Armandina","Armandino","Armando","Armelim","Armenia","Armenio","Armindo"
  ,"Aron","Arquimedes","Arquiminio","Arquimino","Arsenio","Artemisa","Artemisia"
  ,"Artur","Aruna","Ary","Ascenso","Aselio","aser","asia"
  ,"Assis","Assuncao","Assunta","Astrid","Astride","Ataide","Atanasio"
  ,"Atao","Atenais","atila","atina","Aubri","Audete","Aura"
  ,"aurea","Aurelia","Aureliana","aureo","Aurete","Auriana","Ausenda"
  ,"Ausendo","Austrelino","Auta","Auxilia","Ava","Avelino","Aventino"
  ,"Axel","Azelio","Aziz","Azuil","Baldemar","Baldomero","Banduino"
  ,"Baltasar","Baqui","Barac","Barao","Barbara","Barbora","Barcino"
  ,"Bartolina","Bartolomeu","Basilia","Basilio","Basilissa","Bastiao","Batista"
  ,"Beanina","Beatriz","Bebiana","Bebiano","Bela","Belchior","Belem"
  ,"Belina","Belinda","Belisa","Bendavida","Benedita","Benedito","Benevenuto"
  ,"Benicia","Benicio","Benigna","Benilde","Benita","Benjamim","Benjamina"
  ,"Bento","Benvinda","Berardo","Berengaria","Berilo","Bernadete","Bernardete"
  ,"Bernardim","Bernardina","Bernardino","Bernardo","Bernia","Bertila","Bertilde"
  ,"Bertina","Bertino","Berto","Bertolino","Betania","Betia","Betina"
  ,"Betino","Beto","Betsabe","Bia","Biana","Bianca","Bianor"
  ,"Bibiana","Bibili","Bijal","Bina","Bitia","Blandina","Blasia"
  ,"Boanerges","Boavida","Boris","Branca","Brandao","Bras","Brasia"
  ,"Braulio","Brazia","Brena","Brenda","Breno","Brian","Briana"
  ,"Bricia","Brigida","Brigido","Brigite","Briolanjo","Briosa","Brites"
  ,"Brizida","Bruce","Bruna","Bruno","Brunilde","Bryan","Cassia"
  ,"Cael","Caetana","Caetano","Caia","Caico","Caio","Caleb"
  ,"Calila","Calisto","Camelia","Camila","Candice","Candido","Cania"
  ,"Canto","CapitolinaAntonio","Carela","Caren","Carin","Carina","Carisa"
  ,"Carisia","Carissa","Carita","Carla","Carlinda","Carlo","Carlos"
  ,"Carlota","Carmelia","Carmelina","Carmelinda","Carmelita","Carmen","Carmerio"
  ,"Carmezinda","Carmim","Carmina","Carminda","Carminho","Carmo","Carmorinda"
  ,"Carol","Carole","Carolina","Carsta","Cassandra","Cassia","Cassiano"
  ,"Cassilda","Cassio","Casta","Castelina","Castelino","Castor","Castorina"
  ,"Catalina","Catarina","Catarino","Caterina","Catia","Catila","Catilina"
  ,"Cecilia","Cedrico","Celia","Celina","Celinia","Celino","Celio"
  ,"Celisio","Celsa","Celsio","Celso","Celto","Ceres","Cesaltina"
  ,"Cesaria","Cesarina","Cesario","Cesaro","Chantal","Charbel","Cheila"
  ,"Chema","Chloe","Cibele","Cicero","Cid","Cidalia","Cidalina"
  ,"Cidalio","Cidalisa","Cildo","Cilia","Cilio","Cinara","Cinara"
  ,"Cinderela","Cinira","Cintia","Cipora","Circe","Ciria","Cirila"
  ,"Cirilo","Ciro","Cita","Cizina","Clara","Clarina","Clarinda"
  ,"Clarindo","Clarinha","Clarisse","Claudemira","Claudemiro","Claudia","Claudiana"
  ,"Claudiano","Claudio","Cleia","Cleide","Clelia","Clelio","Clemencia"
  ,"Cleodice","Cleonice","Cleopatra","Clesia","Clesio","Clicia","Clicio"
  ,"Clidio","Clife","Climenia","Clivia","Cloe","Cloe","Clorinda"
  ,"Clorindo","Clovis","Colete","Conceicao","Concha","Consolacao","Constanca"
  ,"Constancia","Constancio","Consulino","Cora","Coralia","Coralio","Cordelia"
  ,"Corina","Corino","Corita","Corito","Corsino","Cosete","Cosme"
  ,"Cremilda","Cremilde","Crestila","Crisalia","Crisalida","Crisanta","Crisante"
  ,"Crispim","Cristela","Cristele","Cristene","Cristiana","Cristiano","Cristina"
  ,"Cristofe","Cristoforo","Cristolinda","Cristovao","Cursino","Dacia","Dacio"
  ,"Dafne","Dagmar","Dagoberto","Daina","Daisi","Dalia","Daliana"
  ,"Dalida","Dalila","Dalinda","Dalva","Damaris","Damas","Damiao"
  ,"Damien","Dana","Dania","Daniana","Dariana","Daniel","Daniela"
  ,"Danila","Danilo","Dante","Dara","Darcilia","Darcio","Dario"
  ,"Dario","Darlene","Darnela","Darque","Davi","David","Davide"
  ,"Davina","Davinia","Debora","Decia","Decimo","Deise","Deivid"
  ,"Dejalme","Dejanira","Delcio","Dele","Delfim","Delfino","Delia"
  ,"Deliana","Delio","Delisa","Delmano","Delmar","Delmina","Delmina"
  ,"Delminda","Delmira","Delmiro","Demelza","Demeter","Demetria","Demetrio"
  ,"Dener","Denil","Denis","Denisa","Denise","Deodata","Deodete"
  ,"Deolindo","Deonilde","Deotila","Deotila","Dercio","Derocila","Deusdedito"
  ,"Dhruva","Dialina","Diamantina","Diamantino","Diana","Didaco","Didia"
  ,"Didiana","Diego","Dieter","Digna","Digno","Dilan","Dilermando"
  ,"Diliana","Dilsa","Dimas","Dina","Dina","Dinamene","Dinarda"
  ,"Dinarta","Dinarte","Dineia","Dinis","Dino","Dinora","Dioclecia"
  ,"Diocleciana","Diocleciano","Dioclecio","Diogo","Diomar","Dione","Dionilde"
  ,"Dionisia","Dionisio","Dioniso","Dionisodoro","Dirce","Dircea","Dircila"
  ,"Dirio","Dirque","Disa","Ditza","Diva","Divo","Diza"
  ,"Djalma","Djalme","Djalmo","Djamila","Dolique","Dolores","Domingas"
  ,"Domingos","Dominico","Domitila","Domitilia","Domitilo","Donaldo","Donatila"
  ,"Donato","Donzelia","Donzilia","Donzilio","Dora","Dorabela","Doralice"
  ,"Doriana","Doriclo","Dorina","Dorinda","Dorindo","Dorine","Dorino"
  ,"Doris","Dorisa","Dositeu","Drusila","Druso","Duarte","Duartina"
  ,"Duilio","Dulce","Dulcelina","Dulcidia","Dulcina","Dulcineia","Dulcinio"
  ,"Dulia","Dunia","Dunio","Durbalino","Durval","Durvalina","Durvalino"
  ,"Earine","Eberardo","Eda","Eder","eder","Ederia","Edgar"
  ,"edi","Edina","Edine","edipo","Edir","Edite","Edith"
  ,"Edma","Edmero","Edmur","Edna","Edo","Eduarda","Eduardo"
  ,"Eduartino","Eduina","Eduino","Edvino","Egidio","Egil","Eglantina"
  ,"Eladio","Elana","Elca","Elda","Eleazar","Electra","Eleia"
  ,"Eleine","Elena","Eleonor","Eleonora","Eleuterio","Elgar","Eli"
  ,"elia","Eliab","Eliana","Eliane","Eliano","Elias","Elicia"
  ,"Eliete","Eliezer","elin","Elina","Eline","elio","Elioenai"
  ,"Elisa","Elisabeta","Elisabete","Elisabeth","Elisama","Eliseba","Elisete"
  ,"Eliseu","Elisia","Elisiario","Elma","Elmano","Elmar","Elmer"
  ,"Elmira","Eloa","Elodia","Elodia","Eloi","Eloisa","Elpidio"
  ,"Elsa","Elsinda","elsio","elson","elton","Eluina","Elva"
  ,"Elvina","Elvino","Elza","Elzeario","Elzo","Ema","Emanuel"
  ,"Emanuela","Emaus","Emidia","Emidio","Emilia","Emiliana","Emo"
  ,"Encarnacao","Eneias","Enes","Engelecia","Engracio","enia","Enide"
  ,"Enilda","enio","Enoque","Enrique","Enzo","eola","Eponina"
  ,"Ercilia","Ercilio","Eric","Erica","erica","Erico","erico"
  ,"Erik","Erika","Erique","eris","Ermeria","Ermiterio","Ernani"
  ,"Esau","Esmeralda","Esmeraldo","Esmeria","Especiosa","Esperanca","Estanislau"
  ,"Estefana","Estefania","Estefano","Estela","Estelio","Ester","Estevao"
  ,"Estrela","Etel","etel","Etelca","Eteria","Eudo","Eudora"
  ,"Eufemia","Eularina","Eulogio","Eunice","Eurica","Eurico","Euridice"
  ,"Eustacio","Eutalia","Eva","Evaldo","Evandra","Evandro","Evangelino"
  ,"Evangelista","Evelacio","Evelasio","Evelina","Eveline","Evelio","Evencio"
  ,"Everaldo","Everardo","evila","Expedito","Ezequiel","Ezequiela","EDNEY"
  ,"Fabia","Fabiana","Fabiano","Fabiao","Fabio","Fabiola","Fabricia"
  ,"Fabricio","Falco","Fani","Fania","Fantina","Fara","Farida"
  ,"Fatima","Faustino","Fausto","Feba","Febe","Fedora","Fedra"
  ,"Felicia","Feliciana","Felicidade","Felicissimo","Felisbela","Felisbina","Felismina"
  ,"Felix","Feliz","Ferdinando","Fernandina","Fernandino","Fernando","Fernao"
  ,"Ferrer","Fiama","Fidelia","Fidelio","Filemon","Filena","Filino"
  ,"Filinto","Filipa","FilipeouFelipe","Filipo","Filomena","Filomeno","Filoteu"
  ,"Fiona","Firmino","Firmo","Flaminia","Flavia","Flavio","Flor"
  ,"Flora","Florbela","Florenca","Florencia","Florentino","Floria","Floriana"
  ,"Floripes","Florisa","Florisbela","Florival","Fradique","Francilia","Francina"
  ,"Francisca","Francisco","Franclim","Franco","Franklim","Franklin","Franklino"
  ,"Fred","Frede","Frederica","Frederico","Fredo","Fulvio","Gabi"
  ,"Gabinia","Gabinio","Gabino","Gabriel","Gabriela","Gaela","Gaele"
  ,"Gaia","Gail","Gala","Galiana","Galiano","Galileu","Gamaliel"
  ,"Gaori","Gaorii","Garcia","Gardela","Garibaldo","Gaspar","Gastao"
  ,"Gavio","Gedeao","Geisa","Genciana","Genesia","Genesio","Gentil"
  ,"Georgeta","Georgete","Georgia","Georgina","Georgino","Geralda","Geraldina"
  ,"Geraldino","Geraldo","Gerberta","Gerberto","Gerda","Germana","Germano"
  ,"Gersao","Gerson","Gerta","Gertrudes","Gervasia","Gervasio","Giana"
  ,"Giani","Giulia","Gil","Gilberta","Gilda","Gildasio","Gildo"
  ,"Gileade","Gilma","Gilmeno","Gina","Ginestal","Gino","Gioconda"
  ,"Giovana","Giovani","Giraldina","Girel","Gisela","Giselda","Gisete"
  ,"Gislena","Gislene","Glaucia","Glenda","Glicinia","Gloriosa","Goma"
  ,"Gomes","Goncala","Goncalo","Gonzaga","Goreti","Graca","Gracia"
  ,"Graciana","Graciano","Graciela","Graciete","Graciliana","Graciliano","Gracinda"
  ,"Gracio","Graciosa","Gravelina","Gregoria","Gregorio","Greta","Grimanesa"
  ,"Guadalupe","Gualdim","Gualter","Gueir","Guendolina","Gui","Guida"
  ,"Guido","Guilherme","Guimar","Guislena","Guislene","Gumersinda","Gumersindo"
  ,"Gumesindo","Gusmao","Gustavo","Guterre","Habacuc","Habacuque","Hadassa"
  ,"Haide","Halia","Hamilton","Haraldo","Harolda","Haroldo","Hazael"
  ,"Hebe","Heber","Heda","Hedila","Hedviges","Heitor","Helada"
  ,"Helade","Heladia","Heladio","Helda","Heldemaro","Helder","Heldo"
  ,"Helena","Helenico","Heleno","Helga","Heli","Helia","Heliana"
  ,"Helier","Helio","Heliodora","Heliodoro","Helmut","Heloisa","Helvecia"
  ,"Helvecio","Helvia","Helvio","Hemexi","Hemeteria","Hemeterio","Hemiteria"
  ,"Hemiterio","Henoch","Henrique","Henriqueta","Heralda","Heraldo","Herberta"
  ,"Herberto","Herculana","Herculano","Heredio","Herenia","Herenio","Heriberta"
  ,"Heriberto","Herlander","Herman","Hermana","Hermania","Hermano","Hermenegilda"
  ,"Hermenegildo","Hermenerica","Hermenerico","Hermes","Herminia","Herminio","Hermiterio"
  ,"Hernani","Hersilia","Hersilio","Herve","Higina","Higino","Hilaria"
  ,"Hilario","Hildeberta","Hildeberto","Hildebrando","Hildegarda","Hildegardo","Hilma"
  ,"Hipolita","Hipolito","Hirondino","Holger","Homero","Honorata","Honorato"
  ,"Honorina","Honorino","Horacia","Horacio","Hortense","Hortensia","Hortensio"
  ,"Hugo","Huguete","Hulda","Iag","Iago","Ian","Iana"
  ,"Ianis","Iara","Iasmin","Iasmina","Iberico","Iberina","icaro"
  ,"Ida","iddy","Idalia","Idalina","Idalio","Idario","Idavide"
  ,"Idelia","Idelso","Idilia","Idrisse","Igelcemina","Ignez","Igor"
  ,"Ilca","Ilda","Ildo","Ilidia","Ilidio","Ilsa","Ilse"
  ,"Ilundi","Ima","Indalecio","Indaleta","India","Indira","Indro"
  ,"Ines","Infante","Inga","Ingeburga","Ingo","Ingrid","Ingride"
  ,"Ingue","Inocencia","Inocencio","Inoi","Io","Iolanda","Ionara"
  ,"Ione","Ioque","Iracema","Irais","Ireneia","Iria","Iriana"
  ,"Irina","Irineu","iris","Irisalva","Irma","Irmino","Isa"
  ,"Isaac","Isabel","Isabela","Isabelina","Isac","Isadora","Isael"
  ,"Isai","Isalda","Isalia","Isalina","Isandro","Isaque","Isaura"
  ,"Isaurinda","Isauro","Isidoro","Isidro","Isilda","Isildo","Isis"
  ,"Ismael","Ismalia","Isolda","Isolete","Isolina","Isolino","Israel"
  ,"Italo","Iuri","Iva","Ivan","Ivana","Ivania","Ivanoel"
  ,"Ivanoela","Iven","Ivete","Ivo","Ivone","Izalino","Jabes"
  ,"Jabim","Jacira","Jaco","Jacob","Jacobina","Jacome","Jacqueline"
  ,"Jader","Jadir","Jael","Jaime","Jair","Jairo","Jalmira"
  ,"James","Jamila","Jamilia","Jamim","Janai","Janaina","Janardo"
  ,"Jandira","Janete","Jani","Jania","Janice","Janina","Janine"
  ,"Janique","Jansenio","Januario","Jaque","Jaquelina","Jaqueline","Jaques"
  ,"Jarbas","Jardel","Jasao","Jasmim","Jasmina","Jeanete","Jeni"
  ,"Jenifer","Jeronimo","Jerusa","Jesse","Jessica","Jesualdo","Jesus"
  ,"Jetro","Jezabel","Jil","Jitendra","Jo","Joab","Joabe"
  ,"Joana","Joaninha","Joao","Joaquim","Joas","Job","Jocelina"
  ,"Jocelino","Jociano","Joel","Joela","Joele","Joelma","Jofre"
  ,"Joice","Jonas","Jonata","Jonatas","Joni","Joraci","Jordana"
  ,"Jordano","Jordao","Jorge","Jorgina","Jorio","Jorja","Josabete"
  ,"Josafat","Josana","Joscelina","Joscelino","Jose","Josefa","Josefa"
  ,"Josefina","Josefo","Joselene","Joselia","Joselina","Joselindo","Joselino"
  ,"Josete","Josiana","Josiane","Josias","Josina","Josivania","Josselina"
  ,"Josselino","Josuana","Josue","Jovelina","Jovelino","Jovito","Juda"
  ,"Judas","Juliana","Juliano","Juliao","Julinda","Julio","Julita"
  ,"Juna","Junia","Junio","Juno","Juraci","Jussara","Juvenal"
  ,"Juventino","Karen","Karina","Katarina","Katia","Katie","Kelly"
  ,"Kevin","Kyara","kevin","Laercio","Laertes","Laila","Laira"
  ,"Lais","Lana","Lara","Larissa","Laura","Laureana","Laureano"
  ,"Laurenio","Laurentino","Lauriano","Laurina","Laurinda","Laurine","Lauro"
  ,"Lavinia","Lazaro","Lea","Leao","Leal","Leandra","Leandro"
  ,"Leanor","Leccio","Lecio","Leena","Leila","Lelia","Lemuel"
  ,"Lenia","Lenio","Lenira","Leo","Leoberto","Leocadia","Leolina"
  ,"Leomenia","Leonardina","Leonardo","Leoncio","Leone","Leonel","Leonete"
  ,"Leonia","Leonicio","Leonida","Leonidia","Leonidio","Leonila","Leonilda"
  ,"Leonilde","Leonilia","Leonisa","Leonor","Leonora","Leontina","Leta"
  ,"Leticia","Letizia","Levi","Levina","Lhuzie","Lia","Liana"
  ,"Liane","Lianor","Liara","Liberal","Liberalina","Liberdade","Liberia"
  ,"Libertaria","Libertario","Liberto","Libia","Lici","Licia","Licidas"
  ,"Licinia","Liciniano","Licinio","Licio","Lidia","Lidiana","Lidio"
  ,"Lidorio","Liduina","Liete","Ligia","Ligio","Lila","Lila"
  ,"Lilia","Lilian","Liliana","Liliane","Liliano","Liliete","Lilite"
  ,"Lina","Linda","Lindorfo","Lindoro","Lineia","Linete","Lineu"
  ,"Lino","Linton","Lira","Lis","Lisa","Lisana","Lisandra"
  ,"Lisandro","Lisdalia","Liseta","Lisete","Lisuarte","Lito","Livia"
  ,"Liz","Lizelia","Lizi","Lizie","Loela","Loide","Lolia"
  ,"Lopo","Loredana","Lorena","Lorenzo","Loreta","Lorina","Lorine"
  ,"Lorival","Lourenca","Lourenco","Lourival","Lua","Luamar","Luana"
  ,"Lubelia","Luca","Lucas","Lucelia","Lucelinda","Lucena","Lucete"
  ,"Lucia","Lucialina","Luciana","Lucileine","Lucilia","Lucilina","Lucilio"
  ,"Lucina","Lucinio","Lucio","Luciola","Ludgero","Ludmila","Ludovico"
  ,"Ludovino","Luela","Luena","Luis","Luisa","Luisete","Luizete"
  ,"Lumena","Luna","Lurdes","Lurdite","Lusa","Lussinga","Lutero"
  ,"Lutgarda","Luz","Luzia","Luzinira","Luzio","Lyannii","Lyonce"
  ,"Madalena","Mafalda","Magali","Magda","Mamede","Manel","Manuel"
  ,"Manuela","Mara","Marcia","Marcilene","Marcio","Margarida","Marco"
  ,"Marcos","Marcela","Marcelo","Marcolina","Margarida","Maria","Mariana"
  ,"Mariano","Marilda","Marilia","Marina","Mario","Marisa","Marlene"
  ,"Marli","Marta","Martim","Martinho","Mateus","Matias","Matilda"
  ,"Mauricio","Maura","Mauro","Maxima","Maximo","Maximiliano","Maximino"
  ,"Mecia","Melania","Melinda","Melissa","Melquisedeque","Mem","Mercedes"
  ,"Merrelho","Miguel","Miguelina","Milena","Mileide","Milu","Micael"
  ,"Micaela","Michele","Minervina","Miriam","Moacir","Moises","Monica"
  ,"Morgana","Murilo","Miru","Nadia","Nadine","Nair","Napoleao"
  ,"Natacha","Natalia","Natalina","Natercia","Natividade","Nazare","Nelson"
  ,"Nestor","Neusa","Neuza","Nelia","Nicanor","Nicolas","Nicolau"
  ,"Nidia","Nilza","Nivaldo","Noa","Noah","Noe","Noel"
  ,"Noemia","Norberto","Normando","Nuno","Nuria","Octavio","Octavia"
  ,"Odete","Odilia","Ofelia","Olavo","Olivia","Olivio","Oliveira"
  ,"Olga","Omar","Ondina","Ordonho","Orestes","Oriana","Otilia"
  ,"oscar","Orlando","Osorio","Osvaldo","Ovidio","Paloma","Palmira"
  ,"Palmiro","Pandora","Parcidio","Parias","Pascoal","Poliana","Patricia"
  ,"Patricio","Paulina","Paulino","Paula","Paulo","Paulino","Pedro"
  ,"Petra","Penelope","Pepio","Piedade","Placido","Plinio","Polibio"
  ,"Polibe","Porfirio","Priao","Priscila","Quaiela","Quar","Queli"
  ,"Quelia","Querubim","Quezia","Quevin","Quiliano","Quim","Quintino"
  ,"Quirilo","Quirina","Quirino","Quirio","Quiteria","Quiterio","Rafael"
  ,"Rafaelo","Rafaela","Ramao","Ramiro","Raimundo","Raquel","Raul"
  ,"Rebeca","Regina","Reginaldo","Reinaldo","Reinamor","Remo","Renan"
  ,"Renata","Renato","Ricardina","Ricardo","Rita","Roberta","Roberto"
  ,"Rodolfo","Rodrigo","Rogerio","Romao","Romano","Romulo","Ronaldo"
  ,"Roque","Roquita","Rosa","Rosalia","Rosalina","Rosalinda","Rosana"
  ,"Rossana","Rosario","Rosaura","Roseli","Ruben","Rubim","Rudi"
  ,"Rui","Rute","Ruca","Sabina","Sabino","Sabrina","Sacramento"
  ,"Sadi","Sadraque","Sadrudine","Safia","Safira","Salazar","Salemo"
  ,"Sales","Salete","Sali","Salima","Salma","Salomao","Salome"
  ,"Salomite","Saluquia","Salustiano","Salustiniano","Salvacao","Salvador","SalvadordeJesus"
  ,"Salviano","Salvina","Samanta","Samara","Samaritana","Samaritano","Samir"
  ,"Samira","Samuel","Sancha","Sancho","Sancia","Sancler","Sandra"
  ,"Sandrina","Sandrino","Sandro","Sansao","Santana","Santelmo","Santiago"
  ,"Santos","Sara","Sarah","Sarai","Sarina","Sario","Sasquia"
  ,"Sassia","Satia","Satira","Satiro","Saul","Saula","Saulina"
  ,"Saulo","Sauro","Savio","Sebastiana","Sebastiao","Secundino","Sefora"
  ,"Segismundo","Selena","Selene","Selenia","Selesa","Selesia","Selesio"
  ,"Seleso","Selma","Selmo","Semiramis","Sena","Senia","Senio"
  ,"Seomara","Serafim","Serafina","Serena","Serenela","Sergio","Sesinando"
  ,"Sesira","Severiano","Severino","Sextina","Sheila","Sibila","Siddartha"
  ,"Sidnei","Sidonio","Sidraque","Siena","Sifredo","Silas","Silvana"
  ,"Silvandira","Silvano","Silverio","Silvestre","Silvia","Silvia","Silviana"
  ,"Silviano","Silvio","Simao","Simara","Simaura","Simauro","Simeao"
  ,"Simone","Simoneta","Simplicio","Sindulfo","Sinesio","Sira","Siria"
  ,"Sirla","Sisenando","Sisinio","Sisnando","Sivio","Socorro","Socrates"
  ,"Soeiro","Sofia","Sol","Solana","Solange","Solano","Soledade"
  ,"Solene","Solongia","Sonia","Soraia","Sotero","Stela","Stelina"
  ,"Suati","Sueli","Sulamita","Sunamita","Suraje","Surendralal","Suri"
  ,"Suria","Susana","SusanaFrancisco","SusanaIlidia","Susano","Suse","Susete"
  ,"Susi","Tauane","Tabita","Taciana","Taciano","Tacio","Tadeu"
  ,"Tais","Taisa","Taissa","Talia","Talio","Talita","Tamar"
  ,"Tamara","Tamar","Tamiris","Tanagra","Tania","Tarcisio","Tarina"
  ,"Tarsicio","Tasia","Tasso","Tatiana","Tatiano","Tejala","Teliano"
  ,"Telma","Telmo","Telo","Teodemiro","Teodomiro","Teodora","Teodoro"
  ,"Teofilo","Tercio","Teresa","Teresca","Teresina","Teresinha","Terezinha"
  ,"Teseu","Tiago","Tiana","Tiara","Tiberio","Tiburcio","Ticiana"
  ,"Ticiano","Tierri","Timoteo","Tirsa","Tirso","Tirza","Tita"
  ,"Titania","Tito","Tobias","Toledo","Tomas","Tome","Toni"
  ,"Torcato","Torpecia","Torquato","Traciana","Trajano","Trasila","Trindade"
  ,"Tristao","Tude","Tulio","Tulipa","Turgo","Ubaldino","Ubaldo"
  ,"Udo","Uldarico","Uldrico","Ulisses","ulpia","Ulpiana","Ulpiano"
  ,"ulpio","ulfilas","Ulfrida","Ulfrido","Ulrica","Ulrico","Umbelina"
  ,"Umbelino","Urania","Uranio","Urbalina","Urbalino","Urbanila","Urbina"
  ,"Urbino","Urbiria","Urias","Uriel","Urien","Urraca","Ursa"
  ,"Ursacio","Ursanio","Ursiao","Ursicia","Ursicio","Ursiciana","Ursicino"
  ,"Urso","ursula","Ursulina","Ursulino","ursulo","Uziel","Valdemar"
  ,"Valentim","Valentina","Valeria","Valerio","Valmor","Valter","Vanda"
  ,"Vanessa","Vania","Vasco","Vera","Verissimo","Veronica","Verter"
  ,"Vestina","Vianei","Vicencia","Vicenta","Vicente","Victor","Victoria"
  ,"Vida","Vidal","Vidalio","Vidaul","Vilar","Vilator","Vili"
  ,"Vilma","Vilmar","Vilson","Vinicia","Vinicio","Violante","Violeta"
  ,"Violinda","Virgilio","Virginio","Virgulino","Viriato","Vital","Vitalia"
  ,"Vitaliano","Vitalio","Vitiza","Vito","Vitor","Vitoria","Vitorio"
  ,"Vivalda","Vivaldo","Vivelinda","Viveque","Viviana","Viviane","Vivilde"
  ,"Vivina","Vladimiro","Wersun","Xavier","Xenia","Xenio","Xenocrates"
  ,"Xenon","Xerxes","Xica","Xico","Ximena","Xisto","Yara"
  ,"Yasmin","Yolanda","Yuri","Zacarias","Zahra","Zaido","Zaida"
  ,"Zaira","Zairo","Zamy","Zaqueu","Zara","Zara","Zarco"
  ,"Zardilaque","Zarina","Ze","Zeferina","Zelia","ZelindaO","Zelio"
  ,"Zena","Zenaida","Zenaide","Zenia","Zera","Zila","Zilda"
  ,"Zilia","Zilma","Zita","Ziza","Zoa","Zobaida","Zoe"
  ,"Zola","Zora","Zoraida","Zubaida","Zubeida","Zulaia","Zuleica","Zulmira"
  ]

dist=0
vmax = 0
posAnt=(0,0)

def posInicial(a):
    if a == 0:
        return (round(random.uniform(0,22), 2),round(random.uniform(0,22), 2))
    else: 
        return (round(random.uniform(22,44), 2),round(random.uniform(0,22), 2))

def posGK(a):
    if a == 0:
        return (3,11)
    else: 
        return (41,11)
    
def incrPos(a):
    aux = (a[0] + round(random.uniform(-2,2), 2), a[1] + round(random.uniform(-2,2),2))
    while not (0 <= aux[0] <=44  and 0 <= aux[1] <= 22):
        aux = (a[0] + round(random.uniform(-2,2), 2), a[1] + round(random.uniform(-2,2),2))
    return (round(aux[0],2),round(aux[1],2))
        
def incrPosGK(a):
    aux = (a[0] + round(random.uniform(-0.2,0.2), 2), a[1] + round(random.uniform(-0.2,0.2),2))
    while not ((3 <= aux[0] <= 5 or 39 <= aux[0] <= 41) and  6.5<= aux[1] <= 15.5):
        aux = (a[0] + round(random.uniform(-0.2,0.2), 2), a[1] + round(random.uniform(-0.2,0.2),2))
    return (round(aux[0],2),round(aux[1],2))

    
def posGen(a):
    i = 0
    t = 20*60
    global dist
    dist=0
    global vmax
    vmax=0
    pos = posInicial(a)
    posAnt = pos
    while i < t:
        f.write("{\"posX\":"+str(pos[0])+",\"posY\": "+str(pos[1])+",\"time\":\""+str(i)+"\"},\n")
        i+=1
        pos=incrPos(pos)
        d=sqrt((posAnt[0] - pos[0])**2 + (posAnt[1] - pos[1])**2)
        dist+=round(d,2)
        if d > vmax: vmax=round(d,2)
        posAnt=pos
    if a == 0:
        a=1
    else:
        a=0
    pos = posInicial(a)
    posAnt = pos
    while i< t*2:
        f.write("{\"posX\":"+str(pos[0])+",\"posY\": "+str(pos[1])+",\"time\":\""+str(i)+"\"},\n")
        i+=1
        pos=incrPos(pos)
        d=sqrt((posAnt[0] - pos[0])**2 + (posAnt[1] - pos[1])**2)
        dist+=round(d,2)
        if d > vmax: vmax=round(d,2)
        posAnt=pos
    f.write("{\"posX\":"+str(pos[0])+",\"posY\": "+str(pos[1])+",\"time\":\""+str(i)+"\"}\n")
    

def posGenGK(a):
    i = 0
    t = 20*60
    global dist
    dist=0
    global vmax
    vmax=0
    pos = posGK(a)
    posAnt = pos
    while i <= t:
        f.write("{\"posX\":"+str(pos[0])+",\"posY\": "+str(pos[1])+",\"time\":\""+str(i)+"\"},\n")
        i+=1
        pos=incrPosGK(pos)
        d=sqrt((posAnt[0] - pos[0])**2 + (posAnt[1] - pos[1])**2)
        dist+=round(d,2)
        if d > vmax: vmax=round(d,2)
        posAnt=pos
    if a == 0:
        a=1
    else:
        a=0
    pos = posGK(a)
    posAnt=pos
    while i < t*2:
        f.write("{\"posX\":"+str(pos[0])+",\"posY\": "+str(pos[1])+",\"time\": \""+str(i)+"\"},\n")
        i+=1
        pos=incrPosGK(pos)
        d=sqrt((posAnt[0] - pos[0])**2 + (posAnt[1] - pos[1])**2)
        dist+=round(d,2)
        if d > vmax: vmax=round(d,2)
        posAnt=pos
    f.write("{\"posX\":"+str(pos[0])+",\"posY\": "+str(pos[1])+",\"time\":\""+str(i)+"\"}\n")

def infoGen(a):
    global dist
    global vmax
    vm = round(dist/2400,2)
    f.write(" \"dist\": " + str(dist)+",\n")
    f.write("\"vel_media\": " + str(vm)+",\n")
    f.write("\"vel_max\": " + str(vmax)+"\n")

    
def playerGen(a):
    f.write("{\n \"name\": \""+random.choice(listaNomes)+" "+ random.choice(listaApelidos)+"\", \n")
    f.write("\"pos\":[\n")
    posGen(a)    
    f.write("],\n \"data\": { \n")
    infoGen(a)
    f.write("} }")

def gkGen(a):
    f.write("{\n \"name\": \""+random.choice(listaNomes)+" "+ random.choice(listaApelidos)+"\", \n")
    f.write("\"pos\":[\n")
    posGenGK(a)    
    f.write("],\n \"data\": { \n")
    infoGen(a)
    f.write("} }")

def teamGen(team, i):
    f.write("\"name\": \""+team +"\",\n \"players\": [\n")
    gkGen(i)
    for a in range(0,4):
        f.write(",")
        playerGen(i)
    f.write("] \n")

def main():
    #print(myclient.list_database_names())
    f.write("{\n \"teamA\": {\n")
    teamA = random.choice(teams)
    teamGen(teamA,0)
    f.write("},\n \"teamB\": {\n")
    teamB= random.choice(teams)
    while (teamA == teamB):
            teamB= random.choice(teams)
    teamGen(teamB,1)
    f.write("}\n }")
    f.close() 
       


if __name__ == '__main__':
   main()