'''
Created on Nov 10, 2020

@author: Miruna
'''
from Domain.Persoana import Persoana
from Validari.Validare import ValidareNumar, ValidareNume
from Sortari import selection_sort, shake_sort

from random import randint

class Service_Persoane():
    """
    Clasa care gestioneaza persoanele
    """
    def __init__(self, repository_persoane, validator):
        self.__repository = repository_persoane
        self.__validator = validator
        
    def adaugare_persoana(self, nume, prenume, localitate, strada, numar):
        """
        Functie care adauga o noua persoana
        nume, prenume, localitate, strada, numar - datele persoanei
        """
        persoana_noua = Persoana()
        persoana_noua.set_nume(nume)
        persoana_noua.set_prenume(prenume)
        persoana_noua.set_adresa(localitate, strada, numar)
        
        self.__validator.exceptie(persoana_noua)

        self.__repository.adauga_persoana(persoana_noua)
        
    def adaugare_aleator(self, numar_persoane):
        """
        Functie care adauga o noua persoana
        numar_persoane - numarul de persoane care trebuie adaugate
        """
        for i in range(int(numar_persoane)):
        
            localitati = ["Arad", "Bucuresti", "Cluj-Napoca", "Timisoara", "Oradea", "Constanta", 
                          "Resita", "Craiova", "Iasi", "Botosani", "Satu-Mare", "Baia-Mare", "Bacau", 
                          "Miercurea Ciuc", "Vaslui", "Targu Mures", "Zalau", "Alba-Iulia"]
            lista_prenume = ["Miruna", "Malina", "Ana", "Maria", "Ioana", "Alexandra", "Andreea", "Cristina",
                             "Alexandru", "Andrei", "Rares", "Radu", "Adrian", "Vasile", "Gheorghe", "Cristian",
                             "Eduard", "Denis", "Vlad", "Iasmina", "Claudia", "Madalina", "Mihnea", "Robert",
                             "Mihai", "Oana", "Alexia", "Adina"]
            lista_vocale = "aeiouAEIOU"
            lista_vocale = list(lista_vocale)
            lista_consoane = "bcdfghjlmnprstvzBCDFGHJLMNPRSTVZ"
            lista_consoane = list(lista_consoane)
            litere = [lista_vocale, lista_consoane]
    
            nr_litere = randint(3,15)
           
            se_incepe = randint(0, 1)
            nume = litere[se_incepe][randint(len(litere[se_incepe]) / 2, len(litere[se_incepe]) - 1)]
            
            for i in range(nr_litere - 1):
                if se_incepe == 0:
                    se_incepe = 1
                else:
                    se_incepe = 0
                nume += litere[se_incepe][randint(0 , len(litere[se_incepe]) / 2 - 1)]
                  
            prenume = lista_prenume[randint(0, len(lista_prenume) - 1)]
            
            localitate = localitati[randint(0, len(localitati) - 1)]
            
            nr_litere = randint(3,15)
            
            se_incepe = randint(0, 1)
            strada = litere[se_incepe][randint(len(litere[se_incepe]) / 2, len(litere[se_incepe]) - 1)]
            for i in range(nr_litere - 1):
                if se_incepe == 0:
                    se_incepe = 1
                else:
                    se_incepe = 0
                strada += litere[se_incepe][randint(0 , len(litere[se_incepe]) / 2 - 1)]
            
            numar = randint(1, 1000)
            
            persoana_noua = Persoana()
            persoana_noua.set_nume(nume)
            persoana_noua.set_prenume(prenume)
            persoana_noua.set_adresa(localitate, strada, numar)
    
            self.__repository.adauga_persoana(persoana_noua)    
            
    def sterge_persoana(self, index):
        """
        Functie care sterge o persoana
        index - indexul persoanei
        """
        self.__repository.sterge_persoana(self.__repository.get_lista_persoane()[index])
        
    def cautare_element_ID(self, id):
        """
        Functie care cauta un element (persoana / eveniment) dupa id-ul acestuia
        id - id-ul elementului
        Functia returneaza indexul elementului, daca acesta s-a gasit, sau -1, daca elementul nu exista in lista
        """
        valideaza = ValidareNumar()
        if valideaza.exceptie(id, 1, Persoana.id_persoane):
            index  = self.__repository.cautare_element_ID(id)
        else:
            raise ValueError
        return index
    
    def cautare_persoana_nume(self, nume):
        """
        Functie care cauta o persoana dupa numele acesteia
        nume - numele persoanei
        Functia returneaza indexul persoanei, daca aceasta s-a gasit, sau -1, daca persoana nu exista in lista
        """
        valideaza = ValidareNume()
        if valideaza.exceptie(nume):
            index  = self.__repository.cautare_persoana_nume(nume)
        else:
            raise ValueError
        return index
        
    def modificare_persoana(self, index, nume, prenume, localitate, strada, numar):
        """
        Functie care modifica datele unei persoane
        index - indexul persoanei a carei date sunt actualizate
        nume, prenume, localitate, strada, numar - datele persoanei
        """
        persoana = Persoana()
        persoana.set_nume(nume)
        persoana.set_prenume(prenume)
        persoana.set_adresa(localitate, strada, numar)
        
        self.__validator.exceptie(persoana)
        
        Persoana.scade_id_persoane(1)
        
        self.__repository.modificare_persoana(index, persoana)
        
    def ordonare_dupa_nume(self):
        """
        Functie care ordoneaza lista de persoane dupa numele de familie
        """         
        lista = self.__repository.get_lista_persoane()
        lista = selection_sort(lista, key = lambda x: x.get_nume_intreg())
        return lista
    
    
