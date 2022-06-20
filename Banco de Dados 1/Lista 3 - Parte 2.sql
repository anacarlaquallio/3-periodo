-- Encontre os nomes das aeronaves tais que TODOS os pilotos certificados para operá-las ganhem mais do que $80.000.
SELECT DISTINCT A.nomeAero FROM AERONAVE A WHERE NOT EXISTS 
(SELECT* FROM FUNCIONARIO F, CERTIFICADO C WHERE 
F.idFuncion = C.idFuncion AND F.salario < 80000 AND C.idAero = A.idAero);
--ou
SELECT DISTINCT A.nomeaero FROM AERONAVE A WHERE A.idAero IN 
(SELECT C.idAero FROM CERTIFICADO C, FUNCIONARIO F WHERE C.idfuncion = F.idFuncion AND 
 NOT EXISTS (SELECT * FROM FUNCIONARIO F1 WheRE F1.idFuncion = F.idFuncion AND F1.salario<80000));

-- Para cada piloto que é certificado para mais do que três aeronaves, encontre o idFuncion e a distLimite máxima das aeronaves para as quais ele ou ela é certificado.
select F.idfuncion, MAX(A.distlimite) FROM FUNCIONARIO F, AERONAVE A, CERTIFICADO C WHERE 
F.idfuncion = C.idFuncion GROUP BY C.idAero HAVING COUNT(*)>3;

-- Encontre os nomes dos pilotos cujos salários são menores do que o preço da rota mais barata de Los Angeles a Honolulu.
SELECT DISTINCT F.nomefuncion FROM FUNCIONARIO F WHERE F.salario < (SELECT MIN(V.preco) 
FROM VOO V WHERE V.origem = "Los Angeles" AND V.destino="Honolulu");

-- Para todas as aeronaves com distLimite maior do que 1.000 milhas, encontre o nome da aeronave e o salário médio de todos os pilotos certificados para essa aeronave.
SELECT Temp.aero, Temp.AvgSalario
FROM (SELECT A.idaero, A.nomeaero AS aero,
AVG (F.salario) AS AvgSalario
FROM AERONAVE A, CERTIFICADO C, FUNCIONARIO f
WHERE A.idAero = C.idaero AND
C.idfuncion = F.idFuncion AND A.distLimite > 1000
GROUP BY A.idAero, A.nomeaero ) AS Temp

-- Encontre os nomes dos pilotos certificados para alguma aeronave Boeing.
SELECT DISTINCT F.nomeFuncion FROM FUNCIONARIO F, CERTIFICADO C, AERONAVE A
WHERE F.idFuncion = C.idFuncion
AND C.idAero = A.idAero
AND A.nomeAero LIKE 'Boeing%';

-- Encontre os idAeros de todas as aeronaves que podem ser usadas nas rotas de Los Angeles a Chicago.
select A.idAero FROM AERONAVE A WHERE A.distLimite > (SELECT MIN(V.distancia) FROM VOO V WHERE V.origem = "Los Angeles" AND V.destino = "Chicago");

-- Identifique as rotas que podem ser pilotadas por todo piloto que ganha mais do que $100.000.
SELECT DISTINCT V.origem, V.destino FROM VOO V WHERE NOT EXISTS (SELECT * FROM FUNCIONARIO F WHERE
F.salario>100000 AND NOT EXISTS (SELECT * FROM AERONAVE A, CERTIFICADO C WHERE A.distLimite>V.distancia
AND F.idFuncion = C.idFuncion AND A.idAero = C.idAero));

