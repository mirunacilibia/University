//
// Created by Miruna on 3/23/2021.
//
#include <iostream>
#include <iomanip>
#include <random>
#include <map>

using namespace std;
#include "UI.h"
#include "Validators.h"
#include "Filters.h"
#include "Compare.h"

void UI::print_menu() {

    cout << "\n|----Bine ati venit la agentia de turism!----|\n";
    cout << "|                                            |\n";
    cout << "|       -> 1  -   Adaugati o oferta          |\n";
    cout << "|       -> 2  -   Modificati o oferta        |\n";
    cout << "|       -> 3  -   Stergeti o oferta          |\n";
    cout << "|       -> 4  -   Afisati toate ofertele     |\n";
    cout << "|       -> 5  -   Cautati o oferta           |\n";
    cout << "|       -> 6  -   Filtrati ofertele          |\n";
    cout << "|       -> 7  -   Sortati ofertele           |\n";
    cout << "|       -> 8  -   Wishlist                   |\n";
    cout << "|       -> 9  -   Raport oferte              |\n";
    cout << "|       -> 10 -   Undo                       |\n";
    cout << "|       -> 0  -   Parasiti programul         |\n";
    cout << "|                                            |\n";
    cout << "|--------------------------------------------|\n";
    cout << "\nIntroduceti comanda dorita: ";
    

}

void UI::print_oferte(const vector<Oferta>& oferte) {


    cout << "\n---------------- Oferte de vacanta ----------------\n";
    cout << "  Denumire       Destinatie     Tip         Pret    \n";
    cout << "---------------------------------------------------\n";
    //const int x = oferte.size();
    //for (int i = 0; i < x; i++) {
    for(const Oferta& oferta: oferte){
        cout << std::setw(11) << oferta.get_denumire() << std::setw(14) << oferta.get_destinatie()
             << std::setw(14) << oferta.get_tip() << std::setw(8)
             << oferta.get_pret() << "\n";
    }
    cout << "\n";
}

void UI::add_oferta() {

    string denumire, destinatie, tip, pret;

    cout << "\nIntroduceti datele ofertei: ";
    cout << "\nDenumire: ";
    cin >> denumire;
    cout << "\nDestinatie: ";
    cin >> destinatie;
    cout << "\nTip: ";
    cin >> tip;
    cout << "\nPret: ";
    cin >> pret;

    try{
        this->service.add_oferta(denumire, destinatie, tip, pret);
        cout << "\nOperatia s-a efectuat cu succes!\n";
    }
    catch (RepoException & exception){
        cout << exception.get_message();
    }
    catch (OfertaException & exception){
        cout << exception.get_message();
    }
}

void UI::modify_oferta() {

    string denumire_veche, denumire, destinatie, tip, pret;

    cout << "\nIntroduceti denumirea ofertei pe care o cautati: ";
    cin >> denumire_veche;

    try {
        Oferta oferta = this->service.search_oferta(denumire_veche);
        if (oferta.get_denumire().empty())
            cout << "\nOferta nu exista!\n";
        else {
            cout << "\nIntroduceti noile date ale ofertei: ";
            cout << "\nDenumire: ";
            cin >> denumire;
            cout << "\nDestinatie: ";
            cin >> destinatie;
            cout << "\nTip: ";
            cin >> tip;
            cout << "\nPret: ";
            cin >> pret;

            this->service.modify_oferta(denumire_veche, denumire, destinatie, tip, pret);
            cout << "\nOperatia s-a efectuat cu succes!\n";
        }
    }
    catch (OfertaException& exception){
        cout << exception.get_message();
    }
    catch (RepoException & exception){
        cout << exception.get_message();
    }
}

void UI::delete_oferta() {

    string denumire;

    cout << "\nIntroduceti denumirea ofertei pe care doriti sa o stergeti: ";
    cin >> denumire;

    Oferta oferta = this->service.search_oferta(denumire);
    if(oferta.get_denumire().empty())
        cout << "\nOferta nu exista!\n";
    else {

        this->service.delete_oferta(denumire);
        cout << "\nOperatia s-a efectuat cu succes!\n";
    }
}

