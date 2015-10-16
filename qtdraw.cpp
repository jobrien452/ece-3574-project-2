#include "qtdraw.h"

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
}

void Qtdraw :: trigRen(){
    render();
}

void Qtdraw :: trigSnap(){
    paint.begin(parent);
    for(int i = 0; i < snaps.size(); i++){
        paint.setBrush(Qt::yellow);
	paint.drawEllipse(snaps[i], 2, 2);
    }
    paint.end();
}

bool Qtdraw :: isRendered(){ return rendered; }

