'''
Created on Nov 26, 2020

@author: Miruna
'''
from Validari.Validare import test_exceptii
from Controller.Service_Evenimente import test_interschimbare

from Repository.Repository_Persoana import RepositoryPersoane
from Repository.Repository_Eveniment import RepositoryEvenimente
from Repository.Repository_Inscrieri import Repository_Inscrieri

from Repository.File_Repository_Persoana import FileRepositoryPersoane
from Repository.File_Repository_Eveniment import FileRepositoryEveniment
from Repository.File_Repository_Inscrieri import FileRepositoryInscrieri
from Repository.File_Repository_Nou import RepositoryFilePersoanaNou

from Interfata.UI import ui

test_exceptii()
test_interschimbare()

#tabel_persoane = RepositoryFilePersoanaNou("Persoane.txt")

tabel_persoane = FileRepositoryPersoane("Persoane.txt")
tabel_evenimente = FileRepositoryEveniment("Evenimente.txt")
lista_inscrieri = FileRepositoryInscrieri("Inscrieri.txt")

#tabel_persoane = RepositoryPersoane()
#tabel_evenimente = RepositoryEvenimente()
#lista_inscrieri = Repository_Inscrieri()

ui(tabel_persoane, tabel_evenimente, lista_inscrieri)
