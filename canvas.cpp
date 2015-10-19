#include "canvas.h"

Canvas :: Canvas(QWidget * parent)
	: Qtdraw(parent){

	rendered = true;
	border = QRect(QPoint(0,0),QPoint(880,620));
}

void setPressed(bool x, QPoint p){} //not a function of canvas

QString getSnap(QPoint p){

}

void abort(){} //not a function of canvas

QPixmap render(QPainter * p, QPixmap b){ //called on load
    cpoints << QPoint(0,0) << QPoint(880, 0) << QPoint(440, 0);
    cpoints << QPoint(0,310) << QPoint(0,620) << QPoint(880,620);
    cpoints << QPoint(440, 310) << QPoint(440,620) << QPoint(880,310);
    for(int i = 0; i<cpoint.size(); ++i){
	snaps.append(cpoints[i]);
    }
}

void onMoveRen(QPoint p){} //not a function of canvas
