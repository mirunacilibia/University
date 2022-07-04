'''
Created on Nov 26, 2020

@author: Miruna
'''
from Domain.Persoana import Persoana
from Repository.Repository_Persoana import RepositoryPersoane

class FileRepositoryPersoane(RepositoryPersoane):
    """
    Clasa pentru stocarea datelor legate de persoane in fisiere
    """
    
    def __init__(self, file):
        RepositoryPersoane.__init__(self)
        self.__file = file
        self.__load_from_file()
        
    def __load_from_file(self):
        """
        Functie care preia persoanele din fisier
        """
        try:
            file = open(self.__file, "r")
        except IOError:
            return []
        line = file.readline().strip()
        
        while line != "":
            persoana = Persoana()
            date_persoana = line.split(";")
            persoana.set_nume(date_persoana[1].strip())
            persoana.set_prenume(date_persoana[2].strip())
            persoana.set_adresa(date_persoana[3].strip(), date_persoana[4].strip(), date_persoana[5].strip())
            RepositoryPersoane.adauga_persoana(self, persoana)
            line = file.readline().strip()
        file.close()
    
    def __append_to_file(self, persoana):
        """
        Functie care adauga in fisier o noua persoana
        """
        file = open(self.__file, "a")
        line = str(persoana.get_id()) + ";" + persoana.get_nume() + ";" + persoana.get_prenume() + ";" + persoana.get_localitate() + ";" + persoana.get_strada() + ";" + str(persoana.get_numar()) 
        file.write("\n")
        file.write(line)
        file.close()
    
    def adauga_persoana(self, persoana):
        """
        Modific functia din RepositoryPersoane
        """
        RepositoryPersoane.adauga_persoana(self, persoana)
        
        self.__append_to_file(persoana)
        
    def modificare_persoana(self, index, persoana):
        """
        Functie care modifica in fisier o persoana
        """
        id = self.get_lista_persoane()[index].get_id()
        RepositoryPersoane.modificare_persoana(self, index, persoana)
        modificare = str(id) + ";" + persoana.get_nume() + ";" + persoana.get_prenume() + ";" + persoana.get_localitate() + ";" + persoana.get_strada() + ";" + str(persoana.get_numar()) 
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
        
    def sterge_persoana(self, persoana):
        """
        Functie care sterge o persoana din fisier
        """
        RepositoryPersoane.sterge_persoana(self, persoana)
        
        file = open(self.__file, "r")
        lines = file.read()
        lines = lines.split("\n")
        file.close()
        id = persoana.get_id()
        new_file = open(self.__file, "w")
        for line in lines:
            date_persoana = line.split(";")
            if line == "":
                continue
            elif int(id) == int(date_persoana[0].strip()):
                continue
            else:
                new_file.write(line)
                new_file.write("\n")
        new_file.close()
        
                
        
        
        
        
    