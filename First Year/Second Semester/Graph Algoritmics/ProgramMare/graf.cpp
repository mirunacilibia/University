//
// Created by Miruna on 4/27/2021.
//

#include "graf.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

Arc::Arc(Nod n1, Nod n2, int p, int c) {
    inceput = n1;
    sfarsit = n2;
    pondere = p;
    capacitate = c;
}

Muchie::Muchie(Nod n1, Nod n2, int p) {
    nod1 = n1;
    nod2 = n2;
    pondere = p;
}

Graf::Graf(int nr_noduri) {
    this->nr_noduri = nr_noduri;
    matrice_adiacenta = new int*[nr_noduri];
    for(int i = 0; i < nr_noduri; i++){

        matrice_adiacenta[i] = new int[nr_noduri];
        for(int j = 0; j < nr_noduri; j++)
            matrice_adiacenta[i][j] = 0;

        Nod nod = Nod();
        nod.indice = i;
        nod.nr_fii = 0;
        this->noduri.push_back(nod);

    }
}

void Graf::add_arc(const int &indice1, const int &indice2, const int &pondere, const int& capacitate) {
    Arc arc = Arc(noduri[indice1], noduri[indice2], pondere, capacitate);
    arce.push_back(arc);
}

void Graf::add_muchie(const int &indice1, const int &indice2, const int& pondere) {
    Muchie muchie = Muchie(noduri[indice1], noduri[indice2], pondere);
    muchii.push_back(muchie);
    matrice_adiacenta[indice1][indice2] = matrice_adiacenta[indice2][indice1] = 1;
}

void Graf::initializeaza(int nod_inceput) {

    for(int i = 0; i < nr_noduri; i++){
        noduri[i].timp = 0;
        noduri[i].distanta = -1;
        noduri[i].parinte = -1;
        noduri[i].culoare = "alb";
    }
    noduri[nod_inceput].distanta = 0;
}

bool Graf::conex() {

    bool conex = true;
    initializeaza(0);
    BFS(0);

    for(Nod nod: noduri){
        if(nod.distanta == -1)
            return false;
    }
    return true;
}

void Graf::BFS(const int &nod_inceput) {

    noduri[nod_inceput].culoare = "gri";
    noduri[nod_inceput].distanta = 0;

    queue<Nod> queue;
    queue.push(noduri[nod_inceput]);

    while(!queue.empty()){
        Nod nod_curent = queue.front();
        queue.pop();
        for(auto & muchie : muchii){
            if(muchie.nod1.indice == nod_curent.indice || muchie.nod2.indice == nod_curent.indice){
                Nod nod;
                if(muchie.nod1.indice == nod_curent.indice)
                    nod = muchie.nod2;
                else
                    nod = muchie.nod1;
                if(noduri[nod.indice].culoare == "alb"){
                    noduri[nod.indice].culoare = "gri";
                    noduri[nod.indice].distanta = nod_curent.distanta + 1;
                    noduri[nod.indice].parinte = nod_curent.indice;
                    queue.push(noduri[nod.indice]);
                }
            }
        }
        noduri[nod_curent.indice].culoare = "negru";
    }
}

void Graf::afisare_BFS(const int &nod_inceput) {

    initializeaza(nod_inceput);
    BFS(nod_inceput);

    bool conex = true;
    for(int i = 0; i < nr_noduri; i++){
        vector<int> vector;
        for(Nod nod: noduri){
            if(nod.distanta == i){
                vector.push_back(nod.indice);
            }
            if(nod.distanta == -1)
                conex = false;
        }
        if(!vector.empty()){
            cout << "\nVarfurile de distanta " << i << " : ";
            for(int j = 0; j < vector.size(); j++)
                cout << vector[j] << " ";
        }
    }
    if(!conex) {
        cout << "\n\nVarfurile nedescoperite: ";
        for (Nod nod: noduri) {
            if (nod.distanta == -1) {
                cout << nod.indice + 1 << " ";
            }
        }
    }
}

