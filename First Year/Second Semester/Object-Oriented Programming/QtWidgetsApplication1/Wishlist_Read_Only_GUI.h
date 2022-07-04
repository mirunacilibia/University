//
// Created by Miruna on 5/19/2021.
//

#ifndef UNTITLED_WISHLIST_READ_ONLY_GUI_H
#define UNTITLED_WISHLIST_READ_ONLY_GUI_H

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
#include <QPaintEvent>
#include <QPainter>

#include "Service.h"
#include "Observer.h"

class WishlistReadOnlyGUI: public QWidget, public Observer{

private:

    Service& service;
    int numar_oferte;

    void init_gui();

public:

    WishlistReadOnlyGUI(Service& service) : service(service) {
        init_gui();
        service.add_observer(this);
        update();
    }

    void update() override{
        numar_oferte = service.get_wishlist().size();
        repaint();
    }

    ~WishlistReadOnlyGUI(){
        service.remove_observers(this);
    }

    void paintEvent(QPaintEvent* ev) override;
};

#endif //UNTITLED_WISHLIST_READ_ONLY_GUI_H
