//
// Created by Miruna on 3/28/2021.
//

#ifndef LAB6_7_COMPARE_H
#define LAB6_7_COMPARE_H

/*Functie care compara doua denumiri
 * input:   - of1, of2 - doua obiecte Oferta
 * output:  - true - of1 <= of2
 *          - false - of1 > of2
 **/
bool compare_denumire_increasing(const Oferta& of1, const Oferta& of2);

/*Functie care compara doua denumiri
 * input:   - of1, of2 - doua obiecte Oferta
 * output:  - true - of1 >= of2
 *          - false - of1 < of2
 **/
bool compare_denumire_decreasing(const Oferta& of1, const Oferta& of2);

/*Functie care compara doua destinatii
 * input:   - of1, of2 - doua obiecte Oferta
 * output:  - true - of1 <= of2
 *          - false - of1 > of2
 **/
bool compare_destinatie_increasing(const Oferta& of1, const Oferta& of2);

/*Functie care compara doua destinatii
 * input:   - of1, of2 - doua obiecte Oferta
 * output:  - true - of1 >= of2
 *          - false - of1 < of2
 **/
bool compare_destinatie_decreasing(const Oferta& of1, const Oferta& of2);

/*Functie care compara doua tipuri si preturi
 * input:   - of1, of2 - doua obiecte Oferta
 * output:  - true - of1 <= of2
 *          - false - of1 > of2
 **/
bool compare_tip_increasing(const Oferta& of1, const Oferta& of2);

/*Functie care compara doua tipuri si preturi
 * input:   - of1, of2 - doua obiecte Oferta
 * output:  - true - of1 >= of2
 *          - false - of1 < of2
 **/
bool compare_tip_decreasing(const Oferta& of1, const Oferta& of2);


#endif //LAB6_7_COMPARE_H
