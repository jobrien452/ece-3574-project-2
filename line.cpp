#include "line.h"

Line :: Line(QWidget * parent) 
    :Qtdraw(parent){
    counter = 0; 
}

void Line :: setPressed(QPoint p){
    static bool x = true;
    if(x){
	if(onSnap(p)!=-1){
	    lines.append(QLine(snaps[onSnap(p)],p));
	}else{
            lines.append(QLine(p,p));
	}
	counter++;	
        x = false;
	rendered = false;
    }
    else{
	if(onSnap(lines[counter-1].p1()) == -1){
	    snaps.append(lines[counter-1].p1());
	}
	snaps.append(lines[counter-1].p2());
	x = true;
	rendered = true;
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

QPixmap Line :: render(QPainter * paint, QPixmap board){
    if(rendered){
	QPainter PixmapPainter(&board);
	PixmapPainter.drawLine(lines[counter-1]);
	paint->drawPixmap(0, 0, board);
	rendered = false;
    }
    else if(counter > 0){
 	paint -> drawPixmap(0,0, board);
	paint -> drawLine(lines[counter-1]);
    }
    return board;
}

void Line :: onMoveRen(QPoint p){
    lines[counter-1].setP2(p);
}

void Line :: abort(){
    if(counter > 0){
        lines.pop_back();
        counter--;
    }
}
