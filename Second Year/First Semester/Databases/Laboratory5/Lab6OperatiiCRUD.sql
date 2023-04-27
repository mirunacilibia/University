create or alter function validNumber(@number smallint)
returns int as
begin
	if (@number < 0)
		return 0;
	return 1;
end;

create or alter function validIdAnimale(@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Animale where id = @id)
		return 1;
	return 0;
end;

create or alter function validIdPersoane(@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Persoane where id = @id)
		return 1;
	return 0;
end;

create or alter function validIdTipuri_Animale(@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Tipuri_Animale where id = @id)
		return 1;
	return 0;
end;

create or alter function validSex(@sex nvarchar(30))
returns int as
begin
	if @sex = 'Feminin' or @sex = 'Masculin'
		return 1;
	return 0;
end;

create or alter function getAnimal(@id int)
returns table as
	return select * from Animale
	where id = @id;

create or alter function eNumar(@numar int)


create or alter procedure salveazaAnimal
	@id_proprietar int,
	@nume nvarchar(30),
	@id_tip_animal smallint,
	@sex nvarchar(50),
	@varsta smallint
as
begin
	if (dbo.validIdPersoane(@id_proprietar) = 0) begin
		raiserror('Id-ul proprietarului nu este valid', 10, 1);
		return;
	end;
	if (dbo.validIdTipuri_Animale(@id_tip_animal) = 0) begin
		raiserror('Id-ul tipului de animal nu este valid', 10, 1);
		return;
	end;
	if (dbo.validSex(@sex) = 0) begin
		raiserror('Sexul nu este valid', 10, 1);
		return;
	end;
	if (dbo.validNumber(@varsta) = 0) begin
		raiserror('Varsta nu este valida', 10, 1);
		return;
	end;
	insert into Animale values (@id_proprietar, @nume, @id_tip_animal, @sex, @varsta);
end;

create or alter procedure actualizeazaAnimal
	@id int,
	@id_proprietar int,
	@nume nvarchar(30),
	@id_tip_animal smallint,
	@sex nvarchar(50),
	@varsta smallint
as
begin
	if (dbo.validIdAnimale(@id) = 0) begin
		raiserror('Animalul pe care doriti sa il actualizati nu exista', 10, 1);
		return;
	end;
	if (dbo.validIdPersoane(@id_proprietar) = 0) begin
		raiserror('Id-ul proprietarului nu este valid', 10, 1);
		return;
	end;
	if (dbo.validIdTipuri_Animale(@id_tip_animal) = 0) begin
		raiserror('Id-ul tipului de animal nu este valid', 10, 1);
		return;
	end;
	if (dbo.validSex(@sex) = 0) begin
		raiserror('Sexul nu este valid', 10, 1);
		return;
	end;
	if (dbo.validNumber(@varsta) = 0) begin
		raiserror('Varsta nu este valida', 10, 1);
		return;
	end;

	update Animale
	set id_proprietar = @id_proprietar,
		nume =  @nume,
		id_tip_animal = @id_tip_animal,
		sex = @sex,
		varsta = @varsta
	where id = @id;
	
end;

create or alter procedure stergeAnimal
	@id int
as
begin
	if (dbo.validIdAnimale(@id) = 0) begin
		raiserror('Animalul pe care doriti sa il stergeti nu exista', 10, 1);
		return;
	end;
	
	delete from Animale
	where id = @id;
end;

create or alter procedure returneazaAnimal
	@id int
as
begin
	if (dbo.validIdAnimale(@id) = 0) begin
		raiserror('Animalul pe care doriti sa il cautati nu exista', 10, 1);
		return;
	end;
	
	select * from dbo.getAnimal(@id);
end;


exec salveazaAnimal 1, 'Pufi', 1, 'Feminin', 5
exec returneazaAnimal 4