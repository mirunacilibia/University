#include "Matrice.h"

#include <exception>
#include <iostream>

using namespace std;


Matrice::Matrice(int m, int n) {

    /// Complexitate: Theta(c) - c - capacitatea

    if(m <= 0 || n <= 0)
        throw exception();
    nr_linii = m;
    nr_coloane = n;
    radacina = NIL;

    capacity = 10;
    size = 0;

    elements = new TPair [capacity];
    stanga = new int [capacity];
    dreapta = new int [capacity];
    parinte = new int [capacity];

    for (int i = 0; i < capacity - 1; i++) {
        stanga[i] = i + 1;
        dreapta[i] = NIL;
        parinte[i] = NIL;
        elements[i].valoare = NULL_TELEMENT;
    }
    stanga[capacity - 1] = NIL;
    dreapta[capacity - 1] = NIL;
    parinte[capacity - 1] = NIL;
    elements[capacity - 1].valoare = NULL_TELEMENT;

    prim_liber = 0;
}



int Matrice::nrLinii() const{

    /// Complexitate: Theta(1)

	return nr_linii;
}


int Matrice::nrColoane() const{

    /// Complexitate: Theta(1)

	return nr_coloane;
}


TElem Matrice::element(int i, int j) const{

    /// Complexitate: O(h) - h - inaltimea arborelui

	if(i >= nr_linii || j >= nr_coloane || i < 0 || j < 0)
        throw exception();

	int curent = radacina;
	int precedent = NIL;
    return cauta(curent, precedent, i, j);

}

TElem Matrice::cauta(int& curent, int& precedent, int i, int j) const {

    /// Complexitate: O(h) - h - inaltimea arborelui

    while(curent != NIL){
        if(elements[curent].linie == i && elements[curent].coloana == j) {
            /// am gasit elementul
            return elements[curent].valoare;
        } else if(elements[curent].linie == i && elements[curent].coloana < j){
            /// elementul are indicii mai mari decat elementul curent -> ne ducem pe subarborele din dreapta
            precedent = curent;
            curent = dreapta[curent];
        } else if(elements[curent].linie == i && elements[curent].coloana > j){
            /// elementul are indicii mai mici decat elementul curent -> ne ducem pe subarborele din stanga
            precedent = curent;
            curent = stanga[curent];
        } else if(elements[curent].linie < i){
            /// elementul are indicii mai mari decat elementul curent -> ne ducem pe subarborele din dreapta
            precedent = curent;
            curent = dreapta[curent];
        } else if(elements[curent].linie > i){
            /// elementul are indicii mai mici decat elementul curent -> ne ducem pe subarborele din stanga
            precedent = curent;
            curent = stanga[curent];
        }
    }
    return NULL_TELEMENT;

}

int Matrice::adauga(int pozitie, int i, int j, TElem element) {

    /// Complexitate: Theta(1)

    TPair e;
    e.linie = i;
    e.coloana = j;
    e.valoare = element;
    int p = creeazaNod(e);
    if(p == NIL && size == capacity){
        redim();
        p = creeazaNod(e);
    }
    ///  arborele este gol
    if(radacina == NIL){
        radacina = p;
        size++;
        return 0;
    }
    /// in acest caz, vedem daca adaugam nodul in dreapta sau in stanga
    if(elements[pozitie].linie < i || (elements[pozitie].linie == i && elements[pozitie].coloana < j)){
        /// adaugam in dreapta
        dreapta[pozitie] = p;
        parinte[p] = pozitie;
        size++;
        return 0;
    } else{
        /// adaugam in stanga
        stanga[pozitie] = p;
        parinte[p] = pozitie;
        size++;
        return 0;
    }
}

