'''
Created on Dec 3, 2020

@author: Miruna
'''
from Domain.Persoana import Persoana
from Validari.Validare import RepositoryException

class RepositoryFilePersoanaNou():
    
    def __init__(self, fisier):
        self.__file = fisier
        
    def adauga_persoana(self, persoana):
        """
        Functie care adauga in fisier o persoana
        """
        file = open(self.__file, "a")
        line = str(persoana.get_id()) + ";" + persoana.get_nume() + ";" + persoana.get_prenume() + ";" + persoana.get_localitate() + ";" + persoana.get_strada() + ";" + str(persoana.get_numar()) 
        file.write(line)
        file.write("\n")
        file.close()
        
    def modificare_persoana(self, index, persoana):
        """
        Functie care modifica in fisier o persoana
        """
        file = open(self.__file, "r")
        line = file.readline().strip()
        i = 0
        while line != "":
            if i == index:
                id = line[0]
                break
            i += 1
            line = file.readline().strip()
        file.close()
        modificare = str(id) + ";" + persoana.get_nume() + ";" + persoana.get_prenume() + ";" + persoana.get_localitate() + ";" + persoana.get_strada() + ";" + str(persoana.get_numar()) 
        
        i = 0 
        file = open(self.__file, "r") 
        line = file.readline().strip()
        auxiliar = open(self.__file, "w")  
        while line:
            if index == i:
                auxiliar.write(modificare)
                auxiliar.write("\n")
            else:
                auxiliar.write(line)
                auxiliar.write("\n")
            line = file.readline().strip()
            i += 1
        file.close()
        auxiliar.close()
        
    def sterge_persoana(self, persoana):
        """
        Functie care sterge o persoana din fisier
        """
        id = persoana.get_id()
        i = 0 
        file = open(self.__file, "r") 
        line = file.readline().strip()
        auxiliar = open(self.__file, "w")  
        
        while line:
            if int(id) != int(line[0]):
                auxiliar.write(line)
                auxiliar.write("\n")
            line = file.readline().strip()
            i += 1
        file.close()
        auxiliar.close()
        
    def cautare_element_ID(self, id):
        """
        Functie care cauta un element (persoana / eveniment) dupa id-ul acestuia
        id - id-ul elementului
        Functia returneaza indexul elementului, daca acesta s-a gasit, sau -1, daca elementul nu exista in lista
        """
        index = -1
        file = open(self.__file, "r")
        line = file.readline().strip()
        i = 0
        while line != "":
            if id == line[0]:
                index = i
                break
            i += 1
            line = file.readline().strip()
        file.close()
        if index == -1:
            raise RepositoryException("ID-ul nu exista in lista")
        return index
        
    def cautare_persoana_nume(self, nume):
        """
        Functie care cauta o persoana dupa numele acesteia
        nume - numele persoanei
        Functia returneaza indexul persoanei, daca aceasta s-a gasit, sau -1, daca persoana nu exista in lista
        """
        index = -1
        file = open(self.__file, "r")
        line = file.readline().strip()
        i = 0
        while line != "":
            date_persoana = line.split(";")
            nume_intreg = date_persoana[1] + " " + date_persoana[2]
            if nume == nume_intreg:
                index = i
                break
            i += 1
            line = file.readline().strip()
        file.close()
        if index == -1:
            raise RepositoryException("Numele nu exista in lista")
        return index

    def get_numar_persoane(self):
        """
        Functie care returneaza numarul de persoane inscrise
        """
        try:
            file = open(self.__file, "r")
        except IOError:
            return []
        line = file.readline().strip()
        i = 0
        while line != "":
            i += 1
            line = file.readline().strip()
        file.close()
        
        return i
    
    def get_lista_persoane(self):
        """
        Functie care primeste lista tuturor persoanelor inscrise
        """
        lista = []
        
        file = open(self.__file, "r")
        
        line = file.readline().strip()
        
        while line:
            persoana = Persoana()
            date_persoana = line.split(";")
            persoana.set_id(date_persoana[0].strip())
            persoana.set_nume(date_persoana[1].strip())
            persoana.set_prenume(date_persoana[2].strip())
            persoana.set_adresa(date_persoana[3].strip(), date_persoana[4].strip(), date_persoana[5].strip())
            lista.append(persoana)
            Persoana.scade_id_persoane(1)
            line = file.readline().strip()
        file.close()
        
        return lista
        
        
        
        
        
        
        
        
        
        
        
        
        