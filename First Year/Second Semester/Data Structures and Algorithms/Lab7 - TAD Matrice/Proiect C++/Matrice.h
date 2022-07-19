#pragma once

typedef int TElem;

typedef struct {
    int linie;
    int coloana;
    TElem valoare;
}TPair;

#define NIL -1

#define NULL_TELEMENT 0

class Matrice {

private:
    //tabloul care contine valorile
    TPair *elements;

    //tabloul care contine referinta catre nodul din stanga
    int *stanga;

    //tabloul care contine referinta catre nodul din dreapta
    int *dreapta;

    //tabloul care contine referinta catre nodul parinte
    int *parinte;

    //capacitatea tablourilor
    int capacity;

    //primul loc din tablou nealocat
    int prim_liber;

    //radacina
    int radacina;

    int nr_linii;

    int nr_coloane;

    int size;

    int aloca();

    void dealoca(int i);

    int creeazaNod(TPair e);

    void redim();

    TElem cauta(int& curent, int& precedent, int linie, int coloana) const;

    int adauga(int pozitie, int i, int j, TElem e);

    int sterge(int curent);

    int minim(int pozitie);

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);


	//destructor
	~Matrice();

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;


	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);


	TElem sumaSubDiagonalaPrincipala();

	TElem suma(int nod);
};







