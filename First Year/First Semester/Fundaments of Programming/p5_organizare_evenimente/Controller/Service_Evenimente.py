'''
Created on Nov 10, 2020

@author: Miruna
'''

from Domain.Eveniment import Eveniment
from Validari.Validare import ValidareNumar, ValidareNume, ValidareData
from Sortari import selection_sort, shake_sort, selection_sort_doua_criterii

from random import randint

class Service_Evenimente():
    """
    Clasa care gestioneaza evenimentele
    """
    def __init__(self, repository, validator):
        
        self.__repository = repository
        self.__validator = validator
        
    
    def adaugare_eveniment(self, descriere, zi, luna, an, ora, minut):
        """
        Functie care adauga un nou eveniment
        descriere, zi, luna, an, ora, minut - datele evenimentului
        """
        eveniment = Eveniment()
        eveniment.set_descriere(descriere)
        eveniment.set_data(zi, luna, an)
        eveniment.set_timp(ora, minut)
        
        self.__validator.exceptie(eveniment)

        self.__repository.adauga_eveniment(eveniment)
        
    def sterge_eveniment(self, index):
        """
        Functie care sterge un eveniment
        index - indexul evenimentului
        """
        self.__repository.sterge_eveniment(self.__repository.get_lista_evenimente()[index])
        
    def cautare_element_ID(self, id):
        """
        Functie care cauta un element (persoana / eveniment) dupa id-ul acestuia
        id - id-ul elementului
        Functia returneaza indexul elementului, daca acesta s-a gasit, sau -1, daca elementul nu exista in lista
        """
        valideaza = ValidareNumar()
        if valideaza.exceptie(id, 1, Eveniment.id_evenimente):
            index = self.__repository.cautare_element_ID(id)
        else:
            raise ValueError
        return index
    
    def cautare_eveniment_descriere(self, descriere):
        """
        Functie care cauta un eveniment dupa descrierea acestuia
        descriere - descriere evenimentului
        Functia returneaza indexul persoanei, daca aceasta s-a gasit, sau -1, daca persoana nu exista in lista
        """
        valideaza = ValidareNume()
        if valideaza.exceptie(descriere):
            index = self.__repository.cautare_eveniment_descriere(descriere)
        else:
            raise ValueError
        return index
        
    def modificare_eveniment(self, index, descriere, zi, luna, an, ora, minut):
        """
        Functie care modifica datele unui eveniment
        index - indexul evenimentului a carui date sunt actualizate
        descriere, zi, luna, an, ora, minut - datele evenimentului
        """
        eveniment = Eveniment()
        eveniment.set_descriere(descriere)
        eveniment.set_data(zi, luna, an)
        eveniment.set_timp(ora, minut)
        
        self.__validator.exceptie(eveniment)
        
        Eveniment.scade_id_evenimente(1)
        
        self.__repository.modificare_eveniment(index, eveniment)
        
    def ordonare_dupa_descriere(self):
        """
        Functie care ordoneaza lista de evenimente dupa descriere
        """
        lista_de_ordonat = self.__repository.get_lista_evenimente()
        lista = shake_sort(lista_de_ordonat, key = lambda x: x.get_descriere())
        return lista

    def ordonare_dupa_data(self):
        """
        Functie care ordoneaza lista de evenimente dupa data
        """
        lista_de_ordonat = self.__repository.get_lista_evenimente()
    
        def key(eveniment):
            zi = eveniment.get_zi_eveniment()
            luna = eveniment.get_luna_eveniment()
            an = eveniment.get_an_eveniment()
            data = str(an) + "."
            if int(luna) < 10:
                data += "0"
            data += str(luna) + "."
            if int(zi) < 10:
                data += "0" 
            data += str(zi)
        
            return data
        
        lista = selection_sort_doua_criterii(lista_de_ordonat, key, key2 = lambda x: x.get_descriere())
        
        return lista
  
    def adaugare_aleator(self, numar_evenimente):
        """
        Functie care adauga un nou eveniment
        numar_evenimente - numarul de evenimente care trebuie adaugate
        """
        for i in range(int(numar_evenimente)):
        
            lista_vocale = "aeiouAEIOU"
            lista_vocale = list(lista_vocale)
            lista_consoane = "bcdfghjlmnprstvzBCDFGHJLMNPRSTVZ"
            lista_consoane = list(lista_consoane)
            litere = [lista_vocale, lista_consoane]
    
            nr_litere = randint(3,15)
           
            se_incepe = randint(0, 1)
            descriere = litere[se_incepe][randint(len(litere[se_incepe]) / 2, len(litere[se_incepe]) - 1)]
            
            for i in range(nr_litere - 1):
                if se_incepe == 0:
                    se_incepe = 1
                else:
                    se_incepe = 0
                descriere += litere[se_incepe][randint(0 , len(litere[se_incepe]) / 2 - 1)]
                  
            t = False
            while t == False:
                zi = randint(1, 31)
                luna = randint(1, 12)
                an = randint(2020, 2030)
                valideaza = ValidareData()
                t = valideaza.exceptie(zi, luna, an)
            
            ora = randint(0, 24)
            minut = randint(0, 60)
            
            eveniment = Eveniment()
            eveniment.set_descriere(descriere)
            eveniment.set_data(zi, luna, an)
            eveniment.set_timp(ora, minut)
    
            self.__repository.adauga_eveniment(eveniment)


def interschimbare(a, b):
    """
    Functie care interschimba 2 elemente
    a, b - valorile care se interchimba
    functia returneaza a, b - valorile interschimbate
    """
    aux = a
    a = b
    b = aux
    return a, b


def test_interschimbare():
    
    """Functie de test"""
    
    assert interschimbare(2, 8) == (8, 2)
    assert interschimbare("mere", "pere") == ("pere", "mere")
    assert interschimbare(123, 0) == (0, 123)
    assert interschimbare(5, 5) == (5, 5)
      
    
    
    
    
    