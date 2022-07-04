'''
Created on Nov 10, 2020

@author: Miruna
'''

class RepositoryException(Exception):
    pass

class ValidatorPersoanaException(Exception):
    pass

class ValidatorEvenimentException(Exception):
    pass

class ValidatorInscriereException(Exception):
    pass

class ValidatorComandaException(Exception):
    pass

class ValidarePersoana():
    """
    Clasa care valideaza o persoana
    """
    def __init__(self):
        pass
        
    def exceptie(self, persoana):
        errors = []
        valideaza_nume = ValidareNume()
        valideaza_numar = ValidareNumar()
        if valideaza_nume.exceptie(persoana.get_nume()) == False:
            errors.append("Nume invalid")
        if valideaza_nume.exceptie(persoana.get_prenume()) == False:
            errors.append("Prenume invalid")
        if valideaza_nume.exceptie(persoana.get_localitate()) == False:
            errors.append("Localitate invalida")
        if valideaza_nume.exceptie(persoana.get_strada()) == False:
            errors.append("Strada invalida")
        if valideaza_numar.exceptie(persoana.get_numar(), 1, 1000) == False:
            errors.append("Numar invalid")
        if len(errors) > 0:
            raise ValidatorPersoanaException(errors)
       

class ValidareEveniment():
    """
    Clasa care valideaza un eveniment
    """
    def __init__(self):
        pass
        
    def exceptie(self, eveniment):
        errors = []
        valideaza_nume = ValidareNume()
        valideaza_numar = ValidareNumar()
        valideaza_data = ValidareData()
        if valideaza_nume.exceptie(eveniment.get_descriere()) == False:
            errors.append("Descriere invalida")
        if valideaza_numar.exceptie(eveniment.get_ora(), 0, 24) == False:
            errors.append("Ora invalida")
        if valideaza_numar.exceptie(eveniment.get_minut(), 0, 60) == False:
            errors.append("Minut invalid")
        if valideaza_data.exceptie(eveniment.get_zi_eveniment(), eveniment.get_luna_eveniment(), eveniment.get_an_eveniment()) == False:
            errors.append("Data invalida")
        if len(errors) > 0:
            raise ValidatorEvenimentException(errors)
      
class ValidareComanda():
    """
    Clasa care valideaza o comanda
    """  
    def __init__(self):
        pass
    def exceptie(self, comanda, numar_comenzi):
        errors = []
        valideaza = ValidareNumar()
        if valideaza.exceptie(comanda, 0, numar_comenzi) == False:
            errors.append("Comanda invalida")
        if len(errors) > 0:
            raise ValidatorComandaException(errors)

class ValidareNume():
    """
    Clasa care valideaza numele
    """ 
    def __init__(self):
        pass
       
    def exceptie(self, nume):
        if str(nume).replace(" ", "a", -1).replace("-", "a", -1).isalpha() == False:
            return False
        return True
    
class ValidareNumar():
    """
    Clasa care valideaza numerele
    """
    def __init__(self):
        pass
    
    def exceptie(self, numar, minim, maxim):
        if str(numar).isdigit() == False:
            return False
        elif int(numar) < int(minim) or int(numar) > int(maxim):
            return False
        return True
    
class ValidareData():
    """
    Clasa care valideaza datele
    """
    def __init__(self):
        pass
    
    def exceptie(self, zi, luna, an):
        luni_zile = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if str(an).isdigit() == False or str(zi).isdigit() == False or str(luna).isdigit() == False:
            return False
        elif int(an) < 2020 or int(an) > 2050:
            return False
        elif int(luna) < 1 or int(luna) > 12:
            return False
        elif int(zi) < 1 or int(zi) > luni_zile[int(luna)]:
            return False
        elif int(luna) == 2 and int(an) % 4 != 0 and int(zi) == 29:
            return False
        return True
        


def test_exceptii():
    """ Functie de test """
    
    validator = ValidareNumar()
    
    assert validator.exceptie(100, 50, 2000) == True
    assert validator.exceptie("", 30, 40) == False
    
    validator = ValidareNume()
    
    assert validator.exceptie("Cluj-Napoca") == True
    assert validator.exceptie("4irnr") == False
    
    validator = ValidareData()
    
    assert validator.exceptie(29, 2, 2020) == True
    assert validator.exceptie(29, 2, 2021) == False


