#include "drawing.h"
#include "line.h"

#include <QAction>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	setMouseTracking(true);
	board = QPixmap(1000,1000);
	snaps = QPixmap(1000,1000);
	board.fill(Qt::white);
	setFixedSize(1000,1000);
	line = false;
	circle = false;
	mov = false;
	bs = QPoint(0,0);
	QPalette pal(palette());
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	//can = new Canvas(this);
	l = new Line(this);
	//circle= = new Circle(this);
	//will move to menu widget later
	connect(new QShortcut(QKeySequence(tr("x", "Line")), this),SIGNAL(activated()),this,SLOT(sLine()));
	connect(new QShortcut(QKeySequence(tr("c", "Circle")), this),SIGNAL(activated()),this, SLOT(sCirc()));
	connect(new QShortcut(QKeySequence(tr("Esc", "Abort")), this),SIGNAL(activated()),this, SLOT(abort()));
}

void Drawing :: paintEvent(QPaintEvent * event){
	QPainter paint(this); //use canvas for all these methods besides the line and circle one
	
	if(line || circle){

	    if(line&&mov){
		l->trigRen(&paint,board);
	    }
	    else if(circle&&mov){
		//c->trigRen(&paint);
	    }

	    l->trigSnap(true, &paint, board, bs);// use canvas
	}
	else if(l->isRendered()){ //make statement for circle and line

	    board = l->trigRen(&paint, board);
	}
	else{
	    l->trigRen(&paint, board);//replace with canva
	}	
			
}

void Drawing :: mousePressEvent(QMouseEvent * event){
        if(line || circle){
	     l -> setPressed(event->pos()); //create if for currently pressed, use canvas
	     mov = mov ? false : true;

	     if(!mov){
	         ltrig(false);
	         ctrig(false);
	     }

	update();
	}
}

void Drawing :: mouseMoveEvent(QMouseEvent * event){
	if(circle || line){
	    bs = event->pos();
	    if(mov){
	        l->onMove(event->pos()); //create case for line and circle
	    }
	    update();
	}
}

void Drawing :: sLine(){
	line = line ? false : true;
}

void Drawing :: sCirc(){
	circle = circle ? false : true;
}

void Drawing :: ltrig(bool x){
	line = x;
}

void Drawing :: ctrig(bool x){
	circle = x;
}

void Drawing :: abort(){
	if(line){
	   l->abort();
	   ltrig(false);
	}else if(circle){
	  // circle->abort();
	   ctrig(false);
	}
	update();	//rewrite to canvas disp later
}
