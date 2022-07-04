'''
Created on Nov 10, 2020

@author: Miruna
'''
class Eveniment:
    """
    Clasa care defineste un eveniment
    Date: 
        ID - numar intreg, unic
        Data - zi, luna, an eveniment - nr intregi
        Timp - string
        Descriere - string
    """
    id_evenimente = 1
    mesaj = "Nu exista date"
    
    def __init__(self):
        """
        Intializeaza datele unui eveniment
        """
        self.__zi_eveniment = Eveniment.mesaj
        self.__luna_eveniment = Eveniment.mesaj
        self.__an_eveniment = Eveniment.mesaj
        self.__timp = Eveniment.mesaj
        self.__ora = Eveniment.mesaj
        self.__minut = Eveniment.mesaj
        self.__id = Eveniment.id_evenimente
        self.__descriere = Eveniment.mesaj
        Eveniment.id_evenimente += 1
    
    def get_descriere(self):
        
        """
        Getter
        Returneaza descrierea evenimentului
        """
        return self.__descriere
    
    def get_zi_eveniment(self):
        
        """
        Getter
        Returneaza ziua evenimentului
        """
        return self.__zi_eveniment
    
    def get_luna_eveniment(self):
        
        """
        Getter
        eturneaza luna evenimentului
        """
        return self.__luna_eveniment
    
    def get_an_eveniment(self):
        
        """
        Getter
        Returneaza anul evenimentului
        """
        return self.__an_eveniment
    
    def get_ora(self):
        
        """
        Getter
        Returneaza oral evenimentului
        """
        return self.__ora
    
    def get_minut(self):
        
        """
        Getter
        Returneaza minuul evenimentului
        """
        return self.__minut
    
    def get_data(self):
        
        """
        Setter
        Seteaza data evenimentului
        """
        zi = self.__zi_eveniment
        luna = self.__luna_eveniment
        an = self.__an_eveniment
        
        try:
            if zi == Eveniment.mesaj or zi == Eveniment.mesaj or zi == Eveniment.mesaj:
                raise ValueError
            if int(zi) < 10:
                data = "0" + str(zi)
            else:
                data = str(zi)
            data += "."
            if int(luna) < 10:
                data += "0"
            data += str(luna) + "." + str(an)
        except ValueError:
            data = Eveniment.mesaj
        
        return data
    
    def get_timp(self):
        
        """
        Getter
        Returneaza ora evenimentului
        """
        return self.__timp
    
    def get_id(self):
        
        """
        Getter
        Returneaza ID-ul evenimentului
        """
        return self.__id
    
    def set_descriere(self, descriere):
        
        """
        Setter
        Seteaza descrierea evenimentului
        """
        self.__descriere = descriere

    def set_data(self, zi, luna, an):
        """
        Functie care verifica si valideaza datele pentru data evenimentului
        """
        self.__an_eveniment = an
        self.__luna_eveniment = luna
        self.__zi_eveniment = zi
        
    def set_timp(self, ora, minut):
        """
        Setter
        Seteaza ora evenimentului
        """
        try:
            if ora == Eveniment.mesaj or minut == Eveniment.mesaj:
                raise ValueError    
            if int(ora) < 10:
                timp = "0" + str(ora)
            else:
                timp = str(ora)
            timp += ":"
            if int(minut) < 10:
                timp += "0"
            timp += str(minut)
        except ValueError:
            timp = Eveniment.mesaj
        self.__ora = ora
        self.__minut = minut
        self.__timp = timp
   
    @staticmethod  
    def scade_id_evenimente(numar):
        """
        Modifica id_evenimente
        """
        Eveniment.id_evenimente -= numar