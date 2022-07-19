//
// Created by Miruna on 4/27/2021.
//

#ifndef PROGRAMMARE_GRAF_H
#define PROGRAMMARE_GRAF_H

#define inf 100000

#include <vector>
#include <string>
#include <queue>
#include <deque>
using namespace std;

class Nod{
public:
    int parinte;
    int indice;
    int distanta;
    int timp;
    int nr_fii;
    string culoare;

    Nod() = default;
};

class Arc{
public:
    Nod inceput;
    Nod sfarsit;
    int pondere;
    int capacitate;

    Arc(Nod n1, Nod n2, int p, int c);
};

class Muchie{
public:
    Nod nod1;
    Nod nod2;
    int pondere;

    Muchie(Nod n1, Nod n2, int pondere);
};

class Graf{
public:
    int nr_noduri;
    vector<Nod> noduri;
    vector<Muchie> muchii;
    vector<Arc> arce;
    int** matrice_adiacenta;


    Graf(int nr_noduri);

    ~Graf();

    void add_arc(const int&, const int&, const int&, const int& );

    void add_muchie(const int&, const int&, const int&);

    void initializeaza(int nod_inceput);

//------------------------------ Parcurgeri ale grafului ---------------------------------------------------------------

    void BFS(const int& nod_inceput);

    void afisare_BFS(const int& nod_inceput);

    void DFS();

    int DFS_VISIT(const int &nod, int time);

    bool conex();

//---------------------------------- Ciclu Eulerian --------------------------------------------------------------------

    void hierholzer();

//---------------------------------- Cel mai scurt drum ----------------------------------------------------------------

    void moore(const int& nod_inceput);

    void moore_drum(const int& nod_inceput, const int& nod_final);

//---------------------------------- Cost minim ------------------------------------------------------------------------

    bool bellman_ford(const int& nod_inceput);

    void relax(Arc& nr_arc);

    void dijkstra(const int& nod_inceput);

    void johnson(const int& nod_inceput);

    void inchidere_tranzitiva();

//-------------------------------------- Arbori ------------------------------------------------------------------------

    queue<int> codare_prufer();

    void decodare_prufer(deque<int>& prufer);

    //Codare/Decodare Huffman

    void prim(const int& nod_inceput);


//---------------------------------------- Flux ------------------------------------------------------------------------

    int ford_fulkerson(const int& nod_sursa, const int& nod_destinatie);

    bool BFS_flux(int** &graf_rezidual, const int& nod_inceput, const int& nod_final);
};

#endif //PROGRAMMARE_GRAF_H
