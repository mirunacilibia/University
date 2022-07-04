//
// Created by Miruna on 3/23/2021.
//

#include "Domain.h"
#include "Repository.h"
#include "Service.h"
#include "Validators.h"
#include "Filters.h"
#include "Compare.h"
#include "DynamicArray.h"
#include "Iterator.h"
#include <assert.h>
#include <fstream>

void test_dynamic_array(){
    DynamicArray<Oferta> vector;
    Oferta oferta = Oferta("vacanta", "romania", "vacanta", 500);
    Oferta oferta2 = Oferta("excursie", "romania", "vacanta", 500);
    Oferta oferta3 = Oferta("oferta", "romania", "vacanta", 500);
    vector.add(oferta);
    vector.add(oferta2);
    vector.add(oferta3);
    DynamicArray<Oferta> vector2;
    vector2 = vector;
    assert(vector2.len() == 3);
    assert(vector.len() == 3);
    assert(vector.get(0).get_denumire() == "vacanta");
    vector.del(0);
    assert(vector.len() == 2);
    vector.set(oferta, 0);
    assert(vector.get(0).get_denumire() == "vacanta");

}

void test_iterator(){
    DynamicArray<Oferta> vector;
    Oferta oferta = Oferta("vacanta", "romania", "vacanta", 500);
    Oferta oferta2 = Oferta("excursie", "romania", "vacanta", 500);
    Oferta oferta3 = Oferta("oferta", "romania", "vacanta", 500);
    Oferta oferta4 = Oferta("cadou", "romania", "vacanta", 500);
    vector.add(oferta);
    vector.add(oferta2);
    vector.add(oferta3);
    vector.add(oferta4);
    int nr = 0;
    Iterator<Oferta> iterator = Iterator<Oferta>(vector);
    while(iterator.valid()){
        assert(iterator.element().get_tip() == "vacanta");
        iterator.next();
        nr++;
    }
    assert(nr == 4);
}

void test_create_oferta(){

    Oferta oferta = Oferta("vacanta", "romania", "vacanta", 500);

    assert(oferta.get_denumire() ==  "vacanta");
    assert(oferta.get_destinatie() == "romania");
    assert(oferta.get_tip() == "vacanta");
    assert(oferta.get_pret() == 500);

    Oferta oferta1 = Oferta();

    assert(oferta1.get_denumire().empty());
    assert(oferta1.get_destinatie().empty());
    assert(oferta1.get_tip().empty());
    assert(oferta1.get_pret() == 0);

    Oferta oferta2 = Oferta(oferta1);

    assert(oferta2.get_denumire().empty());
    assert(oferta2.get_destinatie().empty());
    assert(oferta2.get_tip().empty());
    assert(oferta2.get_pret() == 0);

    oferta2.set_denumire("ceva");
    oferta2.set_destinatie("ceva");
    oferta2.set_tip("ceva");
    oferta2.set_pret(100);

    assert(oferta2.get_denumire() == "ceva");
    assert(oferta2.get_destinatie() == "ceva");
    assert(oferta2.get_tip() == "ceva");
    assert(oferta2.get_pret() == 100);
}

void test_add(){

    Repository repo1;
    Service srv1{repo1};

    srv1.add_oferta("vacanta de vara", "austria", "city break", "1000");
    auto vector = srv1.get_all();
    assert(vector.size() == 1);
    assert(vector.at(0).get_denumire() == "vacanta de vara");
    assert(vector.at(0).get_destinatie() == "austria");
    assert(vector.at(0).get_tip() == "city break");
    assert(vector.at(0).get_pret() == 1000);
    try{
        srv1.add_oferta("vacanta de vara", "austria", "city break", "1000");
        assert(false);
    }
    catch (RepoException &error){
        assert(true);
    }
    try{
        srv1.add_oferta("", "", "", "stnt");
        assert(false);
    }
    catch (OfertaException &error){
        assert(true);
    }
}

void test_modify(){
    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("vacanta de vara", "austria", "city break", "1000");
    srv.add_oferta("excursie", "romania", "excursie", "350");

    srv.modify_oferta("vacanta de vara", "ceva", "ceva", "ceva", "400");
    auto vector = srv.get_all();
    assert(vector.at(0).get_denumire() == "ceva");
    assert(vector.at(0).get_destinatie() == "ceva");
    assert(vector.at(0).get_tip() == "ceva");
    assert(vector.at(0).get_pret() == 400);

    try{
        srv.modify_oferta("vacanta de vara", "excursie", "ceva", "ceva", "400");
        assert(false);
    }
    catch (RepoException &error){
        assert(true);
    }

    try{
        srv.modify_oferta("excursie", "", "", "", "stnt");
        assert(false);
    }
    catch (OfertaException &error){
        assert(true);
    }

    try{
        srv.modify_oferta("oferta", "oferta", "ceva", "ceva", "400");
        assert(false);
    }
    catch (RepoException &error){
        assert(true);
    }

}

