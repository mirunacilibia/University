//
// Created by Miruna on 5/21/2021.
//

#ifndef UNTITLED_MODELVIEW_H
#define UNTITLED_MODELVIEW_H

#include <vector>
#include <QAbstractTableModel>
#include "Domain.h"

class TableModel: public QAbstractTableModel{

    vector<Oferta> oferte;

public:

    TableModel(const vector<Oferta>& of) : oferte(of){
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return oferte.size();
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4;
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override{
        if (role == Qt::DisplayRole) {
            Oferta of = oferte[index.row()];
            if(index.column() == 0)
                return QString::fromStdString(of.get_denumire());
            else if(index.column() == 1)
                return QString::fromStdString(of.get_destinatie());
            else if(index.column() == 2)
                return QString::fromStdString(of.get_tip());
            else if(index.column() == 3)
                return QString::number(of.get_pret());
        }
        return QVariant{};
    }

    void set_oferte(const vector<Oferta>& of){

        beginResetModel();
        this->oferte = of;
        QModelIndex stanga_sus = createIndex(0, 0);
        QModelIndex dreapta_jos = createIndex(rowCount(), columnCount());
        emit dataChanged(stanga_sus, dreapta_jos);
        endResetModel();
    }

};


#endif //UNTITLED_MODELVIEW_H
