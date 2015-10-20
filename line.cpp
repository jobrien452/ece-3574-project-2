#include "line.h"
#include <QDebug>
Line :: Line() 
    :Qtdraw(){}

void Line :: setPressed(bool x, QPoint p){
    if(x){
	int b = onSnap(p);
	if(b != -1){
	     qDebug() << b;
	     lines.append(QLine(snaps[b],snaps[b]));
	     gridSnap = snaps[b];
	}
        else{
	     qDebug() <<" :(";
	     lines.append(QLine(p,p));
	     gridSnap = p;
	     qDebug() << ":D";
        }
	clicked = true;
    }
    else{
        int b = onSnap(lines.last().p1());
	if(b == -1){
	     snaps.append(lines.last().p1());
	}

	b = onSnap(lines.last().p2());

	if(b != -1){
	    lines.last().setP2(snaps[b]);
	}else{
	    snaps.append(lines.last().p2());
	}
	blueSnap = -1;//possibly unecessary, find out during testing
	rendered = true;
	//counter++;
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
//	qDebug() << "lrender";
	QPainter PixmapPainter(&b);
	PixmapPainter.drawLine(lines.last());
	paint->drawPixmap(0, 0,b);
	rendered = false;
    }
    else{
	qDebug() << lines;
 	paint -> drawPixmap(0,0, b);
	paint -> drawLine(lines.last());
	//qDebug() << "ldend";
    }
    return b;
}

void Line :: onMoveRen(QPoint p){
    lines.last().setP2(p);
    blueSnap = onSnap(p);
}

void Line :: abort(){
    if(lines.size() > 1){
	//qDebug() << lines;
        lines.pop_back();
    }else{
	//qDebug() << "found";
 	lines.clear();
    }
    blueSnap = -1;
    //delete gridSnap;
    rendered = false;
    clicked = false;
}

