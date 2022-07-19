#pragma once
#include<vector>
#include<utility>


using namespace std;

#define NULL_TCHEIE 0

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;


class IteratorMD;

class MD
{
	friend class IteratorMD;

private:

    //tabloul care contine valorile
    TElem *elements;

    //tabloul care contine referinta catre urmatorul nod
    int *urm;

    //capacitatea tablourilor
    int capacity;

    //dimensiunea tablourilor
    int dimension;

    //primul element
    int prim;

    //primul loc din tablou nealocat
    int prim_liber;

    //functie care redimensioneaza tablourile
    void resize();

    //aloca un spatiu liber
    //returneaza pozitia unui spatiu liber in lista
    int aloca();

    //dealoca pozitia i
    void dealoca(int i);

    //creeaza un nod in lista
    int creeaza_nod(TElem element);

public:
	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();

    TCheie cheieMinima() const;


};

