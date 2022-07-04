'''
Created on Nov 10, 2020

@author: Miruna
'''

from Validari.Validare import ValidareComanda, ValidareEveniment, ValidatorEvenimentException, ValidatorComandaException, ValidareNumar, RepositoryException
from Controller.Service_Evenimente import Service_Evenimente
from Domain.Eveniment import Eveniment

class Consola_Evenimente():
    """
    Clasa care contine functiile de ui care se afiseaza cand se deschid anumite comenzi
    """
    def __init__(self, repository):
        self.__repository = repository

    validator = ValidareEveniment()
    
    @staticmethod
    def citire_date_eveniment():
        """
        Functie care citeste datele unui eveniment
        Functia returneaza toate datele evenimentului
        """
        descriere = input("Descriere:")
        zi = input("Zi: ")
        luna = input("Luna: ")
        an = input("An: ")
        ora = input("Ora:")
        minut = input("Minutul:")
        return descriere, zi, luna, an, ora, minut

    def ui_adaugare_eveniment(self):
        """
        UI pentru optiunea de adaugare
        """
        tabel_evenimente = self.__repository
        print("\nIntroduceti datele evenimentului:")
        descriere, zi, luna, an, ora, minut = Consola_Evenimente.citire_date_eveniment()
        adaugare = Service_Evenimente(tabel_evenimente, Consola_Evenimente.validator)
        try:
            adaugare.adaugare_eveniment(descriere, zi, luna, an, ora, minut)
            print("Evenimentul a fost adaugat")
        except ValidatorEvenimentException as errors:
            Eveniment.scade_id_evenimente(1)
            print(errors)
            
            
    def afisare_eveniment(self, index):
        """
        Functie care afiseaza un eveniment
        eveniment_de_afisat - evenimentul care se afiseaza
        tabel - tabelul din care sunt preluate datele persoanei
        """
        tabel_evenimente = self.__repository
        if int(index) > int(tabel_evenimente.get_numar_evenimente()):
            print("\nNu exista evenimentul in lista")     
        else:
            eveniment_de_afisat = tabel_evenimente.get_lista_evenimente()[index]
            print("\nID:", eveniment_de_afisat.get_id(), "\nDescriere:", eveniment_de_afisat.get_descriere(), "\nData:", eveniment_de_afisat.get_data(), "Ora:", eveniment_de_afisat.get_timp())             
                 
    def ui_cautare_eveniment(self):
        """
        UI pentru optiunea de cautare a unui eveniment
        """
        tabel_evenimente = self.__repository
        cautare = Service_Evenimente(tabel_evenimente, Consola_Evenimente.validator)
        print("\nCautati evenimentul dupa ID / descriere?\n1 - ID\n2 - Descriere")
        comanda = input("Comanda: ")
        index = -2
        valideaza = ValidareComanda()
        try:
            valideaza.exceptie(comanda, 2)
            if int(comanda) == 1:
                id = input("Introduceti ID-ul: ")
                try:
                    index = cautare.cautare_element_ID(id)
                except ValueError:
                    print("\nDatele introduse nu sunt valide")
                except RepositoryException as re:
                    print(re)
            else:
                nume = input("Introduceti numele: ")
                try:
                    index = cautare.cautare_eveniment_descriere(nume)
                except ValueError:
                    print("\nDatele introduse nu sunt valide")
                except RepositoryException as re:
                    print(re)
        except ValidatorComandaException as errors:
            print(errors)
        if index != -1 and index != -2:
            self.afisare_eveniment(index)
        elif index == -1:
            print("\nNu exista evenimentul in lista")
        return index
    
    def ui_stergere_eveniment(self):
        """
        UI pentru optiunea de stergere a unui eveniment
        """
        tabel_evenimente = self.__repository
        stergere = Service_Evenimente(tabel_evenimente, Consola_Evenimente.validator)
        index = self.ui_cautare_eveniment()
        if index != -1 and index != -2:
            stergere.sterge_eveniment(index)
            print("\nEvenimentul a fost sters\n")
            
    def ui_modificare_eveniment(self):
        """
        UI pentru optiunea de modificare eveniment
        """
        tabel_evenimente = self.__repository
        modificare = Service_Evenimente(tabel_evenimente, Consola_Evenimente.validator)
        index = self.ui_cautare_eveniment()
        if index != -1 and index != -2:
            print("Inlocuiti datele:\n")
            descriere, zi, luna, an, ora, minut = Consola_Evenimente.citire_date_eveniment()
            try:
                modificare.modificare_eveniment(index, descriere, zi, luna, an, ora, minut)
            except ValidatorEvenimentException as errors:
                print(errors)
        
    def afisare_evenimente_dupa_ID(self):
        """
        Functie care afiseaza toate evenimentele ordonate dupa ID
        """
        tabel_evenimente = self.__repository
        au_fost_afisate = False
        for i, el in enumerate (tabel_evenimente.get_lista_evenimente()):
            self.afisare_eveniment(i)
            au_fost_afisate = True
        if au_fost_afisate == False:
            print("Nu exista evenimente")
            
    def afisare_evenimente_dupa_data(self):
        """
        Functie care afiseaza toate evenimentele ordonate dupa ID
        """
        tabel_evenimente = self.__repository
        au_fost_afisate = False
        ordonare = Service_Evenimente(tabel_evenimente, Consola_Evenimente.validator)
        lista_de_afisat = ordonare.ordonare_dupa_data()
        for i, el in enumerate (lista_de_afisat):
            self.afisare_eveniment(i)
            au_fost_afisate = True
        if au_fost_afisate == False:
            print("Nu exista evenimente")
            
            
    def adaugare_aleator(self):
        """
        Functie care adauga aleator un eveniment
        """
        numar_evenimente = input("Cate evenimente doriti sa adaugati?")
        valideaza = ValidareNumar()
        if valideaza.exceptie(numar_evenimente, 1, 100) == True:
            adauga = Service_Evenimente(self.__repository, Consola_Evenimente.validator)
            adauga.adaugare_aleator(numar_evenimente)
        else:
            print("Numarul introdus este invalid")
        