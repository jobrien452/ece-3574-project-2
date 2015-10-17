#ifndef QTDRAW_H
#define QTDRAW_H

#include <QObject>
#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QMap>
#include <QList>
#include <QString>
#include <QPixmap>
//#include "snap.h"

class Qtdraw : public QObject {

    Q_OBJECT

    public:
        Qtdraw(QWidget * parent);
        //bool isRendered();
	virtual void setPressed(QPoint ) = 0;
	void onMove(QPoint );
	bool onSnap(QPoint );
	virtual QString getSnap(QPoint ) = 0;
	virtual void abort() = 0;
	void bSnap(QPaint *, QPixmap, QPoint);
    protected:
        virtual void render(QPainter *, QPixmap) = 0;
	virtual void onMoveRen(QPoint ) = 0;
        static QList <QPoint> snaps;
	bool rendered;
        QWidget * parent;
//	QMouseEvent * currente;
    private:
	static QPixmap mpSnap;
    public slots:
        void trigRen(QPainter *, QPixmap);
        void trigSnap(bool, QPainter *, QPixmap);

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
