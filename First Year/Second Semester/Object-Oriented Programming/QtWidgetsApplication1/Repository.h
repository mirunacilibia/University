//
// Created by Miruna on 3/23/2021.
//

#ifndef LAB6_7_REPOSITORY_H
#define LAB6_7_REPOSITORY_H

#include <vector>
#include "Domain.h"
#include "DynamicArray.h"
using std::vector;
using namespace std;
typedef Oferta TElem;

class Repository{
private:
    vector<Oferta> oferte;
    //vector<Oferta> wishlist;
public:

    /*Constructorul implicit
     * input:   -
     * output:  - se creeaza un repository*/
    Repository() = default;

     /*Functie care adauga o oferta
     * input:   - un obiect Oferta
     * output:  - se adauga un nou obiect in memorie
     * throw RepoException daca mai exista o oferta cu aceasi descriere
     * */
     virtual void add_oferta(const Oferta&);

    /*Functie care modifica o oferta
     * input:   - denumire: string, numele ofertei
     *          - destinatie: string, destinatia ofertei
     *          - tip: string, tipul ofertei
     *          - pret: nr intreg, pretul ofertei
     *          - denumire_veche: string, denumirea initiala a ofertei
     * output:  - se modifica oferta in memorie
     * throw RepoException daca modificarea duce la suprascrierea unei oferte existente
     * */
    virtual void modify_oferta(const string&, const string&, const string&, const string&, const int&);

    /*Functie care sterge o oferta
    * input:   - denumire: string, numele ofertei
    * output:  - se sterge oferta din memorie
    * */
    virtual void delete_oferta(const string&);

    /*Functie care cauta o oferta
     * input:   - denumire - string
     * output:  - obiectul gasit
     * */
     virtual Oferta search_oferta(const string& );

    /*Functie care returneaza toate ofertele din memorie
     * input:   -
     * output:  - un vector care contine toate ofertele*/
    virtual vector<Oferta>& get_all() ;


    /*Destructorul implicit*/
    virtual ~Repository() = default;
};

#endif //LAB6_7_REPOSITORY_H