int Graf::DFS_VISIT(const int &nod, int time){

    time++;
    noduri[nod].distanta = time;
    noduri[nod].culoare = "gri";

    for(auto & muchie : muchii) {
        if (muchie.nod1.indice == nod || muchie.nod2.indice == nod) {
            int nod_curent;
            if (muchie.nod1.indice == nod)
                nod_curent = muchie.nod2.indice;
            else
                nod_curent = muchie.nod1.indice;
            if(noduri[nod_curent].culoare == "alb") {
                noduri[nod_curent].parinte = nod;
                time = DFS_VISIT(nod_curent, time);
            }
        }
    }
    noduri[nod].culoare = "negru";
    time++;
    noduri[nod].timp = time;

    return time;
}

void Graf::DFS() {

    initializeaza(0);
    int time = 0;
    for(auto & nod: noduri){
        if(nod.culoare == "alb")
            time = DFS_VISIT(nod.indice, time);
    }

    for(int i = 0; i < nr_noduri; i++){
        cout << i << " " << noduri[i].distanta << " " << noduri[i].timp << " " << noduri[i].culoare << " " << noduri[i].parinte <<"\n";
    }
}

void Graf::moore(const int &nod_inceput) {

    for(int i = 0; i < nr_noduri; i++) {
        noduri[i].distanta = inf;
        noduri[i].parinte = -1;
    }

    noduri[nod_inceput].distanta = 0;

    queue<Nod> queue;
    queue.push(noduri[nod_inceput]);

    while(!queue.empty()){
        Nod nod_curent = queue.front();
        queue.pop();
        for(auto & muchie : muchii){
            if(muchie.nod1.indice == nod_curent.indice || muchie.nod2.indice == nod_curent.indice){
                Nod nod;
                if(muchie.nod1.indice == nod_curent.indice)
                    nod = muchie.nod2;
                else
                    nod = muchie.nod1;
                if(noduri[nod.indice].distanta == inf){
                    noduri[nod.indice].parinte = nod_curent.indice;
                    noduri[nod.indice].distanta = noduri[nod_curent.indice].distanta + 1;
                    queue.push(noduri[nod.indice]);
                }
            }
        }
    }
}

void Graf::moore_drum(const int &nod_inceput, const int &nod_final) {

    int drum[100];
    moore(nod_inceput);

    int lungime_drum = noduri[nod_final].distanta;

    if(lungime_drum == -1)
        printf("\nNu exista drum!\n");

    else {

        int nod = nod_final;
        while(nod != -1){
            drum[lungime_drum] = nod;
            lungime_drum--;
            nod = noduri[nod].parinte;
        }

        cout << "\nLantul cel mai scurt de la nodul " << nod_inceput << " la nodul "<< nod_final <<" este:\n";
        for (int i = 0; i <= noduri[nod_final].distanta; i++)
            cout << drum[i] << " ";
        cout << "\n";
    }

}

void Graf::hierholzer() {

    //avem un vector muchii in care retinem cate muchii mai trebuie eliminate
    vector<unordered_map<int, int>> muchii_ramase;
    muchii_ramase = vector<unordered_map<int, int>>(nr_noduri + 1);


    for(auto& muchie: muchii){
        muchii_ramase[muchie.nod1.indice][muchie.nod2.indice] = 1;
        muchii_ramase[muchie.nod2.indice][muchie.nod1.indice] = 1;
    }
    for(auto& lista_muchii: muchii_ramase){
        if(lista_muchii.size() % 2 == 1){
            cout << "Graful nu este Eulerian!\n";
            return;
        }
    }

    stack<int> ciclu_eulerian;
    stack<int> ciclu_curent;

    //incepem de la primul nod
    ciclu_curent.push(0);

    while(!ciclu_curent.empty()){
        int nod = ciclu_curent.top();

        if(muchii_ramase[nod].size() == 0){
            //daca nu mai exista muchii lipite de nod
            ciclu_eulerian.push(nod);
            ciclu_curent.pop();
        }
        else{
            //altfel luam o muchie
            int nod_de_sters = muchii_ramase[nod].begin()->first;
            ciclu_curent.push(nod_de_sters);
            muchii_ramase[nod].erase(nod_de_sters);
            muchii_ramase[nod_de_sters].erase(nod);
        }
    }


    //afisare in consola

//    cout << "Ciclul eulerian este: ";
//    while(!ciclu_eulerian.empty()){
//        cout << ciclu_eulerian.top() << " ";
//        ciclu_eulerian.pop();
//    }
//    cout << "\n";


    //afisare in fisier

    ofstream fout("out.txt");
    while(!ciclu_eulerian.empty()){
        fout << ciclu_eulerian.top() << " ";
        ciclu_eulerian.pop();
    }
    fout.close();

}