int Matrice::sterge(int curent) {

    /// Complexitate: O(h) - h - inaltimea arborelui

    if(stanga[curent] == NIL && dreapta[curent] == NIL){
        /// nodul pe care vrem sa il stergem nu are descendenti
        if(curent == radacina){
            /// nodul pe care il stergem e radacina
            radacina = NIL;
        } else{
            /// nodul pe care il stergem nu e radacina
            int p = parinte[curent];
            if(stanga[p] == curent){
                stanga[p] = NIL;
            } else if(dreapta[p] == curent){
                dreapta[p] = NIL;
            }
        }
        TElem value = elements[curent].valoare;
        dealoca(curent);
        size--;
        return value;
    } else if(stanga[curent] == NIL && dreapta[curent] != NIL){
        /// nodul are descendenti drepti
        if(curent == radacina){
            TElem value = elements[curent].valoare;
            radacina = dreapta[curent];
            parinte[radacina] = NIL;
            dealoca(curent);
            size--;
            return value;
        } else{
            int parent = parinte[curent];
            if(stanga[parent] == curent){
                /// a fost fiul stang al tatalui
                parinte[dreapta[curent]] = parent;
                stanga[parent] = dreapta[curent];
            } else{
                /// a fost fiul drept al tatalui
                parinte[dreapta[curent]] = parent;
                dreapta[parent] = dreapta[curent];
            }
            TElem value = elements[curent].valoare;
            dealoca(curent);
            size--;
            return value;
        }
    } else if(stanga[curent] != NIL && dreapta[curent] == NIL){
        /// nodul are descendenti stangi
        if(curent == radacina){
            TElem value = elements[curent].valoare;
            radacina = stanga[curent];
            parinte[radacina] = NIL;
            dealoca(curent);
            size--;
            return value;
        } else{
            int parent = parinte[curent];
            if(stanga[parent] == curent){
                /// a fost fiul stang al tatalui
                parinte[stanga[curent]] = parent;
                stanga[parent] = stanga[curent];
            } else{
                /// a fost fiul drept al tatalui
                parinte[stanga[curent]] = parent;
                dreapta[parent] = stanga[curent];
            }
            TElem value = elements[curent].valoare;
            dealoca(curent);
            size--;
            return value;
        }
    } else{
        /// nodul are si descendenti stangi, si drepti

        /// gasim nodul minim din subarborele drept al nodului curent
        int nod_minim = minim(dreapta[curent]);
        int parent = parinte[nod_minim];

        if(dreapta[nod_minim] == NIL){
            /// nodul minim nu are descendenti
            /// verficam numai dreapta, pentru ca fiind minimul, sigur nu are descendenti stangi
            stanga[parent] = NIL;
        } else{
            /// nodul minim are descendenti
            stanga[parent] = dreapta[nod_minim];
            int copil = dreapta[nod_minim];
            parinte[copil] = parent;
        }
        TElem value = elements[curent].valoare;
        elements[curent] = elements[nod_minim];
        dealoca(nod_minim);
        size--;
        return value;
    }
}


int Matrice::minim(int pozitie) {

    /// Complexitate: O(h) - h - inaltimea arborelui

    while(stanga[pozitie] != NIL)
        pozitie = stanga[pozitie];
    return pozitie;
}

TElem Matrice::modifica(int i, int j, TElem element) {

    /// Complexitate: O(h) - h - inaltimea arborelui

    if(i >= nr_linii || j >= nr_coloane || i < 0 || j < 0)
        throw exception();

    /// pentru inceput, cautam daca exista elementul
    /// daca exista, il stergem sau il modificam
    /// daca nu exista, il adaugam sau nu facem nimic
    int curent = radacina;
    int precedent = NIL;
    TElem val_veche = cauta(curent, precedent, i, j);

    /// Cazul I - adaugam sau modificam
    if(element != 0){
        /// exista elementul in matrice -> ii modificam valoarea
        if(val_veche != NULL_TELEMENT){
            elements[curent].valoare = element;
            return val_veche;
        }
        /// trebuie sa adaugam elementul
        return adauga(precedent, i, j, element);
    }
    /// Cazul II - stergem sau nu facem nimic
    else{
        /// nu facem nimic
        if(val_veche == NULL_TELEMENT){
            return 0;
        }
        /// trebuie sa stergem valoarea din arbore
        return sterge(curent);
    }
}

