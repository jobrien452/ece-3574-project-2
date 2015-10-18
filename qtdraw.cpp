#include "qtdraw.h"
#include <QDebug>
QList<QPoint> Qtdraw::snaps = QList<QPoint>() << QPoint(500,500);

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
    blueSnap = -1;
}

bool Qtdraw :: isRendered(){
    return rendered;
}

void Qtdraw :: onMove(QPoint p){
    
    onMoveRen(p);
}

int Qtdraw :: onSnap(QPoint p){
    for(int i = 0; i< snaps.size(); ++i){
	if(((p.x()-7) < snaps[i].x() && snaps[i].x() < (p.x()+7)) && ((p.y()-7) < snaps[i].y()&& snaps[i].y() < (p.y()+7))){
		qDebug() << p;
		return i;
        } 
    }
    return -1; 
}

QPixmap Qtdraw :: trigRen(QPainter * p, QPixmap b){
   // trigSnap(false, p, mp);
   return render(p,b);
}

void Qtdraw :: trigSnap(QPainter * p){
   //p->drawPixmap(0,0, mpSnap);
   p->setBrush(Qt::yellow); 
   for(int i = 0; i < snaps.size(); i++){
       if(blueSnap == i){
	   p->setBrush(Qt::darkGray);
	   p->drawEllipse(snaps[i],10,10);
	   p->setBrush(Qt::blue);
	   p->drawEllipse(snaps[i],7,7);
           p->setBrush(Qt::yellow);   
       }
       else{
           p->drawEllipse(snaps[i], 7, 7);
       }
   }
}

void Qtdraw :: bSnap(QPainter * p, QPoint bs){
  
    p->setBrush(Qt::darkGray);
    p->drawEllipse(bs, 10, 10);
    p->setBrush(Qt::blue);
    p->drawEllipse(bs, 7, 7);
    p->setBrush(Qt::yellow); 
}
