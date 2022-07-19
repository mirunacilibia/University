#include "IteratorMD.h"
#include "MD.h"

using namespace std;

IteratorMD::IteratorMD(const MD& _md): md(_md) {

    //Complexitate: Theta(1)

    curent = _md.prim;
}

TElem IteratorMD::element() const{

    //Complexitate: Theta(1)

    if(!valid())
        throw exception();
    return md.elements[curent];
}

bool IteratorMD::valid() const {

    //Complexitate: Theta(1)

	return curent != -1;
}

void IteratorMD::urmator() {

    //Complexitate: Theta(1)

    if(!valid())
        throw exception();
    curent = md.urm[curent];
}

void IteratorMD::prim() {

    //Complexitate: Theta(1)

    curent = md.prim;
}

