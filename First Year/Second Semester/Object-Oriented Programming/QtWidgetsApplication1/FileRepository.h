//
// Created by Miruna on 4/14/2021.
//

#ifndef LAB6_7_FILEREPOSITORY_H
#define LAB6_7_FILEREPOSITORY_H

#include "Domain.h"
#include "Repository.h"
using namespace std;

class FileRepository: public Repository{
    string file;
    void load_from_file();
    void write_to_file();

public:

    explicit FileRepository(const string& file);

    void add_oferta(const Oferta& oferta) override;

    void delete_oferta(const string& denumire) override;

    void modify_oferta(const string &denumire_veche, const string &denumire, const string &destinatie, const string &tip, const int &pret) override;

    ~FileRepository() override;
};

#endif //LAB6_7_FILEREPOSITORY_H
