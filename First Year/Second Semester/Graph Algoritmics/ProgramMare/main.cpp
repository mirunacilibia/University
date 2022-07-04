//
// Created by Miruna on 4/27/2021.
//

#include <iostream>
#include <fstream>
#include "graf.h"

using namespace std;

int main(){

//-------------------------------------- Daca am nevoie de muchii ------------------------------------------------------

//    int nr_noduri, nr_muchii;
//    ifstream fin("in.txt");
//    fin >> nr_noduri >> nr_muchii;
//    Graf graf = Graf(nr_noduri);
//    for(int i = 0; i < nr_muchii; i++){
//        int x, y;
//        fin >> x >> y;
//        graf.add_muchie(x, y, 0);
//    }
//    fin.close();


//---------------------------------- Daca am nevoie de muchii ponderate ------------------------------------------------

//    int nr_noduri, nr_muchii;
//    ifstream fin("in3.txt");
//    fin >> nr_noduri >> nr_muchii;
//    Graf graf = Graf(nr_noduri);
//    for(int i = 0; i < nr_muchii; i++){
//        int x, y, z;
//        fin >> x >> y >> z;
//        graf.add_muchie(x, y, z);
//    }
//    fin.close();


//----------------------------------------- Daca am nevoie de arce -----------------------------------------------------

//    int nr_noduri, nr_arce, nod_inceput;
//    ifstream fin("in2.txt");
//    fin >> nr_noduri >> nr_arce >> nod_inceput;
//    Graf graf = Graf(nr_noduri);
//    for(int i = 0; i < nr_arce; i++){
//        int x, y, z;
//        fin >> x >> y >> z;
//        graf.add_arc(x, y, z, 0);
//    }
//    fin.close();

//----------------------------------------- Daca am nevoie de vector de tati -------------------------------------------

//    int nr_noduri;
//    ifstream fin("in4.txt");
//    fin >> nr_noduri;
//    Graf graf = Graf(nr_noduri);
//    for(int i = 0; i < nr_noduri; i++){
//        int x;
//        fin >> x;
//        graf.noduri[i].parinte = x;
//        graf.noduri[x].nr_fii++;
//    }
//    fin.close();


//    graf.afisare_BFS(0);

//    graf.DFS();

//    for(int i = 0; i < nr_noduri - 1; i++)
//        for(int j = i + 1; j < nr_noduri; j++)
//            graf.moore_drum(i, j);

//    graf.hierholzer();

//    graf.bellman_ford(nod_inceput);
//    graf.dijkstra(nod_inceput);
//
//    fstream fout("out2.txt");
//    for(int i = 0; i < graf.nr_noduri; i++) {
//        if(graf.noduri[i].distanta == 100000)
//            fout << "INF ";
//        else
//            fout << graf.noduri[i].distanta << " ";
//    }
//    fout.close();

//    graf.prim(0);
//    cout << nr_noduri - 1 << "\n";
//    for(const auto& nod: graf.noduri){
//        if(nod.parinte != -1){
//            cout << nod.parinte << " " << nod.indice << "\n";
//        }
//    }

//    queue<int> prufer = graf.codare_prufer();
//    cout << prufer.size() << "\n";
//    while(!prufer.empty()){
//        int nod = prufer.front();
//        prufer.pop();
//        cout << nod << " ";
//    }

    int nr_noduri, nod;
    deque<int> prufer;
    ifstream fin("in5.txt");
    fin >> nr_noduri;
    Graf graf = Graf(nr_noduri + 1);
    for(int i = 0; i < nr_noduri; i++){
        fin >> nod;
        prufer.push_back(nod);
    }
    fin.close();

    graf.decodare_prufer(prufer);

    for(int i = 0; i <= nr_noduri; i++){
        cout << graf.noduri[i].parinte << " ";
    }

    return 0;
}

