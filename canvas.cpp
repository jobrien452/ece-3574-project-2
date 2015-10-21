#include "canvas.h"
#include <QDebug>

Canvas :: Canvas()//overload constructor so class isnt hardcoded
	: Qtdraw(){

    overload(QPoint(4,4),QPoint(880,620));
}

Canvas :: Canvas(QPoint origin, QPoint bottomRight)
	: Qtdraw(){
    overload(origin, bottomRight);   
}

void Canvas :: overload(QPoint origin, QPoint bottomRight){
    rendered = true;
    border = QRect(origin, bottomRight);
    int cy = border.center().y();
    int cx = border.center().x();
    cpoints << border.topLeft() << QPoint(cx,border.top())  << border.topRight();
    cpoints << QPoint(border.left(),cy) << border.center() << QPoint(border.right(),cy);
    cpoints << border.bottomLeft() << QPoint(cx, border.bottom()) << border.bottomRight();
    //qDebug() << cpoints; 
    createLabels(); 
}

void Canvas :: createLabels(){
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

QPoint Canvas :: getCenter(){
    return cpoints[4];
}

void Canvas :: setPressed(bool x, QPoint p){} //not a function of canvas

QString Canvas :: getSnap(QPoint p){
    for(int i = 0; i<labels.size(); ++i){
        if(inSnap(p,cpoints[i])&&labels.contains(i))
           // qDebug() << labels.value(i) << " " << inSnap(p,cpoints[i]);
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
