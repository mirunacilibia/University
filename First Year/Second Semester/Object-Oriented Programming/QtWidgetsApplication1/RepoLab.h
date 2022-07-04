//
// Created by Miruna on 4/19/2021.
//

#ifndef LAB6_7_REPOLAB_H
#define LAB6_7_REPOLAB_H

#include <map>
#include "Repository.h"

using std::map;

class RepoLab: public Repository{
private:
    map<string, Oferta> oferte;
    vector<Oferta> vof;
    float probability;
public:
    explicit RepoLab(const float & prob);

    void add_oferta(const Oferta& oferta) override;

    Oferta search_oferta(const string& ) override;

    void delete_oferta(const string& denumire) override;

    void modify_oferta(const string &denumire_veche, const string &denumire, const string &destinatie, const string &tip, const int &pret) override;

     vector<Oferta>& get_all() override;

     void map_vector();

    ~RepoLab() override = default;

};

#endif //LAB6_7_REPOLAB_H
