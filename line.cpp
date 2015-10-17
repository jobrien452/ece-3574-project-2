#include "line.h"

Line :: Line(QWidget * parent) 
    :Qtdraw(parent){

    type = "Line"; 
}

void Line :: setPressed(QPoint & p){
    static bool x = true;
    if(x){
	psnaps.append(p);
        x = false;
    }
    else{
	psnaps[1] = p;
        for(int i = 0; i < psnaps.size(); i++)
	    snaps.append(psnaps[i]);
	x = true;
	rendered = true;
    }
}

QString Line :: getSnap(QPoint & p){
    if(psnap[0] == p)
	return "Start";
    else if(psnap[1] == p)
	return "End";
    else
	return "";
}

void Line :: render(QPainter * paint){
    if(rendered){
	QPainter PixmapPainter(&board);
	PixmapPainter.drawLine(psnap[0],psnap[1]);
	paint->drawPixmap(0, 0, board);
    }
    else{
 	paint -> drawPixmap(0,0, board);
	paint -> drawLine(psnaps[0],psnaps[1]);
    }
}

void Line :: onMoveRen(QPoint & p){
    psnap[1] = p;
}
