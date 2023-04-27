use SpitalVeterinar;

-- 5 where
-- 3 group by
-- 2 distinct
-- 2 having
-- 7 mai mult de 2 tabele
-- 2 relatii m-n 


-- 1. O interogare care afiseaza judetele din care provin minim 2 persoane, ordonate descrescator 
--	  dupa numarul de persoane
-- 1 group by
-- 1 having

select judet 
from Persoane
group by judet
having count(id) > 1
order by count(id) desc;

--2. O interogare care afiseaza numele persoanei si numele animalelor care au cel putin un vaccin
-- 1 distinct
-- 1 din mai multe tabele

select distinct P.nume, P.prenume, A.nume, A.id
from Persoane P inner join 
				Animale A on A.id_proprietar = P.id inner join
					Animale_Vaccinuri AV on AV.id_animal = A.id; 

-- 3. O interogare care afiseaza animalele de gen feminin si vaccinurile pe care le au acestea
-- 2 din mai multe tabele
-- 1 dintr-o relatie m-n
-- 1 where

select V.denumire, A.nume, A.varsta, A.id_proprietar
from Vaccinuri V inner join
				Animale_Vaccinuri AV on V.id = AV.id_vaccin inner join
					Animale A on AV.id_animal = A.id
where A.sex = 'feminin';

-- 4. O interogare care afiseaza persoanele si medicii care se ocupa de animalele
--	  acestora care provin din judete diferite
-- 3 din mai multe tabele
-- 2 dintr-o relatie m-n
-- 2 where

select P.nume, P.prenume, P.judet, A.nume, A.prenume, A.judet
from Angajati A inner join
				Programari Progr on A.id = Progr.id_medic inner join
					Persoane P on Progr.id_persoana = P.id
where P.judet != A.judet;

-- 5. O interogare care afiseaza cate pisici si cati caini sunt vaccinati cu vaccinul de Rabie
-- 4 din mai multe tabele
-- 3 where
-- 2 group by

select T.denumire, count(T.id) as numar_animale
from Vaccinuri V inner join
				Animale_Vaccinuri AV on V.id = AV.id_vaccin inner join
					Animale A on AV.id_animal = A.id inner join
						Tipuri_Animale T on T.id = A.id_tip_animal
where V.denumire = 'Rabie'
group by T.denumire;


-- 6. O interogare care afiseaza cainii care au fost internati in spital in data de 07.10.2021
-- 5 din mai multe tabele
-- 4 where

select A.nume, T.denumire, I.data_internare, I.data_externare 
from Internari I inner join
				Animale A on I.id_animal = A.id inner join
					Tipuri_Animale T on T.id = A.id_tip_animal
where	I.data_internare <= '2021-10-07' and
		(I.data_externare >= '2021-10-07' or I.data_externare is null) and
		T.denumire = 'Caine';

-- 7. O interogare care afiseaza persoanele care si-au internat animalele in luna septembrie
-- 6 din mai multe tabele
-- 5 where

select P.nume, P.prenume, A.nume
from Internari I inner join
				Animale A on I.id_animal = A.id inner join
					Persoane P on P.id = A.id_proprietar
where	I.data_internare < '2021-10-01';

-- 8. O interogare care afiseaza judetele din care provin angajatii nascuti inainte de anul 1980
-- 2 distinct
-- 6 where

select distinct A.judet
from Angajati A
where A.data_nasterii < '1980';

-- 9. O interogare care afiseaza rasele din care exista cel putin doua animale
-- 3 group by
-- 2 having

select T.denumire, T.rasa, count(A.id) as numar_animale
from Tipuri_Animale T inner join
				Animale A on A.id_tip_animal = T.id
group by T.rasa, T.denumire 
having count(A.id) > 1;

-- 10. O interogare care afiseaza cati caini are fiecare persoana ordonat dupa numele persoanei
-- 7 din mai multe tabele
-- 4 group by
-- 3 having

select P.id, P.nume, P.prenume, T.denumire, count(T.id) as numar_animale
from Tipuri_Animale T inner join
				Animale A on A.id_tip_animal = T.id inner join
					Persoane P on P.id = A.id_proprietar
group by P.id, P.nume, P.prenume, T.denumire
having T.denumire = 'Caine'
order by P.id asc;
