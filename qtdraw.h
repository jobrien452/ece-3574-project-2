#ifndef QTDRAW_H
#define QTDRAW_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QMap>
#include <QList>
#include <QString>
//#include "snap.h"

class Qtdraw : public QObject {

    Q_OBJECT

    public:
        Qtdraw(QWidget * parent);
        //bool isRendered();
	virtual QString getType();
    protected:
        virtual void render();
        static QList <QPoint> snaps;
	static QPixmap board = QPixmap(400, 400); 
	QList <QPoint> psnaps;
	bool rendered;
        QWidget * parent;
        QPainter paint;

    public slots:
        void trigRen();
        void dispSnap();

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
