//
// Created by Miruna on 3/23/2021.
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

using namespace std;
#include "GUI.h"
#include "Validators.h"
#include "Filters.h"
#include "Compare.h"
#include "Wishlist_GUI.h"
#include "Wishlist_Read_Only_GUI.h"


void GUI::init_gui()
{

    oferte->setModel(model);

    setWindowTitle("Aplicatia de oferte tursitice");
    add_button->setStyleSheet("background-color:darkCyan;");
    modify_button->setStyleSheet("background-color:darkCyan;");
    delete_button->setStyleSheet("background-color:darkCyan;");
    search_button->setStyleSheet("background-color:darkCyan;");
    filter_button->setStyleSheet("background-color:darkCyan;");
    sort_button->setStyleSheet("background-color:darkCyan;");
    raport_button->setStyleSheet("background-color:darkCyan;");
    wishlist_button->setStyleSheet("background-color:darkCyan;");
    undo_button->setStyleSheet("background-color:darkCyan;");
    exit->setStyleSheet("background-color:darkCyan;");

    setStyleSheet("background-color:lightGray;");
    oferte->setStyleSheet("background-color:white;");

    QHBoxLayout* horrizontal_layout = new QHBoxLayout;
    setLayout(horrizontal_layout);
	
    QWidget* meniu = new QWidget;
    QVBoxLayout* vertical_layout = new QVBoxLayout();
    meniu->setLayout(vertical_layout);
    QLabel* titlu = new QLabel("Bine ati venit la aplicatia de gestionat oferte turistice!");



    vertical_layout->addWidget(titlu);
    vertical_layout->addWidget(add_button);
    vertical_layout->addWidget(modify_button);
    vertical_layout->addWidget(delete_button);
    vertical_layout->addWidget(search_button);
    vertical_layout->addWidget(filter_button);
    vertical_layout->addWidget(sort_button);
    vertical_layout->addWidget(raport_button);
    vertical_layout->addWidget(wishlist_button);
    vertical_layout->addWidget(undo_button);
    vertical_layout->addWidget(exit);

    QFormLayout* form = new QFormLayout();
    date->setLayout(form);

    label_denumire_veche->setVisible(false);
    label_denumire->setVisible(false);
    label_destinatie->setVisible(false);
    label_tip->setVisible(false);
    label_pret->setVisible(false);

    text_denumire_veche->setVisible(false);
    text_denumire_veche->setPlaceholderText("Denumirea");
    for(const auto& oferta: service.get_all())
        text_denumire_veche->addItem(QString::fromStdString(oferta.get_denumire()));

    text_denumire->setVisible(false);
    text_destinatie->setVisible(false);
    text_tip->setVisible(false);
    text_pret->setVisible(false);

    text_denumire->setStyleSheet("background-color:white;");
    text_denumire_veche->setStyleSheet("background-color:white;");
    text_destinatie->setStyleSheet("background-color:white;");
    text_tip->setStyleSheet("background-color:white;");
    text_pret->setStyleSheet("background-color:white;");

    form->addRow(label_denumire_veche, text_denumire_veche);
    form->addRow(label_denumire, text_denumire);
    form->addRow(label_destinatie, text_destinatie);
    form->addRow(label_tip, text_tip);
    form->addRow(label_pret, text_pret);

    command_add->setVisible(false);
    command_search->setVisible(false);
    command_modify->setVisible(false);
    command_delete->setVisible(false);

    command_add->setStyleSheet("background-color:darkCyan;");
    command_search->setStyleSheet("background-color:darkCyan;");
    command_modify->setStyleSheet("background-color:darkCyan;");
    command_delete->setStyleSheet("background-color:darkCyan;");

    form->addWidget(command_add);
    form->addWidget(command_search);
    form->addWidget(command_modify);
    form->addWidget(command_delete);

    horrizontal_layout->addWidget(meniu);
    horrizontal_layout->addWidget(date);
    horrizontal_layout->addWidget(oferte);

}

void GUI::reload_combo_box(){

    text_denumire_veche->clear();
    for(const auto& oferta: service.get_all())
        text_denumire_veche->addItem(QString::fromStdString(oferta.get_denumire()));
}

