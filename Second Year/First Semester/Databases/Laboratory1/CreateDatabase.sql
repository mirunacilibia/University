USE [master]
GO
/****** Object:  Database [SpitalVeterinar]    Script Date: 4/27/2023 4:12:19 PM ******/
CREATE DATABASE [SpitalVeterinar]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'SpitalVeterinar', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\SpitalVeterinar.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'SpitalVeterinar_log', FILENAME = N'C:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\SpitalVeterinar_log.ldf' , SIZE = 73728KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT
GO
ALTER DATABASE [SpitalVeterinar] SET COMPATIBILITY_LEVEL = 150
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [SpitalVeterinar].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [SpitalVeterinar] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET ARITHABORT OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [SpitalVeterinar] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [SpitalVeterinar] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET  DISABLE_BROKER 
GO
ALTER DATABASE [SpitalVeterinar] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [SpitalVeterinar] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [SpitalVeterinar] SET  MULTI_USER 
GO
ALTER DATABASE [SpitalVeterinar] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [SpitalVeterinar] SET DB_CHAINING OFF 
GO
ALTER DATABASE [SpitalVeterinar] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [SpitalVeterinar] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [SpitalVeterinar] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [SpitalVeterinar] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO
ALTER DATABASE [SpitalVeterinar] SET QUERY_STORE = OFF
GO
USE [SpitalVeterinar]
GO
/****** Object:  UserDefinedFunction [dbo].[validIdAnimale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validIdAnimale](@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Animale where id = @id)
		return 1;
	return 0;
end;
GO
/****** Object:  UserDefinedFunction [dbo].[validIdAnimaleVaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validIdAnimaleVaccinuri](@id_animal int, @id_vaccin int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Animale_Vaccinuri where id_animal = @id_animal and id_vaccin = @id_vaccin)
		return 1;
	return 0;
end;
GO
/****** Object:  UserDefinedFunction [dbo].[validIdPersoane]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validIdPersoane](@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Persoane where id = @id)
		return 1;
	return 0;
end;
GO
/****** Object:  UserDefinedFunction [dbo].[validIdTipuri_Animale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validIdTipuri_Animale](@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Tipuri_Animale where id = @id)
		return 1;
	return 0;
end;
GO
/****** Object:  UserDefinedFunction [dbo].[validIdVaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validIdVaccinuri](@id int)
returns int as
begin
	-- daca exista id-ul pe care il cautam noi in alta tabela
	-- atunci ne va returna 1, altfel 0
	if exists (select * from Vaccinuri where id = @id)
		return 1;
	return 0;
end;
GO
/****** Object:  UserDefinedFunction [dbo].[validNumber]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validNumber](@number smallint)
returns int as
begin
	if (@number < 0)
		return 0;
	return 1;
end;
GO
/****** Object:  UserDefinedFunction [dbo].[validSex]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[validSex](@sex nvarchar(30))
returns int as
begin
	if @sex = 'Feminin' or @sex = 'Masculin'
		return 1;
	return 0;
end;
GO
/****** Object:  Table [dbo].[Angajati]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Angajati](
	[id] [int] NOT NULL,
	[functie] [nvarchar](30) NULL,
	[interval_orar] [nchar](10) NULL,
	[salar] [int] NULL,
	[nume] [nvarchar](30) NOT NULL,
	[prenume] [nvarchar](30) NULL,
	[judet] [nvarchar](30) NULL,
	[id_oras] [smallint] NULL,
	[adresa] [nvarchar](50) NULL,
	[data_nasterii] [date] NULL,
	[studii] [nvarchar](30) NULL,
 CONSTRAINT [PK_Angajat] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ViewAngajati]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[ViewAngajati]
AS
SELECT dbo.Angajati.*
FROM     dbo.Angajati
GO
/****** Object:  Table [dbo].[Persoane]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Persoane](
	[id] [int] NOT NULL,
	[nume] [nvarchar](30) NOT NULL,
	[prenume] [nvarchar](50) NULL,
	[judet] [nvarchar](30) NULL,
	[id_oras] [smallint] NULL,
	[adresa] [nvarchar](250) NULL,
	[data_nasterii] [date] NULL,
 CONSTRAINT [PK_Persoane] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ViewPersoane]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[ViewPersoane]
AS
SELECT dbo.Persoane.*
FROM     dbo.Persoane
GO
/****** Object:  Table [dbo].[Animale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Animale](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[id_proprietar] [int] NOT NULL,
	[nume] [nvarchar](30) NULL,
	[id_tip_animal] [smallint] NOT NULL,
	[sex] [nvarchar](50) NULL,
	[varsta] [smallint] NULL,
 CONSTRAINT [PK_Animale] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ViewAnimale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[ViewAnimale]
AS
SELECT dbo.Animale.*
FROM     dbo.Animale
GO
/****** Object:  Table [dbo].[Vaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Vaccinuri](
	[id] [int] IDENTITY(1,1) NOT NULL,
	[denumire] [nvarchar](50) NULL,
	[termen_valabilitate] [smallint] NULL,
 CONSTRAINT [PK_Vaccin] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ViewVaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[ViewVaccinuri]
AS
SELECT dbo.Vaccinuri.*
FROM     dbo.Vaccinuri
GO
/****** Object:  Table [dbo].[Animale_Vaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Animale_Vaccinuri](
	[id_animal] [int] NOT NULL,
	[id_vaccin] [int] NOT NULL,
 CONSTRAINT [PK_Animale_Vaccinuri] PRIMARY KEY CLUSTERED 
(
	[id_animal] ASC,
	[id_vaccin] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ViewAnimaleVaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   view [dbo].[ViewAnimaleVaccinuri] as
	select A.id as ID_Animal, A.nume, V.denumire as Denumire_Vaccin from
	Vaccinuri V inner join Animale_Vaccinuri AV
	on V.id = AV.id_vaccin
	inner join Animale A 
	on AV.id_animal = A.id
	where V.denumire = 'Rabie';
GO
/****** Object:  Table [dbo].[Programari]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Programari](
	[id] [int] NOT NULL,
	[id_medic] [int] NOT NULL,
	[id_persoana] [int] NOT NULL,
	[data_programare] [date] NULL,
	[ora_programare] [smallint] NULL,
 CONSTRAINT [PK_Programare] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  View [dbo].[ViewProgramari]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE VIEW [dbo].[ViewProgramari]
AS
SELECT dbo.Angajati.id, dbo.Programari.data_programare, dbo.Programari.ora_programare, dbo.Persoane.id AS Expr1, dbo.Persoane.nume, dbo.Persoane.prenume, dbo.Angajati.prenume AS Expr2, dbo.Angajati.nume AS Expr3, 
                  dbo.Angajati.functie
FROM     dbo.Angajati INNER JOIN
                  dbo.Programari ON dbo.Angajati.id = dbo.Programari.id_medic INNER JOIN
                  dbo.Persoane ON dbo.Programari.id_persoana = dbo.Persoane.id
GO
/****** Object:  UserDefinedFunction [dbo].[getAnimal]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[getAnimal](@id int)
returns table as
	return select * from Animale
	where id = @id;
GO
/****** Object:  UserDefinedFunction [dbo].[getVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   function [dbo].[getVaccin](@id int)
returns table as
	return select * from Vaccinuri
	where id = @id;
GO
/****** Object:  View [dbo].[ViewVaccinuriTermen]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   view [dbo].[ViewVaccinuriTermen] as
	select * from Vaccinuri
	where termen_valabilitate > 3;
GO
/****** Object:  Table [dbo].[FiseMedicale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[FiseMedicale](
	[id] [smallint] NOT NULL,
	[diagnostic] [nvarchar](50) NULL,
	[tratament] [nvarchar](50) NULL,
	[id_animal] [int] NULL,
 CONSTRAINT [PK__FiseMedi__3213E83FC960FF79] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY],
 CONSTRAINT [UQ__FiseMedi__3213E83E5D12AE5C] UNIQUE NONCLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Internari]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Internari](
	[id] [smallint] NOT NULL,
	[data_internare] [date] NULL,
	[data_externare] [date] NULL,
	[id_animal] [int] NULL,
 CONSTRAINT [PK_Internare] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Orase]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Orase](
	[id] [smallint] NOT NULL,
	[denumire] [nvarchar](50) NULL,
 CONSTRAINT [PK_Orase] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tables]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tables](
	[TableID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Tables] PRIMARY KEY CLUSTERED 
(
	[TableID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Telefoane]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Telefoane](
	[id] [smallint] NOT NULL,
	[nr_telefon] [char](10) NULL,
	[id_persoana] [int] NULL,
 CONSTRAINT [PK_Telefoane] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestRuns]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestRuns](
	[TestRunID] [int] IDENTITY(1,1) NOT NULL,
	[Description] [nvarchar](2000) NULL,
	[StartAt] [datetime] NULL,
	[EndAt] [datetime] NULL,
 CONSTRAINT [PK_TestRuns] PRIMARY KEY CLUSTERED 
(
	[TestRunID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestRunTables]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestRunTables](
	[TestRunID] [int] NOT NULL,
	[TableID] [int] NOT NULL,
	[StartAt] [datetime] NOT NULL,
	[EndAt] [datetime] NOT NULL,
 CONSTRAINT [PK_TestRunTables] PRIMARY KEY CLUSTERED 
(
	[TestRunID] ASC,
	[TableID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestRunViews]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestRunViews](
	[TestRunID] [int] NOT NULL,
	[ViewID] [int] NOT NULL,
	[StartAt] [datetime] NOT NULL,
	[EndAt] [datetime] NOT NULL,
 CONSTRAINT [PK_TestRunViews] PRIMARY KEY CLUSTERED 
(
	[TestRunID] ASC,
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tests]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tests](
	[TestID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Tests] PRIMARY KEY CLUSTERED 
(
	[TestID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestTables]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestTables](
	[TestID] [int] NOT NULL,
	[TableID] [int] NOT NULL,
	[NoOfRows] [int] NOT NULL,
	[Position] [int] NOT NULL,
 CONSTRAINT [PK_TestTables] PRIMARY KEY CLUSTERED 
(
	[TestID] ASC,
	[TableID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[TestViews]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[TestViews](
	[TestID] [int] NOT NULL,
	[ViewID] [int] NOT NULL,
 CONSTRAINT [PK_TestViews] PRIMARY KEY CLUSTERED 
(
	[TestID] ASC,
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Tipuri_Animale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Tipuri_Animale](
	[id] [smallint] NOT NULL,
	[denumire] [nvarchar](30) NULL,
	[rasa] [nvarchar](50) NULL,
 CONSTRAINT [PK_Tip_Animal] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Versiuni]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Versiuni](
	[id] [int] NULL,
	[versiune] [int] NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Views]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Views](
	[ViewID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
 CONSTRAINT [PK_Views] PRIMARY KEY CLUSTERED 
(
	[ViewID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_Animale_ID_Cresc]    Script Date: 4/27/2023 4:12:20 PM ******/
