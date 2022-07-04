'''
Created on Nov 26, 2020

@author: Miruna
'''
import unittest
from Domain.Persoana import Persoana
from Domain.Eveniment import Eveniment
from Domain.Inscriere import Inscriere

class TestPersoana(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        self.persoana = Persoana()
    
    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    def test_persoana(self):
        
        self.persoana.set_adresa("Arad", "Revolutiei", "102")
        self.persoana.set_nume("Popescu")
        self.persoana.set_prenume("Ana")
        
        self.assertTrue(self.persoana.get_id() == 1)
        self.assertTrue(self.persoana.get_nume() == "Popescu")
        self.assertTrue(self.persoana.get_prenume() == "Ana")
        self.assertTrue(self.persoana.get_nume_intreg() == "Popescu Ana")
        self.assertTrue(self.persoana.get_adresa() == "Localitatea: Arad\nStrada: Revolutiei\nNumarul: 102")
        
        Persoana.scade_id_persoane(1)
        
class TestEveniment(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        self.eveniment = Eveniment()
    
    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    def test_eveniment(self):
        
        self.eveniment.set_descriere("Concert")
        self.eveniment.set_data(29, 2, 2020)
        self.eveniment.set_timp(20,30)
        
        self.assertTrue(self.eveniment.get_id() == 1)
        self.assertTrue(self.eveniment.get_descriere() == "Concert")
        self.assertTrue(self.eveniment.get_zi_eveniment() == 29)
        self.assertTrue(self.eveniment.get_luna_eveniment() == 2)
        self.assertTrue(self.eveniment.get_an_eveniment() == 2020)
        self.assertTrue(self.eveniment.get_data() == "29.02.2020")
        self.assertTrue(self.eveniment.get_timp() == "20:30")
        
        Eveniment.scade_id_evenimente(1)

class TestInscriere(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        self.inscriere = Inscriere(3, 7)
    
    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    def test_inscriere(self):
        
        self.assertTrue(self.inscriere.get_id_persoana() == 3)
        self.assertTrue(self.inscriere.get_id_eveniment() == 7)