void GUI::reload_list(const vector<Oferta>& lista_oferte)
{

    model->set_oferte(lista_oferte);

//    oferte->clear();
//    oferte->setColumnCount(4);
//    oferte->setRowCount(lista_oferte.size());
//    QTableWidgetItem* item = new QTableWidgetItem("Denumire");
//    oferte->setHorizontalHeaderItem(0, item);
//    QTableWidgetItem* item2 = new QTableWidgetItem("Destinatie");
//    oferte->setHorizontalHeaderItem(1, item2);
//    QTableWidgetItem* item3 = new QTableWidgetItem("Tip");
//    oferte->setHorizontalHeaderItem(2, item3);
//    QTableWidgetItem* item4 = new QTableWidgetItem("Pret");
//    oferte->setHorizontalHeaderItem(3, item4);
	
//    for (int i = 0; i < lista_oferte.size(); i++)
//    {
//        string denumire = lista_oferte[i].get_denumire();
//        QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(denumire));
//        oferte->setItem(i, 0, item);
//        string destinatie = lista_oferte[i].get_destinatie();
//        QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(destinatie));
//        oferte->setItem(i, 1, item2);
//        string tip = lista_oferte[i].get_tip();
//        QTableWidgetItem* item3 = new QTableWidgetItem(QString::fromStdString(tip));
//        oferte->setItem(i, 2, item3);
//        string pret = std::to_string(lista_oferte[i].get_pret());
//        QTableWidgetItem* item4 = new QTableWidgetItem(QString::fromStdString(pret));
//        oferte->setItem(i, 3, item4);
//    }
}

void GUI::connect_signal_slots() {

//    QObject::connect(oferte, &QTableWidget::itemSelectionChanged, [&]()
//    {
//        auto sel = oferte->selectedItems();
//        auto s1 = sel.at(0);
//
//        Oferta oferta = service.search_oferta(s1->text().toStdString());
//
//        if (!oferta.get_denumire().empty()) {
//            string s = oferta.get_denumire() + " " + oferta.get_destinatie() + " " + oferta.get_tip() + " " +
//                       std::to_string(oferta.get_pret());
//            QMessageBox::information(nullptr, "Oferta cautata este: ", QString::fromStdString(s));
//        }
//    });


    QObject::connect(add_button, &QPushButton::clicked, [&]()
    {
            hide_buttons();
            add_oferta();
            clear_text();
    });

    QObject::connect(modify_button, &QPushButton::clicked, [&]()
    {
        reload_combo_box();
        hide_buttons();
        modify_oferta();
        clear_text();
    });

    QObject::connect(delete_button, &QPushButton::clicked, [&]()
        {
            reload_combo_box();
            hide_buttons();
            delete_oferta();
            clear_text();
        });

    QObject::connect(search_button, &QPushButton::clicked, [&]()
        {
            reload_combo_box();
            hide_buttons();
            search_oferta();
            clear_text();
        });

    QObject::connect(filter_button, &QPushButton::clicked, [&]()
        {
            hide_buttons();
            filter_oferte();
        });

    QObject::connect(sort_button, &QPushButton::clicked, [&]()
        {
            hide_buttons();
            sort_oferte();
        });

    QObject::connect(raport_button, &QPushButton::clicked, [&]()
    {
        hide_buttons();
        raport_oferta();
    });

    QObject::connect(wishlist_button, &QPushButton::clicked, [&]()
    {
        hide_buttons();
        wishlist();
    });

    QObject::connect(undo_button, &QPushButton::clicked, [&]()
    {
        hide_buttons();
        undo();
    });

    QObject::connect(exit, &QPushButton::clicked, [&]()
        {
            //qDebug() << "am iesit";
            QMessageBox::information(nullptr, "Info", "Va mai asteptam! La revedere!");
            close();
        });

    QObject::connect(command_add, &QPushButton::clicked, [&](){

        auto denumire = text_denumire->text();
        auto destinatie = text_destinatie->text();
        auto tip = text_tip->text();
        auto pret = text_pret->text();

        try {
            service.add_oferta(denumire.toStdString(), destinatie.toStdString(), tip.toStdString(), pret.toStdString());
            reload_list(service.get_all());
            QMessageBox::information(nullptr, "Info", "Adaugarea a fost efectuata cu succes!");
        }
        catch (RepoException& exception) {
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }
        catch (OfertaException& exception) {
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }

        label_denumire->setVisible(false);
        label_destinatie->setVisible(false);
        label_tip->setVisible(false);
        label_pret->setVisible(false);

        text_denumire->setVisible(false);
        text_destinatie->setVisible(false);
        text_tip->setVisible(false);
        text_pret->setVisible(false);

        command_add->setVisible(false);
    });

    QObject::connect(command_modify, &QPushButton::clicked, [&]() {

        auto denumire_veche = text_denumire_veche->currentText();

        try {
            Oferta oferta = this->service.search_oferta(denumire_veche.toStdString());
            if (oferta.get_denumire().empty())
                QMessageBox::information(nullptr, "Info", "Oferta nu exista!");
            else {
                auto denumire = text_denumire->text();
                auto destinatie = text_destinatie->text();
                auto tip = text_tip->text();
                auto pret = text_pret->text();

                this->service.modify_oferta(denumire_veche.toStdString(), denumire.toStdString(), destinatie.toStdString(),
                                            tip.toStdString(), pret.toStdString());

                reload_list(service.get_all());
                QMessageBox::information(nullptr, "Info", "Modificarea a fost efectuata cu succes!");
            }
        }
        catch (RepoException &exception) {
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }
        catch (OfertaException &exception) {
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }

        label_denumire_veche->setVisible(false);
        label_denumire->setVisible(false);
        label_destinatie->setVisible(false);
        label_tip->setVisible(false);
        label_pret->setVisible(false);

        text_denumire_veche->setVisible(false);
        text_denumire->setVisible(false);
        text_destinatie->setVisible(false);
        text_tip->setVisible(false);
        text_pret->setVisible(false);

        command_modify->setVisible(false);

    });

    QObject::connect(command_delete, &QPushButton::clicked, [&]() {

        auto denumire = text_denumire_veche->currentText();
        if (denumire.length() == 0)
            QMessageBox::information(nullptr, "Info", "Nu ati introdus denumirea!");
        else {
            Oferta oferta = this->service.search_oferta(denumire.toStdString());
            if (oferta.get_denumire().empty())
                QMessageBox::information(nullptr, "Info", "Oferta nu exista!");
            else {

                this->service.delete_oferta(denumire.toStdString());
                reload_list(service.get_all());
                QMessageBox::information(nullptr, "Info", "Stergerea s-a efectuat cu succes!");
            }
        }
        label_denumire->setVisible(false);
        text_denumire_veche->setVisible(false);
        command_delete->setVisible(false);
    });

    QObject::connect(command_search, &QPushButton::clicked, [&]() {

        auto denumire = text_denumire_veche->currentText();

        try {
            Oferta oferta = this->service.search_oferta(denumire.toStdString());
            if (oferta.get_denumire().empty()) {
                QMessageBox::information(nullptr, "Info", "Oferta cautata nu a fost gasita!");
            } else {
                string s = oferta.get_denumire() + " " + oferta.get_destinatie() + " " + oferta.get_tip() + " " +
                           std::to_string(oferta.get_pret());
                QMessageBox::information(nullptr, "Oferta cautata este: ", QString::fromStdString(s));
            }
        }
        catch (OfertaException &exception) {
            QMessageBox::information(nullptr, "Info", QString::fromStdString(exception.get_message()));
        }

        label_denumire->setVisible(false);
        text_denumire_veche->setVisible(false);
        command_search->setVisible(false);
    });
}


