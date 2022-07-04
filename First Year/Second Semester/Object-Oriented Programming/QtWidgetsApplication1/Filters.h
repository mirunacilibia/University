//
// Created by Miruna on 3/28/2021.
//

#ifndef LAB6_7_FILTERS_H
#define LAB6_7_FILTERS_H

/*Functie care verifica filtrul de pret pentru o oferta
 * input:   - of - un obiect Oferta
 *          - pret - nr intreg, pretul dupa care se filtreaza
 * output:  - true - pretul ofertei e mai mic decat "pret"
 *          - false - altfel
 **/
bool filtru_pret_mai_mic(const Oferta&, const string&);

/*Functie care verifica filtrul de pret pentru o oferta
 * input:   - of - un obiect Oferta
 *          - pret - nr intreg, pretul dupa care se filtreaza
 * output:  - true - pretul ofertei e mai mare decat "pret"
 *          - false - altfel
 **/
bool filtru_pret_mai_mare(const Oferta&, const string&);

/*Functie care verifica filtrul de destinatie pentru o oferta
 * input:   - of - un obiect Oferta
 *          - secventa - string, secventa care trebuie sa apara in destinatie
 * output:  - true - secventa apare in destinatie
 *          - false - altfel
 **/
bool filtru_destinatie(const Oferta&, const string&);

#endif //LAB6_7_FILTERS_H