bool Graf::BFS_flux(int **&graf_rezidual, const int &nod_inceput, const int &nod_final) {

    initializeaza(nod_inceput);

    noduri[nod_inceput].culoare = "gri";
    noduri[nod_inceput].distanta = 0;

    queue<Nod> queue;
    queue.push(noduri[nod_inceput]);

    while(!queue.empty()){
        Nod nod_curent = queue.front();
        queue.pop();
        for(int i = 0; i < nr_noduri; i++){
            if(noduri[i].culoare == "alb" && graf_rezidual[nod_curent.indice][i] > 0){

                noduri[i].culoare = "gri";
                noduri[i].distanta = nod_curent.distanta + 1;
                noduri[i].parinte = nod_curent.indice;
                queue.push(noduri[i]);

                //daca am gasit deja nodul cautat nu mai are rost sa continuam
                if(i == nod_final) {
                    return true;
                }
            }
        }
        noduri[nod_curent.indice].culoare = "negru";
    }
    return false;
}

int Graf::ford_fulkerson(const int &nod_sursa, const int &nod_destinatie) {

    int** graf_rezidual = new int*[nr_noduri];
    for(int i = 0; i < nr_noduri; i++){
        graf_rezidual[i] = new int[nr_noduri];
        for(int j = 0; j < nr_noduri; j ++)
            graf_rezidual[i][j] = 0;
    }

    for(auto& arc: arce){
        graf_rezidual[arc.inceput.indice][arc.sfarsit.indice] = arc.capacitate;
    }

    int flux_maxim = 0;

    while(BFS_flux(graf_rezidual, nod_sursa, nod_destinatie)){

        int flux_actual = INT_MAX;
        for(int i = nod_destinatie; i != nod_sursa; i = noduri[i].parinte){
            int j = noduri[i].parinte;
            flux_actual = min(flux_actual, graf_rezidual[j][i]);
        }

        for(int i = nod_destinatie; i != nod_sursa; i = noduri[i].parinte){
            int j = noduri[i].parinte;
            graf_rezidual[j][i] -= flux_actual;
            graf_rezidual[i][j] += flux_actual;
        }

        flux_maxim += flux_actual;
    }

    for(int i = 0; i < nr_noduri; i++)
        delete graf_rezidual[i];
    delete[] graf_rezidual;

    return flux_maxim;
}

bool Graf::bellman_ford(const int &nod_inceput) {

    for(int i = 0; i < nr_noduri; i++){
        noduri[i].distanta = 100000;
        noduri[i].parinte = -1;
    }
    noduri[nod_inceput].distanta = 0;

    for(int i = 1; i < nr_noduri; i++){
        for(int j = 0; j < arce.size(); j++) {
            relax(arce[j]);
        }
    }
    for(int j = 0; j < arce.size(); j++)
        if(noduri[arce[j].sfarsit.indice].distanta > noduri[arce[j].inceput.indice].distanta + arce[j].pondere)
            return false;
    return true;
}

void Graf::relax(Arc &arc) {

    if(noduri[arc.inceput.indice].distanta + arc.pondere < noduri[arc.sfarsit.indice].distanta){
        noduri[arc.sfarsit.indice].distanta = noduri[arc.inceput.indice].distanta + arc.pondere;
        noduri[arc.sfarsit.indice].parinte = noduri[arc.inceput.indice].indice;
    }
}

struct Comparare{
    bool operator()(const Nod& n1, const Nod& n2){
    return n1.distanta > n2.distanta;
    }
};

void Graf::dijkstra(const int &nod_inceput) {

    priority_queue<Nod, vector<Nod>, Comparare> coada;

    noduri[nod_inceput].distanta = 0;
    for(int i = 0; i < nr_noduri; i++){
        if(i != nod_inceput)
            noduri[i].distanta = 100000;
        noduri[i].parinte = -1;
    }

    coada.push(noduri[nod_inceput]);

    while (!coada.empty()){
        Nod nod = coada.top();
        coada.pop();
        for(auto& arc: arce){
            if(arc.inceput.indice == nod.indice)
                if(noduri[arc.inceput.indice].distanta + arc.pondere < noduri[arc.sfarsit.indice].distanta){
                    noduri[arc.sfarsit.indice].distanta = noduri[arc.inceput.indice].distanta + arc.pondere;
                    noduri[arc.sfarsit.indice].parinte = noduri[arc.inceput.indice].indice;
                    coada.push(noduri[arc.sfarsit.indice]);
                }
        }
    }
}

