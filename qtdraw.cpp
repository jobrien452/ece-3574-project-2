#include "qtdraw.h"
QList<QPoint> Qtdraw::snaps = QList<QPoint>() << QPoint(200,200);

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
}

void Qtdraw :: onMove(QPoint p){
    
    onMoveRen(p);
}

bool Qtdraw :: onSnap(QPoint p){
    for(int i = 0; i< snaps.size(); ++i){
	if(snaps[i] == p)
		return true;
    } 
    return false; 
}

void Qtdraw :: trigRen(QPainter * p, QPixmap mp){
    trigSnap(false, p, mp);
    render(p, mp);
}

void Qtdraw :: trigSnap(bool x, QPainter * p, QPixmap mpSnap){
    
    if(x){
	p->drawPixmap(0,0, mpSnap);
	p->setBrush(Qt::yellow);
	for(int i = 0; i < snaps.size(); i++){
	    p->drawEllipse(snaps[i], 10, 10);
        }
    }else{
	p->drawPixmap(0,0,mpSnap);
    }
	
}

void Qtdraw :: bSnap(QPainter * p, QPixmap mpSnap, QPoint bs){
    trigSnap(true, p, mpSnap);
    p->setBrush(Qt::darkGray);
    p->drawEllipse(bs, 14, 14);
    p->setBrush(Qt::blue);
    p->drawEllipse(bs, 10, 10); 

}
//bool Qtdraw :: isRendered(){ return rendered; }

