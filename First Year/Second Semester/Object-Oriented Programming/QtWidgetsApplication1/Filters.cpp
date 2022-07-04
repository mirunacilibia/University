//
// Created by Miruna on 3/28/2021.
//

#include "Domain.h"

using namespace std;

bool filtru_pret_mai_mic(const Oferta& oferta, const string& pret_string) {
    int pret = stoi(pret_string);
    return oferta.get_pret() <= pret;
}

bool filtru_pret_mai_mare(const Oferta& oferta, const string& pret_string) {
    int pret = stoi(pret_string);
    return oferta.get_pret() > pret;
}

bool filtru_destinatie(const Oferta& oferta, const string& destinatie) {
    //return oferta.get_destinatie().find(destinatie) != std::string::npos;
    for(int i = 0; i < oferta.get_destinatie().length(); i++){
        int j = 0;
        for(j = 0; j < destinatie.length(); j++){
            if(oferta.get_destinatie()[i + j] != destinatie[j])
                break;
        }
        if(j == destinatie.length())
            return true;
    }
    return false;
}