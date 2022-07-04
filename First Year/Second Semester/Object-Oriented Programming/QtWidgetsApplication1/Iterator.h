//
// Created by Miruna on 4/5/2021.
//

#ifndef LAB6_7_ITERATOR_H
#define LAB6_7_ITERATOR_H

template <typename TElem>
class DynamicArray;

template<typename TElem>
class Iterator {
    friend class DynamicArray<TElem>;
private:
    const DynamicArray<TElem>& v;
    int poz = 0;
public:

    explicit Iterator(DynamicArray<TElem>& v) noexcept;

    Iterator(DynamicArray<TElem>& v, int poz)noexcept;

    bool valid()const;

    TElem element() const;

    void next();
};

template<typename TElem>
Iterator<TElem>::Iterator(DynamicArray<TElem>& v) noexcept:v{ v } {}

template<typename TElem>
Iterator<TElem>::Iterator(DynamicArray<TElem>& v, int poz)noexcept : v{ v }, poz{ poz } {}

template<typename TElem>
bool Iterator<TElem>::valid()const {
    return poz < v.len();
}

template<typename TElem>
TElem Iterator<TElem>::element() const {
    return v.get(poz);
}

template<typename TElem>
void Iterator<TElem>::next() {
    poz++;
}

#endif //LAB6_7_ITERATOR_H
