//
// Created by Miruna on 3/28/2021.
//
#include <string>
#include "Domain.h"

using namespace std;

bool compare_denumire_increasing(const Oferta& of1, const Oferta& of2){
    return of1.get_denumire() < of2.get_denumire();
}

bool compare_denumire_decreasing(const Oferta& of1, const Oferta& of2){
    return of1.get_denumire() > of2.get_denumire();
}

bool compare_destinatie_increasing(const Oferta& of1, const Oferta& of2){
    return of1.get_destinatie() < of2.get_destinatie();
}

bool compare_destinatie_decreasing(const Oferta& of1, const Oferta& of2){
    return of1.get_destinatie() > of2.get_destinatie();
}

bool compare_tip_increasing(const Oferta& of1, const Oferta& of2){
    if (of1.get_tip() == of2.get_tip())
        return of1.get_pret() < of2.get_pret();
    else return of1.get_tip() < of2.get_tip();
}

bool compare_tip_decreasing(const Oferta& of1, const Oferta& of2){
    if (of1.get_tip() == of2.get_tip())
        return of1.get_pret() > of2.get_pret();
    else return of1.get_tip() > of2.get_tip();
}