void test_delete(){

    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("vacanta de vara", "austria", "city break", "1000");
    srv.add_oferta("excursie", "romania", "excursie", "350");

    srv.delete_oferta("excursie");
    auto vector = srv.get_all();
    assert(vector.size() == 1);
    srv.delete_oferta("vacanta de vara");
    vector = srv.get_all();
    assert(vector.empty());
    try{
        srv.delete_oferta("");
        assert(false);
    }
    catch (OfertaException &error){
        assert(true);
    }
    try{
        srv.delete_oferta("ceva");
        assert(false);
    }
    catch (RepoException &error){
        assert(true);
    }
}

void test_search(){

    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("vacanta de vara", "austria", "city break", "1000");

    Oferta oferta = srv.search_oferta("vacanta de vara");
    assert(oferta.get_destinatie() == "austria");
    oferta = srv.search_oferta("ceva");
    assert(oferta.get_destinatie().empty());
    try{
        oferta = srv.search_oferta("");
        assert(false);
    }
    catch (OfertaException &error){
        assert(true);
    }
}

void test_filter(){

    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("vacanta de vara", "austria", "city break", "1000");
    srv.add_oferta("excursie", "romania", "excursie", "350");
    srv.add_oferta("oferta", "ungaria", "vacanta", "450");

    vector<Oferta> lista = srv.filter_oferta(filtru_pret_mai_mic, "500");
    assert(srv.filter_oferta(filtru_pret_mai_mic, "500").size() == 2);
    assert(srv.filter_oferta(filtru_pret_mai_mare, "400").size() == 2);
    assert(srv.filter_oferta(filtru_destinatie, "ro").size() == 1);
}

void test_sort(){

    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("oferta", "ungaria", "vacanta", "450");
    srv.add_oferta("vacanta de vara", "austria", "city break", "1000");
    srv.add_oferta("excursie", "romania", "excursie", "350");
    srv.add_oferta("cadou", "germania", "city break", "670");
    srv.add_oferta("deplasare", "germania", "actiune caritabila", "600");


    assert(srv.sort_oferta(compare_denumire_increasing).at(0).get_denumire() == "cadou");
    assert(srv.sort_oferta(compare_denumire_decreasing).at(0).get_denumire() == "vacanta de vara");
    assert(srv.sort_oferta(compare_destinatie_increasing).at(0).get_denumire() == "vacanta de vara");
    assert(srv.sort_oferta(compare_destinatie_decreasing).at(0).get_denumire() == "oferta");
    assert(srv.sort_oferta(compare_tip_increasing).at(0).get_denumire() == "deplasare");
    assert(srv.sort_oferta(compare_tip_decreasing).at(0).get_denumire() == "oferta");

}

void test_validators(){

    RepoException exc = RepoException("mesaj");
    assert(exc.get_message() == "mesaj");

    UndoException undo = UndoException("mesaj");
    assert(undo.get_message() == "mesaj");

    OfertaValidator val = OfertaValidator();
    val.validare("vacanta de vara", "austria", "city break", "1000");
    assert(val.get_message().length() == 0);
    val.validare("", "austria", "city break", "1000");
    assert(val.get_message() == "Denumirea nu a fost introdusa corect!\n");
    val.validare("", "", "city break", "1000");
    assert(val.get_message() == "Denumirea nu a fost introdusa corect!\nDestinatia nu a fost introdusa corect!\n");
    val.validare("vacanta de vara", "austria", "", "1000");
    assert(val.get_message() == "Tipul nu a fost introdus corect!\n");
    val.validare("vacanta de vara", "austria", "city break", "ajbfa");
    assert(val.get_message() == "Pretul nu a fost introdus corect!\n");

    OfertaException ofexc = OfertaException("mesaj");
    assert(ofexc.get_message() == "mesaj");
}

