#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;
#include <vector>

MD::MD() {

    //Complexitate: Theta(1)

    capacity = 1;
    dimension = 0;
    elements = new TElem[capacity];
    urm = new int[capacity];

    prim = -1;
    prim_liber = 0;
    urm[0] = -1;

}


void MD::adauga(TCheie c, TValoare v) {

    //Complexitate: O(n)

    if(dimension == capacity)
        resize();
    dimension ++;

    TElem element;
    element.first = c;
    element.second = v;

    int pozitie = creeaza_nod(element);
    urm[pozitie] = prim;
    prim = pozitie;

}


bool MD::sterge(TCheie c, TValoare v) {

    //Complexitate: O(n)

    int p = prim;
    while(p != -1){
        if(elements[p].first == c && elements[p].second == v){
            if(p == prim)
                prim = urm[prim];
            else{
                int q = prim;
                while(urm[q] != p)
                    q = urm[q];
                urm[q] = urm[p];
            }
            elements[p].first = 0;
            elements[p].second = 0;
            dealoca(p);
            dimension--;
            return true;
        }
        p = urm[p];
    }
	return false;
}


vector<TValoare> MD::cauta(TCheie c) const {

    //Complexitate: Theta(n)
    // n - dimension

    vector<TValoare> vector;
    int p = prim;
    while(p != -1){
        if(elements[p].first == c)
            vector.push_back(elements[p].second);
        p = urm[p];
    }
	return vector;
}


int MD::dim() const {

    //Complexitate: Theta(1)

	return dimension;
}


bool MD::vid() const {

    //Complexitate: Theta(1)

    return prim == -1;
}

IteratorMD MD::iterator() const {

    //Complexitate: Theta(1)

	return IteratorMD(*this);
}


MD::~MD() {

    //Complexitate: Theta(1)

    delete[] elements;
    delete[] urm;
}

int MD::aloca() {

    //Complexitate: Theta(1)

    int i = prim_liber;
    prim_liber = urm[prim_liber];

    return i;
}

void MD::dealoca(int i) {

    //Complexitate: Theta(1)

    urm[i] = prim_liber;
    prim_liber = i;
}

int MD::creeaza_nod(TElem element) {

    //Complexitate: Theta(1)

    int i = aloca();
    elements[i] = element;
    urm[i] = -1;
    return i;
}

void MD::resize() {

    //Complexitate: Theta(n)
    // n - capacitatea noua

    TElem *new_elements = new TElem[2 * capacity];
    int *new_urm = new int[2 * capacity];

    capacity = 2 * capacity;

    for(int i = 0; i < dimension; i++){
        new_elements[i] = elements[i];
        new_urm[i] = urm[i];
    }

    for(int i = dimension; i < capacity - 1; i++){
        new_urm[i] = i + 1;
    }
    new_urm[capacity - 1] =  -1;
    if(prim_liber == -1)
        prim_liber = dimension;
    delete[] elements;
    delete[] urm;

    elements = new_elements;
    urm = new_urm;
}

/*găsește și returnează cheia minimă a multidicționarului
Dacă multidicționarul este vid, se returnează NULL_TCHEIE
TCheie cheieMinima() const;
Obs:  Pentru a avea NULL_TCHEIE, se adaugă la începutul Multidictionar.h următoarea definiție:
#define NULL_TCHEIE 0
*/

/*Pseudocod

 Algoritm cheieMinima(MD):
    curent <- MD.prim
    minim <- 100000

    daca curent = -1 atunci
        returneaza NULL_TCHEIE
    sf daca

    cat timp curent != -1 executa
        daca elements[curent] < minim atunci
            minim <- elements[curent]
        sf daca
        curent <- urm[curent]
    sf cat timp

    returneaza minim
 sf Algoritm
 * */

TCheie MD::cheieMinima() const {

    /*Complexitate
     * Caz favorabil: Theta(n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * */

    int curent = prim;
    TCheie minim = 100000;

    if(curent == -1)
        return NULL_TCHEIE;

    while(curent != -1){
        if(elements[curent].first < minim)
            minim = elements[curent].first;
        curent = urm[curent];
    }
    return minim;
}


