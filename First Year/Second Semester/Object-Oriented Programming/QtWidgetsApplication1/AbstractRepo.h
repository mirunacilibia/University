//
// Created by Miruna on 4/19/2021.
//

#ifndef LAB6_7_ABSTRACTREPO_H
#define LAB6_7_ABSTRACTREPO_H

class AbstractRepo{
public:

    virtual void add_oferta(const Oferta&) = 0;

    virtual void modify_oferta(const string&, const string&, const string&, const string&, const int&) = 0;

    virtual void delete_oferta(const string&) = 0;

    virtual Oferta search_oferta(const string& ) = 0;

    virtual vector<Oferta>& get_all() = 0;

    virtual ~Repository(){};
};

#endif //LAB6_7_ABSTRACTREPO_H
