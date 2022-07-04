//
// Created by Miruna on 4/14/2021.
//

#ifndef LAB6_7_UNDO_H
#define LAB6_7_UNDO_H

#include <memory>

class ActiuneUndo{
public:

    virtual void do_undo() = 0;

    virtual ~ActiuneUndo(){};
};

class UndoAdd: public ActiuneUndo{
    Oferta oferta;
    Repository& repository;
public:

    UndoAdd(Repository& repo, const Oferta& of) : repository{repo}, oferta{of} {}

    void do_undo() override {
        repository.delete_oferta(oferta.get_denumire());
    }
};

class UndoModify: public ActiuneUndo{
    Oferta oferta;
    string denumire;
    Repository& repository;
public:

    UndoModify(Repository& repo, const Oferta& of, const string& den) : repository{repo}, oferta{of}, denumire{den}  {}

    void do_undo() override {
        repository.modify_oferta(denumire, oferta.get_denumire(), oferta.get_destinatie(), oferta.get_tip(), oferta.get_pret());
    }
};

class UndoDelete: public ActiuneUndo{
    Oferta oferta;
    Repository& repository;
public:

    UndoDelete(Repository& repo, const Oferta& of) : repository{repo}, oferta{of}{}

    void do_undo() override {
        repository.add_oferta(oferta);
    }
};

#endif //LAB6_7_UNDO_H
