#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {

    //Complexitate : Theta(m)

    m = 100;
    dimension = 0;

    elements = new TElem [m];
    urm = new int [m];

    for(int i = 0; i < m; i++){
        elements[i] = NULL_TELEM;
        urm[i] = NULL_TELEM;
    }

    prim_liber = 0;
}


void Colectie::adauga(TElem elem) {

    //Complexitate : O(m), dar in ipoteza dispersiei uniforme este Theta(1)

    if(dimension == m)
        redim();

    dimension++;
    int index = d(elem);
    if(elements[index] == NULL_TELEM)
    {
        elements[index] = elem;
        if(index == prim_liber)
            update_prim_liber();
        return;
    }

    int index_precedent = NULL_TELEM;
    while(index != NULL_TELEM)
    {
        index_precedent = index;
        index = urm[index];
    }

    if(prim_liber >= m)
        throw exception();

    elements[prim_liber] = elem;
    urm[index_precedent] = prim_liber;
    update_prim_liber();
}


bool Colectie::sterge(TElem elem) {

    //Complexitate : O(m), dar in ipoteza dispersiei uniforme este Theta(1)

    int i = d(elem);
    int j = NULL_TELEM;

    //pentru inceput, cautam elementul in colectie
    while (i != NULL_TELEM && elements[i] != elem){
        j = i;
        i = urm[i];
    }

    if(i == NULL_TELEM)
        return false;
    // nu exista elementul

    bool final = false;
    do{
        int poz = urm[i];
        int precedent = i;
        while(poz != NULL_TELEM && d(elements[poz]) != i){
            precedent = poz;
            poz = urm[poz];
        }
        if(poz == NULL_TELEM)
            final = true;
        else{
            elements[i] = elements[poz];
            j = precedent;
            i = poz;
        }
    } while (!final);

    if(j == NULL_TELEM){
        int index = 0;
        while (index < m && j == NULL_TELEM){
            if(urm[index] == i)
                j = index;
            else
                index++;
        }
    }
    if(j != NULL_TELEM)
        urm[j] = urm[i];

    elements[i] = NULL_TELEM;
    urm[i] = NULL_TELEM;

    if(prim_liber > i)
        prim_liber = i;

    dimension--;
    return true;

}


bool Colectie::cauta(TElem elem)  {

    //Complexitate : O(m), dar in ipoteza dispersiei uniforme este Theta(1)

    if(dimension == 0)
        return false;
    int index = d(elem);
    while(urm[index] != NULL_TELEM){
        if(elements[index] == elem)
            return  true;
        index = urm[index];
    }
    if(elements[index] == elem)
        return true;
    return false;
}

int Colectie::nrAparitii(TElem elem)  {

    //Complexitate : O(m), dar in ipoteza dispersiei uniforme este Theta(1)

    if(dimension == 0)
        return 0;

    int contor = 0;
    int index = d(elem);
    while(urm[index] != NULL_TELEM){
        if(elements[index] == elem)
            contor++;
        index = urm[index];
    }
    if(elements[index] == elem)
        contor++;
    return contor;
}


int Colectie::dim() const {

    //Complexitate : Theta(1)

    return dimension;
}


bool Colectie::vida() const {

    //Complexitate : Theta(1)

    return dimension == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {

    //Complexitate : Theta(1)

    delete[] elements;
    delete[] urm;

}

int hashCode(TElem e){

    //Complexitate : Theta(1)

    return abs(e);
}

int Colectie::d(TElem element) {

    //Complexitate : Theta(1)

    return hashCode(element) %  m;
}

void Colectie::update_prim_liber() {

    //Complexitate : O(m)

    prim_liber++;
    while(prim_liber < m && elements[prim_liber] != NULL_TELEM)
        prim_liber++;
}

void Colectie::redim() {

    //Completxitate: Theta(m)

    TElem* new_elements = new TElem [2 * m];
    TElem* new_urm = new int [2 * m];

    int m_vechi = m;
    m *= 2;
    for(int i = 0; i < m; i++){
        new_elements[i] = NULL_TELEM;
        new_urm[i] = NULL_TELEM;
    }

    prim_liber = 0;
    for(int i = 0; i < m_vechi; i++){
        // daca exista element pe pozitia i il adaugam
        if(elements[i] != NULL_TELEM){
            int index = d(elements[i]);
            if(new_elements[index] == NULL_TELEM)
            {
                new_elements[index] = elements[i];
                if(index == prim_liber) {
                    prim_liber++;
                    while(prim_liber < m && new_elements[prim_liber] != NULL_TELEM)
                        prim_liber++;
                }
                continue;
            }

            int index_precedent = NULL_TELEM;
            while(index != NULL_TELEM)
            {
                index_precedent = index;
                index = new_urm[index];
            }

            if(prim_liber >= m)
                throw exception();

            new_elements[prim_liber] = elements[i];
            new_urm[index_precedent] = prim_liber;
            prim_liber++;
            while(prim_liber < m && new_elements[prim_liber] != NULL_TELEM)
                prim_liber++;
        }
    }

    delete[] elements;
    delete[] urm;

    elements = new_elements;
    urm = new_urm;
}


/*Pseudocod
 *
 * Subalgoritm eliminaAparitii(nr, elem)
 *
 * daca nr < 0 atunci
 *     exceptie
 * sf daca
 *
 * contor <- 0
 *
 * pentru i <- 1, nr executa
 *      daca sterge(elem) = true atunci
 *          contor <- contor + 1
 *      altfel
 *          break
 *      sf daca
 * sf pentru
 *
 * returneaza contor
 *
 */



int Colectie::eliminaAparitii(int nr, TElem elem) {

    //Complexitate: O(nr * m), dar in ipoteza dispersiei uniforme este Theta(nr)

    if(nr < 0)
        throw exception();

    int contor = 0;

    for(int i = 0; i < nr; i++) {
        if(sterge(elem)){
            contor++;
        }
        else
            break;
    }

    return contor;
}


