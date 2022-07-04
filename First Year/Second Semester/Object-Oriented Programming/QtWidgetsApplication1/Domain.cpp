//
// Created by Miruna on 3/23/2021.
//

#include "Domain.h"

#include <utility>
#include <iostream>
using namespace std;

Oferta::Oferta() {
    this -> denumire = "";
    this -> destinatie = "";
    this -> tip = "";
    this -> pret = 0;
}

Oferta::Oferta(const std::string& denumire, const std::string& destinatie, const std::string& tip, const int& pret) {

    this -> denumire = denumire;
    this -> destinatie = destinatie;
    this -> tip = tip;
    this -> pret = pret;
    cout << "s-a copiat\n";
}

Oferta::Oferta(const Oferta& oferta){

    denumire = oferta.denumire;
    destinatie = oferta.destinatie;
    tip = oferta.tip;
    pret = oferta.pret;
}

const std::string & Oferta::get_denumire() const {
        return this -> denumire;
}

const std::string &Oferta::get_destinatie() const{
    return this -> destinatie;
}

const std::string &Oferta::get_tip() const{
    return this -> tip;
}

const int &Oferta::get_pret() const{
    return this -> pret;
}

void Oferta::set_denumire(const string& denumire) {
    this->denumire = denumire;
}

void Oferta::set_destinatie(const string& destinatie) {
    this->destinatie = destinatie;
}

void Oferta::set_tip(const string& tip) {
    this->tip = tip;
}

void Oferta::set_pret(int pret) {
    this->pret = pret;
}



