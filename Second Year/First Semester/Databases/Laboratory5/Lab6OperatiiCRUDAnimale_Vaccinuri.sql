create or alter function validIdAnimaleVaccinuri(@id_animal int, @id_vaccin int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Animale_Vaccinuri where id_animal = @id_animal and id_vaccin = @id_vaccin)
		return 1;
	return 0;
end;

create or alter procedure salveazaAnimaleVaccin
	@id_animal int,
	@id_vaccin int
as
begin
	if (dbo.validIdAnimaleVaccinuri(@id_animal, @id_vaccin) = 1) begin
			raiserror('Deja exista', 10, 1);
			return;
	end;
	if (dbo.validIdVaccinuri(@id_vaccin) = 0) begin
			raiserror('Vaccinul pe care doriti sa il salvati nu exista', 10, 1);
			return;
	end;
	if (dbo.validIdAnimale(@id_animal) = 0) begin
		raiserror('Animalul pe care doriti sa il salvati nu exista', 10, 1);
		return;
	end;
	insert into Animale_Vaccinuri values (@id_animal, @id_vaccin);
end;

create or alter procedure stergeAnimaleVaccin
	@id_animal int,
	@id_vaccin int
as
begin
	if (dbo.validIdAnimaleVaccinuri(@id_animal, @id_vaccin) = 0) begin
			raiserror('Nu exista', 10, 1);
			return;
	end;
	delete from Animale_Vaccinuri
	where id_animal = @id_animal and id_vaccin = @id_vaccin;
end;

create or alter procedure returneazaAnimaleVaccin
	@id_animal int,
	@id_vaccin int
as
begin
	if (dbo.validIdAnimaleVaccinuri(@id_animal, @id_vaccin) = 0) begin
			raiserror('Nu exista', 10, 1);
			return;
	end;
	
	select A.id, A.nume, V.id, V.denumire from
	Vaccinuri V inner join Animale_Vaccinuri AV
	on V.id = AV.id_vaccin
	inner join Animale A 
	on AV.id_animal = A.id
	where AV.id_animal = @id_animal and AV.id_vaccin = @id_vaccin;
end;


exec salveazaAnimaleVaccin 5, 2
exec returneazaAnimaleVaccin 5, 2
exec stergeAnimaleVaccin 1, 1