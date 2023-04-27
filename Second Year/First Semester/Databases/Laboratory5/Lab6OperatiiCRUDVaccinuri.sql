create or alter function validIdVaccinuri(@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Vaccinuri where id = @id)
		return 1;
	return 0;
end;

create or alter function getVaccin(@id int)
returns table as
	return select * from Vaccinuri
	where id = @id;

create or alter procedure salveazaVaccin
	@denumire nvarchar(50),
	@termen_valabilitate smallint
as
begin
	if (dbo.validNumber(@termen_valabilitate) = 0) begin
		raiserror('Termenul de valabilitate nu este valid', 10, 1);
		return;
	end;
	insert into Vaccinuri values (@denumire, @termen_valabilitate);
end;

create or alter procedure actualizeazaVaccin
	@id int,
	@denumire nvarchar(50),
	@termen_valabilitate smallint
as
begin
	if (dbo.validNumber(@termen_valabilitate) = 0) begin
		raiserror('Termenul de valabilitate nu este valid', 10, 1);
		return;
	end;
	if (dbo.validIdVaccinuri(@id) = 0) begin
		raiserror('Vaccinul pe care doriti sa il actualizati nu exista', 10, 1);
		return;
	end;

	update Vaccinuri
	set denumire = @denumire,
		termen_valabilitate =  @termen_valabilitate
	where id = @id;
	
end;

create or alter procedure stergeVaccin
	@id int
as
begin
	if (dbo.validIdVaccinuri(@id) = 0) begin
		raiserror('Vaccinul pe care doriti sa il stergeti nu exista', 10, 1);
		return;
	end;
	
	delete from Vaccinuri
	where id = @id;
end;

create or alter procedure returneazaVaccin
	@id int
as
begin
	if (dbo.validIdVaccinuri(@id) = 0) begin
		raiserror('Vaccinul pe care doriti sa il cautati nu exista', 10, 1);
		return;
	end;
	
	select * from dbo.getVaccin(@id);
end;


exec salveazaVaccin 'Rabie', 1
exec actualizeazaVaccin 1, 'Anual', 1
exec returneazaVaccin 1
exec stergeVaccin 1