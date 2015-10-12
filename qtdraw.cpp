#include "qtdraw.h"

Qtdraw :: Qtdraw(QWidget * par){
    parent = par;
    rendered = false;
}

void Qtdraw :: render(){
    paint.begin(parent);
    paint.setPen(Qt::blue);
    paint.drawLine(10,10,20,20);
    paint.end();
}

void Qtdraw :: trigRen(){
    render();
}

bool Qtdraw :: isRendered(){ return rendered; }