void UI::search_oferta() {

    string denumire;

    cout << "\nIntroduceti denumirea ofertei pe care doriti sa o cautati: ";
    cin >> denumire;

    try{
        Oferta oferta = this->service.search_oferta(denumire);
        if(oferta.get_denumire().empty()){
            cout << "\nOferta cautata nu a fost gasita!\n";
        }
        else{
            cout << "\nOferta pe care o cautati are urmatoarele detalii:\n";
            cout << "\n  Denumire       Destinatie     Tip         Pret    \n";
            cout << std::setw(11) << oferta.get_denumire() << std::setw(14) << oferta.get_destinatie()
                 << std::setw(14) << oferta.get_tip() << std::setw(8)
                 << oferta.get_pret() << "\n";
        }
    }
    catch (OfertaException& exception){
        cout << exception.get_message();
    }
}

void UI::filter_oferte() {

    string filter, conditie, pret, secventa;

    cout << "\nDupa ce doriti sa filtrati? (destinatie/pret)\n";
    cin >> filter;
    if(filter == "destinatie"){

        cout << "\nIntroduceti secventa cautata: ";
        cin >> secventa;
        print_oferte(service.filter_oferta(filtru_destinatie, secventa));

    } else if(filter == "pret"){

        cout << "\nFiltrati dupa pret minim/maxim: ";
        cin >> conditie;
        cout << "\nIntroduceti pretul: ";
        cin >> pret;
        try{
            const int incercare = stoi(pret);
        }
        catch (...){
            cout << "\nDatele au fost introduse gresit!\n";
            return;
        }

        if(conditie == "maxim")
            print_oferte(service.filter_oferta(filtru_pret_mai_mic, pret));

        else if(conditie == "minim")
            print_oferte(service.filter_oferta(filtru_pret_mai_mare, pret));

        else
            cout << "\nDatele au fost introduse gresit!\n";

    }else
        cout << "\nDatele au fost introduse gresit!\n";

}

void UI::sort_oferte() {

    string filter, order;

    cout << "\nDupa ce doriti sa sortati? (denumire / destinatie / tip_pret)\n";
    cin >> filter;
    cout << "\ncrescator / descrescator?\n";
    cin >> order;

    if(order == "crescator") {

        if (filter == "denumire") {
            print_oferte(service.sort_oferta(compare_denumire_increasing));
        } else if (filter == "destinatie") {
            print_oferte(service.sort_oferta(compare_destinatie_increasing));
        } else if (filter == "tip_pret"){
            print_oferte(service.sort_oferta(compare_tip_increasing));
        } else{
            cout << "\nDatele au fost introduse gresit!\n";
        }

    } else if(order == "descrescator"){

        if (filter == "denumire") {
            print_oferte(service.sort_oferta(compare_denumire_decreasing));
        } else if (filter == "destinatie") {
            print_oferte(service.sort_oferta(compare_destinatie_decreasing));
        } else if (filter == "tip_pret"){
            print_oferte(service.sort_oferta(compare_tip_decreasing));
        } else{
            cout << "\nDatele au fost introduse gresit!\n";
        }

    }else
        cout << "\nDatele au fost introduse gresit!\n";
}

void UI::raport_oferta(){

    map<string, int> raport;
    raport = service.raport_oferta();

    cout << "\nRaport destinatii:\n\n";
    for(const auto& elements: raport){
        if(elements.second == 1)
            cout << elements.first << ": o oferta\n";
        else
            cout << elements.first << ": " << elements.second << " oferte\n";
    }
}

void UI::add_wishlist() {

    string denumire;
    cout << "\nIntroduceti denumirea ofertei: ";
    cin >> denumire;

    try{
        int exista = service.add_wishlist(denumire);
        if(!exista)
            cout << "\nOferta pe care doriti sa o adaugati nu exista!\n";
        else
            cout << "\nOperatia s-a efectuat cu succes!\n";
        cout <<"\nExista " << service.get_wishlist().size() << " oferte in wishlist\n";
    }
    catch (RepoException & exception){
        cout << exception.get_message();
    }
    catch (OfertaException & exception){
        cout << exception.get_message();
    }
}

void UI::delete_wishlist() {
    service.delete_wishlist();
    cout << "\nComanda a fost efectuata!\n";
    cout <<"\nExista " << service.get_wishlist().size() << " oferte in wishlist\n";
}