void GUI::clear_text()
{
    //text_denumire_veche->clear();
    text_denumire->clear();
    text_destinatie->clear();
    text_tip->clear();
    text_pret->clear();
}


GUI::GUI(const Service& srv) : service(srv)
{
    init_gui();
    reload_list(service.get_all());
    connect_signal_slots();
}

void GUI::add_oferta() {

    label_denumire->setVisible(true);
    label_destinatie->setVisible(true);
    label_tip->setVisible(true);
    label_pret->setVisible(true);

    text_denumire->setVisible(true);
    text_destinatie->setVisible(true);
    text_tip->setVisible(true);
    text_pret->setVisible(true);

    command_add->setVisible(true);
}

void GUI::modify_oferta() {

    label_denumire_veche->setVisible(true);
    label_denumire->setVisible(true);
    label_destinatie->setVisible(true);
    label_tip->setVisible(true);
    label_pret->setVisible(true);

    text_denumire_veche->setVisible(true);
    text_denumire->setVisible(true);
    text_destinatie->setVisible(true);
    text_tip->setVisible(true);
    text_pret->setVisible(true);

    command_modify->setVisible(true);
}

void GUI::delete_oferta() {

    //label_denumire->setVisible(true);
    text_denumire_veche->setVisible(true);
    command_delete->setVisible(true);
}

void GUI::search_oferta() {

    //label_denumire->setVisible(true);
    text_denumire_veche->setVisible(true);
    command_search->setVisible(true);
}

