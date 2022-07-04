'''
Created on Nov 26, 2020

@author: Miruna
'''
import unittest
from Domain.Persoana import Persoana
from Domain.Eveniment import Eveniment
from Validari.Validare import ValidareEveniment, ValidarePersoana, ValidatorPersoanaException, RepositoryException, ValidatorEvenimentException
from Controller.Service_Persoane import Service_Persoane
from Controller.Service_Evenimente import Service_Evenimente
from Controller.Service_Inscriere import Service_Inscriere
from Repository.Repository_Persoana import RepositoryPersoane
from Repository.Repository_Eveniment import RepositoryEvenimente
from Repository.Repository_Inscrieri import Repository_Inscrieri

class TestServicePersoana(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        validator = ValidarePersoana()
        lista = RepositoryPersoane()
        self.service = Service_Persoane(lista, validator)
        self.service.adaugare_persoana("Cilibia", "Miruna", "Arad", "George Cosbuc", 31)
        self.service.adaugare_persoana("Popa", "Ion", "Bucuresti", "Unirii", 25)
        self.service.adaugare_persoana("Stoica", "Andreea", "Timisoara", "Victoriei", 2)
        self.service.adaugare_persoana("Bucur", "Vasile", "Cluj", "Eminescu", 1)
        
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_adaugare(self):
        
        self.assertRaises(ValidatorPersoanaException, self.service.adaugare_persoana, "Cilibia", "", "2324", "", 22)
        self.assertRaises(ValidatorPersoanaException, self.service.adaugare_persoana, "Cilibia", 351, "Arad", "Cosbuc", 22)
        self.assertRaises(ValidatorPersoanaException, self.service.adaugare_persoana, "Cilibia12", "Miruna", "Arad", "Cosbuc", "")
        Persoana.scade_id_persoane(7)
    
    def test_cautare(self):
        
        self.assertTrue(self.service.cautare_element_ID(1) == 0)
        self.assertRaises(ValueError, self.service.cautare_element_ID, "ebtq")
        
        self.assertTrue(self.service.cautare_persoana_nume("Popa Ion") == 1)
        self.assertRaises(ValueError, self.service.cautare_persoana_nume, "")
        Persoana.scade_id_persoane(4)
        
    def test_modificare(self):
        
        self.service.modificare_persoana(0, "Cilibia", "Maria", "Arad", "Aurel Vlaicu", 106)
        self.assertTrue(self.service.cautare_persoana_nume("Cilibia Maria") == 0)
        
        self.service.modificare_persoana(0, "Popescu", "Maria", "Arad", "Aurel Vlaicu", 106)
        self.assertTrue(self.service.cautare_persoana_nume("Popescu Maria") == 0)
        Persoana.scade_id_persoane(4)
        
    def test_ordonare(self):
        
        lista_ordonata = self.service.ordonare_dupa_nume()
        self.assertTrue(lista_ordonata[1].get_nume_intreg() == "Cilibia Miruna")
        Persoana.scade_id_persoane(4)
        
    def test_stergere(self):
        
        self.service.sterge_persoana(1)
        self.assertRaises(RepositoryException, self.service.cautare_persoana_nume, "Popa Ion")
        self.assertTrue(self.service.cautare_element_ID(3) == 1)
        Persoana.scade_id_persoane(4)
         
class TestServiceEveniment(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        validator = ValidareEveniment()
        lista = RepositoryEvenimente()
        self.service = Service_Evenimente(lista, validator)
        self.service.adaugare_eveniment("Concert", 29, 2, 2020, 20, 30)
        self.service.adaugare_eveniment("Piesa de teatru", 21, 11, 2020, 19, 30)
        self.service.adaugare_eveniment("Film", 10, 5, 2021, 10, 0)
        self.service.adaugare_eveniment("Strangere de fonduri", 31, 12, 2020, 16, 45)
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_adaugare(self):
        
        self.assertRaises(ValidatorEvenimentException, self.service.adaugare_eveniment, "Concert", 29, 2, 2022, 20, 30)
        self.assertRaises(ValidatorEvenimentException, self.service.adaugare_eveniment, "Concert4624", 29, 2, 2020, 20, 30)
        self.assertRaises(ValidatorEvenimentException, self.service.adaugare_eveniment, "Concert", "rrg", 2, "", 20, 30)
        Eveniment.scade_id_evenimente(7)
    
    def test_cautare(self):
        
        self.assertTrue(self.service.cautare_element_ID(1) == 0)
        self.assertRaises(ValueError, self.service.cautare_element_ID, "ebtq")
        
        self.assertTrue(self.service.cautare_eveniment_descriere("Piesa de teatru") == 1)
        self.assertRaises(ValueError, self.service.cautare_eveniment_descriere, "")
        Eveniment.scade_id_evenimente(4)
        
    def test_modificare(self):
        
        self.service.modificare_eveniment(0, "Cinema in aer liber", 21, 11, 2020, 19, 30)
        self.assertTrue(self.service.cautare_eveniment_descriere("Cinema in aer liber") == 0)
        
        self.service.modificare_eveniment(0, "Targ de carte", 28, 1, 2021, 19, 30)
        self.assertTrue(self.service.cautare_eveniment_descriere("Targ de carte") == 0)
        Eveniment.scade_id_evenimente(4)
        
    def test_ordonare(self):
        
        lista_ordonata = self.service.ordonare_dupa_descriere()
        self.assertTrue(lista_ordonata[1].get_descriere() == "Film")
        
        lista_ordonata = self.service.ordonare_dupa_data()
        self.assertTrue(lista_ordonata[0].get_data() == "29.02.2020")
        Eveniment.scade_id_evenimente(4)
        
    def test_stergere(self):
        
        self.service.sterge_eveniment(1)
        self.assertRaises(RepositoryException, self.service.cautare_eveniment_descriere, "Piesa de teatru")
        self.assertTrue(self.service.cautare_element_ID(3) == 1)
        Eveniment.scade_id_evenimente(4)
      
class TestServiceInscriere(unittest.TestCase):
       
    def setUp(self):
        unittest.TestCase.setUp(self)
        persoane = RepositoryPersoane()
        evenimente = RepositoryEvenimente()
        self.service = Service_Inscriere(Repository_Inscrieri(), persoane, evenimente)
        
        eveniment = Eveniment()
        eveniment.set_descriere("Concert")
        evenimente.adauga_eveniment(eveniment)
        eveniment = Eveniment()
        eveniment.set_descriere("Piesa de teatru")
        evenimente.adauga_eveniment(eveniment)
        eveniment = Eveniment()
        evenimente.adauga_eveniment(eveniment)
        eveniment = Eveniment()
        evenimente.adauga_eveniment(eveniment)
        eveniment = Eveniment()
        evenimente.adauga_eveniment(eveniment)
        Eveniment.scade_id_evenimente(5)
        
        persoana = Persoana()
        persoana.set_nume("Stoica")
        persoane.adauga_persoana(persoana)
        persoana = Persoana()
        persoana.set_nume("Bucur")
        persoane.adauga_persoana(persoana)
        Persoana.scade_id_persoane(2)
        
        self.service.inscrie_persoana_eveniment(1, 1)
        self.service.inscrie_persoana_eveniment(1, 2)
        self.service.inscrie_persoana_eveniment(2, 1)
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_inscriere(self):
        
        self.assertRaises(RepositoryException, self.service.inscrie_persoana_eveniment, 1, 1)
        self.assertRaises(RepositoryException, self.service.inscrie_persoana_eveniment, 7, 2)
        self.assertRaises(RepositoryException, self.service.inscrie_persoana_eveniment, 1, 10)
    
    def test_dto_to_object_persoana(self):
        
        self.assertTrue(self.service.dto_to_object_persoana(1).get_nume() == "Stoica")
        self.assertRaises(ValueError, self.service.dto_to_object_persoana, 5)
        self.assertTrue(self.service.dto_to_object_persoana(2).get_nume() == "Bucur")
        self.assertRaises(ValueError, self.service.dto_to_object_persoana, -3)
        
    def test_dto_to_object_eveniment(self):
        
        self.assertTrue(self.service.dto_to_object_eveniment(1).get_descriere() == "Concert")
        self.assertRaises(ValueError, self.service.dto_to_object_eveniment, 10)
        self.assertTrue(self.service.dto_to_object_eveniment(2).get_descriere() == "Piesa de teatru")
        self.assertRaises(ValueError, self.service.dto_to_object_eveniment, -3)
        
    def test_cele_mai_multe_evenimente(self):
        
        self.assertTrue(self.service.cele_mai_multe_evenimente() == (2, [1]))
        self.service.inscrie_persoana_eveniment(2, 2)
        self.assertTrue(self.service.cele_mai_multe_evenimente() == (2, [1, 2]))
        
    def test_evenimente_participari(self):
        
        self.assertTrue(self.service.evenimente_participari() == [[1, 2]])
    
    

    
    
    
    