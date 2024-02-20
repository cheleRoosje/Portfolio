/*
   Program: whovilleScript_MR.sql
   Programmer: Michele Roosje
   Date: 19 February 2024
   Purpose: Creation, population of the tables, as well as the SQL spatial queries 
   for the Whoville database Assignment 02
*/

--Create tables for Whoville database

-- drop tables if they exist
DROP TABLE IF EXISTS whoplace CASCADE;
DROP TABLE IF EXISTS whoroad CASCADE;
DROP TABLE IF EXISTS whodistrict CASCADE;

-- create point (place) table
CREATE TABLE whoplace(
   whoplaceid        numeric(2)      PRIMARY KEY
,  name        varchar(20)  NOT NULL
);

-- create line (road) table
CREATE TABLE whoroad(
  whoroadid    numeric(2)   PRIMARY KEY
, name       varchar(30) NOT NULL
);

-- create polygon (district) table
CREATE TABLE whodistrict(
  whodistrictid     numeric(2)    PRIMARY KEY
, name       varchar(30)  NOT NULL
);


--set the date display style
SET DATESTYLE TO ISO,MDY;

-- Populate the Whoville tables

-- delete all records from table(s)
DELETE FROM whoplace;
DELETE FROM whoroad;
DELETE FROM whodistrict;

-- insert records/rows into WHOPLACE table
INSERT INTO whoplace (whoplaceid,name) VALUES
(1,'Cindy Lou''s House')
,(2,'Town Christmas Tree')
,(3,'Mayor''s House')
,(4,'Christmas Feast Hall');

-- insert records/rows into WHOROAD table
INSERT INTO whoroad (whoroadid,name) VALUES
(1,'Snowflake Lane')
,(2,'Grinch Road')
,(3,'Mount Crumpet Street')
,(4,'Punker''s Road');

-- insert records into WHODISTRICT table
INSERT INTO whodistrict (whodistrictid,name) VALUES
(1,'Mayor''s Square')
,(2,'Punker''s Pond')
,(3,'Sandwich Corner')
,(4,'Singer''s Diamond')
,(5,'Star District');


-- drop shape column if it exists in whoplace table
ALTER TABLE whoplace 
DROP COLUMN IF EXISTS shape;

--add shape column to whoplace table
alter table whoplace
add column shape geometry('POINT',0); 

--add points to whoplace table
UPDATE whoplace
SET    shape = ST_GeomFromText('POINT(-12 35 )', 0)
WHERE  name like 'Cindy Lou''s House';

UPDATE whoplace
SET    shape = ST_GeomFromText('POINT(-25 24)', 0)
WHERE  name like 'Town Christmas Tree';

UPDATE whoplace
SET    shape = ST_GeomFromText('POINT(-16 17)', 0)
WHERE  name like 'Mayor''s House';

UPDATE whoplace
SET    shape=st_geomfromtext('point(-28 12)',0)
WHERE  name like 'Christmas Feast Hall';


-- drop shape column if it exists in whoroad table
ALTER TABLE whoroad 
DROP COLUMN IF EXISTS shape;

--add shape column to whoroad table
alter table whoroad
add column shape geometry('LINESTRING', 0);

-- add lines (roads) to whoroad table
UPDATE whoroad
SET shape = ST_GeomFromText('LINESTRING(-0 22, -53 22)', 0)
WHERE NAME LIKE 'Snowflake Lane';

UPDATE whoroad
SET shape = ST_GeomFromText('LINESTRING(-23 22, -52 1)', 0)
WHERE NAME LIKE 'Punker''s Road';

UPDATE whoroad
SET shape = ST_GeomFromText('LINESTRING(-0 2, -53 2)', 0)
WHERE NAME LIKE 'Mount Crumpet Street';

UPDATE whoroad
SET shape = ST_GeomFromText('LINESTRING(-23 1, 23 41)', 0)
WHERE NAME LIKE 'Grinch Road';

-- drop shape column if it exists in whodistrict table
ALTER TABLE whodistrict 
DROP COLUMN IF EXISTS shape;

--add shape column to whodistrict table
alter table whodistrict
add column shape geometry('POLYGON', 0);

--add polygons (districs) to whodistrict table
UPDATE whodistrict
SET shape = ST_GeomFromText('POLYGON((
-2 20
,-19 20
,-19 3
,-2 3
,-2 20))'
,0)
WHERE NAME LIKE 'Mayor''s Square';


UPDATE whodistrict
SET shape = ST_GeomFromText('POLYGON((
-32 19
,-49 19
,-49 6
,-32 19))'
,0)
WHERE NAME LIKE 'Punker''s Pond';


UPDATE whodistrict
SET shape = ST_GeomFromText('POLYGON((
-25 17
,-42 4
,-25 4
,-25 17))'
,0)
WHERE NAME LIKE 'Sandwich Corner';


UPDATE whodistrict
SET shape = ST_GeomFromText('POLYGON((
-39 39
,-49 31
,-39 24
,-29 31
,-39 39))'
,0)
WHERE NAME LIKE 'Singer''s Diamond';


UPDATE whodistrict
SET shape = ST_GeomFromText('POLYGON((
-12 40
,-20 34
,-16 30
,-17 24
,-12 28
,-7 24
,-8 30
,-4 34
,-10 34
,-12 40))'
,0)
WHERE NAME LIKE 'Star District';

--Whoville spatial queries

-- 1. Calculate the area of all the Whoville districts, listing from largest to smallest areas 
--showing one decimal place for the area column.

SELECT name AS "Whodistrict Name", ST_Area(shape)::numeric(10, 1) 
AS "Calculated Area in Whounits"
FROM whodistrict
ORDER BY "Calculated Area in Whounits" ASC;

--2a. Determine the total length of all roads in Whoville that the snowplough will have to clear. 
--Show two decimal places for the length total.

SELECT name AS "Road Name", sum(ST_Length(shape))::numeric(10,2) AS "Road Length"
FROM whoroad
GROUP BY name;

--2b. I wasn't sure if you meant the length of each road or all combined so I did it both ways.

SELECT sum(ST_Length(shape))::numeric(10,2) AS "Total Road Length"
FROM whoroad;

--3. Determine the distance between Cindy Lou's House and the Town Christmas Tree. 
SELECT ST_Distance(cl.shape, ct.shape)::numeric(10, 2) AS "Distance"
FROM whoplace cl, whoplace ct
WHERE cl.name LIKE 'Cindy Lou''s House' 
AND ct.name LIKE 'Town Christmas Tree';

--4. Determine what Whoplaces are located within the Sandwich Corner district.

SELECT whoplace.name AS "Whoplaces within Sandwich Corner"
FROM whoplace
JOIN whodistrict ON ST_Within(whoplace.shape, whodistrict.shape)
WHERE whodistrict.name = 'Sandwich Corner';



