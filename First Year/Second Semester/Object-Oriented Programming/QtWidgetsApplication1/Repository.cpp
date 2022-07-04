//
// Created by Miruna on 3/23/2021.
//

#include "Repository.h"
#include "Validators.h"
#include <algorithm>

using namespace std;
using std::vector;

void Repository::add_oferta(const Oferta& oferta) {

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(), [oferta](const Oferta& of){return of.get_denumire() == oferta.get_denumire();});
    if(it != oferte.end())
        throw RepoException("\nOferta este deja adaugata in memorie!\n");

    this->oferte.push_back(oferta);
}

 vector<TElem>& Repository::get_all()  {
    return oferte;
}

Oferta Repository::search_oferta(const string& denumire) {

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(), [denumire](const Oferta& of){return of.get_denumire() == denumire;});
    if(it != oferte.end())
        return (*it);

    Oferta oferta = Oferta();
    return oferta;
}

void Repository::modify_oferta(const string &denumire_veche, const string &denumire, const string &destinatie, const string &tip, const int &pret) {

    if(!search_oferta(denumire).get_denumire().empty() && denumire != denumire_veche)
        throw RepoException("\nOferta cu denumirea modificata este deja adaugata in memorie!\n");

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(), [denumire_veche](const Oferta& of){return of.get_denumire() == denumire_veche;});
    if(it != oferte.end()) {
        Oferta oferta = Oferta(denumire, destinatie, tip, pret);
        (*it) = oferta;
    }
    else{
        throw RepoException("\nOferta nu exista!\n");
    }
}

void Repository::delete_oferta(const string & denumire) {

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(), [denumire](const Oferta& of){return of.get_denumire() == denumire;});
    if(it != oferte.end()) {
        oferte.erase(it);
    }
    else{
        throw RepoException("\nOferta nu exista!\n");
    }
}

