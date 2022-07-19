#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {

    //Complexitate: Theta(1)

	if(e1 <= e2)
	    return true;
	else
        return false;
}

void Colectie::redim() {

    /*Complexitate
     * Caz favorabil: Theta(n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: Theta(n)
     * */


    //alocam un spatiu de capacitate dubla
    TElem *eNou = new int[2 * capacity];

    //copiem vechile valori in noua zona
    for (int i = 0; i < dimension; i++)
        eNou[i] = e[i];

    //dublam capacitatea
    capacity = 2 * capacity;

    //eliberam vechea zona
    delete[] e;

    //vectorul indica spre noua zona
    e = eNou;
}

Colectie::Colectie() {

    //Complexitate: Theta(1)

    this -> capacity = 100;

	//spatiu de memorare pentru vector
	e = new TElem[capacity];

	//setam nr de elemente
	this -> dimension = 0;

}

void Colectie::adauga(TElem e) {

    /*Complexitate
     * Caz favorabil: Theta(log2n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: Theta(n)
     * */

	if(dimension == capacity)
        redim();

    int i = 0, stanga = 0, dreapta = dimension - 1, mijloc = 0;

    //cautare binara ca sa gasim pozitia la care adaugam
    while (stanga <= dreapta){
        mijloc = (stanga + dreapta) / 2;
        if(rel(this -> e[mijloc], e)) {
            if(!rel(this->e[mijloc + 1], e) || mijloc + 1 == dimension) {
                i = mijloc + 1;
                break;
            }
            stanga = mijloc + 1;
        }
        else
            dreapta = mijloc - 1;
    }

    //mutam cu o pozitie toate elementele din dreapta
	for(int j = dimension; j > i; j--){
	    this -> e[j] = this -> e[j - 1];
	}
	dimension++;

    this -> e[i] = e;
}


bool Colectie::sterge(TElem e) {

    /*Complexitate
     * Caz favorabil: Theta(log2n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: O(n)
     * Total: O(n)
     * */

    int stanga = 0, dreapta = dimension - 1, mijloc = 0;

    //cautare binara ca sa gasim pozitia pe care o stergem
    while (stanga <= dreapta){
        mijloc = (stanga + dreapta) / 2;
        if(rel(this -> e[mijloc], e)) {
            if(this -> e[mijloc] == e){
                //mutam toate celelalte elemente cu o pozitie spre stanga
                for(int j = mijloc; j < dimension - 1; j++)
                    this -> e[j] = this -> e[j + 1];
                dimension--;
                return true;
            }
            stanga = mijloc + 1;
        }
        else
            dreapta = mijloc - 1;
    }
    return false;

}


bool Colectie::cauta(TElem elem) const {

    /*Complexitate
     * Caz favorabil: Theta(1)
     * Caz nefavorabil: Theta(log2n)
     * Caz mediu: O(log2n)
     * Total: O(log2n)
     * */

    //cautare binara ca sa gasim elementul
	int stanga = 0, dreapta = dimension - 1, mijloc = 0;
    while (stanga <= dreapta){
        mijloc = (stanga + dreapta) / 2;
        if(rel(this -> e[mijloc], elem)) {
            if(this -> e[mijloc] == elem)
                return true;
            stanga = mijloc + 1;
        }
        else
            dreapta = mijloc - 1;
    }
    return false;
}


int Colectie::nrAparitii(TElem elem) const {

    /*Complexitate
     * Caz favorabil: Theta(n)
     * Caz nefavorabil: Theta(n)
     * Caz mediu: Theta(n)
     * Total: Theta(n)
     * */

	int frecventa = 0;

    for(int i = 0; i < dimension; i++)
        if(this -> e[i] == elem)
            frecventa++;
	return frecventa;
}



int Colectie::dim() const {

    //Complexitate: Theta(1)

	return dimension;
}


bool Colectie::vida() const {

    //Complexitate: Theta(1)

	if(dimension == 0)
	    return true;
	else
	    return false;
}


IteratorColectie Colectie::iterator() const {

    //Complexitate: Theta(1)

	return  IteratorColectie(*this);
}


Colectie::~Colectie() {

    //Complexitate: Theta(1)

	delete[] e;
}
