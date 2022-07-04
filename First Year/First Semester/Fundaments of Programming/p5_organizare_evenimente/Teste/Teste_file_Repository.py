'''
Created on Nov 26, 2020

@author: Miruna
'''
import unittest
from Domain.Persoana import Persoana
from Domain.Eveniment import Eveniment
from Repository.File_Repository_Persoana import FileRepositoryPersoane
from Repository.File_Repository_Eveniment import FileRepositoryEveniment
from Repository.File_Repository_Inscrieri import FileRepositoryInscrieri

class TestRepositoryPersoana(unittest.TestCase):
    
    def setUp(self):
        
        unittest.TestCase.setUp(self)
        open('test.txt', 'w').close()
        self.repository = FileRepositoryPersoane("test.txt")
        persoana = Persoana()
        persoana.set_nume("Cilibia")
        persoana.set_prenume("Miruna")
        persoana.set_adresa("Arad", "George Cosbuc", "31")
        self.repository.adauga_persoana(persoana)
        Persoana.scade_id_persoane(1)
        
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)  
        
    def test_load(self):
        
        file = open('test_load.txt', 'w')
        file.write("1;Cilibia;Miruna;Arad;Cosbuc;31")
        file.close()
        repo = FileRepositoryPersoane("test_load.txt") 
        self.assertTrue(repo.get_numar_persoane() == 1)
        self.assertTrue(repo.cautare_persoana_nume("Cilibia Miruna") == 0)
       
    def test_adaugare(self):
        
        file = open("test.txt", 'r')
        line = file.read().strip()
        date_persoana = line.split(";")
        
        self.assertTrue(date_persoana[1].strip() == "Cilibia")
        self.assertTrue(date_persoana[2].strip() == "Miruna")
        self.assertTrue(date_persoana[4].strip() == "George Cosbuc")
        
        file.close()
    
    def test_modificare(self):
        
        persoana = Persoana()
        persoana.set_adresa("Oradea", "Victoriei", 2)
        persoana.set_nume("Stoica")
        persoana.set_prenume("Andreea-Maria")
        self.repository.modificare_persoana(0, persoana)
        Persoana.scade_id_persoane(1)
        
        file = open("test.txt", 'r')
        line = file.read().strip()
        date_persoana = line.split(";")
        
        self.assertTrue(date_persoana[1].strip() == "Stoica")
        self.assertTrue(date_persoana[2].strip() == "Andreea-Maria")
        self.assertTrue(date_persoana[4].strip() == "Victoriei")
        
        file.close()
         
    def test_stergere(self):
        
        self.repository.sterge_persoana(self.repository.get_lista_persoane()[0])
        file = open("test.txt", 'r')
        line = file.read().strip()
        self.assertTrue(line == "")
        file.close()
          
class TestRepositoryEveniment(unittest.TestCase):
    
    def setUp(self):
        unittest.TestCase.setUp(self)
        open('test.txt', 'w').close()
        self.repository = FileRepositoryEveniment('test.txt')
        eveniment = Eveniment()
        eveniment.set_descriere("Concert")
        eveniment.set_data(29, 2, 2020)
        eveniment.set_timp(20,30)
        self.repository.adauga_eveniment(eveniment)
        Eveniment.scade_id_evenimente(1)
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_adaugare(self):
        
        file = open("test.txt", 'r')
        line = file.read().strip()
        date_eveniment = line.split(";")
        
        self.assertTrue(date_eveniment[1].strip() == "Concert")
        self.assertTrue(date_eveniment[2].strip() == "29")
        self.assertTrue(date_eveniment[4].strip() == "2020")
        
        file.close()
    
    def test_load(self):
        
        file = open('test_load.txt', 'w')
        file.write("1;Eveniment;15;10;2021;20;30")
        file.close()
        repo = FileRepositoryEveniment("test_load.txt") 
        self.assertTrue(repo.get_numar_evenimente() == 1)
        self.assertTrue(repo.cautare_eveniment_descriere("Eveniment") == 0)
    
    def test_modificare(self):
        
        eveniment = Eveniment()
        eveniment.set_descriere("Seara de film")
        eveniment.set_data(30, 11, 2020)
        eveniment.set_timp(22,30)
        self.repository.modificare_eveniment(0, eveniment)
        
        file = open("test.txt", 'r')
        line = file.read().strip()
        date_eveniment = line.split(";")
        
        self.assertTrue(date_eveniment[1].strip() == "Seara de film")
        self.assertTrue(date_eveniment[2].strip() == "30")
        self.assertTrue(date_eveniment[5].strip() == "22")

        file.close()
        
        Eveniment.scade_id_evenimente(1)
        
    def test_stergere(self):
        
        self.repository.sterge_eveniment(self.repository.get_lista_evenimente()[0])
        file = open("test.txt", 'r')
        line = file.read().strip()
        self.assertTrue(line == "")
        file.close()
      
class TestRepositoryInscriere(unittest.TestCase):
       
    def setUp(self):
        unittest.TestCase.setUp(self)
        open('test.txt', 'w').close()
        self.repository = FileRepositoryInscrieri('test.txt')
        self.repository.inscrie_persoana_la_eveniment(1, 1)
          
    def tearDown(self):
        unittest.TestCase.tearDown(self)   
       
    def test_inscriere(self):
        
        file = open("test.txt", 'r')
        line = file.read().strip()
        date_inscriere = line.split(";")
        
        self.assertTrue(date_inscriere[0].strip() == "1")
        self.assertTrue(date_inscriere[1].strip() == "1")
        
        file.close()
    
    def test_load(self):
        
        file = open('test_load.txt', 'w')
        file.write("1;4")
        file.close()
        repo = FileRepositoryInscrieri("test_load.txt") 
        self.assertTrue(repo.get_nr_evenimente_la_care_e_inscris(1) == 1)
        self.assertTrue(repo.get_nr_persoane_inscrise(4) == 1)
    