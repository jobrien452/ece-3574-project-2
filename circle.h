#ifndef CIRCLE_H
#define CIRCLE_H

#include "qtdraw.h"
class Circle : public Qtdraw {

    Q_OBJECT
    
    struct circDat { //No easy holder like QLine so I made my own data container
        int r;
	QPoint center;
	QList<QPoint> sides;
    };
    
    enum side { //used to identify sides for text dispaly
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
    };

    public:
	Circle();
	void setPressed(bool, QPoint);
	QString getSnap(QPoint);
	void abort();
	QPoint getCenter();
    private:
	QList<circDat> circles;
	QList<QPoint> csnaps;
    protected:
	QPixmap render(QPainter *, QPixmap);
	void onMoveRen(QPoint);
};

#endif
