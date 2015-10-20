#include "qtdraw.h"
#include <QDebug>
QList<QPoint> Qtdraw::snaps = QList<QPoint>();

Qtdraw :: Qtdraw(){
    rendered = false;
    blueSnap = -1;
}

bool Qtdraw :: isRendered(){
    return rendered;
}

QPoint Qtdraw :: getCenter(){return QPoint(0,0);};

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
	if(((p.x()-4) < snaps[i].x() && snaps[i].x() < (p.x()+4)) && ((p.y()-4) < snaps[i].y()&& snaps[i].y() < (p.y()+4))){
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
