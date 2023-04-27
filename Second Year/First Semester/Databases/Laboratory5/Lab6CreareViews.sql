create or alter view ViewAnimaleVaccinuri as
	select A.id as ID_Animal, A.nume, V.denumire as Denumire_Vaccin from
	Vaccinuri V inner join Animale_Vaccinuri AV
	on V.id = AV.id_vaccin
	inner join Animale A 
	on AV.id_animal = A.id
	where V.denumire = 'Rabie';

create or alter view ViewVaccinuriTermen as
	select * from Vaccinuri
	where termen_valabilitate > 3;

drop index IX_Vaccinuri_Denumire_Cresc on Vaccinuri
create nonclustered index IX_Vaccinuri_Denumire_Cresc on Vaccinuri (denumire asc) include (id, termen_valabilitate)


create index IX_Vaccinuri_Termen_Cresc on Vaccinuri (termen_valabilitate asc)  include (id, denumire)
			

select denumire from Vaccinuri
where denumire like 'R%'

alter index IX_Vaccinuri_Denumire_Cresc on Vaccinuri disable;

alter index IX_Vaccinuri_Denumire_Cresc on Vaccinuri rebuild;

create nonclustered index IX_AnimaleVaccinuri_ID_Cresc on Animale_Vaccinuri (id_vaccin asc) include (id_animal);

create nonclustered index IX_Animale_ID_Cresc on Animale (nume asc) include (id, id_proprietar, id_tip_animal, sex, varsta);

select * from ViewAnimaleVaccinuri

select * from ViewVaccinuriTermen