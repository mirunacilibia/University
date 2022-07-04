//
// Created by Miruna on 3/23/2021.
//

#ifndef LAB6_7_DOMAIN_H
#define LAB6_7_DOMAIN_H

#include <iostream>
#include <string>
using namespace std;

class Oferta{

private:

    std::string denumire;
    std::string destinatie;
    std::string tip;
    int pret;

public:

    /*Constructorul implicit
     * input:   -
     * output:  - se creeaza o oferta*/
    Oferta();


    /*Constructorul
     * input:   - denumire: string, numele ofertei
     *          - destinatie: string, destinatia ofertei
     *          - tip: string, tipul ofertei
     *          - pret: nr intreg, pretul ofertei
     * output:  - se creeaza o oferta*/
    Oferta(const std::string&, const std::string&, const std::string&, const int&);


    /*Functie care returneaza o copie a ofertei
     * input:   - un obiect Oferta
     * output:  - se copiaza oferta*/
    Oferta(const Oferta& oferta);


    /*Getter - denumire
     * input:   -
     * output:  - denumire: string, denumirea ofertei*/
    const std::string & get_denumire() const;


    /*Getter - destinatie
     * input:   -
     * output:  - destinatie: string, destinatia ofertei*/
    const std::string& get_destinatie() const;


    /*Getter - tip
     * input:   -
     * output:  - tip: string, tipul ofertei*/
    const std::string& get_tip() const;


    /*Getter - pret
     * input:   -
     * output:  - pret: nr intreg, pretul ofertei*/
    const int& get_pret() const;

    /*Setter - denumire
     * input:   - denumire: string, denumirea ofertei
     * output:  - se actualizeaza denumirea*/
    void set_denumire(const string& denumire);

    /*Setter - destinatie
     * input:   - destinatie: string, destinatia ofertei
     * output:  - se actualizeaza destinatia*/
    void set_destinatie(const string& destinatie);

    /*Setter - tip
     * input:   - tip: string, tipul ofertei
     * output:  - se actualizeaza tipul*/
    void set_tip(const string& tip);

    /*Setter - pret
     * input:   - pret: nr intreg, pretul ofertei
     * output:  - se actualizeaza pretul*/
    void set_pret(int pret);

};

#endif //LAB6_7_DOMAIN_H
