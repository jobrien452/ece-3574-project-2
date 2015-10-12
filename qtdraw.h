#ifndef QTDRAW_H
#define QTDRAW_H

#include <QObject>
#include <QWidget>
//#include <QList>
#include <QPainter>
//#include "snap.h"

class Qtdraw : public QObject {

    Q_OBJECT

    public:
        Qtdraw(QWidget * parent);
        bool isRendered();
    protected:
        virtual void render();
       // QList<Snap> 
       // renderSnaps();
	bool rendered;
        QWidget * parent;
        QPainter paint;

    public slots:
        void trigRen();

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
