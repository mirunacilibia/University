'''
Created on Nov 19, 2020

@author: Miruna
'''
class Inscriere():
    """
    Clasa pentru inscrierea unei persoane la un eveniment
    """
    def __init__(self, id_persoana, id_eveniment):
        self.__id_persoana = id_persoana
        self.__id_eveniment = id_eveniment
    
    def get_id_persoana(self):
        return self.__id_persoana
    
    def get_id_eveniment(self):
        return self.__id_eveniment
        
