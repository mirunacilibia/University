create or alter procedure insert_Persoane
	@no_rand int
as
begin
	declare @i int = 1
	while @i < @no_rand  begin
		declare @nume nvarchar(30) = 'Pers' + cast(@i as nvarchar(10)) 
		insert into Persoane values(@i, @nume, null, null, null, null, null)
		set @i = @i + 1
	end
end



create or alter procedure insert_Angajati
	@no_rand int
as
begin
	declare @i int = 1
	while @i < @no_rand  begin
		declare @nume nvarchar(30) = 'Angajat' + cast(@i as nvarchar(10)) 
		insert into Angajati values(@i, null, null, null,  @nume, null, null, null, null, null, null)
		set @i = @i + 1
	end
end



create or alter procedure insert_Animale
	@no_rand int
as
begin
	declare @i int = 1

	if not exists (select * from Tipuri_Animale where id = 1)
	begin
		insert into Tipuri_Animale values(1, null, null)
	end
	if not exists (select * from Persoane where id = 1)
	begin
		insert into Persoane values(1, 'Pers', null, null, null, null, null)
	end

	while @i < @no_rand  begin
		declare @nume nvarchar(30) = 'Animal' + cast(@i as nvarchar(10)) 
		insert into Animale values(@i, 1,  @nume, 1, null, null)
		set @i = @i + 1
	end
end



create or alter procedure insert_Vaccinuri
	@no_rand int
as
begin
	declare @i int = 1
	while @i < @no_rand  begin
		declare @nume nvarchar(30) = 'Vaccin' + cast(@i as nvarchar(10)) 
		insert into Vaccinuri values(@i, @nume, null)
		set @i = @i + 1
	end
end



create or alter procedure insert_Programari
	@no_rand int
as
begin
	declare @Persoana int, @Angajat int
	declare @i int = 1
	while @i < @no_rand  begin
		set @Angajat = @i / 5 + 1
		set @Persoana = @i / 5 + 1
		insert into Programari values(@i, @Angajat, @Persoana, null, null)
		set @i = @i + 1
	end
end




create or alter procedure insert_Animale_Vaccinuri
	@no_rand int
as
begin
	declare @Animal int, @Vaccin int
	declare @i int = 1
	while @i < @no_rand  begin
		set @Animal = @i / 5 + 1
		set @Vaccin = @i / 5 + 1
		insert into Animale_Vaccinuri values(@Animal, @Vaccin)
		set @i = @i + 1
	end
end

