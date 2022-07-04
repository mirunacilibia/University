'''
Created on Nov 13, 2020

@author: Miruna
'''
from Validari.Validare import ValidareData
from Sortari import selection_sort, shake_sort

class Service_Inscriere():
    """
    Clasa care gestioneaza inscrierile la evenimente
    """
    def __init__(self, repository_inscrieri, repository_persoane, repository_evenimente):
        self.__repository_inscrieri = repository_inscrieri
        self.__repository_persoane = repository_persoane
        self.__repository_evenimente = repository_evenimente
        
    def inscrie_persoana_eveniment(self, id_persoana, id_eveniment):
        """
        Functie care inscrie persoana la eveniment
        """
        self.__repository_persoane.cautare_element_ID(id_persoana)
        self.__repository_evenimente.cautare_element_ID(id_eveniment)
        self.__repository_inscrieri.inscrie_persoana_la_eveniment(id_persoana, id_eveniment)
       
    def dto_to_object_persoana(self, id_persoana):
        """
        Functie care converteste un id intr-o persoana
        """
        for persoana in self.__repository_persoane.get_lista_persoane():
            if int(id_persoana) == persoana.get_id():
                return persoana
        raise ValueError
    
    def dto_to_object_eveniment(self, id_eveniment):
        """
        Functie care converteste un id intr-un eveniment
        """
        for eveniment in self.__repository_evenimente.get_lista_evenimente():
            if int(id_eveniment) == eveniment.get_id():
                return eveniment
        raise ValueError  
  
    def cele_mai_multe_evenimente(self):
        """
        Functie care returneaza numarul maxim de evenimente la care e inscrisa o persoana, si persoana/ele care sunt incrise la cele mai multe evenimente
        """
        lista_inscrieri = self.__repository_inscrieri.get_lista_inscrieri()
        evenimente_maxim = 0
        persoane = []
        for inscriere in lista_inscrieri:
            id_persoana = inscriere.get_id_persoana()
            try:
                self.dto_to_object_persoana(id_persoana)
                if self.__repository_inscrieri.get_nr_evenimente_la_care_e_inscris(id_persoana) > evenimente_maxim:
                    persoane = [id_persoana]
                    evenimente_maxim = self.__repository_inscrieri.get_nr_evenimente_la_care_e_inscris(id_persoana)
                elif self.__repository_inscrieri.get_nr_evenimente_la_care_e_inscris(id_persoana) == evenimente_maxim:
                    if id_persoana in persoane:
                        pass
                    else:
                        persoane.append(id_persoana)
            except ValueError:
                pass
        return evenimente_maxim, persoane
    
    def evenimente_participari(self):
        """
        Functie care returneaza lista cu primele 20% evenimente cu cei mai multi participanti
        """
        
        lista_participari = {}
        lista_inscrieri = self.__repository_inscrieri.get_lista_inscrieri()
        for inscriere in lista_inscrieri:
            id_eveniment = inscriere.get_id_eveniment()
            if id_eveniment in lista_inscrieri:
                pass
            else:
                try:
                    self.dto_to_object_eveniment(id_eveniment)
                    lista_participari[id_eveniment] = self.__repository_inscrieri.get_nr_persoane_inscrise(id_eveniment)
                except ValueError:
                    pass
                
        lista = []
        for id, nr_participari in lista_participari.items():
            lista.append([id, nr_participari])
            
        lista = shake_sort(lista, key = lambda x: x[1], reversed = True)
            
        procent_evenimente = int((1 / 5) * self.__repository_evenimente.get_numar_evenimente())
        lista = lista[: procent_evenimente]
       
        return lista
    
    def evenimente_in_functie_de_data(self, zi, luna, an):
        """
        """
        valideaza = ValidareData()
        if valideaza.exceptie(zi, luna, an) == False:
            raise ValueError("Data introdusa nu este corecta")
        
        if int(zi) < 10:
            data = "0" + str(zi)
        else:
            data = str(zi)
        data += "."
        if int(luna) < 10:
            data += "0"
        data += str(luna) + "." + str(an)
        
        lista_inscrieri = {}
        for inscriere in self.__repository_inscrieri.get_lista_inscrieri():
            try:
                eveniment = self.dto_to_object_eveniment(inscriere.get_id_eveniment())
                if data == eveniment.get_data():
                    id = inscriere.get_id_persoana()
                    if id in lista_inscrieri:
                        lista_inscrieri[id] += 1
                    else:
                        lista_inscrieri[id] = 1
            except ValueError:
                pass
        
        lista = []
        for id, nr_participari in lista_inscrieri.items():
            lista.append([id, nr_participari])
        for i in range(len(lista) - 1):
            for j in range(i, len(lista)):
                if int(lista[i][1]) < int(lista[j][1]):
                    aux = lista[i]
                    lista[i] = lista[j]
                    lista[j] = aux
        
        persoane_de_afisat = []
        for id in lista:
            try:
                persoana = self.dto_to_object_persoana(id[0])
                persoane_de_afisat.append(persoana)
            except ValueError:
                pass
        
        return persoane_de_afisat

  
  
        
        