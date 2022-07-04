//
// Created by Miruna on 4/16/2021.
//

#ifndef LAB6_7_WISHLIST_H
#define LAB6_7_WISHLIST_H
#include <algorithm>
#include "Validators.h"
#include "Observer.h"
#include <fstream>
#include <vector>
using namespace std;

class Wishlist: public Observable{
private:
    vector<Oferta> oferte;
    vector<string> export_list;
public:

    Wishlist() = default;

    /*Functie care adauga o oferta
     * input:   - un obiect Oferta
     * output:  - se adauga un nou obiect in wishlist
     * throw RepoException daca mai exista o oferta cu aceasi descriere
     * */
    void add_oferta(const Oferta& oferta);

    /*Functie care sterge tot cosul
    * input:   -
    * output:  - se sterge cosul din memorie
    * */
    void clear_wishlist();

    /*Functie care actualizeaza wishlist-ul atunci cand se actrualizeaza lista de oferte
     * input:   - denumire_veche - string
     *          - oferta - un obiect Oferta
     * output:  - se actualizeaza wishlist-ul
     * */
    void update_wishlist_modifiy(const string &denumire_veche, const Oferta& oferta);

    /*Functie care actualizeaza wishlist-ul atunci cand se actrualizeaza lista de oferte
     * input:   - denumire - string
     * output:  - se actualizeaza wishlist-ul
     * */
    void update_wishlist_delete(const string &denumire);

    /*Functie care face export la lista de oferte
     * input:   - file - string, numele fisierului
     * output:  - un fisier HTML care contine wishlist-ul
     * */
    void export_wishlist_html(string file);

    void export_wishlist_cvs(string file);

    /*Functie care returneaza toate ofertele din memorie
     * input:   -
     * output:  - un vector care contine toate ofertele*/
    const vector<Oferta>& get_wishlist() const noexcept;

    //Destructorul
    ~Wishlist();
};

#endif //LAB6_7_WISHLIST_H