void GUI::filter_oferte() {

    string filter, conditie, pret, secventa;

    auto window = new QWidget;
    window->setWindowTitle("Filtre");
    QHBoxLayout* layout = new QHBoxLayout();
    window->setLayout(layout);
    QPushButton* revine = new QPushButton("Reveniti la lista initiala");
    QPushButton* destinatie = new QPushButton("Filtru dupa destinatie");
    QPushButton* pret_minim = new QPushButton("Filtru dupa pret - pret minim");
    QPushButton* pret_maxim = new QPushButton("Filtru dupa pret - pret maxim");

    revine->setStyleSheet("background-color:darkCyan;");
    destinatie->setStyleSheet("background-color:darkCyan;");
    pret_minim->setStyleSheet("background-color:darkCyan;");
    pret_maxim->setStyleSheet("background-color:darkCyan;");

    window->setStyleSheet("background-color:lightGray;");
    lista->setStyleSheet("background-color:white;");
    text->setStyleSheet("background-color:white;");

    layout->addWidget(destinatie);
    layout->addWidget(pret_minim);
    layout->addWidget(pret_maxim);
    layout->addWidget(revine);
    QLabel* label = new QLabel("Conditie pentru filtrare");
    layout->addWidget(label);
    layout->addWidget(text);
    window->show();
	
	
    QObject::connect(destinatie, &QPushButton::clicked, [&]()
        {
            auto secventa = text->text();
    		if(secventa.toStdString().length() > 0)
				reload_list(service.filter_oferta(filtru_destinatie, secventa.toStdString()));
            else
                QMessageBox::information(nullptr, "Info", "Secventa nu a fost introdusa corecta");
            text->clear();
        });

    QObject::connect(pret_minim, &QPushButton::clicked, [&]()
        {
            bool da = true;
            auto pret = text->text();
            const int x = pret.length();
            if(x == 0){
                QMessageBox::information(nullptr, "Info", "Pretul nu a fost introdus corect!");
                da = false;
            }
            else {
                for (int i = 0; i < x; i++)
                    if (!isdigit(pret.toStdString().at(i))) {
                        QMessageBox::information(nullptr, "Info", "Pretul nu a fost introdus corect!");
                        da = false;
                        break;
                    }
            }
    		if(da)
				reload_list(service.filter_oferta(filtru_pret_mai_mare, pret.toStdString()));
            text->clear();
        });

    QObject::connect(pret_maxim, &QPushButton::clicked, [&]()
        {
            bool da = true;
            auto pret = text->text();
            const int x = pret.length();
            if(x == 0){
                QMessageBox::information(nullptr, "Info", "Pretul nu a fost introdus corect!");
                da = false;
            }
            else {
                for (int i = 0; i < x; i++)
                    if (!isdigit(pret.toStdString().at(i))) {
                        QMessageBox::information(nullptr, "Info", "Pretul nu a fost introdus corect!");
                        da = false;
                        break;
                    }
            }
            if (da)
				reload_list(service.filter_oferta(filtru_pret_mai_mic, pret.toStdString()));
            text->clear();
        });

    QObject::connect(revine, &QPushButton::clicked, [&]()
        {
            reload_list(service.get_all());
        });
    
}


