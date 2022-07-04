'''
Created on Nov 3, 2020

@author: Miruna
'''

from Validari.Validare import ValidareComanda, ValidatorComandaException

from Domain.Persoana import Persoana
from Domain.Eveniment import Eveniment

from Interfata.UI_Optiune import Optiune
from Interfata.UI_Meniu import Meniu
from Interfata.Consola_Persoane import Consola_Persoane
from Interfata.Consola_Evenimente import Consola_Evenimente
from Interfata.Consola_Inscrieri import Consola_Inscriere

def date_initiale(tabel_persoane, tabel_evenimente):
    """
    Introduc date in tabel inainte sa incep programul
    """
    tabel = [["Popescu", "Ion", "Arad", "Revolutiei", "20"], ["Ionescu", "Maria", "Bucuresti", "Vasile Alecsandri", "105"], ["Ardelean", "Alina", "Cluj", "Liviu Rebreanu", "59"], ["Dumitrescu", "Bogdan", "Timisoara", "149", "33"]]
    for el in range(4):
        persoana_noua = Persoana()
        persoana_noua.set_nume(tabel[el][0])
        persoana_noua.set_prenume(tabel[el][1])
        persoana_noua.set_adresa(tabel[el][2], tabel[el][3], tabel[el][4])
        tabel_persoane.adauga_persoana(persoana_noua)
        
    tabel = [["Eveniment", 20, 12, 2020, 19, 0], ["Concert", 11, 3, 2021, 21, 30], ["Strangere de fonduri", 20, 12, 2020, 20, 0], ["Piesa de teatru", 28, 11, 2020, 18, 45] ]
    for el in range(4):
        eveniment_nou = Eveniment()
        eveniment_nou.set_descriere(tabel[el][0])
        eveniment_nou.set_data(tabel[el][1], tabel[el][2], tabel[el][3])
        eveniment_nou.set_timp(tabel[el][4], tabel[el][5])
        tabel_evenimente.adauga_eveniment(eveniment_nou)
                                    

"""Functii intializare meniuri""" 

def initializeaza_comanda_lista_persoane(tabel_persoane, lista_persoane):
    """
    Functie care initializeaza comanda 1 - gestionarea listei de persoane
    Modifica si returneaza lista_persoane - meniul comenzii 1
    """ 
    text = "\n"
    text += "-*-" * 20
    text += "\n1 - Adaugati o persoana"
    text += "\n2 - Modificati datele unei persoane"
    text += "\n3 - Stergeti datele unei persoane"
    text += "\n4 - Afisati lista de persoane ordonate dupa ID"
    text += "\n5 - Afisati persoanele in ordine alfabetica"
    text += "\n6 - Cautati o persoana"
    text += "\n7 - Adaugati o persoana aleatoriu"
    text += "\n0 - Revenire la meniul principal\n"
    text += "-*-" * 20
    text += "\n"
    
    lista_persoane.set_meniu(text)
    
    adaugare_pers = Optiune()
    modificare_pers = Optiune()
    stergere_pers = Optiune()
    afisare_ID_pers = Optiune()
    afisare_nume_pers = Optiune()
    cautare_pers = Optiune()
    
    adaugare_aleator = Optiune()
    
    lista_persoane.set_optiuni([adaugare_pers, modificare_pers, stergere_pers, afisare_ID_pers, afisare_nume_pers, cautare_pers, adaugare_aleator])
    lista_persoane.set_numar_optiuni()
    
    for el in range(0,lista_persoane.get_numar_optiuni()):
        lista_persoane.get_optiuni()[el].set_nr_optiune(el + 1)
        lista_persoane.get_optiuni()[el].set_nivel_optiune(1)
        lista_persoane.get_optiuni()[el].set_lista_optiune(tabel_persoane)
    
    functie = Consola_Persoane(tabel_persoane)    
    
    adaugare_pers.set_actiune(functie.ui_adaugare_persoana)                  
    modificare_pers.set_actiune(functie.ui_modificare_persoana)
    stergere_pers.set_actiune(functie.ui_stergere_persoana)
    afisare_ID_pers.set_actiune(functie.afisare_persoane_dupa_ID)
    afisare_nume_pers.set_actiune(functie.afisare_persoane_dupa_nume)
    cautare_pers.set_actiune(functie.ui_cautare_persoana) 
    
    adaugare_aleator.set_actiune(functie.adaugare_aleator)
      
    return lista_persoane

