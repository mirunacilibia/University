//
// Created by Miruna on 3/25/2021.
//

#include "Validators.h"

RepoException::RepoException(const string &mess) {
    mesaj = mess;
}

const string& RepoException::get_message() const{
    return mesaj;
}


const string& OfertaValidator::get_message() const{
    return mesaj;
}

void OfertaValidator::validare(const string & denumire, const string & destinatie, const string & tip, const string & pret_string) {

    mesaj = "";
    if(denumire.length() == 0)
        mesaj += "Denumirea nu a fost introdusa corect!\n";
    if(destinatie.length() == 0)
        mesaj += "Destinatia nu a fost introdusa corect!\n";
    if(tip.length() == 0)
        mesaj += "Tipul nu a fost introdus corect!\n";
    const int x = pret_string.length();
    for(int i = 0; i < x; i++)
        if(!isdigit(pret_string.at(i))) {
            mesaj += "Pretul nu a fost introdus corect!\n";
            break;
        }
}

OfertaException::OfertaException(const string &mess) {
    mesaj = mess;
}

const string& OfertaException::get_message() const{
    return mesaj;
}

UndoException::UndoException(const string &mess) {
    mesaj = mess;
}

const string &UndoException::get_message() const {
    return mesaj;
}
