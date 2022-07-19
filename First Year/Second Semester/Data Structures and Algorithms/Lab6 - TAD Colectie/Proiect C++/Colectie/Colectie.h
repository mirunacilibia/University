#pragma once

#define NULL_TELEM -175740
typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:

    int dimension;

    int capacity;

    //nr locatii din tabela de dispersie
    int m;

    //vector de elemente
    TElem* elements;

    //vector de urmator
    int* urm;

    //functie de redimensionare
    void redim();

    //prim
    int prim_liber;

    //actualizare prim liber
    void update_prim_liber();

    //fucntia de dispersie
    int d(TElem element);


public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) ;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) ;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

        // elimină nr apariții ale elementului elem. În cazul în care elementul apare mai puțin de nr ori, toate aparițiile sale vor fi eliminate.
        // returnează numărul de apariții eliminate ale elementului.
        // aruncă excepție în cazul în care este nr este negativ.
        int eliminaAparitii(int nr, TElem elem);


};

