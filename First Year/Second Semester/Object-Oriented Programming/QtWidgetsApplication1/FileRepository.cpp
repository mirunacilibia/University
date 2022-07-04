//
// Created by Miruna on 4/14/2021.
//

#include <fstream>
#include "FileRepository.h"
#include "Validators.h"

FileRepository::FileRepository(const string& file) {

    this->file = R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\)" + file;
    load_from_file();
}

void FileRepository::load_from_file() {

    ifstream fin(file);
    while(!fin.eof()){
        string denumire;
        fin >> denumire;
        if(fin.eof())
            break;
        string destinatie, tip;
        int pret;
        fin >> destinatie;
        fin >> tip;
        fin >> pret;
        Oferta oferta = Oferta(denumire, destinatie, tip, pret);
        Repository::add_oferta(oferta);
    }
    fin.close();
}

void FileRepository::write_to_file() {

    ofstream fout(file);
    for(const Oferta& oferta: get_all()){
        fout << oferta.get_denumire() << " " << oferta.get_destinatie() << " " << oferta.get_tip() << " " << oferta.get_pret();
        fout << "\n";
    }
    fout.close();
}

void FileRepository::add_oferta(const Oferta &oferta) {
        Repository::add_oferta(oferta);
        write_to_file();
}

void FileRepository::delete_oferta(const string &denumire) {
        Repository::delete_oferta(denumire);
        write_to_file();
}

void FileRepository::modify_oferta(const string &denumire_veche, const string &denumire, const string &destinatie,
                                   const string &tip, const int &pret) {
        Repository::modify_oferta(denumire_veche, denumire, destinatie, tip, pret);
        write_to_file();
}

FileRepository::~FileRepository() {
    ofstream fout(file);
    fout.close();
}

