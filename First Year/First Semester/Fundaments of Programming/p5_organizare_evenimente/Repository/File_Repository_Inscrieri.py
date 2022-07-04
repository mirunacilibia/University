'''
Created on Nov 26, 2020

@author: Miruna
'''

from Repository.Repository_Inscrieri import Repository_Inscrieri

class FileRepositoryInscrieri(Repository_Inscrieri):
    """
    Repository pentru inscrieri in fisier
    """
    
    def __init__(self, file):
        Repository_Inscrieri.__init__(self)
        self.__file = file
        self.__load_from_file()
    
    def __load_from_file(self):
        """
        Functie care preia inscrierile din fisier
        """
        try:
            file = open(self.__file, "r")
        except IOError:
            return []
        line = file.readline().strip()
        while line != "":
            date_inscriere = line.split(";")
            Repository_Inscrieri.inscrie_persoana_la_eveniment(self, date_inscriere[0].strip(), date_inscriere[1].strip())
            line = file.readline().strip()
        file.close()
        
    def __append_to_file(self, id_persoana, id_eveniment):
        """
        Functie care adauga in fisier o noua inscriere
        """
        file = open(self.__file,"a")
        line = str(id_persoana) + ";" + str(id_eveniment)
        file.write("\n")
        file.write(line)
        file.close()
        
    def inscrie_persoana_la_eveniment(self, id_persoana, id_eveniment):
        """
        Modific functia din Repository_Inscrieri
        """
        Repository_Inscrieri.inscrie_persoana_la_eveniment(self, id_persoana, id_eveniment)
        self.__append_to_file(id_persoana, id_eveniment)
    
    
    
    
    
    
    
    
        
        
        