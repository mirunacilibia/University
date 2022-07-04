'''
Created on Nov 17, 2020

@author: Miruna
'''

from Domain.Inscriere import Inscriere
from Validari.Validare import RepositoryException

class Repository_Inscrieri():
    """
    Clasa pentru inscrieri
    """
    
    def __init__(self):
        
        self.__lista_inscrieri = []
     
    def get_lista_inscrieri(self):
        """
        Functie care returneaza lista tuturor inscrierilor
        """
        return self.__lista_inscrieri
     
    def inscrie_persoana_la_eveniment(self, id_persoana, id_eveniment):
        """
        Functie care inscrie o persoana la un eveniment
        """
        inscriere = Inscriere(id_persoana, id_eveniment)
        
        for inscrieri in self.__lista_inscrieri:
            if inscriere.get_id_persoana() == inscrieri.get_id_persoana() and inscriere.get_id_eveniment() == inscrieri.get_id_eveniment():
                raise RepositoryException("Persoana este inscrisa la acest eveniment deja!")
                break
        self.__lista_inscrieri.append(inscriere)
 
    def get_nr_evenimente_la_care_e_inscris(self, id_persoana):
        """
        Functie care returneaza numarul de evenimente la care e inscrisa o persoana
        """
        numar_evenimente = 0
        for inscriere in self.__lista_inscrieri:
            if int(inscriere.get_id_persoana()) == int(id_persoana):
                numar_evenimente += 1
        return numar_evenimente
    
    def get_nr_persoane_inscrise(self, id_eveniment):
        """
        Functie care returneaza numarul de persoane inscrise la un eveniment
        """
        numar_persoane = 0
        for inscriere in self.__lista_inscrieri:
            if int(inscriere.get_id_eveniment()) == int(id_eveniment):
                numar_persoane += 1
        return numar_persoane
    
    def get_lista_evenimente_la_care_e_inscris(self, id_persoana):
        """
        Functie care returneaza lista de evenimente la care e inscrisa o persoana
        """
        lista_id_evenimente = []
        for inscriere in self.__lista_inscrieri:
            if int(inscriere.get_id_persoana()) == int(id_persoana):
                lista_id_evenimente.append(inscriere.get_id_eveniment())
        return lista_id_evenimente
        




