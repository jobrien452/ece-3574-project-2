#include "circle.h"
#include <stdlib.h>
#include <math.h>
#include <QDebug>

Circle :: Circle()
	:Qtdraw(){
	rendered = false;
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
	rendered = false;
    }
    else{
	int b = onSnap(circles.last().center);
	circDat x = circles.last();
	if(b == -1){
		snaps.append(x.center);
		csnaps.append(x.center);
	}
        //qDebug() << circles[counter].rx << "()" << circles[counter].ry;	
	int ovp = -1;
        x.sides.append(QPoint(x.center.x(), x.center.y()-x.r));
        x.sides.append(QPoint(x.center.x(), x.center.y()+x.r));
        x.sides.append(QPoint(x.center.x()-x.r, x.center.y()));
        x.sides.append(QPoint(x.center.x()+x.r, x.center.y()));
        for(int i = 0; i < x.sides.size(); ++i){
	    ovp = onSnap(x.sides[i]);
	    if(ovp != -1){
	         x.sides[i]=snaps[ovp];
	    }
	    else{
	         snaps.append(x.sides[i]);
		 csnaps.append(x.sides[i]);
	    }
	}
	circles.last() = x;
	blueSnap = -1;
	rendered = true;
	clicked = false;
    }		  
}

QPoint Circle :: getCenter(){
    if(circles.size() > 0){
	return circles.last().center;
    }
}

QString Circle :: getSnap(QPoint p){
    QString sc = "";
    int side = -1;
    for(int i = 0; i < circles.size(); ++i){
	for(int z = 0; z < 4; z++){
	    if (((p.x()-4) < circles[i].sides[z].x() && circles[i].sides[z].x() < (p.x()+4)) && ((p.y()-4) < circles[i].sides[z].y()&& circles[i].sides[z].y() < (p.y()+4)))
		side = z;
	}
    }
    if(side != -1){
        switch(side){
	    case TOP   : sc = "Circle's Top";    break;
	    case BOTTOM: sc = "Circle's Bottom"; break;
	    case LEFT  : sc = "Circle's Left";   break;
	    case RIGHT : sc = "Circle's Right";  break;
	}
    }

    if(sc.isEmpty()){
	for(int i = 0; i < circles.size(); ++i){
	    if (((p.x()-4) < circles[i].center.x() && circles[i].center.x() < (p.x()+4)) && ((p.y()-4) < circles[i].center.y()&& circles[i].center.y() < (p.y()+4)))
		sc = "Circle's Center";
	}
    }

    if(!sc.isEmpty()){
	for(int i = 0; i < csnaps.size(); ++i){
	    if(((p.x()-4) < csnaps[i].x() && csnaps[i].x() < (p.x()+4)) && ((p.y()-4) < csnaps[i].y()&& csnaps[i].y() < (p.y()+4))){
		return sc;
	    }	
        }
    }
    return "";
}

void Circle :: abort(){ //method is similar in all implementations, may consider
    if(circles.size() > 1){  //templates to slim code if time allows
	circles.pop_back();
    }
    else{
	circles.clear();
    }
    //delete gridSnap;
    blueSnap = -1;
    rendered = false;
    clicked = false;
}

QPixmap Circle :: render(QPainter * p, QPixmap b){
    if(rendered){
//	qDebug() << "Crender";
	QPainter PixmapPainter(&b);
	PixmapPainter.drawEllipse(circles.last().center, circles.last().r, circles.last().r);
	p->drawPixmap(0,0,b);
	rendered = false;
    }
    else{
//	qDebug() << "CDraw";
	p -> drawPixmap(0,0,b);
	p -> drawEllipse(circles.last().center, circles.last().r, circles.last().r);
    }
    return b;
}

void Circle :: onMoveRen(QPoint p){
    int x = p.x() - circles.last().center.x();
    int y = p.y() - circles.last().center.y();
    int d =(int) sqrt(pow((double)x,2)+pow((double)y,2));
    circles.last().r = d;
    blueSnap = onSnap(p);
}

