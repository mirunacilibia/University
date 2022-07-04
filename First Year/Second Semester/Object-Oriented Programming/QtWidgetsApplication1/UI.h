//
// Created by Miruna on 3/23/2021.
//

#ifndef LAB6_7_UI_H
#define LAB6_7_UI_H

#include <utility>

#include "Service.h"

class UI{

private:

    Service service;

public:

    /*Constructorul
     * input:   - un service
     * output:  - se creeaza un service*/
    explicit UI(const Service& service) : service(service) {
    };


    /*Functie care afiseaza meniul
     * input:   -
     * output:  - se afiseaza meniul
     * */
    static void print_menu();


    /*Functie care afiseaza ofertele
     * input:   - vector care contine oferte
     * output:  - se afiseaza toate ofertele stocate
     * */
    static void print_oferte(const vector<Oferta>&);


    /*Functie care adauga o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca adaugarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void add_oferta();


    /*Functie care modifica o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca modificarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void modify_oferta();


    /*Functie care sterge o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca stergerea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * prinde exceptia daca oferta nu exista
     * */
    void delete_oferta();


    /*Functie care cauta o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca cautarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void search_oferta();


    /*Functie care filtreaza ofertele
     * input:   - se citesc datele
     * output:  - se afiseaza lista de oferte filtrata
     * */
    void filter_oferte();


    /*Functie care sorteaza ofertele
     * input:   - se citesc datele
     * output:  - se afiseaza lista de oferte sortata
     * */
    void sort_oferte();


    /*Functie care acceseaza comanda dorita
     * input:   - command - nr intreg, comanda dorita
     * output:  - se acceseaza comanda dorita
     * prinde exceptia daca comanda nu a fost introdusa corect
     * */
    void choose_command(int);


    /*Functie care ruleaza programul
     * input:   - se citeste comanda dorita
     * output:  -
     * */
    void run();

    //Adauga oferte la inceputul programului
    void add_random();

    /*Functie care acceseaza comenzile pentru wishlist
     * input:   - vector wishlist
     * output:  -
     * */
    void wishlist_menu();

    /*Functie care afiseaza meniul pentru wishlist
     * input:   -
     * output:  - se afiseaza meniul
     * */
    static void print_wishlist_menu();

    /*Functie care adauga o oferta in wishlist
     * input:   - vector wishlist
     * output:  - se afiseaza daca adaugarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void add_wishlist();

    /*Functie care sterge wishlist
     * input:   - vector wishlist
     * output:  - se afiseaza daca stergerea a fost facuta cu succes sau nu
     * */
    void delete_wishlist();

    /*Functie care adauga aleator ofertaein wishlist
     * input:   - vector wishlist
     * output:  - se afiseaza daca adaugarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void generate_wishlist();

    /*Functie care citeste numele fisierului HTML pentru export
     * input:   -
     * output:  - se creeaza fisierul
     * */
    void export_wishlist();

    /*Functie care afiseaza raportul
     * input:   -
     * output:  - se afiseaza raportul pentru destinatii
     * */
    void raport_oferta();

    void undo();
};

#endif //LAB6_7_UI_H