void Graf::johnson(const int &nod_inceput) {

    bellman_ford(nod_inceput);

    for(auto& arc: arce){
        arc.pondere += noduri[arc.inceput.indice].distanta - noduri[arc.sfarsit.indice].distanta;
    }

    for(int j = 0; j < nr_noduri; j++){
        dijkstra(j);
//        fstream fout("out2.txt");
//        for(int i = 0; i < nr_noduri; i++) {
//            if(noduri[i].distanta == 100000)
//                fout << "INF ";
//            else
//                fout << noduri[i].distanta << " ";
//        }
//        fout.close();
    }

}

void Graf::prim(const int &nod_inceput) {

    priority_queue<Nod, vector<Nod>, Comparare> coada;

    vector<bool> in_arbore(nr_noduri, false);

    noduri[nod_inceput].distanta = 0;
    for(int i = 0; i < nr_noduri; i++){
        if(i != nod_inceput)
            noduri[i].distanta = 100000;
        noduri[i].parinte = -1;
    }

    coada.push(noduri[nod_inceput]);

    while (!coada.empty()){
        Nod nod = coada.top();
        coada.pop();
        in_arbore[nod.indice] = true;
        for(auto& muchie: muchii){
            if(muchie.nod1.indice == nod.indice || muchie.nod2.indice == nod.indice){
                int u;
                if(muchie.nod1.indice == nod.indice)
                    u = muchie.nod2.indice;
                else
                    u = muchie.nod1.indice;
                if(in_arbore[u] == false && muchie.pondere < noduri[u].distanta){
                    noduri[u].parinte = nod.indice;
                    noduri[u].distanta = muchie.pondere;
                    coada.push(noduri[u]);
                }

            }
        }
    }
}

struct Comparare_Arbori{
    bool operator()(const Nod& n1, const Nod& n2){
        if(n1.nr_fii == n2.nr_fii)
            return n1.indice > n2.indice;
        else
            return n1.nr_fii > n2.nr_fii;
    }
};

queue<int> Graf::codare_prufer() {

    queue<int> K;
    priority_queue<Nod, vector<Nod>, Comparare_Arbori> coada;

    for(int i = 0; i < nr_noduri; i++){
        if(noduri[i].nr_fii == 0)
            coada.push(noduri[i]);
    }

    for(int i = 0; i < nr_noduri - 1; i++){
        Nod nod = coada.top();
        coada.pop();
        noduri[nod.parinte].nr_fii--;
        if(noduri[nod.parinte].nr_fii == 0)
            coada.push(noduri[nod.parinte]);
        K.push(nod.parinte);
    }

    return K;
}

void Graf::decodare_prufer(deque<int> &prufer) {

    for(int i = 0; i < nr_noduri; i++)
        noduri[i].parinte = -1;

    for(int i = 0; i < nr_noduri - 1; i++){
        int x = prufer.front();
        deque<int>::iterator it;
        for(int j = 0; j < nr_noduri; j++){
            bool gasit = false;
            for(it = prufer.begin(); it != prufer.end() && !gasit; it++)
                if(*it == j){
                    gasit = true;
                    break;
                }
            if(!gasit){
                noduri[j].parinte = x;
                prufer.pop_front();
                prufer.push_back(j);
                break;
            }
        }
    }

}

void Graf::inchidere_tranzitiva() {

    int** inchidere_tranzitiva = new int*[nr_noduri];
    for(int i = 0; i < nr_noduri; i++){
        inchidere_tranzitiva[i] = new int[nr_noduri];
        for(int j = 0; j < nr_noduri; j++)
            inchidere_tranzitiva[i][j] = 0;
    }



}


Graf::~Graf() {

    for(int i = 0; i < nr_noduri; i++)
        delete matrice_adiacenta[i];
    delete matrice_adiacenta;
}


