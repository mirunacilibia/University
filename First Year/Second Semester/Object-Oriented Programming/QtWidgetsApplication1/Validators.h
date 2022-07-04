//
// Created by Miruna on 3/25/2021.
//

#ifndef LAB6_7_VALIDATORS_H
#define LAB6_7_VALIDATORS_H
#include <string>
#include "Domain.h"

using std::string;

class RepoException{
    string mesaj;
public:

    /*Constructorul
     * input:   - mesaj - string, mesajul care se afiseaza in caz de eroare
     * output:  -
     * */
    explicit RepoException(const string& mess);

    /*Functie care returneaza mesajul in caz de eroare
     * input:   -
     * output:  - mesajul care trebuie afisat
     * */
    const string& get_message() const;

};

class UndoException{
    string mesaj;
public:

    /*Constructorul
     * input:   - mesaj - string, mesajul care se afiseaza in caz de eroare
     * output:  -
     * */
    explicit UndoException(const string& mess);

    /*Functie care returneaza mesajul in caz de eroare
     * input:   -
     * output:  - mesajul care trebuie afisat
     * */
    const string& get_message() const;

};

class OfertaException{
    string mesaj;
public:

    /*Constructorul
     * input:   - mesaj - string, mesajul care se afiseaza in caz de eroare
     * output:  -
     * */
    explicit OfertaException(const string& mess);

    /*Functie care returneaza mesajul in caz de eroare
     * input:   -
     * output:  - mesajul care trebuie afisat
     * */
    const string& get_message() const;
};

class OfertaValidator{

    string mesaj;

public:

    /*Constructorul implicit
     * input:   -
     * output:  - se creeaza un validator
     * */
    OfertaValidator() = default;

    /*Functie de validare
     * input:   - denumire: string, numele ofertei
     *          - destinatie: string, destinatia ofertei
     *          - tip: string, tipul ofertei
     *          - pret: string, pretul ofertei
     *output:   - mesaj contine toate erorile
     * */
    void validare(const string & denumire, const string & destinatie, const string & tip, const string & pret_string);

    /*Functie care returneaza mesajul in caz de eroare
     * input:   -
     * output:  - mesajul care trebuie afisat
     * */
    const string& get_message() const;

};

#endif //LAB6_7_VALIDATORS_H
