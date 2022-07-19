#include <exception>
#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {

    //Complexitate: Theta(1)

	pozitie_curenta = 0;
}

TElem IteratorColectie::element() const{

    //Complexitate: Theta(1)

    if(!valid()){
        throw std::exception();
    }

	return col.e[pozitie_curenta];
}

bool IteratorColectie::valid() const {

    //Complexitate: Theta(1)

	return pozitie_curenta < col.dim();
}

void IteratorColectie::urmator() {

    //Complexitate: Theta(1)

	if(!valid()){
	    throw std::exception();
	}

	pozitie_curenta ++;
}

void IteratorColectie::prim() {

    //Complexitate: Theta(1)

	pozitie_curenta = 0;
}