-- Imprima os nomeFuncions dos pilotos que podem operar aeronaves com distLimite maior do que 3.000 milhas, mas que não são certificados em nenhuma aeronave Boeing.
select DISTINCT F.nomefuncion FROM AERONAVE A JOIN CERTIFICADO C ON A.idAero = C.idAero JOIN FUNCIONARIO F
ON C.idFuncion = F.idFuncion WHERE A.distLimite>3000 AND C.idAero NOT IN
(SELECT DISTINCT idaero FROM AERONAVE WHERE nomeaero LIKE 'Boeing%');
--ou                                                                   
sELECT DISTINCT nomeFuncion FROM FUNCIONARIO, AERONAVE, CERTIFICADO
WHERE FUNCIONARIO.idFuncion = CERTIFICADO.idFuncion
AND AERONAVE.distLimite > 3000
AND CERTIFICADO.idAero = AERONAVE.idAero
AND AERONAVE.nomeAero NOT IN (SELECT DISTINCT nomeAero FROM AERONAVE WHERE nomeAero LIKE 'Boeing%');
                                                                
-- Compute a diferença entre o salário médio de um piloto e o salário médio de todos os funcionários (incluindo os pilotos).
SELECT (x - y) FROM (SELECT AVG(F1. salario) AS x FROM FUNCIONARIO F1, CERTIFICADO C WHERE F1.idFuncion = C. idFuncion), (SELECT AVG (F2.salario) AS y FROM FUNCIONARIO F2);

DROP TABLE IF EXISTS CERTIFICADO;
DROP TABLE IF EXISTS VOO;
DROP TABLE IF EXISTS AERONAVE;
DROP TABLE IF EXISTS FUNCIONARIO;

CREATE TABLE VOO(
	nroVoo INTEGER PRIMARY KEY,
	origem VARCHAR(20),
	destino VARCHAR(20),
	distancia INTEGER,
	partida TIMESTAMP,
	chegada TIMESTAMP,
	preco DECIMAL(7,2)
);

CREATE TABLE AERONAVE(
	idAero INTEGER PRIMARY KEY,
	nomeAero VARCHAR(30),
	distLimite INTEGER
);

CREATE TABLE FUNCIONARIO(
	idFuncion INTEGER PRIMARY KEY,
	nomeFuncion VARCHAR(30),
	salario INTEGER
);

CREATE TABLE CERTIFICADO(
	idFuncion INTEGER,
	idAero INTEGER,
	PRIMARY KEY(idFuncion,idAero),
	FOREIGN KEY(idFuncion) REFERENCES FUNCIONARIO(idFuncion),
	FOREIGN KEY(idAero) REFERENCES AERONAVE(idAero)
);

