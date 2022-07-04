'''
Created on Nov 26, 2020

@author: Miruna
'''
import unittest
from Domain.Persoana import Persoana
from Domain.Eveniment import Eveniment
from Validari.Validare import RepositoryException
from Repository.Repository_Persoana import RepositoryPersoane
from Repository.Repository_Eveniment import RepositoryEvenimente
from Repository.Repository_Inscrieri import Repository_Inscrieri

class TestRepositoryPersoana(unittest.TestCase):
    
    def setUp(self):
        
        unittest.TestCase.setUp(self)
        self.repository = RepositoryPersoane()
        
        persoana = Persoana()
        persoana.set_adresa("Arad", "George Cosbuc", "31")
        persoana.set_nume("Cilibia")
        persoana.set_prenume("Miruna")
        self.repository.adauga_persoana(persoana)
        persoana = Persoana()
        persoana.set_adresa("Timisoara", "Victoriei", 2)
        persoana.set_nume("Stoica")
        persoana.set_prenume("Andreea")
        self.repository.adauga_persoana(persoana)
        Persoana.scade_id_persoane(2)
        
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_adaugare(self):
        
        self.assertTrue(self.repository.get_numar_persoane() == 2)
        persoana = Persoana()
        self.repository.adauga_persoana(persoana)
        self.assertTrue(self.repository.get_numar_persoane() == 3)
        Persoana.scade_id_persoane(1)
    
    def test_cautare(self):
        
        self.assertTrue(self.repository.cautare_element_ID(1) == 0)
        self.assertRaises(RepositoryException, self.repository.cautare_element_ID, 5)
        
        self.assertTrue(self.repository.cautare_persoana_nume("Stoica Andreea") == 1)
        self.assertRaises(RepositoryException, self.repository.cautare_persoana_nume, "Pop Alexandru")
        
    def test_modificare(self):
        
        persoana = Persoana()
        persoana.set_adresa("Oradea", "Victoriei", 2)
        persoana.set_nume("Stoica")
        persoana.set_prenume("Andreea-Maria")
        self.repository.modificare_persoana(1, persoana)
        self.assertTrue(self.repository.get_lista_persoane()[1].get_nume_intreg() == "Stoica Andreea-Maria")
        self.assertTrue(self.repository.get_lista_persoane()[1].get_localitate() == "Oradea")
        Persoana.scade_id_persoane(1)
        
    def test_lista(self):
        
        self.assertTrue(self.repository.get_numar_persoane() == 2)
        self.assertTrue(self.repository.get_lista_persoane()[1].get_id() == 2)
         
    def test_stergere(self):
        
        self.repository.sterge_persoana(self.repository.get_lista_persoane()[1])
        self.assertRaises(RepositoryException, self.repository.cautare_persoana_nume, "Stoica Andreea")
        self.assertTrue(self.repository.get_numar_persoane() == 1)   
          
class TestRepositoryEveniment(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        self.repository = RepositoryEvenimente()
        eveniment = Eveniment()
        eveniment.set_descriere("Concert")
        eveniment.set_data(29, 2, 2020)
        eveniment.set_timp(20,30)
        self.repository.adauga_eveniment(eveniment)
        eveniment = Eveniment()
        eveniment.set_descriere("Piesa de teatru")
        eveniment.set_data(21, 11, 2020)
        eveniment.set_timp(19, 30)
        self.repository.adauga_eveniment(eveniment)
        Eveniment.scade_id_evenimente(2)
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_adaugare(self):
        
        self.assertTrue(self.repository.get_numar_evenimente() == 2)
        eveniment = Eveniment()
        self.repository.adauga_eveniment(eveniment)
        self.assertTrue(self.repository.get_numar_evenimente() == 3)
        Eveniment.scade_id_evenimente(1)
    
    def test_cautare(self):
        
        self.assertTrue(self.repository.cautare_element_ID(1) == 0)
        self.assertRaises(RepositoryException, self.repository.cautare_element_ID, 5)
        
        self.assertTrue(self.repository.cautare_eveniment_descriere("Piesa de teatru") == 1)
        self.assertRaises(RepositoryException, self.repository.cautare_eveniment_descriere, "Seara de film")
        
    def test_modificare(self):
        
        eveniment = Eveniment()
        eveniment.set_descriere("Seara de film")
        eveniment.set_data(30, 11, 2020)
        eveniment.set_timp(22,30)
        
        self.repository.modificare_eveniment(0, eveniment)
        self.assertTrue(self.repository.get_lista_evenimente()[0].get_descriere() == "Seara de film")
        self.assertTrue(self.repository.get_lista_evenimente()[0].get_data() == "30.11.2020")
        
        Eveniment.scade_id_evenimente(1)
        
    def test_lista(self):
        
        self.assertTrue(self.repository.get_numar_evenimente() == 2)
        self.assertTrue(self.repository.get_lista_evenimente()[1].get_id() == 2)
        
    def test_stergere(self):
        
        self.repository.sterge_eveniment(self.repository.get_lista_evenimente()[1])
        self.assertRaises(RepositoryException, self.repository.cautare_eveniment_descriere, "Piesa de teatru")
        self.assertTrue(self.repository.get_numar_evenimente() == 1)  
      
class TestRepositoryInscriere(unittest.TestCase):
       
    def setUp(self):
        unittest.TestCase.setUp(self)
        self.repository = Repository_Inscrieri()
        self.repository.inscrie_persoana_la_eveniment(1, 5)
        self.repository.inscrie_persoana_la_eveniment(2, 5)
        self.repository.inscrie_persoana_la_eveniment(1, 3)
        self.repository.inscrie_persoana_la_eveniment(3, 3)
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_inscriere(self):
        
        self.assertTrue(self.repository.get_lista_inscrieri()[1].get_id_persoana() == 2)
        self.assertTrue(self.repository.get_lista_inscrieri()[0].get_id_persoana() == 1)
        self.assertTrue(self.repository.get_lista_inscrieri()[2].get_id_eveniment() == 3)
        
        self.assertRaises(RepositoryException, self.repository.inscrie_persoana_la_eveniment, 1, 5)
        self.assertRaises(RepositoryException, self.repository.inscrie_persoana_la_eveniment, 2, 5)
    
    def test_nr_evenimente_la_care_e_inscris(self):
        
        self.assertTrue(self.repository.get_nr_evenimente_la_care_e_inscris(1) == 2)
        self.assertTrue(self.repository.get_nr_evenimente_la_care_e_inscris(2) == 1)
        self.assertTrue(self.repository.get_nr_evenimente_la_care_e_inscris(3) == 1)
        
    def test_nr_persoane_inscrise(self):
        
        self.assertTrue(self.repository.get_nr_persoane_inscrise(3) == 2)
        self.assertTrue(self.repository.get_nr_persoane_inscrise(5) == 2)
        
    def test_lista_evenimente_la_care_e_inscris(self):
        
        self.assertTrue(self.repository.get_lista_evenimente_la_care_e_inscris(1) == [5, 3])
        self.assertTrue(self.repository.get_lista_evenimente_la_care_e_inscris(2) == [5])
        self.assertTrue(self.repository.get_lista_evenimente_la_care_e_inscris(3) == [3])
    
    