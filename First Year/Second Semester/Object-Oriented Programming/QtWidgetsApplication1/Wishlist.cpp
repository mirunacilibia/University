//
// Created by Miruna on 4/16/2021.
//

#include "Wishlist.h"
#include <algorithm>
#include "Validators.h"
#include <fstream>
#include <vector>
using namespace std;

void Wishlist::add_oferta(const Oferta &oferta) {

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(), [oferta](const Oferta& of){return of.get_denumire() == oferta.get_denumire();});
    if(it != oferte.end())
        throw RepoException("\nOferta este deja adaugata in memorie!\n");

    this->oferte.push_back(oferta);

    notify();
}

void Wishlist::clear_wishlist() {
    oferte.clear();

    notify();
}

void Wishlist::update_wishlist_modifiy(const string &denumire_veche, const Oferta &oferta) {

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(),[denumire_veche](const Oferta& of) { return of.get_denumire() == denumire_veche; });
    if(it != oferte.end()){
        (*it) = oferta;
    }

    notify();

}

void Wishlist::update_wishlist_delete(const string &denumire) {

    vector<Oferta>::iterator it;
    it = find_if(oferte.begin(), oferte.end(), [denumire](const Oferta& of){return of.get_denumire() == denumire;});
    if(it != oferte.end()) {
        oferte.erase(it);
    }

    notify();
}

void Wishlist::export_wishlist_html(string file) {
    file = file + ".html";
    file = R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\)" + file;
    ofstream out(file);
    out << "<html><body>\n";
    out << "<table border=\"1\" style=\"width:100 % \">\n";
    for(const Oferta& oferta: oferte){
        out << "<tr>\n";
        out << "<td>" << oferta.get_denumire() << "</td>\n";
        out << "<td>" << oferta.get_destinatie() << "</td>\n";
        out << "<td>" << oferta.get_tip() << "</td>\n";
        out << "<td>" << oferta.get_pret() << "</td>\n";
        out << "</tr>\n";
    }
    out << "</table>\n";
    out << "</body></html>\n";
    out.close();
    export_list.push_back(file);
}

void Wishlist::export_wishlist_cvs(string file) {
    file = file + ".cvs";
    file = R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\Lab6-7\)" + file;
    ofstream out(file);
    //for(const Oferta& oferta: get_wishlist()){
    for(const Oferta& oferta: oferte){
        string of;
        of = oferta.get_denumire() + "," + oferta.get_destinatie() + "," + oferta.get_tip() + "," + to_string(oferta.get_pret());
        out << of << "\n";
    }
    out.close();
    export_list.push_back(file);
}

const vector<Oferta> &Wishlist::get_wishlist() const noexcept {
        return oferte;
}

Wishlist::~Wishlist() {
//    for(const string& file: export_list){
//        char* fisier = new char[file.length() + 1];
//        copy(file.begin(), file.end(), fisier);
//        remove(fisier);
//        delete[] fisier;
}

