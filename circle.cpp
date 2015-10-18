#include "circle.h"
Circle :: Circle(QWidget * parent)
	:Qtdraw(parent){
	counter = 0;
}

void Circle :: setPressed(bool x, QPoint p){
    circDat tempDat;
    if(x){
	int b = onSnap(p);
	if(b != -1){
	     tempDat.center = snaps[b];
	     blueSnap = b;
	}
	else{
	     tempDat.center = p;
	     blueSnap = -2;
	     gridSnap = p;
	}
	circles.append(tempDat);
    }
    else{
	int b = onSnap(circle[counter].center);
	if(b == -1){
		snaps.append(circle[counter].center);
	}

	  
}

QString Circle :: getSnap(QPoint p){

}

void Circle :: abort(){

}

QPixmap render(QPainter *, QPixmap){

}

void onMoveRen(QPoint){

}

