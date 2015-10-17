#include "drawing.h"
#include "line.h"

#include <QAction>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	board = QPixmap(400,400);
	//setFixedSize(1250,750);
	line = false;
	circle = false;
	mov = false;
	ons = false;
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
	QPainter paint(this); //use canvas for all these methods besides the line and circle one
	
	if(line || circle){
	    if(line&&mov){
		l->trigRen(&paint);
	    }else if(circle&&mov){
		//c->trigRen(&paint);
	    }
	    l->trigSnap(true, &paint, board);
	    if(ons){
	        l->bsnap(&paint,board,bs);
	    }
	}else{
	    l->trigSnap(false, &paint, board);
	}
		
}

void Drawing :: mousePressEvent(QMouseEvent * event){
	l -> setPressed(event->pos()); //create if for currently pressed
	mov = mov ? false : true;
	update();
}

void Drawing :: mouseMoveEvent(QMouseEvent * event){
	if(circle || line){
	    if(l->onSnap()){//use canvas for this meth
	        bs = event->pos();
		ons = true;
		//implement qstring name disp here
	    }
	    else{
		ons = false;
		//implement returning cords here
	    }
	    if(mov){
	        l->onMove(event->pos());
	    }
	    update();
	}
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
	  // circle->abort();
	   ctrig();
	}
	update();	//rewrite to canvas disp later
}
