#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;


Nod::Nod(TElem elem, PNod urm, PNod prec) {

    //Complexitate: Theta(1)

    this -> elem = elem;
    this -> urm = urm;
    this -> prec = prec;
}

TElem Nod::element() {

    //Complexitate: Theta(1)

    return elem;
}

PNod Nod::urmator() {

    //Complexitate: Theta(1)

    return urm;
}

PNod Nod::precedent() {

    //Complexitate: Theta(1)

    return prec;
}


DO::DO(Relatie r) {

    //Complexitate: Theta(1)

	prim = nullptr;
	ultim = nullptr;
	relatie = r;
}


TValoare DO::adauga(TCheie c, TValoare v) {

    /*Complexitate
     * Caz favorabil: Theta(1)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: O(n)
     * */

	TElem element;
	element.first = c;
	element.second = v;

	//cazul in care cheia exista deja in dictionar
	if(cauta(c) != NULL_TVALOARE){

	    int valoare_veche = cauta(c);
        PNod p = prim;

        while(p != ultim && p->element().first != c){
            p = p->urmator();
        }
        // am gasit elementul si actualizam valoarea
        p->elem = element;

	    return valoare_veche;

	}
	//cheia nu exista in dictionar
	else{
        PNod nod = new Nod(element, nullptr, nullptr);
        PNod p = prim;

        if(vid()){
            prim = nod;
            ultim = nod;
            return NULL_TVALOARE;
        }
        //cautam pozitia in care trebuie sa inseram elementul
        while(p != nullptr && relatie(p -> element().first, c)){
            p = p->urmator();
        }

        //avem 3 cazuri, in functie de locul in care trebuie sa adaugam elementul
        if(p == prim){
            nod->urm = prim;
            prim->prec = nod;
            prim = nod;
        } else if(p == nullptr){
            ultim->urm = nod;
            nod->prec = ultim;
            ultim = nod;
        } else{
            nod->prec = p->prec;
            p->prec->urm = nod;
            p->prec = nod;
            nod->urm = p;
        }

        return NULL_TVALOARE;
	}

}


TValoare DO::cauta(TCheie c) const {

    /*Complexitate
     * Caz favorabil: Theta(1)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: O(n)
     * */

    PNod p = prim;

    if(vid())
        return NULL_TVALOARE;

    while(p != ultim && p->element().first != c){
        p = p->urmator();
    }

    if(p->element().first == c)
        return p->element().second;
    else
        return NULL_TVALOARE;
}

TValoare DO::sterge(TCheie c) {

    /*Complexitate
     * Caz favorabil: Theta(1)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: O(n)
     * */

    if(cauta(c) == NULL_TVALOARE) {
        return NULL_TVALOARE;
    }
    else{
        PNod p = prim;
        while(p != ultim && p->element().first != c){
            p = p->urmator();
        }
        //gasim pozitia pe care se afla elementul pe care il stergem
        int valoare = p->element().second;

        if(prim == ultim){
            prim = nullptr;
            ultim = nullptr;
            delete p;
            return valoare;
        }

        //luam cele 3 cazuri si stergem
        if(p == prim){
            prim = p->urm;
            prim->prec = nullptr;
            delete p;

        }else if(p == ultim){

            p->prec->urm = nullptr;
            ultim = ultim->prec;
            delete p;

        }else{

            p->prec->urm = p->urm;
            p->urm->prec = p->prec;
            delete p;
        }

        return valoare;
    }
}

int DO::dim() const {

    /*Complexitate
     * Caz favorabil: Theta(n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: Theta(n)
     * */

	int contor = 0;
    PNod p = prim;
    while(p != nullptr){
        contor++;
        p = p->urmator();
    }
    return contor;
}

bool DO::vid() const {

    //Complexitate: Theta(1)

    PNod p = prim;
    if(p == nullptr)
        return true;
    return false;
}

Iterator DO::iterator() const {

    //Complexitate: Theta(1)

	return  Iterator(*this);
}

DO::~DO() {

    /*Complexitate
     * Caz favorabil: Theta(n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: Theta(n)
     * */

    while (prim != nullptr){
        PNod p = prim;
        prim = prim->urm;
        delete p;
    }
}

int DO::actualizeazaValori(DO &m) {

    /*Complexitate
     * Caz favorabil: Theta(n*m)
     * Caz nefavorabil: Theta(n*m)
     * Caz mediu: Theta(n*m)
     * Total: O(n*m)
     * */

    int contor = 0;
    PNod p = prim;
    while (p != nullptr){
        int valoare = m.cauta(p->element().first);
        if(valoare != NULL_TVALOARE && valoare != p->element().second){
            contor++;
            TElem element;
            element.first = p->element().first;
            element.second = valoare;
            p->elem = element;
        }
        p = p->urm;
    }
    return contor;
}

/* modifică, în dicționarul curent, valorile asociate cheilor existente cu valorile asociate
 * acelorași chei în dicționarul d, dacă acestea diferă
 * returnează numărul de perechi modificate
 * int DO::actualizeazaValori(DO& m);
 * */

