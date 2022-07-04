'''
Created on Nov 8, 2020

@author: Miruna
'''
class Optiune:
    """
    Clasa pentru fiecare comanda din meniu
    """
    mesaj = "Nu exista date"
    
    def __init__(self):
        self.__nr_optiune = Optiune.mesaj 
        self.__text_optiune = Optiune.mesaj 
        self.__actiune = Optiune.mesaj
        self.__nivel_optiune = Optiune.mesaj
        self.__lista_optiune = Optiune.mesaj
    
    def get_text_optiune(self):
        """
        Getter
        Returneaza textul optiunii alese
        """
        return self.__text_optiune
    
    def get_actiune(self):
        """
        Getter
        Returneaza functia care se acceseaza la apelul comenzii
        """
        return self.__actiune
    
    def get_nivel_optiune(self):
        """
        Getter
        Returneaza comanda de care tine subcomanda, sau 0 daca comanda e din meniul principal 
        """
        return self.__nivel_optiune
    
    def get_lista_optiune(self):
        """
        Getter
        Returneaza lista care este actualizata cand se acceseaza optiunea
        """
        return self.__lista_optiune
    
    def get_comanda(self):
        """
        Getter
        Returneaza numarul optiunii alese
        """
        return self.__nr_optiune
    
    def set_nr_optiune(self, numar_optiune):
        """
        Setter
        Seteaza numarul optiunii alese
        """
        self.__nr_optiune = numar_optiune
    
    def set_text_optiune(self, text):
        """
        Setter
        Seteaza textul optiunii alese
        """
        self.__text_optiune = text
    
    def set_actiune(self, actiune):
        """
        Setter
        Seteaza functia care se acceseaza la apelul comenzii
        """
        self.__actiune = actiune
    
    def set_nivel_optiune(self, nivel):
        """
        Setter
        Seteaza comanda de care tine subcomanda, sau 0 daca comanda e din meniul principal 
        """
        self.__nivel_optiune = nivel
        
    def set_lista_optiune(self, lista):
        """
        Setter
        Seteaza lista care este actualizata cand se acceseaza optiunea
        """
        self.__lista_optiune = lista