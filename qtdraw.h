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
        Qtdraw();
        bool isRendered();
	virtual void setPressed(bool, QPoint) = 0;
	void onMove(QPoint, bool );
	int onSnap(QPoint );
	virtual QPoint getCenter() = 0;
	virtual QString getSnap(QPoint ) = 0;
	virtual void abort() = 0;
	void bSnap(QPainter *, QPoint);
        QPixmap trigRen(QPainter *, QPixmap);
    protected:
        virtual QPixmap render(QPainter *, QPixmap) = 0;
	virtual void onMoveRen(QPoint) = 0;
        static QList <QPoint> snaps;
	bool rendered, clicked;
	int blueSnap;
	QPoint gridSnap;
    public slots:
        void trigSnap(QPainter *);

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
