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
	virtual void setPressed(QPoint &) = 0;
	void onMove(QPoint &);
	QString getType();
	virtual QString getSnap(QPoint &) = 0;
	void abort();
    protected:
        virtual void render(QPainter *) = 0;
	virtual void onMoveRen(QPoint &) = 0;
        static QList <QPoint&> snaps;
	static QPixmap board = QPixmap(400, 400);
	QList <QPoint&> psnaps;
	bool rendered;
        QWidget * parent;
	QString type;
//	QMouseEvent * currente;
    private:
	static QPixmap mpSnap;
    public slots:
        void trigRen(QPainter *);
        void trigSnap(bool, QPainter *);

   /* signals:
        HovSnap();
        ClkSnap();
        ClkCord();*/
};

#endif 
