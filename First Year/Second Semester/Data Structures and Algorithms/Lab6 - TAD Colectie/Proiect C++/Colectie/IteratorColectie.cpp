#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {

    curent = 0;
    deplasare();
}

void IteratorColectie::prim() {

    curent = 0;
    deplasare();
}


void IteratorColectie::urmator() {

    curent++;
    deplasare();
}


bool IteratorColectie::valid() const {

    return curent < col.m;
}



TElem IteratorColectie::element() const {

    return col.elements[curent];
}

void IteratorColectie::deplasare() {

    while ((curent < col.m) && col.elements[curent] == NULL_TELEM)
        curent++;
}
