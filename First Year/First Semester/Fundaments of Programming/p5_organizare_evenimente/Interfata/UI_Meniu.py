'''
Created on Nov 8, 2020

@author: Miruna
'''
class Meniu:
    
    """
    Clasa care contine toate instructiunile din meniu
    """
    meniu_principal = "\n"
    meniu_principal += "-*-" * 20
    meniu_principal += "\nMeniu principal"
    meniu_principal += "\n1 - Gestionati lista de persoane"
    meniu_principal += "\n2 - Gestionati lista de evenimente"
    meniu_principal += "\n3 - Inscrieri si rapoarte legate de inscrieri"
    meniu_principal += "\n0 - Iesiti din program\n"
    meniu_principal += "-*-" * 20
    meniu_principal += "\n"
    
    def __init__(self):
        """
        Se initializeaza meniul
        """ 
        self.__text_meniu = Meniu.meniu_principal
        self.__optiuni = "Nu ati ales comanda"
        self.__numar_optiuni = 0
        self.__comanda_meniu_superior = 0
     
    def get_meniu(self):
        
        """
        Getter
        Returneaza meniul care se afiseaza
        """
        return self.__text_meniu
    
    def get_optiuni(self):
       
        """
        Getter
        Returneaza comenzile din meniu
        """
        return self.__optiuni
    
    def get_numar_optiuni(self):
        """
        Getter
        Returneaza numarul de optiuni pe care il are meniul
        """
        return self.__numar_optiuni 
    
    def get_comanda_meniu_superior(self):
        """
        Getter
        Returneaza numarul comenzii care se acceseaza pentru a se ajnge la acest meniu; 0 in cazul meniului principal
        """
        return self.__comanda_meniu_superior
    
    def get_comanda(self):
        """
        Getter
        Returneaza numarul comenzii care se acceseaza pentru a se ajnge la acest meniu; 0 in cazul meniului principal
        """
        return self.__comanda_meniu_superior
        
    def set_meniu(self, meniu):
        
        """
        Setter 
        Seteaza textul meniului
        """
        self.__text_meniu = meniu
    
    def set_optiuni(self, lista):
        
        """
        Setter 
        Seteaza comenzile meniului
        """
        self.__optiuni = lista
    
    def set_comanda_meniu_superior(self, comanda_meniu_superior):
        
        """
        Getter
        Seteaza numarul comenzii care se acceseaza pentru a se ajnge la acest meniu; 0 in cazul meniului principal
        """
        self.__comanda_meniu_superior = comanda_meniu_superior
        
    def set_numar_optiuni(self):
        """
        Setter
        Seteaza numarul de optiuni pe care il are meniul
        """
        self.__numar_optiuni = len(self.get_optiuni())
        