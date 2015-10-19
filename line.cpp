#include "line.h"
#include <QDebug>
Line :: Line() 
    :Qtdraw(){
    counter = 0; 
}

void Line :: setPressed(bool x, QPoint p){
    if(x){
	int b = onSnap(p);
	if(b != -1){
	    // qDebug() << b;
	     lines.append(QLine(snaps[b],snaps[b]));
	     gridSnap = snaps[b];
	}
        else{
	     lines.append(QLine(p,p));
	     gridSnap = p;
        }
	clicked = true;
    }
    else{
        int b = onSnap(lines[counter].p1());
	if(b == -1){
	     snaps.append(lines[counter].p1());
	}

	b = onSnap(lines[counter].p2());

	if(b != -1){
	    lines[counter].setP2(snaps[b]);
	}else{
	    snaps.append(lines[counter].p2());
	}
	blueSnap = -1;//possibly unecessary, find out during testing
	rendered = true;
	counter++;
	clicked = false;
    }
}

QString Line :: getSnap(QPoint p){
    for(int i = 0; i < lines.size(); ++i){
	if(lines[i].p1() == p){
		return "Line's Start";
	}
	else if(lines[i].p2() == p){
		return "Line's End";
	}
    }
}

QPixmap Line :: render(QPainter * paint, QPixmap b){
    if(rendered){
	QPainter PixmapPainter(&b);
	PixmapPainter.drawLine(lines[counter-1]);
	paint->drawPixmap(0, 0,b);
	rendered = false;
    }
    else{
 	paint -> drawPixmap(0,0, b);
	paint -> drawLine(lines[counter]);
    }
    return b;
}

void Line :: onMoveRen(QPoint p){
    lines[counter].setP2(p);
    blueSnap = onSnap(p);
}

void Line :: abort(){
    if(counter > 0){
        lines.pop_back();
    }else{
 	lines.clear();
    }
    blueSnap = -1;
    rendered = false;
    clicked = false;
}
