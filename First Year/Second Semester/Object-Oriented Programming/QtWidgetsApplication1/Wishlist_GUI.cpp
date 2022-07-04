//
// Created by Miruna on 4/27/2021.
//
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLineEdit>
#include <QDebug>
#include <QtWidgets/QFormLayout>
#include <QString>
#include <string>
#include <vector>
#include <QStandardItemModel>
#include "Wishlist_GUI.h"

void WishlistGUI::init_gui() {

    setWindowTitle("Wishlist");

    oferte->setStyleSheet("background-color:white;");
    setStyleSheet("background-color:lightGray;");

    QHBoxLayout* horrizontal_layout = new QHBoxLayout;
    setLayout(horrizontal_layout);

    QWidget* meniu = new QWidget;
    QVBoxLayout* vertical_layout = new QVBoxLayout();
    meniu->setLayout(vertical_layout);
    QLabel* titlu = new QLabel("Meniu wishlist");

    vertical_layout->addWidget(titlu);
    vertical_layout->addWidget(add_button);
    vertical_layout->addWidget(delete_button);
    vertical_layout->addWidget(generate_button);
    vertical_layout->addWidget(export_button);
    vertical_layout->addWidget(reload);
    vertical_layout->addWidget(exit);

    add_button->setStyleSheet("background-color:darkCyan;");
    delete_button->setStyleSheet("background-color:darkCyan;");
    generate_button->setStyleSheet("background-color:darkCyan;");
    export_button->setStyleSheet("background-color:darkCyan;");
    reload->setStyleSheet("background-color:darkCyan;");
    exit->setStyleSheet("background-color:darkCyan;");


    QFormLayout* form = new QFormLayout();
    date->setLayout(form);

    label_denumire->setVisible(false);
    label_numar_oferte->setVisible(false);
    label_tip->setVisible(false);
    label_nume_fisier->setVisible(false);

    text_denumire->setVisible(false);
    text_denumire->setPlaceholderText("Denumirea ofertei");
    for(const auto& oferta: service.get_all())
        text_denumire->addItem(QString::fromStdString(oferta.get_denumire()));

    text_numar_oferte->setVisible(false);
    text_tip->setVisible(false);
    text_nume_fisier->setVisible(false);

    text_denumire->setStyleSheet("background-color:white;");
    text_numar_oferte->setStyleSheet("background-color:white;");
    text_tip->setStyleSheet("background-color:white;");
    text_nume_fisier->setStyleSheet("background-color:white;");

    form->addRow(label_denumire, text_denumire);
    form->addRow(label_numar_oferte, text_numar_oferte);
    form->addRow(label_tip, text_tip);
    form->addRow(label_nume_fisier, text_nume_fisier);

    command_add->setVisible(false);
    command_generate->setVisible(false);
    command_export->setVisible(false);

    command_add->setStyleSheet("background-color:darkCyan;");
    command_generate->setStyleSheet("background-color:darkCyan;");
    command_export->setStyleSheet("background-color:darkCyan;");

    form->addWidget(command_add);
    form->addWidget(command_generate);
    form->addWidget(command_export);

    horrizontal_layout->addWidget(meniu);
    horrizontal_layout->addWidget(date);
    horrizontal_layout->addWidget(oferte);
}

void WishlistGUI::reload_list(const vector<Oferta> &lista_oferte) {

//    wishlist.clear_wishlist();
//    for(const auto& of: service.get_wishlist()){
//        wishlist.add_oferta(of);
//    }

    oferte->clear();
    oferte->setColumnCount(4);
    oferte->setRowCount(lista_oferte.size());
    QTableWidgetItem* item = new QTableWidgetItem("Denumire");
    oferte->setHorizontalHeaderItem(0, item);
    QTableWidgetItem* item2 = new QTableWidgetItem("Destinatie");
    oferte->setHorizontalHeaderItem(1, item2);
    QTableWidgetItem* item3 = new QTableWidgetItem("Tip");
    oferte->setHorizontalHeaderItem(2, item3);
    QTableWidgetItem* item4 = new QTableWidgetItem("Pret");
    oferte->setHorizontalHeaderItem(3, item4);

    for (int i = 0; i < lista_oferte.size(); i++)
    {
        string denumire = lista_oferte[i].get_denumire();
        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(denumire));
        oferte->setItem(i, 0, item);
        string destinatie = lista_oferte[i].get_destinatie();
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(destinatie));
        oferte->setItem(i, 1, item2);
        string tip = lista_oferte[i].get_tip();
        QTableWidgetItem* item3 = new QTableWidgetItem(QString::fromStdString(tip));
        oferte->setItem(i, 2, item3);
        string pret = std::to_string(lista_oferte[i].get_pret());
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::fromStdString(pret));
        oferte->setItem(i, 3, item4);
    }
}

