#include <exception>
#include "Iterator.h"
#include "DO.h"

using namespace std;

Iterator::Iterator(const DO& d) : dict(d){

    //Complexitate: Theta(1)

    curent = d.prim;
}

void Iterator::prim(){

    //Complexitate: Theta(1)

    curent = dict.prim;
}

void Iterator::urmator(){

    //Complexitate: Theta(1)

    if(!valid())
        throw exception();
    curent = curent->urmator();
}

bool Iterator::valid() const{

    //Complexitate: Theta(1)

    if(curent == nullptr)
        return false;
    return true;
}

TElem Iterator::element() const{

    //Complexitate: Theta(1)

	return pair <TCheie, TValoare>  (curent->element().first, curent->element().second);
}