int Matrice::aloca() {

    /// Complexitate: Theta(1)

    int i = prim_liber;
    if(i != NIL)
        prim_liber = stanga[prim_liber];
    return i;
}

void Matrice::dealoca(int i) {

    /// Complexitate: Theta(1)

    stanga[i] = prim_liber;
    prim_liber = i;
    elements[i].linie = NIL;
    elements[i].coloana = NIL;
    elements[i].valoare = NULL_TELEMENT;
    dreapta[i] = NIL;
    parinte[i] = NIL;
}

int Matrice::creeazaNod(TPair e) {

    /// Complexitate: Theta(1)

    int i = aloca();
    if(i != NIL){
        elements[i] = e;
        stanga[i] = NIL;
        dreapta[i] = NIL;
        parinte[i] = NIL;
    }

    return i;
}

void Matrice::redim() {

    /// Complexitate: Theta(c) - c - noua capacitate

    TPair* new_elements = new TPair [2 * capacity];
    int* new_stanga = new int[2 * capacity];
    int* new_dreapta = new int[2 * capacity];
    int* new_parinte = new int[2 * capacity];

    ///copiem vechile valori in vectorii noi
    for (int i = 0; i < size; i++)
    {
        new_elements[i] = elements[i];
        new_stanga[i] = stanga[i];
        new_dreapta[i] = dreapta[i];
        new_parinte[i] = parinte[i];
    }

    prim_liber = size;
    new_stanga[prim_liber] = size + 1;
    new_dreapta[prim_liber] = NIL;
    new_parinte[prim_liber] = NIL;

    capacity = 2 * capacity;

    ///reinitializarea listei inlantuite a spatiului liber
    for (int i = size + 1; i < capacity - 1; i++) {
        new_stanga[i] = i + 1;
        new_dreapta[i] = NIL;
        new_parinte[i] = NIL;
    }
    new_stanga[capacity - 1] = NIL;
    new_dreapta[capacity - 1] = NIL;
    new_parinte[capacity - 1] = NIL;

    ///eliberam vectorii
    delete[] elements;
    delete[] stanga;
    delete[] dreapta;
    delete[] parinte;

    elements = new_elements;
    stanga = new_stanga;
    dreapta = new_dreapta;
    parinte = new_parinte;
}

Matrice::~Matrice() {

    /// Complexitate: Theta(1)

    delete[] elements;
    delete[] stanga;
    delete[] dreapta;
    delete[] parinte;
}

TElem Matrice::sumaSubDiagonalaPrincipala() {

    /// Complexitate: Theta(n) - n - numarul de elemente din arbore

    /// sub diagonala principala -> i > j

    int s = suma(radacina);
    return s;

}

/// Pseudocod
/// subalgoritm suma(nod)
///     sum <- 0
///     daca elements(nod).linie > elements(nod).coloana atunci
///         sum <- sum + elements(nod).valoare
///     sf daca
///     daca stanga(nod) != NIL atunci
///         sum <- sum + suma(stanga(nod))
///     sf daca
///     daca dreapta(nod) != NIL atunci
///         sum <- sum + suma(dreapta(nod))
///     sf daca
///     returneaza sum
/// sf subalgoritm

TElem Matrice::suma(int nod) {

    int sum = 0;

    if(elements[nod].linie > elements[nod].coloana) {
        //cout << elements[nod].linie << " " << elements[nod].coloana << "\n";
        sum += elements[nod].valoare;
    }
    if(stanga[nod] != NIL)
        sum += suma(stanga[nod]);
    if(dreapta[nod] != NIL)
        sum += suma(dreapta[nod]);
    return sum;
}
