#include <assert.h>

#include "DO.h"
#include "Iterator.h"

#include <exception>
#include <iostream>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void test(){

    DO dictOrd = DO(relatie1);
    dictOrd.adauga(1,2);
    dictOrd.adauga(7,1);
    dictOrd.adauga(10,3);
    dictOrd.adauga(5,10);
    dictOrd.adauga(6,30);

    DO m = DO(relatie1);
    m.adauga(1,6);
    m.adauga(2,1);
    m.adauga(3,9);
    m.adauga(4,3);
    m.adauga(5,10);
    m.adauga(6,0);

    assert(dictOrd.actualizeazaValori(m) == 2);
    assert(dictOrd.cauta(1) == 6);
    assert(dictOrd.cauta(2) == NULL_TVALOARE);
    assert(dictOrd.cauta(3) == NULL_TVALOARE);
    assert(dictOrd.cauta(4) == NULL_TVALOARE);
    assert(dictOrd.cauta(5) == 10);
    assert(dictOrd.cauta(6) == 0);
    assert(dictOrd.cauta(7) == 1);
    assert(dictOrd.cauta(10) == 3);

}

void testAll(){
	DO dictOrd = DO(relatie1);
	assert(dictOrd.dim() == 0);
	assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    assert(dictOrd.dim() == 1);
    assert(!dictOrd.vid());
    assert(dictOrd.cauta(1)!=NULL_TVALOARE);
    TValoare v =dictOrd.adauga(1,3);
    assert(v == 2);
    assert(dictOrd.cauta(1) == 3);
    Iterator it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
    	TElem e = it.element();
    	assert(e.second != NULL_TVALOARE);
    	it.urmator();
    }
    assert(dictOrd.sterge(1) == 3);
    assert(dictOrd.vid());
}

