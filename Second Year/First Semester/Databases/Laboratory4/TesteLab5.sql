
create or alter procedure createTests
as
begin
	
	declare @TimpStart datetime, @TimpSfarsit datetime
	declare @TestID int, @TestRunID int, @TableID int, @NoOfRows int, @ViewID int
	declare @TestName varchar(30), @TableName varchar(50), @ViewName varchar(50)

	declare cursor_teste cursor for select TestID, Name from Tests
	open cursor_teste
	fetch next from cursor_teste into @TestID, @TestName

	while @@FETCH_STATUS = 0 begin

		-- aici facem delete-urile
		declare cursor_tabele cursor scroll for
		select T.TableID, Name, NoOfRows
		from Tables T inner join TestTables TT on T.TableID = TT.TableID
		where TT.TestID = @TestID
		order by Position

		open cursor_tabele
		fetch next from cursor_tabele into @TableID, @TableName, @NoOfRows
		while @@FETCH_STATUS = 0 begin
			exec('delete from ' + @TableName)
			fetch next from cursor_tabele into @TableID, @TableName, @NoOfRows
		end

		-- aici facem insert-urile
		insert into TestRuns values(@TestName, GETDATE(), null)
		set @TestRunID = @@IDENTITY

		fetch prior from cursor_tabele into @TableID, @TableName, @NoOfRows
		while @@FETCH_STATUS = 0 begin
			insert into TestRunTables values(@TestRunID, @TableID, GETDATE(), GETDATE())
			-- apel de proceduri
			declare @procedureName nvarchar(MAX) = 'insert_' + @TableName
			exec @procedureName @NoOfRows
			update TestRunTables set EndAt = GETDATE() where TestRunID = @TestRunID and TableID = @TableID
			fetch prior from cursor_tabele into @TableID, @TableName, @NoOfRows
		end

		close cursor_tabele
		deallocate cursor_tabele

		-- pentru view-uri
		declare cursor_views cursor scroll for
		select V.ViewID, Name
		from Views V inner join TestViews TV on V.ViewID = TV.ViewID
		where TV.TestID = @TestID

		open cursor_views
		fetch next from cursor_views into @ViewID, @ViewName
		while @@FETCH_STATUS = 0 begin
			set @TimpStart = GETDATE()
			exec('select * from ' + @ViewName)
			set @TimpSfarsit = GETDATE()
			insert into TestRunViews values(@TestRunID, @ViewID, @TimpStart, @TimpSfarsit)
			fetch next from cursor_views into @ViewID, @ViewName
		end
		
		update TestRuns set EndAt = @TimpSfarsit where TestRunID = @TestRunID

		close cursor_views
		deallocate cursor_views

		fetch next from cursor_teste into @TestID, @TestName
	end

	close cursor_teste
	deallocate cursor_teste

end

exec createTests