#include "circle.h"
#include <stdlib.h>
#include <math.h>
#include <QDebug>

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
	tempDat.r = 0;
	circles.append(tempDat);
	clicked = true;
    }
    else{
	int b = onSnap(circles[counter].center);
	circDat x = circles[counter];
	if(b == -1){
		snaps.append(tempDat.center);
	}
        //qDebug() << circles[counter].rx << "()" << circles[counter].ry;	
	int ovp = -1;
        x.sides.append(QPoint(x.center.x(), x.center.y()+x.r));
        x.sides.append(QPoint(x.center.x(), x.center.y()-x.r));
        x.sides.append(QPoint(x.center.x()-x.r, x.center.y()));
        x.sides.append(QPoint(x.center.x()+x.r, x.center.y()));
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
	PixmapPainter.drawEllipse(circles[counter-1].center, circles[counter-1].r, circles[counter-1].r);
	p->drawPixmap(0,0,b);
	rendered = false;
    }
    else{
	p -> drawPixmap(0,0,b);
	p -> drawEllipse(circles[counter].center, circles[counter].r, circles[counter].r);
    }
    return b;
}

void Circle :: onMoveRen(QPoint p){
    int x = p.x() - circles[counter].center.x();
    int y = p.y() - circles[counter].center.y();
    int d =(int) sqrt(pow((double)x,2)+pow((double)y,2));
    circles[counter].r = d;
    blueSnap = onSnap(p);
}

