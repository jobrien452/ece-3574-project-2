#include "drawing.h"
#include "line.h"

#include <QAction>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	//setFixedSize(1250,750);
	line = false;
	circle = false;
	QPalette pal(palette());
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	//can = new Canvas(this);
	l = new Line(this);
	//circle= = new Circle(this);
	//will move to menu widget later
	connect(new QShortcut(QKeySequence(tr("x", "Line")), this),SIGNAL(activated()),this,SLOT(ltrig()));
	connect(new QShortcut(QKeySequence(tr("c", "Circle")), this),SIGNAL(activated()),this SLOT(ctrig()));
	connect(new QShortcut(QKeySequence(tr("Esc", "Abort")), this),SIGNAL(activated()),this SLOT(abort()));
}

void Drawing :: paintEvent(QPaintEvent * event){
	QPainter paint(this);
	
	if(snap){
	    l->trigSnap(true, &paint);
	    snap = false;
	}
	else if(line);
	    l -> trigRen(&paint); 
	}
	else if(circle){
	    circle -> trigRen(&paint);
	}else{
	    l->trigSnap(false, &paint);
	}
		
}

void Drawing :: mousePressEvent(QMouseEvent * event){
	l -> setPressed(event->pos());
	update();
}

void Drawing :: mouseMoveEvent(QMouseEvent * event){
	l -> onMove(event->pos());
	update();
}

void Drawing :: ltrig(){
	if(line){
	    line = false;
	    snap = false;
	}
	else if(!circle){
	    line = true;
	    snap = true;
	}
	update();
}

void Drawing :: ctrig(){
	if(circle){
	    cirlce = false;
	    snap = false;
	}
	else if(!line){
	    circle = true;
	    snap = true;
	    //can->dispSnap(true);
	}
	update();
}

void Drawing :: abort(){
	if(line){
	   l->abort();
	   ltrig();
	}else if(circle){
	   circle->abort();
	   ctrig();
 
	}
	snap = false;
	update();	//rewrite to canvas disp later
}
