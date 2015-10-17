#include "qtdraw.h"

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
}

void setPressed(bool x, QPoint & p){
    if(x){    
	psnaps.append(*p);
    }
    else{
	psnaps.append(*p);
	for(int i = 0; i < psnaps.size(); i++)
	     snaps.append(psnaps[i]);
    }
	
}

void onMove(Qpoint & p){
    
    onMoveRen(*p);
}

void Qtdraw :: trigRen(QPainter * p){
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
        mpSnap->fill(Qt::transparent);
    }
    p->drawPixmap(0, 0, mpSnap);
	
}

//bool Qtdraw :: isRendered(){ return rendered; }