void UI::generate_wishlist() {

    int numar;

    cout << "\nCate oferte doriti sa adaugati? ";
    cin >> numar;
    bool toate = service.generate_wishlist(numar);
    if(!toate){
        cout << "\nNu se pot adauga toate ofertele dorite!\n";
        cout <<"\nExista " << service.get_wishlist().size() << " oferte in wishlist\n";
    }
    else {
        cout << "\nComanda a fost efectuata cu succes!\n";
        cout <<"\nExista " << service.get_wishlist().size() << " oferte in wishlist\n";
    }
}

void UI::export_wishlist(){

    string file, type;

    cout << "\nIntroduceti numele fisierului in care se salveaza cosul: ";
    cin >> file;
    cout << "\nIntroduceti tipul fisierului in care se salveaza cosul(cvs/html): ";
    cin >> type;

    service.export_wishlist(file, type);

}

void UI::print_wishlist_menu() {

    cout << "\n|--------Meniu Wishlist----------|\n";
    cout << "|                                |\n";
    cout << "|   -> 1  -   Adaugati in cos    |\n";
    cout << "|   -> 2  -   Goleste cosul      |\n";
    cout << "|   -> 3  -   Afisati cosul      |\n";
    cout << "|   -> 4  -   Generati un cos    |\n";
    cout << "|   -> 5  -   Export in fisier   |\n";
    cout << "|   -> 0  -   Meniu principal    |\n";
    cout << "|                                |\n";
    cout << "|--------------------------------|\n";
    cout << "\nIntroduceti comanda dorita: ";
}

void UI::wishlist_menu() {

    int command = 0;
    print_wishlist_menu();
    try{
        cin.exceptions(iostream::failbit);
        cin >> command;
    }
    catch(...){
        cout << "\nDatele introduse nu sunt valide!\n";
    }
    while(command != 0){

        switch(command){
            case 1:
                add_wishlist();
                break;
            case 2:
                delete_wishlist();
                break;
            case 3:
                print_oferte(service.get_wishlist());
                break;
            case 4:
                generate_wishlist();
                break;
            case 5:
                export_wishlist();
                break;
            default:
                cout << "\nComanda nu exista!\n";
                break;
        }
        print_wishlist_menu();
        try{
            cin.exceptions(iostream::failbit);
            cin >> command;
        }
        catch(...){
            cout << "\nDatele introduse nu sunt valide!\n";
        }
    }
}

void UI::undo(){
    try{
        service.undo();
        cout << "\nUndo-ul a fost efectuat!\n";
    }
    catch (UndoException& error){
        cout << error.get_message();
    }
}

void UI::choose_command(int command) {

    switch (command) {
        case 1:
            add_oferta();
            break;
        case 2:
            modify_oferta();
            break;
        case 3:
            delete_oferta();
            break;
        case 4:
            print_oferte(service.get_all());
            break;
        case 5:
            search_oferta();
            break;
        case 6:
            filter_oferte();
            break;
        case 7:
            sort_oferte();
            break;
        case 8:
            wishlist_menu();
            break;
        case 9:
            raport_oferta();
            break;
        case 10:
            undo();
            break;
        default:
            cout << "\nComanda nu exista!\n";
            break;
    }
}

void UI::run() {

    this->add_random();
    int command = 0;
    print_menu();
    try {
        cin.exceptions(iostream::failbit);
        cin >> command;
    }
    catch (...) {
        cout << "\nDatele introduse nu sunt valide!\n";
    }

    while (command != 0) {
        choose_command(command);
        print_menu();
        try {
            cin.exceptions(iostream::failbit);
            cin >> command;
        } catch (...) {
            cout << "\nDatele introduse nu sunt valide!\n";
        }
    }
    cout << "\nAti parasit programul. Va mai asteptam!";
}

void UI::add_random() {
    service.add_oferta("Oferta1", "Austria", "Concediu", "850");
    service.add_oferta("Oferta2", "Grecia", "Vacanta", "1000");
    service.add_oferta("Oferta3", "Costinesti", "Vacanta", "600");
    service.add_oferta("Oferta4", "Sibiu", "City-break", "500");
    service.add_oferta("Oferta5", "Romania", "Tur", "970");
    service.add_oferta("Oferta6", "Bucegi", "Excursie", "380");
    service.add_oferta("Oferta7", "Romania", "Cadou", "760");
}











