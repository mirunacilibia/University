//
// Created by Miruna on 4/27/2021.
//

#ifndef UNTITLED_WISHLIST_GUI_H
#define UNTITLED_WISHLIST_GUI_H

#include <QtWidgets/QApplication>
#include <utility>
#include <QtWidgets/QPushButton>
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QDebug>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QTableWidget>
#include <string>
#include <vector>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QComboBox>

#include "Service.h"
#include "Observer.h"

class WishlistGUI: public QWidget, public Observer{

private:
    Service& service;
    QPushButton* add_button = new QPushButton("Adauga in wishlist");
    QPushButton* delete_button = new QPushButton("Sterge wishlist-ul");
    QPushButton* generate_button = new QPushButton("Genereaza oferte");
    QPushButton* export_button = new QPushButton("Export wishlist");
    QPushButton* reload = new QPushButton("Reload");
    QPushButton* exit = new QPushButton("Iesire");

    QPushButton* command_add = new QPushButton("Acceseaza comanda de adaugare");
    QPushButton* command_export = new QPushButton("Acceseaza comanda de export");
    QPushButton* command_generate = new QPushButton("Acceseaza comanda de generare");

    //QLineEdit* text_denumire = new QLineEdit;
    QComboBox* text_denumire = new QComboBox;
    QSpinBox* text_numar_oferte = new QSpinBox;
    QLineEdit* text_tip = new QLineEdit;
    QLineEdit* text_nume_fisier = new QLineEdit;

    QLabel* label_denumire = new QLabel("Denumire: ");
    QLabel* label_numar_oferte = new QLabel("Cate oferte generati?: ");
    QLabel* label_tip = new QLabel("Tip (cvs / html): ");
    QLabel* label_nume_fisier = new QLabel("Numele fisierului: ");

    QWidget* date = new QWidget;
    QTableWidget* oferte = new QTableWidget(this);

    void init_gui();

    void reload_list(const vector<Oferta>&);

    void connect_signal_slots();

    void clear_text();

    void hide_buttons();

public:
    WishlistGUI(Service& srv);

    /*Functie care adauga o oferta in wishlist
     * input:   - vector wishlist
     * output:  - se afiseaza daca adaugarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void add_wishlist();

    /*Functie care sterge wishlist
     * input:   - vector wishlist
     * output:  - se afiseaza daca stergerea a fost facuta cu succes sau nu
     * */
    void delete_wishlist();

    /*Functie care adauga aleator ofertaein wishlist
     * input:   - vector wishlist
     * output:  - se afiseaza daca adaugarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void generate_wishlist();

    /*Functie care citeste numele fisierului HTML pentru export
     * input:   -
     * output:  - se creeaza fisierul
     * */
    void export_wishlist();

    void update() override{
//        wishlist.clear_wishlist();
//        for(const auto& of: service.get_wishlist()){
//            wishlist.add_oferta(of);
//        }
        reload_list(service.get_wishlist());
    }

    ~WishlistGUI(){
        //wishlist.remove_observers(this);
        service.remove_observers(this);
    }

};


#endif //UNTITLED_WISHLIST_GUI_H
