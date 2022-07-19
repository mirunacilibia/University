#include "TestScurt.h"
#include <assert.h>
#include <iostream>
#include "Colectie.h"
#include "IteratorColectie.h"

using namespace std;



void testAll() { //apelam fiecare functie sa vedem daca exista
	Colectie c;
	assert(c.vida() == true);
	assert(c.dim() == 0); //adaug niste elemente
	c.adauga(5);
	c.adauga(1);
	c.adauga(10);
	c.adauga(7);
	c.adauga(1);
	c.adauga(11);
	c.adauga(-3);
	assert(c.dim() == 7);
	assert(c.cauta(10) == true);
	assert(c.cauta(16) == false);
	assert(c.nrAparitii(1) == 2);
	assert(c.nrAparitii(7) == 1);
	assert(c.sterge(1) == true);
	assert(c.sterge(6) == false);
	assert(c.dim() == 6);
	assert(c.nrAparitii(1) == 1);
	IteratorColectie ic = c.iterator();
	ic.prim();
	while (ic.valid()) {
		TElem e = ic.element();
		ic.urmator();
	}	 
}

void test(){

    Colectie c;
    c.adauga(7);
    c.adauga(5);
    c.adauga(10);
    c.adauga(1);
    c.adauga(10);
    c.adauga(7);
    c.adauga(1);
    c.adauga(11);
    c.adauga(10);
    c.adauga(-3);
    c.adauga(11);

    assert(c.eliminaAparitii(3, 10) == 3);
    assert(c.dim() == 8);

    assert(c.eliminaAparitii(5, 11) == 2);
    assert(c.dim() == 6);

    assert(c.eliminaAparitii(2, -10) == 0);
    assert(c.dim() == 6);

    assert(c.eliminaAparitii(2, 5) == 1);
    assert(c.dim() == 5);
}