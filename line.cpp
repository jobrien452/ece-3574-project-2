#include "line.h"

Line :: Line(QWidget * parent) 
    :Qtdraw(parent){

    type = "Line"; 
}

void Line :: setPressed(QPoint p){
    static bool x = true;
    if(x){
        lines.append(QLine(p,p));
	counter++;	
        x = false;
    }
    else{
	lines[counter-1].setP2(p);
        for(int i = 0; i < lines.size(); i++){
	    snaps.append(lines[i].p1());
	    snaps.append(lines[i].p2());
	}
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

void Line :: render(QPainter * paint, QPixmap board){
    if(rendered){
	QPainter PixmapPainter(&board);
	PixmapPainter.drawLine(lines[counter-1]);
	paint->drawPixmap(0, 0, board);
    }
    else{
 	paint -> drawPixmap(0,0, board);
	paint -> drawLine(lines[counter-1]);
    }
}

void Line :: onMoveRen(QPoint p){
    lines[counter-1].setP2(p);
}

void Line :: abort(){
    lines.pop_back();
    counter--;
}
