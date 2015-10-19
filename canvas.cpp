#include "canvas.h"
#include <QDebug>

Canvas :: Canvas(QWidget * parent)//overload constructor so class isnt hardcoded
	: Qtdraw(parent){

    rendered = true;
    border = QRect(QPoint(4,4),QPoint(880,620));
    cpoints << QPoint(4,4) << QPoint(438, 4) << QPoint(880, 4);
    cpoints << QPoint(4,308) << QPoint(438,308) << QPoint(880,308);
    cpoints << QPoint(4, 620) << QPoint(438,620) << QPoint(880,620);
    labels.insert(0, "top-left corner");
    labels.insert(1, "top-edge");
    labels.insert(2, "top-right corner");
    labels.insert(3, "left edge");
    labels.insert(4, "center");
    labels.insert(5, "right edge");
    labels.insert(6, "bottom-left corner");
    labels.insert(7, "bottom edge");
    labels.insert(8, "bottom-right corner");

}

void Canvas :: setPressed(bool x, QPoint p){} //not a function of canvas

QString Canvas :: getSnap(QPoint p){
    for(int i = 0; i<labels.size(); ++i){
        if((cpoints[i]==p)&&labels.contains(i))
	    return "Canvas's "+labels.value(i);
    }
    return "";
}

void Canvas :: abort(){} //not a function of canvas

QPixmap Canvas :: render(QPainter * p, QPixmap b){ //called on load
    if(rendered){
        for(int i = 0; i<cpoints.size(); ++i){
	snaps.append(cpoints[i]);
        }
    
    QPainter PixmapPainter(&b);
    PixmapPainter.drawRect(border);
    p -> drawPixmap(0,0, b);
    rendered = false;//can only be rendered once on load
    }
    return b;
}

void Canvas :: onMoveRen(QPoint p){} //not a function of canvas
