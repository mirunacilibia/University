'''
Created on Nov 13, 2020

@author: Miruna
'''
from Interfata.Consola_Persoane import Consola_Persoane
from Controller.Service_Inscriere import Service_Inscriere
from Controller.Service_Evenimente import Service_Evenimente
from Repository.Repository_Eveniment import RepositoryEvenimente
from Validari.Validare import ValidareEveniment, RepositoryException

class Consola_Inscriere():
    """
    Clasa care contine functiile de ui care se afiseaza cand se deschid anumite comenzi
    """
    def __init__(self, repository_inscrieri, repository_persoane, repository_evenimente):
        self.__repository_inscrieri = repository_inscrieri
        self.__repository_persoane = repository_persoane
        self.__repository_evenimente = repository_evenimente
        
    validator_evenimente = ValidareEveniment()
    
    def ui_inscrie_persoana_la_eveniment(self):
        """
        UI pentru optiunea de inscriere persoana la eveniment
        """
        id_persoana = input("\nIntroduceti id-ul persoanei pe care doriti sa o incrieti la eveniment: ")
        id_eveniment = input("\nIntroduceti id-ul evenimentului la care doriti sa inscrieti persoana: ")
        try:
            inscrie = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
            inscrie.inscrie_persoana_eveniment(id_persoana, id_eveniment)
            print("\nPersoana a fost inscrisa la eveniment")
        except RepositoryException as re:
            print(re)
    
    def afisare_dupa_descriere(self):
        """
        UI pentru functia de afisare dupa descriere
        """
        lista_de_ordonat = self.lista_evenimente()
        ordonare = Service_Evenimente(lista_de_ordonat, Consola_Inscriere.validator_evenimente)
        lista_de_afisat = ordonare.ordonare_dupa_descriere()
        au_fost_afisate = False
        print("\nEvenimente la care este inscris:")
        for el in lista_de_afisat:
            eveniment_de_afisat = el
            print("\nID:", eveniment_de_afisat.get_id(), "\nDescriere:", eveniment_de_afisat.get_descriere(), "\nData:", eveniment_de_afisat.get_data(), "Ora:", eveniment_de_afisat.get_timp())
            au_fost_afisate = True
        if au_fost_afisate == False:
            print("Nu exista evenimente")
    
        
    def afisare_dupa_id(self):
        """
        UI pentru functia de afisare dupa id
        """
        lista_de_ordonat = self.lista_evenimente()
        ordonare = Service_Evenimente(lista_de_ordonat, Consola_Inscriere.validator_evenimente)
        lista_de_afisat = ordonare.ordonare_dupa_data()
        au_fost_afisate = False
        print("\nEvenimente la care este inscris:")
        for el in lista_de_afisat:
            eveniment_de_afisat = el
            print("\nID:", eveniment_de_afisat.get_id(), "\nDescriere:", eveniment_de_afisat.get_descriere(), "\nData:", eveniment_de_afisat.get_data(), "Ora:", eveniment_de_afisat.get_timp())
            au_fost_afisate = True
        if au_fost_afisate == False:
            print("Nu exista evenimente")
            
    def lista_evenimente(self):
        """
        Lista de evenimente la care participa o persoana
        """
        id_persoana = input("\nIntroduceti id-ul persoanei pentru care doriti sa afisati evenimentele: ")
        lista_de_ordonat = self.__repository_inscrieri.get_lista_evenimente_la_care_e_inscris(id_persoana)
        transformare = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
        try:
            persoana = transformare.dto_to_object_persoana(id_persoana)
        except ValueError:
            print("Nu exista id-ul")
        print("\nPersoana:")
        print("\nID:", persoana.get_id(), "\nNume:", persoana.get_nume_intreg())
        lista = RepositoryEvenimente()
        for id in lista_de_ordonat:
            try:
                lista.adauga_eveniment(transformare.dto_to_object_eveniment(id))
            except ValueError:
                pass
        return lista 
    
    def cele_mai_multe_evenimente(self):
        """
        Persoanele care participa la cele mai multe evenimente
        """
        raport = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
        evenimente_maxim, lista_id_persoane = raport.cele_mai_multe_evenimente()
        if lista_id_persoane == []:
            print("\nNu exista persoane care participa la evenimente!\n")
        else:
            print("\nNumarul maxim de evenimente la care participa persoanele este ", evenimente_maxim)
            print("Persoanele sunt:")
            afisare = Consola_Persoane(self.__repository_persoane)
            for id in lista_id_persoane:
                for index, persoana in enumerate(self.__repository_persoane.get_lista_persoane()):
                    if int(persoana.get_id()) == int(id):
                        afisare.afisare_persoana(index)
        
    def primele_evenimente_dupa_numar_participanti(self):
        """
        Evenimentele la care participa la cele mai multe persoane dupa nr de participanti
        """
        raport = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
        lista = raport.evenimente_participari()
        if len(lista) == 0:
            print("\nNu exista destule inscrieri pentru a intocmi acest raport\n")
        else:
            print("Evenimentele cu cei mai multi participanti sunt:")
            for element in lista:
                id = element[0]
                nr_participanti = element[1]
                eveniment = raport.dto_to_object_eveniment(id)
                print("\nID:", eveniment.get_id(), "\nDescriere:", eveniment.get_descriere(), "\nData:", eveniment.get_data(), "Ora:", eveniment.get_timp())
                print("Participanti: ", nr_participanti)
        
    def primele_evenimente_dupa_descriere(self):
        """
        Evenimentele la care participa la cele mai multe persoane dupa descriere
        """
        raport = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
        lista_participari = raport.evenimente_participari()
        lista = RepositoryEvenimente()
        transformare = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
        for element in lista_participari:
            lista.adauga_eveniment(transformare.dto_to_object_eveniment(element[0]))
        ordonare = Service_Evenimente(lista, Consola_Inscriere.validator_evenimente)
        lista_de_afisat = ordonare.ordonare_dupa_descriere()
        if len(lista_de_afisat) == 0:
            print("\nNu exista destule inscrieri pentru a intocmi acest raport\n")
        else:
            au_fost_afisate = False
            print("\nEvenimentele cu cei mai multi participanti sunt:")
            for el in lista_de_afisat:
                eveniment_de_afisat = el
                print("\nID:", eveniment_de_afisat.get_id(), "\nDescriere:", eveniment_de_afisat.get_descriere(), "\nData:", eveniment_de_afisat.get_data(), "Ora:", eveniment_de_afisat.get_timp())
                au_fost_afisate = True
            if au_fost_afisate == False:
                print("Nu exista evenimente")
    
    def evenimente_in_functie_de_data(self):
        """
        Persoanele care participa la evenimente intr-o anumita data
        """    
        print("\nIntroduceti data la care doriti sa verificati inscrierile:")
        zi = input("Zi: ")
        luna = input("Luna: ")
        an = input("An: ")
        
        try:
            raport = Service_Inscriere(self.__repository_inscrieri, self.__repository_persoane, self.__repository_evenimente)
            lista = raport.evenimente_in_functie_de_data(zi, luna, an)
            if len(lista) == 0:
                print("\nNu exista inscrieri in aceasta zi\n")
            else:
                print("\nPersoanele care participa la evenimente in perioada data sunt:")
                for persoana in lista:
                    print("\nID:", persoana.get_id(), "\nNume:", persoana.get_nume_intreg())
        except ValueError as ve:
            print(ve)
        
    
    
    
    
    
        
    
        