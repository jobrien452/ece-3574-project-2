#include "qtdraw.h"

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
    type = "qtdraw object";
}

QString Qtdraw :: getType(){
    return type;
}

void Qtdraw :: onMove(Qpoint & p){
    
    onMoveRen(p);
}

void Qtdraw :: trigRen(QPainter * p){
    trigSnap(false, p);
    render(p);
}

void Qtdraw :: trigSnap(bool x, QPainter * p){
    
    mpSnap = new QPixmap(400, 400);
    if(x){
	QPainter PixmapPainter(&mpSnap);
	PixmapPainter.setBrush(Qt::yellow);
	for(int i = 0; i < snaps.size(); i++){
	    PixmapPainter.drawEllipse(snaps[i], 2, 2);
        }
    }
    else{
        mpSnap.fill(Qt::transparent);
    }
    p->drawPixmap(0, 0, mpSnap);
	
}

//bool Qtdraw :: isRendered(){ return rendered; }

