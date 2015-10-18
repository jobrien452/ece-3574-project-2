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
	virtual void setPressed(QPoint ) = 0;
	void onMove(QPoint );
	int onSnap(QPoint );
	virtual QString getSnap(QPoint ) = 0;
	virtual void abort() = 0;
	void bSnap(QPainter *, QPoint);
        QPixmap trigRen(QPainter *);
    protected:
        virtual QPixmap render(QPainter *) = 0;
	virtual void onMoveRen(QPoint ) = 0;
        static QList <QPoint> snaps;
	static QPixmap art;
	static QPixmap smap;
	bool rendered;
        QWidget * parent;
//	QMouseEvent * currente;
    public slots:
        void trigSnap(QPainter *, QPoint);

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
