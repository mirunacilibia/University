

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
#include <QtWidgets/QComboBox>

#include "Service.h"
#include "ModelView.h"

class GUI: public QWidget {

private:

    Service service;
    QPushButton* add_button = new QPushButton("Adauga oferta");
    QPushButton* modify_button = new QPushButton("Modifica oferta");
    QPushButton* delete_button = new QPushButton("Sterge oferta");
    QPushButton* search_button = new QPushButton("Cauta oferta");
    QPushButton* filter_button = new QPushButton("Filtreaza oferte");
    QPushButton* sort_button = new QPushButton("Sorteaza ofertele");
    QPushButton* raport_button = new QPushButton("Raport");
    QPushButton* wishlist_button = new QPushButton("Wishlist");
    QPushButton* undo_button = new QPushButton("Undo");
    QPushButton* exit = new QPushButton("Iesire");

    QPushButton* command_add = new QPushButton("Acceseaza comanda de adaugare");
    QPushButton* command_modify = new QPushButton("Acceseaza comanda de modificare");
    QPushButton* command_search = new QPushButton("Acceseaza comanda de cautare");
    QPushButton* command_delete = new QPushButton("Acceseaza comanda de stergere");

    QComboBox* text_denumire_veche = new QComboBox;
    QLineEdit* text_denumire = new QLineEdit;
    QLineEdit* text_destinatie = new QLineEdit;
    QLineEdit* text_tip = new QLineEdit;
    QLineEdit* text_pret = new QLineEdit;
    QLineEdit* text = new QLineEdit;

    QLabel* label_denumire_veche = new QLabel("Denumirea ofertei modificate: ");
    QLabel* label_denumire = new QLabel("Denumire: ");
    QLabel* label_destinatie = new QLabel("Destinatie: ");
    QLabel* label_tip = new QLabel("Tip: ");
    QLabel* label_pret = new QLabel("Pret: ");

    QWidget* date = new QWidget;
    QListWidget* lista = new QListWidget;
    //QTableWidget* oferte = new QTableWidget(this);
    QTableView* oferte = new QTableView;
    TableModel* model = new TableModel(service.get_all());


    void init_gui();

    void reload_combo_box();
	
    void reload_list(const vector<Oferta>&);

    void connect_signal_slots();

    void hide_buttons();

    void clear_text();

public:

    GUI(const Service& srv);


    /*Functie care adauga o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca adaugarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void add_oferta();

    /*Functie care modifica o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca modificarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void modify_oferta();

    /*Functie care sterge o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca stergerea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * prinde exceptia daca oferta nu exista
     * */
    void delete_oferta();

    /*Functie care cauta o oferta
     * input:   - se citesc datele
     * output:  - se afiseaza daca cautarea a fost facuta cu succes sau nu
     * prinde exceptia daca datele nu sunt valide
     * */
    void search_oferta();


    /*Functie care filtreaza ofertele
     * input:   - se citesc datele
     * output:  - se afiseaza lista de oferte filtrata
     * */
    void filter_oferte();


    /*Functie care sorteaza ofertele
     * input:   - se citesc datele
     * output:  - se afiseaza lista de oferte sortata
     * */
    void sort_oferte();

    /*Functie care afiseaza raportul
     * input:   -
     * output:  - se afiseaza raportul pentru destinatii
     * */
    void raport_oferta();

    void wishlist();

    void undo();

};