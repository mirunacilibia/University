//
// Created by Miruna on 3/29/2021.
//

#ifndef LAB6_7_DYNAMICARRAY_H
#define LAB6_7_DYNAMICARRAY_H

template<typename TElem>
class DynamicArray{
private:
    TElem *elements;
    int capacity{};
    int size{};
    void resize();
public:

    /*Constructorul
     * input:   -
     * output:  - se creeaza un vector dinamic*/
    DynamicArray();

    ~DynamicArray();

    DynamicArray(const DynamicArray &v);

    /*Supraincarcarea operatorului =
     * input:   - un vector dinamic
     * output:  - se copiaza vectorul*/
    DynamicArray &operator=(const DynamicArray &v);

    /*Functie care adauga un element
     * input:   - un TElem
     * output:  - se adauga un nou obiect in memorie
     * */
    void add(const TElem&);

    /*Functie care sterge un element
     * input:   - position - nr intreg, pozitia elementului
     * output:  - se sterge elementul
     * */
    void del(const int& position);

    /*Functie care returneaza o copie a unui element
     * input:   - position - nr intreg, pozitia elementului
     * output:  - returneaza elementul de pe pozitia dorita
     * */
    TElem get(const int& position) const;

    /*Functie care modifica un element
     * input:   - position - nr intreg, pozitia elementului
     *          - un element TElem
     * output:  - modifica elementul de pe pozitia dorita
     * */
    void set(const TElem&, const int& position);

    //Returneaza lungimea vectorului
    int len() const;

    void destroy();

};

template<typename TElem>
DynamicArray<TElem>::DynamicArray() {
    this->capacity = 1;
    this->size = 0;
    this->elements = new TElem[capacity];
}

template<typename TElem>
void DynamicArray<TElem>::add(const TElem &element) {

    if(capacity == size)
        this->resize();

    this->elements[size] = element;
    size++;
}

template<typename TElem>
void DynamicArray<TElem>::del(const int& position) {

    for(int i = position; i < size - 1; i++)
        this -> elements[i] = this -> elements[i + 1];
    size--;
}

template<typename TElem>
void DynamicArray<TElem>::resize() {

    auto *new_elements = new TElem[2 * capacity];

    //copiem vechile valori in noua zona
    for (int i = 0; i < size; i++)
        new_elements[i] = elements[i];

    //dublam capacitatea
    capacity = 2 * capacity;

    //eliberam vechea zona
    delete[] elements;

    //vectorul indica spre noua zona
    elements = new_elements;
}

template<typename TElem>
TElem DynamicArray<TElem>::get(const int &position) const{
    return elements[position];
}

template<typename TElem>
int DynamicArray<TElem>::len() const{
    return size;
}

template<typename TElem>
void DynamicArray<TElem>::set(const TElem & oferta, const int& position) {
    elements[position].set_destinatie(oferta.get_destinatie());
    elements[position].set_denumire(oferta.get_denumire());
    elements[position].set_tip(oferta.get_tip());
    elements[position].set_pret(oferta.get_pret());
}

template<typename TElem>
DynamicArray<TElem> &DynamicArray<TElem>::operator=(const DynamicArray &v) {
    if(this != &v) {
        delete[] this->elements;
        this->elements = new TElem[v.capacity];
        this->capacity = v.capacity;
        this->size = v.size;
        for (int index = 0; index < this->size; index++)
            this->elements[index] = v.elements[index];
    }
    return *this;
}

template<typename TElem>
void DynamicArray<TElem>::destroy() {
    delete[] elements;
}

template<typename TElem>
DynamicArray<TElem>::~DynamicArray() {
    delete[] elements;
}

template<typename TElem>
DynamicArray<TElem>::DynamicArray(const DynamicArray &v) {
    this->capacity = v.capacity;
    this->size = v.size;
    this->elements = new TElem[capacity];
    for (int index = 0; index < this->size; index++)
        this->elements[index] = v.elements[index];
}

#endif //LAB6_7_DYNAMICARRAY_H