void WishlistGUI::connect_signal_slots() {

    service.add_observer(this);

    QObject::connect(reload, &QPushButton::clicked, [&]()
    {
        reload_list(service.get_wishlist());
    });

    QObject::connect(add_button, &QPushButton::clicked, [&]()
    {
        hide_buttons();
        add_wishlist();
        clear_text();
    });

    QObject::connect(delete_button, &QPushButton::clicked, [&]()
    {
            hide_buttons();
            delete_wishlist();
    });


    QObject::connect(generate_button, &QPushButton::clicked, [&]()
    {
        hide_buttons();
        generate_wishlist();
        clear_text();
    });


    QObject::connect(export_button, &QPushButton::clicked, [&]()
    {
        hide_buttons();
        export_wishlist();
        clear_text();
    });


    QObject::connect(exit, &QPushButton::clicked, [&]()
    {
        //qDebug() << "am iesit";
        QMessageBox::information(nullptr, "Info", "Ati parasit meniul de wishlist!");
        close();
    });

    QObject::connect(command_add, &QPushButton::clicked, [&](){

        auto denumire = text_denumire->currentText();

        try{
            int exista = service.add_wishlist(denumire.toStdString());
            if(!exista)
                QMessageBox::information(nullptr, "Info", "Oferta pe care doriti sa o adaugati nu exista!");
            else {
                QMessageBox::information(nullptr, "Info", "Operatia s-a efectuat cu succes!");
            }
        }
        catch (RepoException & exception){
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }
        catch (OfertaException & exception){
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }


        reload_list(service.get_wishlist());

        label_denumire->setVisible(false);
        text_denumire->setVisible(false);
        command_add->setVisible(false);
    });

    QObject::connect(command_generate, &QPushButton::clicked, [&](){

        auto nr = text_numar_oferte->text();
        int numar = nr.toInt();

        bool toate = service.generate_wishlist(numar);

        reload_list(service.get_wishlist());
        if(!toate){
            QMessageBox::information(nullptr, "Info", "Nu se pot adauga toate ofertele dorite!");
        }
        else {
            QMessageBox::information(nullptr, "Info", "Comanda a fost efectuata cu succes!");
        }

        label_numar_oferte->setVisible(false);
        text_numar_oferte->setVisible(false);
        command_generate->setVisible(false);
    });

    QObject::connect(command_export, &QPushButton::clicked, [&](){

        auto file = text_nume_fisier->text();
        auto type = text_tip->text();

        service.export_wishlist(file.toStdString(), type.toStdString());

        label_tip->setVisible(false);
        label_nume_fisier->setVisible(false);
        text_nume_fisier->setVisible(false);
        text_tip->setVisible(false);
        command_export->setVisible(false);
    });
}

void WishlistGUI::clear_text() {

    //text_denumire->clear();
    text_numar_oferte->clear();
    text_tip->clear();
    text_nume_fisier->clear();
}

WishlistGUI::WishlistGUI(Service &srv)  : service(srv){

    init_gui();
    reload_list(service.get_wishlist());
    connect_signal_slots();
}

void WishlistGUI::add_wishlist() {

    label_denumire->setVisible(true);
    text_denumire->setVisible(true);
    command_add->setVisible(true);
}

void WishlistGUI::delete_wishlist() {

    service.delete_wishlist();


    reload_list(service.get_wishlist());
    QMessageBox::information(nullptr, "Info", "Operatia s-a efectuat cu succes!");
}

void WishlistGUI::generate_wishlist() {

    label_numar_oferte->setVisible(true);
    text_numar_oferte->setVisible(true);
    command_generate->setVisible(true);
}

void WishlistGUI::export_wishlist() {

    label_tip->setVisible(true);
    label_nume_fisier->setVisible(true);
    text_nume_fisier->setVisible(true);
    text_tip->setVisible(true);
    command_export->setVisible(true);
}

void WishlistGUI::hide_buttons() {

    label_denumire->setVisible(false);
    label_numar_oferte->setVisible(false);
    label_tip->setVisible(false);
    label_nume_fisier->setVisible(false);

    text_denumire->setVisible(false);
    text_numar_oferte->setVisible(false);
    text_tip->setVisible(false);
    text_nume_fisier->setVisible(false);

    command_add->setVisible(false);
    command_generate->setVisible(false);
    command_export->setVisible(false);

}