def initializeaza_comanda_lista_evenimente(tabel_evenimente, lista_evenimente):
    """
    Functie care initializeaza comanda 2 - gestionarea listei de evenimente
    Modifica si returneaza lista_evenimente - meniul comenzii 2
    """
    text = "\n"
    text += "-*-" * 20
    text += "\n1 - Adaugati un eveniment"
    text += "\n2 - Modificati datele unui eveniment"
    text += "\n3 - Stergeti datele unui eveniment"
    text += "\n4 - Afisati lista de evenimente ordonate dupa ID"
    text += "\n5 - Afisati lista de evenimente ordonate dupa data"
    text += "\n6 - Cautati un eveniment"
    text += "\n7 - Adaugati un eveniment aleatoriu"
    text += "\n0 - Revenire la meniul principal\n"
    text += "-*-" * 20
    text += "\n"
    
    lista_evenimente.set_meniu(text)
    
    adaugare_even = Optiune()
    modificare_even = Optiune()
    stergere_even = Optiune()
    afisare_ID_even = Optiune()
    afisare_data_even = Optiune()
    cautare_even = Optiune()
    
    adaugare_aleator = Optiune()
    
    lista_evenimente.set_optiuni([adaugare_even, modificare_even, stergere_even, afisare_ID_even, afisare_data_even, cautare_even, adaugare_aleator])
    lista_evenimente.set_numar_optiuni()
    
    for el in range(0,lista_evenimente.get_numar_optiuni()):
        lista_evenimente.get_optiuni()[el].set_nr_optiune(el + 1)
        lista_evenimente.get_optiuni()[el].set_nivel_optiune(2)
        lista_evenimente.get_optiuni()[el].set_lista_optiune(tabel_evenimente)
        
    functie = Consola_Evenimente(tabel_evenimente)  
        
    adaugare_even.set_actiune(functie.ui_adaugare_eveniment)
    modificare_even.set_actiune(functie.ui_modificare_eveniment)
    stergere_even.set_actiune(functie.ui_stergere_eveniment)
    afisare_ID_even.set_actiune(functie.afisare_evenimente_dupa_ID)
    afisare_data_even.set_actiune(functie.afisare_evenimente_dupa_data)
    cautare_even.set_actiune(functie.ui_cautare_eveniment)
    
    adaugare_aleator.set_actiune(functie.adaugare_aleator)
    
    return lista_evenimente

