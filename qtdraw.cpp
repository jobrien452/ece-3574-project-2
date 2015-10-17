#include "qtdraw.h"

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
}

void Qtdraw :: onMove(Qpoint p){
    
    onMoveRen(p);
}

bool Qtdraw :: onSnap(QPoint p){
    for(int i = 0; i<snaps.size(); ++i){
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
	    p->drawEllipse(snaps[i], 2, 2);
        }
    }else{
	p->drawPixmap(0,0,mpSnap);
    }
	
}

void Qtdraw :: bSnap(QPainter * p, QPixmap mpSnap, QPoint bs){
    trigSnap(true, p, mpSnap)
    p->setBrush(Qt::darkGray);
    p->drawEllipse(bs, 4, 4);
    p->setBrush(Qt::blue);
    p->drawEllipse(bs, 2, 2); 

}
//bool Qtdraw :: isRendered(){ return rendered; }