CREATE NONCLUSTERED INDEX [IX_Animale_ID_Cresc] ON [dbo].[Animale]
(
	[nume] ASC
)
INCLUDE([id],[id_proprietar],[id_tip_animal],[sex],[varsta]) WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_AnimaleVaccinuri_ID_Cresc]    Script Date: 4/27/2023 4:12:20 PM ******/
CREATE NONCLUSTERED INDEX [IX_AnimaleVaccinuri_ID_Cresc] ON [dbo].[Animale_Vaccinuri]
(
	[id_vaccin] ASC
)
INCLUDE([id_animal]) WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
SET ANSI_PADDING ON
GO
/****** Object:  Index [IX_Vaccinuri_Denumire_Cresc]    Script Date: 4/27/2023 4:12:20 PM ******/
CREATE NONCLUSTERED INDEX [IX_Vaccinuri_Denumire_Cresc] ON [dbo].[Vaccinuri]
(
	[denumire] ASC
)
INCLUDE([id],[termen_valabilitate]) WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
/****** Object:  Index [IX_Vaccinuri_Termen_Cresc]    Script Date: 4/27/2023 4:12:20 PM ******/
CREATE NONCLUSTERED INDEX [IX_Vaccinuri_Termen_Cresc] ON [dbo].[Vaccinuri]
(
	[termen_valabilitate] ASC
)
INCLUDE([id],[denumire]) 
WHERE ([termen_valabilitate]>(3))
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, SORT_IN_TEMPDB = OFF, DROP_EXISTING = OFF, ONLINE = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON, OPTIMIZE_FOR_SEQUENTIAL_KEY = OFF) ON [PRIMARY]
GO
ALTER TABLE [dbo].[Persoane] ADD  CONSTRAINT [implicit_value_judet]  DEFAULT ('Arad') FOR [judet]
GO
ALTER TABLE [dbo].[Angajati]  WITH CHECK ADD  CONSTRAINT [FK_Angajat_Orase] FOREIGN KEY([id_oras])
REFERENCES [dbo].[Orase] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Angajati] CHECK CONSTRAINT [FK_Angajat_Orase]
GO
ALTER TABLE [dbo].[Animale]  WITH CHECK ADD  CONSTRAINT [FK_Animale_Persoane] FOREIGN KEY([id_proprietar])
REFERENCES [dbo].[Persoane] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Animale] CHECK CONSTRAINT [FK_Animale_Persoane]
GO
ALTER TABLE [dbo].[Animale]  WITH CHECK ADD  CONSTRAINT [FK_Animale_Tip_Animal] FOREIGN KEY([id_tip_animal])
REFERENCES [dbo].[Tipuri_Animale] ([id])
GO
ALTER TABLE [dbo].[Animale] CHECK CONSTRAINT [FK_Animale_Tip_Animal]
GO
ALTER TABLE [dbo].[Animale_Vaccinuri]  WITH CHECK ADD  CONSTRAINT [FK_Animal_Vaccin_Animale] FOREIGN KEY([id_animal])
REFERENCES [dbo].[Animale] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Animale_Vaccinuri] CHECK CONSTRAINT [FK_Animal_Vaccin_Animale]
GO
ALTER TABLE [dbo].[Animale_Vaccinuri]  WITH CHECK ADD  CONSTRAINT [FK_Animal_Vaccin_Vaccin] FOREIGN KEY([id_vaccin])
REFERENCES [dbo].[Vaccinuri] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Animale_Vaccinuri] CHECK CONSTRAINT [FK_Animal_Vaccin_Vaccin]
GO
ALTER TABLE [dbo].[FiseMedicale]  WITH CHECK ADD  CONSTRAINT [foreign_key] FOREIGN KEY([id_animal])
REFERENCES [dbo].[Animale] ([id])
GO
ALTER TABLE [dbo].[FiseMedicale] CHECK CONSTRAINT [foreign_key]
GO
ALTER TABLE [dbo].[Internari]  WITH CHECK ADD  CONSTRAINT [FK_Internare_Animale] FOREIGN KEY([id_animal])
REFERENCES [dbo].[Animale] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Internari] CHECK CONSTRAINT [FK_Internare_Animale]
GO
ALTER TABLE [dbo].[Persoane]  WITH CHECK ADD  CONSTRAINT [FK_Persoane_Orase] FOREIGN KEY([id_oras])
REFERENCES [dbo].[Orase] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Persoane] CHECK CONSTRAINT [FK_Persoane_Orase]
GO
ALTER TABLE [dbo].[Programari]  WITH CHECK ADD  CONSTRAINT [FK_Programare_Angajat] FOREIGN KEY([id_medic])
REFERENCES [dbo].[Angajati] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Programari] CHECK CONSTRAINT [FK_Programare_Angajat]
GO
ALTER TABLE [dbo].[Programari]  WITH CHECK ADD  CONSTRAINT [FK_Programare_Persoane] FOREIGN KEY([id_persoana])
REFERENCES [dbo].[Persoane] ([id])
GO
ALTER TABLE [dbo].[Programari] CHECK CONSTRAINT [FK_Programare_Persoane]
GO
ALTER TABLE [dbo].[Telefoane]  WITH CHECK ADD  CONSTRAINT [FK_Telefoane_Persoane] FOREIGN KEY([id_persoana])
REFERENCES [dbo].[Persoane] ([id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Telefoane] CHECK CONSTRAINT [FK_Telefoane_Persoane]
GO
ALTER TABLE [dbo].[TestRunTables]  WITH CHECK ADD  CONSTRAINT [FK_TestRunTables_Tables] FOREIGN KEY([TableID])
REFERENCES [dbo].[Tables] ([TableID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunTables] CHECK CONSTRAINT [FK_TestRunTables_Tables]
GO
ALTER TABLE [dbo].[TestRunTables]  WITH CHECK ADD  CONSTRAINT [FK_TestRunTables_TestRuns] FOREIGN KEY([TestRunID])
REFERENCES [dbo].[TestRuns] ([TestRunID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunTables] CHECK CONSTRAINT [FK_TestRunTables_TestRuns]
GO
ALTER TABLE [dbo].[TestRunViews]  WITH CHECK ADD  CONSTRAINT [FK_TestRunViews_TestRuns] FOREIGN KEY([TestRunID])
REFERENCES [dbo].[TestRuns] ([TestRunID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunViews] CHECK CONSTRAINT [FK_TestRunViews_TestRuns]
GO
ALTER TABLE [dbo].[TestRunViews]  WITH CHECK ADD  CONSTRAINT [FK_TestRunViews_Views] FOREIGN KEY([ViewID])
REFERENCES [dbo].[Views] ([ViewID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestRunViews] CHECK CONSTRAINT [FK_TestRunViews_Views]
GO
ALTER TABLE [dbo].[TestTables]  WITH CHECK ADD  CONSTRAINT [FK_TestTables_Tables] FOREIGN KEY([TableID])
REFERENCES [dbo].[Tables] ([TableID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestTables] CHECK CONSTRAINT [FK_TestTables_Tables]
GO
ALTER TABLE [dbo].[TestTables]  WITH CHECK ADD  CONSTRAINT [FK_TestTables_Tests] FOREIGN KEY([TestID])
REFERENCES [dbo].[Tests] ([TestID])
ON UPDATE CASCADE
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[TestTables] CHECK CONSTRAINT [FK_TestTables_Tests]
GO
ALTER TABLE [dbo].[TestViews]  WITH CHECK ADD  CONSTRAINT [FK_TestViews_Tests] FOREIGN KEY([TestID])
REFERENCES [dbo].[Tests] ([TestID])
GO
ALTER TABLE [dbo].[TestViews] CHECK CONSTRAINT [FK_TestViews_Tests]
GO
ALTER TABLE [dbo].[TestViews]  WITH CHECK ADD  CONSTRAINT [FK_TestViews_Views] FOREIGN KEY([ViewID])
REFERENCES [dbo].[Views] ([ViewID])
GO
ALTER TABLE [dbo].[TestViews] CHECK CONSTRAINT [FK_TestViews_Views]
GO
/****** Object:  StoredProcedure [dbo].[actualizeazaAnimal]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[actualizeazaAnimal]
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
GO
/****** Object:  StoredProcedure [dbo].[actualizeazaVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[actualizeazaVaccin]
	@id int,
	@denumire nvarchar(50),
	@termen_valabilitate smallint
as
begin

	if (dbo.validIdVaccinuri(@id) = 0) begin
		raiserror('Vaccinul pe care doriti sa il stergeti nu exista', 10, 1);
		return;
	end;

	update Vaccinuri
	set denumire = @denumire,
		termen_valabilitate =  @termen_valabilitate
	where id = @id;
	
end;
GO
/****** Object:  StoredProcedure [dbo].[change_versions]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[change_versions]
	@versiune_dorita int
as
begin
	declare @versiune_actuala int
	declare @vers int
	set @versiune_actuala = (select versiune from Versiuni where id = 1)
	print @versiune_actuala 

	while @versiune_actuala < @versiune_dorita
	begin
		set @versiune_actuala = @versiune_actuala + 1
		exec('procedura' + @versiune_actuala)
	end

	while @versiune_actuala > @versiune_dorita
	begin
		set @vers = @versiune_actuala + 5 
		exec('procedura' + @vers)
		set @versiune_actuala = @versiune_actuala - 1
	end
end
GO
/****** Object:  StoredProcedure [dbo].[createTests]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create   procedure [dbo].[createTests]
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
GO
/****** Object:  StoredProcedure [dbo].[insert_Angajati]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insert_Angajati]
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
GO
/****** Object:  StoredProcedure [dbo].[insert_Animale]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insert_Animale]
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
GO
/****** Object:  StoredProcedure [dbo].[insert_Animale_Vaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insert_Animale_Vaccinuri]
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
GO
/****** Object:  StoredProcedure [dbo].[insert_Persoane]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insert_Persoane]
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
GO
/****** Object:  StoredProcedure [dbo].[insert_Programari]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insert_Programari]
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
GO
/****** Object:  StoredProcedure [dbo].[insert_Vaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insert_Vaccinuri]
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
GO
/****** Object:  StoredProcedure [dbo].[insertAnimaleVaccinuri]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insertAnimaleVaccinuri]
	@id_proprietar int,
	@nume nvarchar(30),
	@id_tip_animal smallint,
	@sex nvarchar(50),
	@varsta smallint,
	@denumire nvarchar(50),
	@termen_valabilitate smallint
as
begin

	begin tran;

	begin try

		if @sex != 'Feminin' and @sex != 'Masculin'
			throw 50001, 'Sex invalid', 1; 
		if @varsta < 0
			throw 50001, 'Varsta invalida', 1; 
		if @termen_valabilitate < 0
			throw 50001, 'Termen de valabilitate invalid', 1; 
		if @id_proprietar < 0
			throw 50001, 'ID proprietar invalid', 1; 
		if @id_tip_animal < 0
			throw 50001, 'ID tip animal invalid', 1; 
		if (select LEN(@nume)) < 1
			throw 50001, 'Nume invalid', 1; 
		if (select LEN(@denumire)) < 1
			throw 50001, 'Denumire invalida', 1; 

		print('Date valide')

		insert into Vaccinuri values (@denumire, @termen_valabilitate);
		declare @vaccinID as int;
		set @vaccinID = @@IDENTITY;

		print('S-a realizat primul insert - vaccinuri')

		begin tran;

		insert into Animale values (@id_proprietar, @nume, @id_tip_animal, @sex, @varsta);
		declare @animalID as int;
		set @animalID = @@IDENTITY;

		print('S-a realizat al doilea insert - animale')

		commit tran;

		insert into Animale_Vaccinuri values (@animalID, @vaccinID);

		print('S-a realizat al treilea insert - tabel de legatura')

		commit tran;

	end try
	begin catch

		declare @error_message nvarchar(1000);
		select @error_message = ERROR_MESSAGE();
		print @error_message;

		print('Datele nu sunt valide')

		if @@TRANCOUNT > 0
			rollback tran;

	end catch;

end;
GO
/****** Object:  StoredProcedure [dbo].[insertAnimaleVaccinuriVersiunea2]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[insertAnimaleVaccinuriVersiunea2]
	@id_proprietar int,
	@nume nvarchar(30),
	@id_tip_animal smallint,
	@sex nvarchar(50),
	@varsta smallint,
	@denumire nvarchar(50),
	@termen_valabilitate smallint
as
begin

	begin try

		if @sex != 'Feminin' and @sex != 'Masculin'
			throw 50001, 'Sex invalid', 1; 
		if @varsta < 0
			throw 50001, 'Varsta invalida', 1; 
		if @termen_valabilitate < 0
			throw 50001, 'Termen de valabilitate invalid', 1; 
		if @id_proprietar < 0
			throw 50001, 'ID proprietar invalid', 1; 
		if @id_tip_animal < 0
			throw 50001, 'ID tip animal invalid', 1; 
		if (select LEN(@nume)) < 1
			throw 50001, 'Nume invalid', 1; 
		if (select LEN(@denumire)) < 1
			throw 50001, 'Denumire invalida', 1; 

		print('Date valide')

		begin tran;
		save tran savepoint;

		insert into Vaccinuri values (@denumire, @termen_valabilitate);
		declare @vaccinID as int;
		set @vaccinID = @@IDENTITY;

		print('S-a realizat primul insert - vaccinuri')

		save tran savepoint;

		insert into Animale values (@id_proprietar, @nume, @id_tip_animal, @sex, @varsta);
		declare @animalID as int;
		set @animalID = @@IDENTITY;

		print('S-a realizat al doilea insert - animale')

		save tran savepoint;

		insert into Animale_Vaccinuri values (@animalID, @vaccinID);

		print('S-a realizat al treilea insert - tabel de legatura')

		commit tran;

	end try
	begin catch

		rollback tran savepoint;
		commit tran;

		declare @error_message nvarchar(1000);
		select @error_message = ERROR_MESSAGE();
		print @error_message;

		print('Datele nu sunt valide')

	end catch;

end;
GO
/****** Object:  StoredProcedure [dbo].[procedura1]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura1]
as
begin
	alter table Tipuri_Animale
	alter column rasa nvarchar(50);

	print 'am modificat tipul de date'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 1
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura10]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura10]
as
begin
	alter table FiseMedicale
	drop constraint foreign_key

	print 'am sters cheia straina'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 4
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura2]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura2]
as
begin
	alter table Persoane
	add constraint implicit_value_judet default 'Arad' for judet

	print 'am adaugat constrangerea'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 2
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura3]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura3]
as
begin
	create table FiseMedicale(
		id smallint not null unique,
		diagnostic nvarchar(50),
		tratament nvarchar(50),
		primary key(id)
	)

	print 'am creat tabelul'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 3
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura4]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura4]
as
begin
	alter table FiseMedicale
	add id_animal smallint;

	print 'am adaugat coloana'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 4
	where id = 1;

end
GO
/****** Object:  StoredProcedure [dbo].[procedura5]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura5]
as
begin
	alter table FiseMedicale
	add constraint foreign_key foreign key (id_animal)
	references Animale(id)

	print 'am adaugat cheie straina'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 5
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura6]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura6]
as
begin
	alter table Tipuri_Animale
	alter column rasa nvarchar(30);

	print 'am revenit la tipul de date intial'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 0
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura7]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura7]
as
begin
	alter table Persoane
	drop constraint implicit_value_judet

	print 'am sters constrangerea'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 1
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura8]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura8]
as
begin
	drop table FiseMedicale

	print 'am sters tabelul'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 2
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[procedura9]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE procedure [dbo].[procedura9]
as
begin
	alter table FiseMedicale
	drop column id_animal;

	print 'am sters coloana'

	-- aici actualizam versiunea
	update Versiuni
	set versiune = 3
	where id = 1;
end
GO
/****** Object:  StoredProcedure [dbo].[returneazaAnimal]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[returneazaAnimal]
	@id int
as
begin
	if (dbo.validIdAnimale(@id) = 0) begin
		raiserror('Animalul pe care doriti sa il stergeti nu exista', 10, 1);
		return;
	end;
	
	select * from dbo.getAnimal(@id);
end;
GO
/****** Object:  StoredProcedure [dbo].[returneazaAnimaleVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[returneazaAnimaleVaccin]
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
GO
/****** Object:  StoredProcedure [dbo].[returneazaVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[returneazaVaccin]
	@id int
as
begin
	if (dbo.validIdVaccinuri(@id) = 0) begin
		raiserror('Vaccinul pe care doriti sa il cautati nu exista', 10, 1);
		return;
	end;
	
	select * from dbo.getVaccin(@id);
end;
GO
/****** Object:  StoredProcedure [dbo].[salveazaAnimal]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[salveazaAnimal]
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
	insert into Animale values (@id_proprietar, @nume, @id_tip_animal, @sex, @varsta);
end;
GO
/****** Object:  StoredProcedure [dbo].[salveazaAnimaleVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[salveazaAnimaleVaccin]
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
GO
/****** Object:  StoredProcedure [dbo].[salveazaVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[salveazaVaccin]
	@denumire nvarchar(50),
	@termen_valabilitate smallint
as
begin
	insert into Vaccinuri values (@denumire, @termen_valabilitate);
end;
GO
/****** Object:  StoredProcedure [dbo].[stergeAnimal]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[stergeAnimal]
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
GO
/****** Object:  StoredProcedure [dbo].[stergeAnimaleVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[stergeAnimaleVaccin]
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
GO
/****** Object:  StoredProcedure [dbo].[stergeVaccin]    Script Date: 4/27/2023 4:12:20 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
create   procedure [dbo].[stergeVaccin]
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
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[40] 4[20] 2[20] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "Angajati"
            Begin Extent = 
               Top = 7
               Left = 48
               Bottom = 170
               Right = 242
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewAngajati'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewAngajati'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[40] 4[20] 2[20] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "Animale"
            Begin Extent = 
               Top = 7
               Left = 48
               Bottom = 170
               Right = 242
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewAnimale'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewAnimale'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[32] 4[29] 2[16] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "Animale"
            Begin Extent = 
               Top = 7
               Left = 48
               Bottom = 170
               Right = 242
            End
            DisplayFlags = 280
            TopColumn = 0
         End
         Begin Table = "Animale_Vaccinuri"
            Begin Extent = 
               Top = 7
               Left = 290
               Bottom = 126
               Right = 484
            End
            DisplayFlags = 280
            TopColumn = 0
         End
         Begin Table = "Vaccinuri"
            Begin Extent = 
               Top = 27
               Left = 553
               Bottom = 168
               Right = 775
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
      Begin ColumnWidths = 9
         Width = 284
         Width = 1200
         Width = 2784
         Width = 1548
         Width = 1944
         Width = 1200
         Width = 1200
         Width = 1200
         Width = 1200
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 12
         Column = 1440
         Alias = 900
         Table = 1176
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1356
         SortOrder = 1416
         GroupBy = 1356
         Filter = 1356
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewAnimaleVaccinuri'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewAnimaleVaccinuri'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[40] 4[20] 2[20] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "Persoane"
            Begin Extent = 
               Top = 7
               Left = 48
               Bottom = 170
               Right = 242
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewPersoane'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewPersoane'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[31] 4[23] 2[27] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "Angajati"
            Begin Extent = 
               Top = 10
               Left = 43
               Bottom = 173
               Right = 237
            End
            DisplayFlags = 280
            TopColumn = 4
         End
         Begin Table = "Programari"
            Begin Extent = 
               Top = 7
               Left = 290
               Bottom = 170
               Right = 500
            End
            DisplayFlags = 280
            TopColumn = 1
         End
         Begin Table = "Persoane"
            Begin Extent = 
               Top = 4
               Left = 552
               Bottom = 167
               Right = 746
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewProgramari'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewProgramari'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPane1', @value=N'[0E232FF0-B466-11cf-A24F-00AA00A3EFFF, 1.00]
Begin DesignProperties = 
   Begin PaneConfigurations = 
      Begin PaneConfiguration = 0
         NumPanes = 4
         Configuration = "(H (1[40] 4[20] 2[20] 3) )"
      End
      Begin PaneConfiguration = 1
         NumPanes = 3
         Configuration = "(H (1 [50] 4 [25] 3))"
      End
      Begin PaneConfiguration = 2
         NumPanes = 3
         Configuration = "(H (1 [50] 2 [25] 3))"
      End
      Begin PaneConfiguration = 3
         NumPanes = 3
         Configuration = "(H (4 [30] 2 [40] 3))"
      End
      Begin PaneConfiguration = 4
         NumPanes = 2
         Configuration = "(H (1 [56] 3))"
      End
      Begin PaneConfiguration = 5
         NumPanes = 2
         Configuration = "(H (2 [66] 3))"
      End
      Begin PaneConfiguration = 6
         NumPanes = 2
         Configuration = "(H (4 [50] 3))"
      End
      Begin PaneConfiguration = 7
         NumPanes = 1
         Configuration = "(V (3))"
      End
      Begin PaneConfiguration = 8
         NumPanes = 3
         Configuration = "(H (1[56] 4[18] 2) )"
      End
      Begin PaneConfiguration = 9
         NumPanes = 2
         Configuration = "(H (1 [75] 4))"
      End
      Begin PaneConfiguration = 10
         NumPanes = 2
         Configuration = "(H (1[66] 2) )"
      End
      Begin PaneConfiguration = 11
         NumPanes = 2
         Configuration = "(H (4 [60] 2))"
      End
      Begin PaneConfiguration = 12
         NumPanes = 1
         Configuration = "(H (1) )"
      End
      Begin PaneConfiguration = 13
         NumPanes = 1
         Configuration = "(V (4))"
      End
      Begin PaneConfiguration = 14
         NumPanes = 1
         Configuration = "(V (2))"
      End
      ActivePaneConfig = 0
   End
   Begin DiagramPane = 
      Begin Origin = 
         Top = 0
         Left = 0
      End
      Begin Tables = 
         Begin Table = "Vaccinuri"
            Begin Extent = 
               Top = 7
               Left = 48
               Bottom = 148
               Right = 270
            End
            DisplayFlags = 280
            TopColumn = 0
         End
      End
   End
   Begin SQLPane = 
   End
   Begin DataPane = 
      Begin ParameterDefaults = ""
      End
   End
   Begin CriteriaPane = 
      Begin ColumnWidths = 11
         Column = 1440
         Alias = 900
         Table = 1170
         Output = 720
         Append = 1400
         NewValue = 1170
         SortType = 1350
         SortOrder = 1410
         GroupBy = 1350
         Filter = 1350
         Or = 1350
         Or = 1350
         Or = 1350
      End
   End
End
' , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewVaccinuri'
GO
EXEC sys.sp_addextendedproperty @name=N'MS_DiagramPaneCount', @value=1 , @level0type=N'SCHEMA',@level0name=N'dbo', @level1type=N'VIEW',@level1name=N'ViewVaccinuri'
GO
USE [master]
GO
ALTER DATABASE [SpitalVeterinar] SET  READ_WRITE 
GO
