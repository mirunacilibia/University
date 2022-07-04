//
// Created by Miruna on 4/19/2021.
//

#include "RepoLab.h"
#include "Validators.h"

RepoLab::RepoLab(const float &prob) {
    probability = prob;
}

void RepoLab::add_oferta(const Oferta &oferta) {

    float nr = ((float) rand() / (RAND_MAX));
    cout << nr;
    if( nr < probability)
        throw RepoException("\nExceptie data de probabilitate!\n");

    if(oferte.find(oferta.get_denumire()) != oferte.end())
        throw RepoException("\nOferta exista deja in memorie!\n");
    this->oferte.insert(pair<string, Oferta>(oferta.get_denumire(), oferta));
}

void RepoLab::delete_oferta(const string &denumire) {

    float nr = ((float) rand() / (RAND_MAX));
    cout << nr;
    if( nr < probability)
        throw RepoException("\nExceptie data de probabilitate!\n");

    auto it = oferte.find(denumire);
    if(it != oferte.end()) {
        oferte.erase(it);
    }
    else{
        throw RepoException("\nOferta nu exista!\n");
    }
}

void RepoLab::modify_oferta(const string &denumire_veche, const string &denumire, const string &destinatie,
                            const string &tip, const int &pret) {

    float nr = ((float) rand() / (RAND_MAX));
    cout << nr;
    if( nr < probability)
        throw RepoException("\nExceptie data de probabilitate!\n");

    if(!search_oferta(denumire).get_denumire().empty() && denumire != denumire_veche)
        throw RepoException("\nOferta cu denumirea modificata este deja adaugata in memorie!\n");

    auto it = oferte.find(denumire_veche);
    if(it != oferte.end()) {
        Oferta oferta = Oferta(denumire, destinatie, tip, pret);
        (*it).second = oferta;
    }
    else{
        throw RepoException("\nOferta nu exista!\n");
    }
}

Oferta RepoLab::search_oferta(const string &denumire) {
    //vector<Oferta>::iterator it;
    auto it = oferte.find(denumire);
    if(it != oferte.end())
        return (*it).second;

    Oferta oferta = Oferta();
    return oferta;
}

vector<Oferta>& RepoLab::get_all() {
    map_vector();
    return vof;
}

void RepoLab::map_vector() {
    vof.clear();
    for(const auto& elements: oferte){
        vof.push_back(elements.second);
    }
}