void test_wishlist(){
    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("oferta", "ungaria", "vacanta", "450");
    srv.add_oferta("vacanta de vara", "austria", "city break", "1000");
    srv.add_oferta("excursie", "romania", "excursie", "350");
    srv.add_oferta("cadou", "germania", "city break", "670");
    srv.add_oferta("deplasare", "germania", "actiune caritabila", "600");


    srv.add_wishlist("oferta");
    srv.add_wishlist("cadou");
    try {
        srv.add_wishlist("oferta");
        assert(false);
    }
    catch (RepoException &error){
        assert(true);
    }
    assert(srv.add_wishlist("ceva") == false);

    assert(srv.get_wishlist().size() == 2);
    assert(srv.get_wishlist().at(0).get_denumire() == "oferta");
    assert(srv.get_wishlist().at(1).get_denumire() == "cadou");

    srv.delete_wishlist();
    assert(srv.get_wishlist().empty());

    assert(srv.generate_wishlist(1) == true);
    assert(srv.get_wishlist().size() == 1);
    assert(srv.generate_wishlist(3) == true);
    assert(srv.get_wishlist().size() == 4);
    srv.delete_wishlist();
    assert(srv.generate_wishlist(10) == false);
    assert(srv.get_wishlist().size() == 5);

//    srv.export_wishlist("test", "html");
//    ifstream in(R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.html)");
//    string oferta;
//    int contor = 0;
//    while(!in.eof()){
//        getline(in, oferta);
//        contor++;
//    }
//
//    in.close();
//    assert(contor == 35);
//    string file = R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.html)";
//    char* fisier = new char[file.length() + 1];
//    copy(file.begin(), file.end(), fisier);
//    remove(fisier);
//    delete[] fisier;
//
//    cout << "!\n";
//
//    srv.export_wishlist("test", "cvs");
//    ifstream in1(R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.cvs)");
//    contor = 0;
//    while(!in1.eof()){
//        getline(in1, oferta);
//        contor++;
//    }
//    in1.close();
//
//    cout << "!\n";

//    assert(contor == 6);
//    string file1 = R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.cvs)";
//    char* fisier1 = new char[file1.length() + 1];
//    copy(file1.begin(), file1.end(), fisier1);
//    remove(fisier1);
//    delete[] fisier1;


    srv.delete_oferta("oferta");
    assert(srv.get_wishlist().size() == 4);
    srv.delete_wishlist();
    srv.add_wishlist("cadou");
    srv.modify_oferta("cadou", "ceva", "ceva", "ceva", "200");
    assert(srv.get_wishlist()[0].get_denumire() == "ceva");

}

void test_raport(){

    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("oferta", "ungaria", "vacanta", "450");
    srv.add_oferta("excursie", "romania", "excursie", "350");
    srv.add_oferta("cadou", "germania", "city break", "670");
    srv.add_oferta("deplasare", "germania", "actiune caritabila", "600");

    auto raport = srv.raport_oferta();
    assert(raport["ungaria"] == 1);
    assert(raport["romania"] == 1);
    assert(raport["germania"] == 2);
}

void test_undo(){

    Repository repo;
    Service srv = Service(repo);

    srv.add_oferta("oferta", "ungaria", "vacanta", "450");
    srv.add_oferta("excursie", "romania", "excursie", "350");

    srv.modify_oferta("oferta", "ceva", "ceva", "ceva", "200");
    srv.undo();
    assert(srv.search_oferta("oferta").get_denumire() == "oferta");

    srv.delete_oferta("oferta");
    srv.undo();
    assert(srv.get_all().size() == 2);
    srv.undo();
    assert(srv.get_all().size() == 1);
    srv.undo();
    assert(srv.get_all().empty());
    try{
        srv.undo();
        assert(false);
    }
    catch (UndoException & error){
        assert(true);
    }
}

void test_file_repo(){

    ofstream fout(R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.txt)");
    fout << "oferta romania excursie 800\n";
    fout.close();

    FileRepository repo = FileRepository("test.txt");
    Service srv = Service(repo);

    assert(srv.get_all().size() == 1);
    srv.delete_oferta("oferta");
    string str, str2;
    ifstream fin1(R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.txt)");
    fin1 >> str;

    assert(fin1.eof() == true);
    fin1.close();
    srv.add_oferta("of", "ro", "excursie", "500");
    ifstream fin2(R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.txt)");
    fin2 >> str;
    assert(str == "of");

    fin2.close();
    ifstream fin3(R"(C:\Users\Miruna\Desktop\Facultate\Anul 1\Semestrul 2\OOP\Laborator\untitled\test.txt)");
    srv.modify_oferta("of", "oferta", "romania", "excursie", "800");
    fin3 >> str;
    assert(str == "oferta");
    fin3.close();

}

void test_all(){

    test_create_oferta();
    cout << "final test create\n\n";
    test_add();
    cout << "final test add\n\n";
    test_validators();
    cout << "final test validators\n\n";
    test_search();
    cout << "final test search\n\n";
    test_modify();
    cout << "final test modify\n\n";
    test_delete();
    cout << "final test delete\n\n";
    test_filter();
    cout << "final test filter\n\n";
    test_sort();
    cout << "final test sort\n\n";
    test_dynamic_array();
    cout << "final test array\n\n";
    test_iterator();
    cout << "final test iterator\n\n";
    test_wishlist();
    cout << "final test wishlist\n\n";
    test_raport();
    cout << "final test raport\n\n";
    test_undo();
    cout << "final test undo\n\n";
    test_file_repo();
    cout << "final test file repo\n\n";
}
