'''
Created on Nov 10, 2020

@author: Miruna
'''

class Persoana:
    
    """
    Clasa care defineste o persoana
    Date: 
        Nume - string
        Prenume - string
        ID - numar intreg, unic
        Adresa - string
        Evenimente - evenimentele la care e inscrisa persoana
    """
    
    id_persoane = 1
    mesaj = "Nu exista date"
    
    def __init__(self):
        
        """
        Intializeaza datele unei persoane
        """
        self.__nume = Persoana.mesaj
        self.__prenume = Persoana.mesaj
        self.__id = Persoana.id_persoane
        self.__adresa = Persoana.mesaj 
        self.__localitate = Persoana.mesaj
        self.__strada = Persoana.mesaj
        self.__numar = Persoana.mesaj
        Persoana.id_persoane += 1   
    
    def get_nume(self):
        """
        Getter
        Returneaza numele persoanei
        """
        return self.__nume
    
    def get_prenume(self):
        """
        Getter
        Returneaza prenumele persoanei
        """
        return self.__prenume
    
    def get_nume_intreg(self):
        
        """
        Getter
        Returneaza numele intreg al persoanei
        """
        try:
            if self.get_nume() == Persoana.mesaj or self.get_prenume() == Persoana.mesaj:
                raise ValueError
            nume_intreg = self.get_nume() + " " + self.get_prenume()
        except ValueError:
            nume_intreg = Persoana.mesaj
        return nume_intreg
    
    def get_id(self):
        
        """
        Getter
        Returneaza ID-ul persoanei
        """
        return self.__id
    
    def get_adresa(self):
        
        """
        Getter
        Returneaza adresa persoanei
        """
        return self.__adresa
    
    def set_nume(self, nume):
        
        """
        Setter
        Seteaza numele persoanei
        """
        self.__nume = nume
           
    def set_prenume(self, prenume):

        """
        Setter
        Seteaza prenumele persoanei
        """
        self.__prenume = prenume
        
    
    def set_adresa(self, localitate, strada, numar):
        
        """
        Setter
        Seteaza adresa persoanei
        """
        if localitate != Persoana.mesaj and strada != Persoana.mesaj and numar != Persoana.mesaj: 
            adresa = "Localitatea: " + localitate + "\nStrada: " + strada + "\nNumarul: " + str(numar)
            self.__localitate = localitate
            self.__strada = strada
            self.__numar = numar
        else:
            adresa = Persoana.mesaj
        self.__adresa = adresa
        
    def set_id(self, id):
        self.__id = id
    
    def get_localitate(self):
        return self.__localitate
    
    def get_strada(self):
        return self.__strada
    
    def get_numar(self):
        return self.__numar
      
    @staticmethod  
    def scade_id_persoane(numar):
        """
        Modifica id_persoane
        """
        Persoana.id_persoane -= numar
    
    def get_id_persoane(self):
        return Persoana.id_persoane
        