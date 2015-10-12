#ifndef SNAP_H
#define SNAP_H

#include <QWidget>
#include <QObject>
#include <QString>

class Snap : public QWidget {

    public:
        int x,y;
        Qstring locName();
};         