void GUI::sort_oferte() {

    auto window = new QWidget;
    window->setWindowTitle("Sortari");
    QWidget* meniu = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout();
    meniu->setLayout(layout);
    QPushButton* revine = new QPushButton("Reveniti la lista initiala");
    QPushButton* den_cresc = new QPushButton("Dupa denumire - crescator");
    QPushButton* den_descresc = new QPushButton("Dupa denumire - descrescator");
    QPushButton* dest_cresc = new QPushButton("Dupa destinatie - crescator");
    QPushButton* dest_descresc = new QPushButton("Dupa destinatie - descrescator");
    QPushButton* tip_cresc = new QPushButton("Dupa tip + pret - crescator");
    QPushButton* tip_descresc = new QPushButton("Dupa tip + pret - descrescator");

    revine->setStyleSheet("background-color:darkCyan;");
    den_cresc->setStyleSheet("background-color:darkCyan;");
    den_descresc->setStyleSheet("background-color:darkCyan;");
    dest_cresc->setStyleSheet("background-color:darkCyan;");
    dest_descresc->setStyleSheet("background-color:darkCyan;");
    tip_cresc->setStyleSheet("background-color:darkCyan;");
    tip_descresc->setStyleSheet("background-color:darkCyan;");


    layout->addWidget(den_cresc);
    layout->addWidget(den_descresc);
    layout->addWidget(dest_cresc);
    layout->addWidget(dest_descresc);
    layout->addWidget(tip_cresc);
    layout->addWidget(tip_descresc);
    layout->addWidget(revine);
    QHBoxLayout* l2 = new QHBoxLayout;
    window->setLayout(l2);

    window->setStyleSheet("background-color:lightGray;");
    lista->setStyleSheet("background-color:white;");

    l2->addWidget(meniu);
    l2->addWidget(lista);
    lista->clear();
    window->show();
   

    QObject::connect(den_cresc, &QPushButton::clicked, [&]()
        {
            reload_list(service.sort_oferta(compare_denumire_increasing));
            lista->clear();
    		for(const Oferta& oferta: service.sort_oferta(compare_denumire_increasing))
    		{
                lista->addItem(QString::fromStdString(oferta.get_denumire()));
    		}
        });

    QObject::connect(den_descresc, &QPushButton::clicked, [&]()
        {
            reload_list(service.sort_oferta(compare_denumire_decreasing));
            lista->clear();
    		for (const Oferta& oferta : service.sort_oferta(compare_denumire_decreasing))
            {
                lista->addItem(QString::fromStdString(oferta.get_denumire()));
            }
        });

    QObject::connect(dest_cresc, &QPushButton::clicked, [&]()
        {
            reload_list(service.sort_oferta(compare_destinatie_increasing));
            lista->clear();
            for (const Oferta& oferta : service.sort_oferta(compare_destinatie_increasing))
            {
                lista->addItem(QString::fromStdString(oferta.get_denumire()));
            }
        });

    QObject::connect(dest_descresc, &QPushButton::clicked, [&]()
        {
            reload_list(service.sort_oferta(compare_destinatie_decreasing));
            lista->clear();
            for (const Oferta& oferta : service.sort_oferta(compare_destinatie_decreasing))
            {
                lista->addItem(QString::fromStdString(oferta.get_denumire()));
            }
        });

    QObject::connect(tip_cresc, &QPushButton::clicked, [&]()
        {
            reload_list(service.sort_oferta(compare_tip_increasing));
            lista->clear();
            for (const Oferta& oferta : service.sort_oferta(compare_tip_increasing))
            {
                lista->addItem(QString::fromStdString(oferta.get_denumire()));
            }
        });

    QObject::connect(tip_descresc, &QPushButton::clicked, [&]()
        {
            reload_list(service.sort_oferta(compare_tip_decreasing));
            lista->clear();
            for (const Oferta& oferta : service.sort_oferta(compare_tip_decreasing))
            {
                lista->addItem(QString::fromStdString(oferta.get_denumire()));
            }
        });

    QObject::connect(revine, &QPushButton::clicked, [&]()
        {
            reload_list(service.get_all());
        });

}

void GUI::raport_oferta() {

    QWidget* window = new QWidget;
    window->setWindowTitle("Raport");
    QVBoxLayout* layout = new QVBoxLayout();
    window->setLayout(layout);
    layout->addWidget(lista);

    window->show();

    lista->clear();
    for(const auto& elements: service.raport_oferta())
    {
        string elem = "";
        if(elements.second == 1)
            elem = elements.first + ": o oferta";
        else
            elem = elements.first + ": " + to_string(elements.second) + " oferte";
        lista->addItem(QString::fromStdString(elem));
    }
    lista->item(0)->setBackground(QBrush{ Qt::red, Qt::SolidPattern});

}

void GUI::undo(){
    try{
        service.undo();
        QMessageBox::information(nullptr, "Info", "Undo-ul a fost efectuat!");
    }
    catch (UndoException& error){
        QMessageBox::information(nullptr, "Info", QString::fromStdString(error.get_message()));
    }

    reload_list(service.get_all());
}

void GUI::wishlist() {

    auto wishlist = new WishlistGUI(service);
    auto wishlist_read_only = new WishlistReadOnlyGUI(service);
    wishlist->show();
    wishlist_read_only->show();

}

void GUI::hide_buttons() {

    label_denumire_veche->setVisible(false);
    label_denumire->setVisible(false);
    label_destinatie->setVisible(false);
    label_tip->setVisible(false);
    label_pret->setVisible(false);

    text_denumire_veche->setVisible(false);
    text_denumire->setVisible(false);
    text_destinatie->setVisible(false);
    text_tip->setVisible(false);
    text_pret->setVisible(false);

    command_add->setVisible(false);
    command_search->setVisible(false);
    command_modify->setVisible(false);
    command_delete->setVisible(false);
}












