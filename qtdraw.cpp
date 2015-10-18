#include "qtdraw.h"
#include <QDebug>
QList<QPoint> Qtdraw::snaps = QList<QPoint>() << QPoint(200,200);
QPixmap art = QPixmap(1000,1000);
QPixmap smap = QPixmap(1000,1000);

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
}

bool Qtdraw :: isRendered(){
    return rendered;
}

void Qtdraw :: onMove(QPoint p){
    
    onMoveRen(p);
}

int Qtdraw :: onSnap(QPoint p){
    for(int i = 0; i< snaps.size(); ++i){
	if(((p.x()-7) < snaps[i].x() < (p.x()+7)) && ((p.y()-7) < snaps[i].y() < (p.y()+7))){
		qDebug() << snaps[i];
		return i;
        } 
    }
    return -1; 
}

QPixmap Qtdraw :: trigRen(QPainter * p){
   // trigSnap(false, p, mp);
   return render(p, mp);
}

void Qtdraw :: trigSnap(bool x, QPainter * p, QPoint bs){
    if(x){
	QPainter PixmapPainter(
        int b = onSnap(bs);
        //p->drawPixmap(0,0, mpSnap);
        p->setBrush(Qt::yellow);
        for(int i = 0; i < snaps.size(); i++){
            if(b == i){
                bSnap(p, snaps[i]);
	        p->setBrush(Qt::yellow);   
            }
            else{
                p->drawEllipse(snaps[i], 7, 7);
            }
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
