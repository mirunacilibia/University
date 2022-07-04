'''
Created on Nov 10, 2020

@author: Miruna
'''
from Validari.Validare import RepositoryException

class RepositoryPersoane():
    """
    Repository pentru persoana
    """
    def __init__(self):
        self.__lista_persoane = []
        self.__elemente_lista = 0
    
    def adauga_persoana(self, persoana):
        """
        Functie care adauga o persoana
        """
        self.__lista_persoane.append(persoana) 
        self.__elemente_lista += 1
        
    def modificare_persoana(self, index, persoana):
        """
        Functie care modifica o persoana
        """
        self.__lista_persoane[index].set_nume(persoana.get_nume())
        self.__lista_persoane[index].set_prenume(persoana.get_prenume())
        self.__lista_persoane[index].set_adresa(persoana.get_localitate(), persoana.get_strada(), persoana.get_numar())
    
    def sterge_persoana(self, persoana):
        """
        Functie care sterge o persoana
        """
        self.__lista_persoane.remove(persoana) 
        self.__elemente_lista -= 1
        
    def get_lista_persoane(self):
        """
        Functie care primeste lista tuturor persoanelor inscrise
        """
        return self.__lista_persoane
    
    def cautare_element_ID(self, id):
        """
        Functie care cauta un element (persoana / eveniment) dupa id-ul acestuia, recursiv
        id - id-ul elementului
        Functia returneaza indexul elementului, daca acesta s-a gasit, sau -1, daca elementul nu exista in lista
        """
        index = RepositoryPersoane.cautare_id_recursiv(self.get_lista_persoane(), id, 0)
        if index == -1:
            raise RepositoryException("ID-ul nu exista in lista")
        return index
    
    @staticmethod
    def cautare_id_recursiv(lista, id, pozitie):
        """
        Functie pentru cautarea recursiva
        """
        if pozitie == len(lista): 
            return -1
        elif int(lista[pozitie].get_id()) == int(id):
            return pozitie
        else:
            return RepositoryPersoane.cautare_id_recursiv(lista, id, pozitie + 1)
    
    def cautare_persoana_nume(self, nume):
        """
        Functie care cauta o persoana dupa numele acesteia
        nume - numele persoanei
        Functia returneaza indexul persoanei, daca aceasta s-a gasit, sau -1, daca persoana nu exista in lista
        """
        index = RepositoryPersoane.cautare_nume_recursiv(self.get_lista_persoane(), nume, 0)
        if index == -1:
            raise RepositoryException("Numele nu exista in lista")
        return index

    @staticmethod
    def cautare_nume_recursiv(lista, nume, pozitie):
        """
        Functie pentru cautarea recursiva
        """
        if pozitie == len(lista): 
            return -1
        elif str(lista[pozitie].get_nume_intreg()) == str(nume):
            return pozitie
        else:
            return RepositoryPersoane.cautare_nume_recursiv(lista, nume, pozitie + 1)

    def get_numar_persoane(self):
        """
        Functie care returneaza nmarul de persoane inscrise
        """
        return self.__elemente_lista
    