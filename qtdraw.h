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
        bool isRendered();
	virtual void setPressed(bool, QPoint) = 0;
	void onMove(QPoint );
	int onSnap(QPoint );
	virtual QString getSnap(QPoint ) = 0;
	virtual void abort() = 0;
	void bSnap(QPainter *, QPoint);
        QPixmap trigRen(QPainter *, QPixmap);
    protected:
        virtual QPixmap render(QPainter *, QPixmap) = 0;
	virtual void onMoveRen(QPoint) = 0;
        static QList <QPoint> snaps;
	bool rendered;
        QWidget * parent;
	int blueSnap;
//	QMouseEvent * currente;
    public slots:
        void trigSnap(QPainter *);

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
