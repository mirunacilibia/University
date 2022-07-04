//
// Created by Miruna on 3/23/2021.
//

#include "Service.h"
#include "Validators.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <cstdio>

using namespace std;
using std::vector;

Service::Service(Repository &repository) : repository(repository) {
}

void Service::add_oferta(const string & denumire, const string & destinatie, const string & tip, const string & pret_string) {

    OfertaValidator validator{};
    validator.validare(denumire, destinatie, tip, pret_string);
    if(validator.get_message().length() > 0)
        throw OfertaException(validator.get_message());
    const int pret = stoi(pret_string);
    Oferta oferta {denumire, destinatie, tip, pret};
    this->repository.add_oferta(oferta);

    this -> undo_actions.push_back(new UndoAdd{repository, oferta});
}

 const vector<Oferta>& Service::get_all() const noexcept{
    return repository.get_all();
}

 Oferta Service::search_oferta(const string & denumire) {

    OfertaValidator validator;
    validator.validare(denumire, "ceva", "ceva", "100");
    if(validator.get_message().length() > 0)
        throw OfertaException(validator.get_message());

    return this->repository.search_oferta(denumire);
}

void Service::modify_oferta(const string &denumire_veche, const string &denumire, const string &destinatie, const string &tip, const string &pret) {
    OfertaValidator validator;
    validator.validare(denumire, destinatie, tip, pret);
    if(validator.get_message().length() > 0)
        throw OfertaException(validator.get_message());
    const int int_pret = stoi(pret);
    Oferta oferta = search_oferta(denumire_veche);
    this->repository.modify_oferta(denumire_veche, denumire, destinatie, tip, int_pret);
    Oferta of = Oferta(denumire, destinatie, tip, int_pret);
    this->wishlist.update_wishlist_modifiy(denumire_veche, of);

    this->undo_actions.push_back(new UndoModify{repository, oferta, denumire});
}

void Service::delete_oferta(const string &denumire) {

    OfertaValidator validator;
    validator.validare(denumire, "ceva", "ceva", "100");
    if(validator.get_message().length() > 0)
        throw OfertaException(validator.get_message());
    Oferta oferta = search_oferta(denumire);
    this->repository.delete_oferta(denumire);
    this->wishlist.update_wishlist_delete(denumire);

    this -> undo_actions.push_back(new UndoDelete{repository, oferta});
}

vector<Oferta> Service::filter_oferta(Function function, const string& conditie) const {

    vector<Oferta> vector1 = get_all();

    int size = count_if(vector1.begin(), vector1.end(), [conditie, function](const Oferta& of){return function(of, conditie);});
    vector<Oferta> filtered_vector(size);
    copy_if(vector1.begin(), vector1.end(), filtered_vector.begin(), [conditie, function](const Oferta& of){return function(of, conditie);});

    return filtered_vector;
}

vector<Oferta> Service::sort_oferta(Sort_function function) const{

    vector<Oferta> sorted_vector = get_all();
    sort(sorted_vector.begin(), sorted_vector.end(), function);

    return sorted_vector;
}

std::map<string, int> Service::raport_oferta() const {

    map<string, int> raport;
    for(const Oferta& oferta: get_all()){
        if(raport.find(oferta.get_destinatie()) == raport.end()){
            raport.insert(pair<string, int>(oferta.get_destinatie(), 1));
        }
        else{
            raport[oferta.get_destinatie()]++;
        }
    }
    return raport;
}

void Service::undo(){
    if(undo_actions.empty())
        throw UndoException("\nNu mai puteti efectua undo!\n");
    ActiuneUndo* action = undo_actions.back();
    action -> do_undo();
    undo_actions.pop_back();
    delete action;
}

bool Service::add_wishlist(const string& denumire){

    Oferta oferta = this->search_oferta(denumire);
    if(!oferta.get_denumire().empty()) {
        //repository.add_wishlist(oferta);
        wishlist.add_oferta(oferta);
        return true;
    }
    return false;
}

void Service::delete_wishlist(){
    //repository.delete_wishlist();
    wishlist.clear_wishlist();
}

bool Service::generate_wishlist(int numar){

    string denumire;
    int size = get_all().size();
    mt19937 mt{random_device{}()};
    uniform_int_distribution<> dist(0, size - 1);

    while (numar > 0) {
        //if(repository.get_wishlist().size() == size){
        if(wishlist.get_wishlist().size() == size){
            return false;
        }
        int random = dist(mt);
        denumire = get_all().at(random).get_denumire();
        try {
            add_wishlist(denumire);
            numar--;
        }
        catch (RepoException & error){
        }
    }
    return true;
}

const vector<Oferta> &Service::get_wishlist() {
    //return repository.get_wishlist();
    return wishlist.get_wishlist();
}

void Service::export_wishlist(const string& file, const string& type) {

    if(type == "cvs")
        wishlist.export_wishlist_cvs(file);
    else
        wishlist.export_wishlist_html(file);

}

Service::~Service() {

//    for(const string& file: export_list){
//        char* fisier = new char[file.length() + 1];
//        copy(file.begin(), file.end(), fisier);
//        remove(fisier);
//        delete[] fisier;
//    }

    /*for(int i = 0; i < undo_actions.size(); i++){
        delete undo_actions[i];
    }*/
}



