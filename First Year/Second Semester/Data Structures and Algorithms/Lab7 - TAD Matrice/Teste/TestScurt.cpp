#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1,1,5);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
	assert(m.element(1,2) == NULL_TELEMENT);
}

void test(){

    Matrice m(5,5);
    m.modifica(0,1,5);
    m.modifica(1,0,5);
    m.modifica(1,4,5);
    m.modifica(2,0,5);
    m.modifica(2,4,5);
    m.modifica(3,1,5);
    m.modifica(3,2,5);
    m.modifica(3,4,5);

    assert(m.sumaSubDiagonalaPrincipala() == 20);

    Matrice m2(3,3);
    m2.modifica(0,1,5);
    m2.modifica(0,2,5);
    m2.modifica(1,0,5);
    m2.modifica(2,0,5);

    assert(m2.sumaSubDiagonalaPrincipala() == 10);

}
