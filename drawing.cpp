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

	if(line)
	    l -> trigRen(&paint); 
	
	if(circle)
	    circle -> trigRen(&paint);

		
}

void Drawing :: mousePressEvent(QMouseEvent * event){
	l -> setPressed(true, event->pos());  
}

void Drawing :: mouseMoveEvent(QMouseEvent * event){
	l -> onMove(event->pos());
	update();
}

void Drawing :: mouseReleaseEvent(QMouseEvent * event){
	l -> setPressed(false, event->pos());
	update();
}

void Drawing :: ltrig(){
	if(line){
	    line = false;
	}
	else if(!circle){
	    line = true;
       	    l->trigSnap(true, &paint);//rewrite to canvas disp later
	}
}

void Drawing :: ctrig(){
	if(circle){
	    cirlce = false;
	}
	else if(!line){
	    circle = true;
	    //can->dispSnap(true);
	}
}

void Drawing :: abort(){
	if(line){
	   l->abort();
	   ltrig();
	}else if(circle){
	   circle->abort();
	   ctrig();
 
	}
	l->dispSnap(false);	//rewrite to canvas disp later
}
