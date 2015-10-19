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

void Qtdraw :: onMove(QPoint p, bool x){
    if(x){
        onMoveRen(p);
    }
    else{
        blueSnap = onSnap(p);
    }
}

int Qtdraw :: onSnap(QPoint p){
    for(int i = 0; i< snaps.size(); ++i){
	if(((p.x()-7) < snaps[i].x() && snaps[i].x() < (p.x()+7)) && ((p.y()-7) < snaps[i].y()&& snaps[i].y() < (p.y()+7))){
//		qDebug() << p;
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
	   bSnap(p, snaps[i]);  
       }
       else{
           p->drawEllipse(snaps[i], 4, 4);
       }
   }
   if(clicked){
      bSnap(p, gridSnap);
   }
}

void Qtdraw :: bSnap(QPainter * p, QPoint bs){
  
    p->setBrush(Qt::darkGray);
    p->drawEllipse(bs, 6, 6);
    p->setBrush(Qt::blue);
    p->drawEllipse(bs, 4, 4);
    p->setBrush(Qt::yellow); 
}
