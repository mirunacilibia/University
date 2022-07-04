'''
Created on Nov 10, 2020

@author: Miruna
'''
from Validari.Validare import RepositoryException

class RepositoryEvenimente():
    """
    Repository evenimente
    """
    def __init__(self):
        self.__lista_evenimente = []
    
    def adauga_eveniment(self, eveniment):
        """
        Functie care adauga un eveniment
        """
        self.__lista_evenimente.append(eveniment) 
        
    def modificare_eveniment(self, index, eveniment):
        """
        Functie care modifica un eveniment
        """
        self.__lista_evenimente[index].set_descriere(eveniment.get_descriere())
        self.__lista_evenimente[index].set_data(eveniment.get_zi_eveniment(), eveniment.get_luna_eveniment(), eveniment.get_an_eveniment())
        self.__lista_evenimente[index].set_timp(eveniment.get_ora(), eveniment.get_minut())
    
    def sterge_eveniment(self, eveniment):
        """
        Functie care sterge un eveniment
        """
        self.__lista_evenimente.remove(eveniment) 

    def get_lista_evenimente(self):
        """
        Functie care returneaza toate evenimentele adaugate
        """
        return self.__lista_evenimente
    
    def cautare_element_ID(self, id):
        """
        Functie care cauta un element (persoana / eveniment) dupa id-ul acestuia
        id - id-ul elementului
        Functia returneaza indexul elementului, daca acesta s-a gasit, sau -1, daca elementul nu exista in lista
        """
        index = -1
        for i, el in enumerate (self.get_lista_evenimente()):
            if int(el.get_id()) == int(id):
                index = i
                break
        if index == -1:
            raise RepositoryException("ID-ul nu exista in lista")
        return index
    
    def cautare_eveniment_descriere(self, descriere):
        """
        Functie care cauta un eveniment dupa descrierea acestuia
        descriere - descriere evenimentului
        Functia returneaza indexul persoanei, daca aceasta s-a gasit, sau -1, daca persoana nu exista in lista
        """
        index = -1
        for i, el in enumerate (self.get_lista_evenimente()):
            if str(el.get_descriere()) == str(descriere):
                index = i
                break
        if index == -1:
            raise RepositoryException("Descrierea nu exista in lista")
        return index
    
    def get_numar_evenimente(self):
        """
        Functie care returneaza numarul de evenimente adaugate
        """
        return len(self.__lista_evenimente)
