#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QFormLayout>

#include <QtWidgets/QApplication>

#include "GUI.h"
#include "RepoLab.h"
#include "Tests.h"

int main(int argc, char *argv[])
{
    test_all();

    QApplication a(argc, argv);

    Repository repo = Repository();
    //FileRepository repo = FileRepository("repo.txt");
    //RepoLab repo = RepoLab(0.1);
    Service srv = Service(repo);

    srv.add_oferta("Oferta1", "Austria", "Concediu", "850");
    srv.add_oferta("Oferta2", "Grecia", "Vacanta", "1000");
    srv.add_oferta("Oferta3", "Costinesti", "Vacanta", "600");
    srv.add_oferta("Oferta4", "Sibiu", "City-break", "500");
    srv.add_oferta("Oferta5", "Romania", "Tur", "970");
    srv.add_oferta("Oferta6", "Bucegi", "Excursie", "380");
    srv.add_oferta("Oferta7", "Romania", "Cadou", "760");

    GUI gui(srv);
    gui.show();

    return a.exec();
}
