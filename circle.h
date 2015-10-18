#ifndef CIRCLE_H
#define CIRCLE_H

#include "qtdraw.h"
class Circle : public Qtdraw {

    Q_OBJECT
    
    struct circDat { //No easy holder like QLine so I made my own data container
        int rx;
	int ry;
	QPoint center, left, right, top, bottom;
    };

    public:
	Circle(QWidget * parent);
	void setPressed(bool, QPoint);
	QString getSnap(QPoint);
	void abort();
    protected:
	QPixmap render(QPainter *, QPixmap);
	void onMoveRen(QPoint);
	QList<circDat> circles;
	int counter;
};

#endif
