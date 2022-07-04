//
// Created by Miruna on 5/19/2021.
//

#include <QPainter>
#include "Wishlist_Read_Only_GUI.h"

void WishlistReadOnlyGUI::paintEvent(QPaintEvent *ev) {

    QPainter painter{ this };
    for(int i = 0; i < numar_oferte; i++)
        painter.drawRect(50 + 20 * i, 70, 10, 40);
}

void WishlistReadOnlyGUI::init_gui() {

    setStyleSheet("background-color:darkCyan;");
    setWindowTitle("Wishlist");
    setFixedSize(300, 300);
}

