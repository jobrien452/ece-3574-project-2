#include "circle.h"
#include <stdlib.h>

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
	     gridSnap = snaps[b];
	}
	else{
	     tempDat.center = p;
	     gridSnap = p;
	}
	tempDat.rx = 0;
	tempDat.ry = 0;
	circles.append(tempDat);
	clicked = true;
    }
    else{
	int b = onSnap(circles[counter].center);
	circDat x = circles[counter];
	if(b == -1){
		snaps.append(tempDat.center);
	}
	
	int ovp = -1;
        x.sides.append(QPoint(tempDat.center.x(), tempDat.center.y()+tempDat.ry));
        x.sides.append(QPoint(tempDat.center.x(), tempDat.center.y()-tempDat.ry));
        x.sides.append(QPoint(tempDat.center.x()-tempDat.rx, tempDat.center.y()));
        x.sides.append(QPoint(tempDat.center.x()+tempDat.rx, tempDat.center.y()));
        for(int i = 0; i < x.sides.size(); ++i){
	    ovp = onSnap(x.sides[i]);
	    if(ovp != -1){
	         x.sides[i]=snaps[ovp];
	    }
	    else{
	         snaps.append(x.sides[i]);
	    }
	}
	circles[counter] = x;
	blueSnap = -1;
	rendered = true;
	counter ++;
	clicked = false;
    }		  
}

QString Circle :: getSnap(QPoint p){
    return "";//just for testing
}

void Circle :: abort(){ //method is similar in all implementations, may consider
    if(counter > 0){  //templates to slim code if time allows
	circles.pop_back();
    }
    else{
	circles.clear();
    }
    blueSnap = -1;
    rendered = false;
    clicked = false;
}

QPixmap Circle :: render(QPainter * p, QPixmap b){
    if(rendered){
	QPainter PixmapPainter(&b);
	PixmapPainter.drawEllipse(circles[counter-1].center, circles[counter-1].rx, circles[counter-1].ry );
	p->drawPixmap(0,0,b);
	rendered = false;
    }
    else{
	p -> drawPixmap(0,0,b);
	p -> drawEllipse(circles[counter-1].center, circles[counter-1].rx, circles[counter-1].ry);
    }
    return b;
}

void Circle :: onMoveRen(QPoint p){
    circles[counter].rx = abs(circles[counter].center.x()- p.x());
    circles[counter].ry = abs(circles[counter].center.y()- p.y());
    blueSnap = onSnap(p);
}

