//
// Created by Miruna on 3/23/2021.
//

#ifndef LAB6_7_SERVICE_H
#define LAB6_7_SERVICE_H

#include <map>
#include "Repository.h"
#include "Undo.h"
#include "FileRepository.h"
#include "Wishlist.h"
#include <memory>
//using std::unique_ptr;

typedef bool(Function)(const Oferta&, const string&);

typedef bool(Sort_function)(const Oferta&, const Oferta&);

class Service{

private:

    Repository& repository;
    //vector<string> export_list;
    //vector<unique_ptr<ActiuneUndo>> undo_actions;
    Wishlist wishlist;
    vector<ActiuneUndo*> undo_actions;

public:

    /*Constructorul
     * input:   - repository
     * output:  - se creeaza un service*/
    explicit Service(Repository &repository);

    /*Functie care adauga o oferta
     * input:   - denumire: string, numele ofertei
     *          - destinatie: string, destinatia ofertei
     *          - tip: string, tipul ofertei
     *          - pret: string, pretul ofertei
     * output:  - se adauga un nou obiect in memorie
     * throw OfertaException daca datele nu sunt corecte
     * */
    void add_oferta(const string&, const string&, const string&, const string&);

    /*Functie care cauta o oferta
     * input:   - denumire: string, numele ofertei
     * output:  - 1 - exista oferta
     *            0 - nu exista
     * throw OfertaException daca datele nu sunt corecte
     * */
     Oferta search_oferta(const string&) ;

    /*Functie care modifica o oferta
     * input:   - denumire: string, numele ofertei
     *          - destinatie: string, destinatia ofertei
     *          - tip: string, tipul ofertei
     *          - pret: string, pretul ofertei
     *          - denumire_veche: string, denumirea initiala a ofertei
     * output:  - se modifica oferta in memorie
     * throw OfertaException daca datele nu sunt corecte
     * */
    void modify_oferta(const string&, const string&, const string&, const string&, const string&);

    /*Functie care sterge o oferta
    * input:   - denumire: string, numele ofertei
    * output:  - se sterge oferta din memorie
    * throw OfertaException daca datele nu sunt corecte
    * */
    void delete_oferta(const string&);

    /*Functie care filtreaza ofertele
    * input:    - function: functia dupa care se filtreaza
    *           - conditie: string, conditia dupa care se filtreaza
    * output:   - o lista cu ofertele filtrate
    * throw OfertaException daca datele nu sunt corecte
    * */
    vector<Oferta> filter_oferta(Function function, const string& ) const;

    /*Functie care sorteaza ofertele
    * input:    - function: functia dupa care se sorteaza
    * output:   - o lista cu ofertele sortate
    * */
    vector<Oferta> sort_oferta(Sort_function function) const;

    /*Functie care returneaza toate ofertele din memorie
     * input:   -
     * output:  - un vector care contine toate ofertele*/
    const vector<Oferta>& get_all() const noexcept;

    /*Destructorul implicit*/
    ~Service();

    /*Functie care adauga o oferta in wishlist
     * input:   - denumire: string, numele ofertei
     *          - vector wishlist
     * output:  - true - oferta exista
     *          - false - oferta nu exista
     * throw OfertaException daca datele nu sunt corecte
     * */
    bool add_wishlist(const string &denumire);

    /*Functie care sterge tot wishlist-ul
     * input:   - vector wishlist
     * output:  - un wishlist gol
     * */
    void delete_wishlist();

    /*Functie care adauga aleator oferte in wishlist
     * input:   - numar - nr intreg, numarul de oferte care se adauga
     *          - vector wishlist
     * output:  - true - s-au adaugat "numar" oferte
     *          - false - wishlist-ul contine deja toate ofertele posibile
     * */
    bool generate_wishlist(int numar);

    /*Functie care returneaza wishlist-ul
     * input:   -
     * output:  - un vector care contine wishlist-ul*/
    const vector<Oferta> &get_wishlist();

    /*Functie care exporta cosul intr-un fisier HTML
     * input:   - file - string, numele fisierului
     * output:  - se creeaza un fisier care contine cosul
     * */
    void export_wishlist(const string&, const string&);

    void add_observer(Observer* obs){
        wishlist.add_observer(obs);
    }

    void remove_observers(Observer* obs){
        wishlist.remove_observers(obs);
    }

    /*Functie care realizeaza raportul
     * input:   -
     * output:  - un dictionar care contine frecventa de aparitie a destinatiilor*/
    std::map<string, int> raport_oferta() const;

    void undo();
};

#endif //LAB6_7_SERVICE_H