def initializeaza_comanda_inscriere_persoane(lista_inscrieri, tabel_persoane, tabel_evenimente, inscriere_persoane):
    """
    Functie care initializeaza comanda 3 - inscrieti persoane la evenimente
    Modifica si returneaza inscriere_persoane - meniul comenzii 3
    """
    text = "\n"
    text += "-*-" * 20
    text += "\n1 - Inscrieti o persoana la un eveniment"
    text += "\n2 - Afisati lista de evenimente la care participa o persoana ordonat alfabetic dupa descriere"
    text += "\n3 - Afisati lista de evenimente la care participa o persoana ordonat dupa data"
    text += "\n4 - Afisati persoana/persoanele care participa la cele mai multe evenimente"
    text += "\n5 - Afisati primele 20% evenimente cu cei mai multi participanti, dupa numarul de participanti"
    text += "\n6 - Afisati primele 20% evenimente cu cei mai multi participanti, dupa descriere"
    text += "\n7 - Afisati lista persoanelor care participa la eveniment intr-o anumita zi"
    text += "\n0 - Revenire la meniul principal\n"
    text += "-*-" * 20
    text += "\n"
    
    inscriere_persoane.set_meniu(text)
    
    inscrie_pers = Optiune()
    afis_descriere = Optiune()
    afis_data = Optiune()
    cele_mai_multe_even = Optiune()
    even_dupa_nr = Optiune()
    even_dupa_descriere = Optiune()
    even_zi = Optiune()
    
    inscriere_persoane.set_optiuni([inscrie_pers, afis_descriere, afis_data, cele_mai_multe_even, even_dupa_nr, even_dupa_descriere, even_zi])
    inscriere_persoane.set_numar_optiuni()
    
    for el in range(0, inscriere_persoane.get_numar_optiuni()):
        inscriere_persoane.get_optiuni()[el].set_nr_optiune(el + 1)
        inscriere_persoane.get_optiuni()[el].set_nivel_optiune(3)
        inscriere_persoane.get_optiuni()[el].set_lista_optiune(lista_inscrieri)
        
    functie = Consola_Inscriere(lista_inscrieri, tabel_persoane, tabel_evenimente)  
        
    inscrie_pers.set_actiune(functie.ui_inscrie_persoana_la_eveniment)
    afis_descriere.set_actiune(functie.afisare_dupa_descriere)
    afis_data.set_actiune(functie.afisare_dupa_id)
    cele_mai_multe_even.set_actiune(functie.cele_mai_multe_evenimente)
    even_dupa_nr.set_actiune(functie.primele_evenimente_dupa_numar_participanti)
    even_dupa_descriere.set_actiune(functie.primele_evenimente_dupa_descriere)
    even_zi.set_actiune(functie.evenimente_in_functie_de_data)
    
    return inscriere_persoane
   

   
def initializeaza_comenzile(tabel_persoane, tabel_evenimente, lista_inscrieri):
    
    """
    Functie care initializeaza toate comenzile si meniurile
    """
    meniu_principal = Meniu()
    
    lista_persoane = Meniu()
    lista_evenimente = Meniu()
    inscriere_persoane = Meniu()
    meniu_principal.set_optiuni([lista_persoane, lista_evenimente, inscriere_persoane])
    meniu_principal.set_numar_optiuni()
    
    for el in range(0, meniu_principal.get_numar_optiuni()):
        meniu_principal.get_optiuni()[el].set_comanda_meniu_superior(el + 1)
    
    lista_persoane = initializeaza_comanda_lista_persoane(tabel_persoane, lista_persoane)
    lista_evenimente = initializeaza_comanda_lista_evenimente(tabel_evenimente, lista_evenimente)
    inscriere_persoane = initializeaza_comanda_inscriere_persoane(lista_inscrieri, tabel_persoane, tabel_evenimente, inscriere_persoane)
    return meniu_principal


"""Interfata utilizator""" 

def introducere_comanda(meniu, comanda):
    """
    Functie care citeste comanda data din meniu
    meniu - meniul care se afiseaza
    comanda - comanda care se da
    functia returneaza optiune, comanda - optiunea care a fost aleasa, comanda care a fost aleasa
    """
    print(meniu.get_meniu())    
    comanda = input("\nIntroduceti comanda: ")
    valideaza = ValidareComanda()
    optiune = -1
    try:
        valideaza.exceptie(comanda, meniu.get_numar_optiuni())
        if int(comanda) != 0:
            for el in meniu.get_optiuni():
                        if int(el.get_comanda()) == int(comanda):
                            optiune = el
                            break     
    except ValidatorComandaException as errors:
        print(errors)
        optiune = 0
        comanda = -1
    return optiune, comanda
    
def ui(tabel_persoane, tabel_evenimente, lista_inscrieri):
    """ Interfata utilizator - alegerea comenzilor"""
    
    #date_initiale(tabel_persoane, tabel_evenimente)
    meniu = initializeaza_comenzile(tabel_persoane, tabel_evenimente, lista_inscrieri)
    comanda = 1
    while int(comanda) != 0:
        submeniu, comanda = introducere_comanda(meniu, comanda)
        if submeniu == -1:
            print("Ati parasit programul")
        elif submeniu != 0:
            subcomanda = 1
            optiune, subcomanda = introducere_comanda(submeniu, subcomanda)
            if optiune != -1 and optiune != 0:
                optiune.get_actiune()()

    



