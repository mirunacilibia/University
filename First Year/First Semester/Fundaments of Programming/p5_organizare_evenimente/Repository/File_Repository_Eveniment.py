'''
Created on Nov 26, 2020

@author: Miruna
'''
from Domain.Eveniment import Eveniment
from Repository.Repository_Eveniment import RepositoryEvenimente

class FileRepositoryEveniment(RepositoryEvenimente):
    """
    Clasa pentru stocarea datelor legate de evenimente in fisiere
    """
    
    def __init__(self, file):
        RepositoryEvenimente.__init__(self)
        self.__file = file
        self.__load_from_file()
        
    def __load_from_file(self):
        """
        Functie care preia evenimentele din fisier
        """
        try:
            file = open(self.__file, "r")
        except IOError:
            return []
        line = file.readline().strip()
        
        while line != "":
            eveniment = Eveniment()
            date_eveniment = line.split(";")
            eveniment.set_descriere(date_eveniment[1].strip())
            eveniment.set_data(date_eveniment[2].strip(), date_eveniment[3].strip(), date_eveniment[4].strip())
            eveniment.set_timp(date_eveniment[5].strip(), date_eveniment[6].strip())
            RepositoryEvenimente.adauga_eveniment(self, eveniment)
            line = file.readline().strip()
        file.close()
    
    def __append_to_file(self, eveniment):
        """
        Functie care adauga in fisier un nou eveniment
        """
        file = open(self.__file,"a")
        line = str(eveniment.get_id()) + ";" + eveniment.get_descriere() + ";" + str(eveniment.get_zi_eveniment()) + ";" + str(eveniment.get_luna_eveniment()) + ";" + str(eveniment.get_an_eveniment()) + ";" + str(eveniment.get_ora()) + ";" + str(eveniment.get_minut())
        file.write("\n")
        file.write(line)
        file.close()
    
    def adauga_eveniment(self, eveniment):
        """
        Modific functia din RepositoryPersoane
        """
        RepositoryEvenimente.adauga_eveniment(self, eveniment)
        
        self.__append_to_file(eveniment)
        
    def modificare_eveniment(self, index, eveniment):
        """
        Functie care modifica in fisier o persoana
        """
        id = self.get_lista_evenimente()[index].get_id()
        RepositoryEvenimente.modificare_eveniment(self, index, eveniment)
        modificare = str(id) + ";" + eveniment.get_descriere() + ";" + str(eveniment.get_zi_eveniment()) + ";" + str(eveniment.get_luna_eveniment()) + ";" + str(eveniment.get_an_eveniment()) + ";" + str(eveniment.get_ora()) + ";" + str(eveniment.get_minut())
        file = open(self.__file, "r")
        lines = file.readlines()
        file.close()
        new_file = open(self.__file, "w")
        i = 0
        for line in lines:
            if index == i:
                new_file.write(modificare)
                new_file.write("\n")
            else:
                new_file.write(line)
            i += 1
        new_file.close()
        
    def sterge_eveniment(self, eveniment):
        """
        Functie care sterge o persoana din fisier
        """
        RepositoryEvenimente.sterge_eveniment(self, eveniment)
        
        file = open(self.__file, "r")
        lines = file.read()
        lines = lines.split("\n")
        file.close()
        id = eveniment.get_id()
        new_file = open(self.__file, "w")
        for line in lines:
            date_eveniment = line.split(";")
            if line == "":
                continue
            elif int(id) == int(date_eveniment[0].strip()):
                continue
            else:
                new_file.write(line)
                new_file.write("\n")
        new_file.close()
        