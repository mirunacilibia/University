'''
Created on Nov 10, 2020

@author: Miruna
'''
from Controller.Service_Persoane import Service_Persoane
from Validari.Validare import ValidareComanda, ValidarePersoana, ValidatorPersoanaException, ValidareNumar, ValidatorComandaException, RepositoryException

class Consola_Persoane():
    """
    Clasa care contine functiile de ui care se afiseaza cand se deschid anumite comenzi
    """
    def __init__(self, repository_persoane):
        self.__repository = repository_persoane

    validator = ValidarePersoana()

    @staticmethod
    def citire_date_persoana():
        """
        Functie care citeste datele unei persoane
        Functia returneaza toate datele persoanei
        """
        nume = input("Numele:")
        prenume = input("Prenumele:")
        print("Adresa:")
        localitate = input("Localitatea:")
        strada = input("Strada:")
        numar = input("Numarul:")
        return nume, prenume, localitate, strada, numar

    def ui_adaugare_persoana(self):
        """
        UI pentru optiunea de adaugare
        """
        tabel_persoane = self.__repository
        print("\nIntroduceti datele persoanei:")
        nume, prenume, localitate, strada, numar = Consola_Persoane.citire_date_persoana()
        adaugare = Service_Persoane(tabel_persoane, Consola_Persoane.validator)
        try:
            adaugare.adaugare_persoana(nume, prenume, localitate, strada, numar)
        except ValidatorPersoanaException as errors:
            print(errors)
            
    def afisare_persoana(self, index):
        """
        Functie care afiseaza o persoana
        index - indexul persoanei care se afiseaza
        tabel - tabelul din care sunt preluate datele persoanei
        """
        tabel_persoane = self.__repository
        if int(index) > int(tabel_persoane.get_numar_persoane()):
            print("\nNu exista persoana in lista")     
        else:
            persoana_de_afisat = tabel_persoane.get_lista_persoane()[index]
            print("\nID:", persoana_de_afisat.get_id(), "\nNume:", persoana_de_afisat.get_nume_intreg())
            print(persoana_de_afisat.get_adresa())
    
    def ui_cautare_persoana(self):
        """
        UI pentru optiunea de cautare a unei persoane
        """
        tabel_persoane = self.__repository
        cautare = Service_Persoane(tabel_persoane, Consola_Persoane.validator)
        print("\nCautati persoana dupa ID / nume?\n1 - ID\n2 - Nume")
        index = -2
        comanda = input("Comanda: ")
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
                    index = cautare.cautare_persoana_nume(nume)
                except ValueError:
                    print("\nDatele introduse nu sunt valide")
                except RepositoryException as re:
                    print(re)
        except ValidatorComandaException:
            print("\nDatele introduse nu sunt valide")
        if index != -1 and index != -2:
            self.afisare_persoana(index)
        elif index == -1:
            print("\nNu exista persoana in lista")
        return index
    
    def ui_stergere_persoana(self):
        """
        UI pentru optiunea de stergere a unei persoane
        """
        tabel_persoane = self.__repository
        stergere = Service_Persoane(tabel_persoane, Consola_Persoane.validator)
        index = self.ui_cautare_persoana()
        if index != -1 and index != -2:
            stergere.sterge_persoana(index)
            print("\nPersoana a fost stearsa\n")
    
    def ui_modificare_persoana(self):
        """
        UI pentru optiunea de modificare persoana
        """
        tabel_persoane = self.__repository
        modificare = Service_Persoane(tabel_persoane, Consola_Persoane.validator)
        index = self.ui_cautare_persoana()
        if index != -1 and index != -2:
            print("Inlocuiti datele:\n")
            nume, prenume, localitate, strada, numar = Consola_Persoane.citire_date_persoana()
            try:
                modificare.modificare_persoana(index, nume, prenume, localitate, strada, numar)
            except ValidatorPersoanaException as errors:
                print(errors)
            
    def afisare_persoane_dupa_ID(self):
        """
        Functie care afiseaza toate persoanele inscrise ordonate dupa ID
        """
        tabel_persoane = self.__repository
        au_fost_afisate = False
        for i, el in enumerate (tabel_persoane.get_lista_persoane()):
            self.afisare_persoana(i)
            au_fost_afisate = True
        if au_fost_afisate == False:
            print("Nu exista evenimente")
                            
    def afisare_persoane_dupa_nume(self):
        """
        Functie care afiseaza toate persoanele inscrise ordonate dupa numele de familie
        """
        tabel_persoane = self.__repository
        au_fost_afisate = False
        ordonare = Service_Persoane(tabel_persoane, Consola_Persoane.validator)
        lista_ordonata = ordonare.ordonare_dupa_nume()
        for i, el in enumerate (lista_ordonata):
            au_fost_afisate = True
            print("\nID:", el.get_id(), "\nNume:", el.get_nume_intreg())   
        if au_fost_afisate == False:
            print("Nu exista evenimente")
            
            
    def adaugare_aleator(self):
        """
        Functie care adauga aleator o persoana 
        """
        numar_persoane = input("Cate persoane doriti sa adaugati?")
        valideaza = ValidareNumar()
        try:
            valideaza.exceptie(numar_persoane, 1, 100)
            adauga = Service_Persoane(self.__repository, Consola_Persoane.validator)
            adauga.adaugare_aleator(numar_persoane)
        except ValueError:
            print("Numarul dat nu este valid")
            
        
        
    
    
    