INSERT INTO VOO(nroVoo, origem, destino, distancia, partida, chegada, preco) VALUES (99,'Los Angeles','Washington D.C.',2308,'2005/04/12 09:30','2005/04/12 21:40',235.98), (13,'Los Angeles','Chicago',1749,'2005/04/12 08:45','2005/04/12 20:45',220.98), (346,'Los Angeles','Dallas',1251,'2005/04/12 11:50','2005/04/12 19:05',225.43), (387,'Los Angeles','Boston',2606,'2005/04/12 07:03','2005/04/12 17:03',261.56), (7,'Los Angeles','Sydney',7487,'2005/04/12 22:30','2005/04/14 6:10',1278.56), (2,'Los Angeles','Tokyo',5478,'2005/04/12 12:30','2005/04/13 15:55',780.99), (33,'Los Angeles','Honolulu',2551,'2005/04/12 09:15','2005/04/12 11:15',375.23), (34,'Los Angeles','Honolulu',2551,'2005/04/12 12:45','2005/04/12 15:18',425.98), (76,'Chicago','Los Angeles',1749,'2005/04/12 08:32','2005/04/12 10:03',220.98), (68,'Chicago','New York',802,'2005/04/12 09:00','2005/04/12 12:02',202.45), (7789,'Madison','Detroit',319,'2005/04/12 06:15','2005/04/12 08:19',120.33), (701,'Detroit','New York',470,'2005/04/12 08:55','2005/04/12 10:26',180.56), (702,'Madison','New York',789,'2005/04/12 07:05','2005/04/12 10:12',202.34), (4884,'Madison','Chicago',84,'2005/04/12 22:12','2005/04/12 23:02',112.45), (2223,'Madison','Pittsburgh',517,'2005/04/12 08:02','2005/04/12 10:01',189.98), (5694,'Madison','Minneapolis',247,'2005/04/12 08:32','2005/04/12 09:33',120.11), (304,'Minneapolis','New York',991,'2005/04/12 10:00','2005/04/12 1:39',101.56),(149,'Pittsburgh','New York',303,'2005/04/12 09:42','2005/04/12 12:09',116.50);
INSERT INTO AERONAVE(idAero, nomeAero,	distLimite) VALUES (1,'Boeing 747-400',8430), (2,'Boeing 737-800',3383), (3,'Airbus A340-300',7120), (4,'British Aerospace Jetstream 41',1502), (5,'Embraer ERJ-145',1530), (6,'SAAB 340',2128), (7,'Piper Archer III',520), (8,'Tupolev 154',4103), (16,'Schwitzer 2-33',30), (9,'Lockheed L1011',6900), (10,'Boeing 757-300',4010), (11,'Boeing 777-300',6441), (12,'Boeing 767-400ER',6475), (13,'Airbus A320',2605), (14,'Airbus A319',1805), (15,'Boeing 727',1504);
INSERT INTO FUNCIONARIO(idFuncion, nomeFuncion,	salario) VALUES (242518965,'James Smith',120433), (141582651,'Mary Johnson',178345), (011564812,'John Williams',153972), (567354612,'Lisa Walker',256481), (552455318,'Larry West',101745), (550156548,'Karen Scott',205187), (390487451,'Lawrence Sperry',212156), (274878974,'Michael Miller',99890), (254099823,'Patricia Jones',24450), (356187925,'Robert Brown',44740), (355548984,'Angela Martinez',212156), (310454876,'Joseph Thompson',212156), (489456522,'Linda Davis',127984), (489221823,'Richard Jackson',23980), (548977562,'William Ward',84476), (310454877,'Chad Stewart',33546), (142519864,'Betty Adams',227489), (269734834,'George Wright',289950), (287321212,'Michael Miller',48090), (552455348,'Dorthy Lewis',92013), (248965255,'Barbara Wilson',43723), (159542516,'William Moore',48250), (348121549,'Haywood Kelly',32899), (090873519,'Elizabeth Taylor',32021), (486512566,'David Anderson',743001), (619023588,'Jennifer Thomas',54921), (015645489,'Donald King',18050), (556784565,'Mark Young',205187), (573284895,'Eric Cooper',114323), (574489456,'William Jones',105743), (574489457,'Milo Brooks',20);
INSERT INTO CERTIFICADO(idFuncion, idAero) VALUES (567354612,1),(567354612,2), (567354612,10), (567354612,11), (567354612,12), (567354612,15), (567354612,7), (567354612,9), (567354612,3), (567354612,4), (567354612,5), (552455318,2), (552455318,14), (550156548,1), (550156548,12), (390487451,3), (390487451,13), (390487451,14), (274878974,10), (274878974,12), (355548984,8), (355548984,9), (310454876,8), (310454876,9), (548977562,7), (142519864,1), (142519864,11), (142519864,12), (142519864,10), (142519864,3), (142519864,2), (142519864,13), (142519864,7), (269734834,1), (269734834,2), (269734834,3), (269734834,4), (269734834,5), (269734834,6), (269734834,7), (269734834,8), (269734834,9), (269734834,10), (269734834,11), (269734834,12), (269734834,13), (269734834,14), (269734834,15), (552455318,7), (556784565,5), (556784565,2), (556784565,3), (573284895,3), (573284895,4), (573284895,5), (574489456,8), (574489456,6), (574489457,7), (242518965,2), (242518965,10), (141582651,2), (141582651,10), (141582651,12), (011564812,2), (011564812,10), (356187925,6), (159542516,5), (159542516,7), (090873519,6);
