#include "drawing.h"
#include "line.h"

#include <QAction>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	board = QPixmap(1000,1000);
	board.fill(Qt::white);
	setFixedSize(1000,1000);
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
	connect(new QShortcut(QKeySequence(tr("c", "Circle")), this),SIGNAL(activated()),this, SLOT(ctrig()));
	connect(new QShortcut(QKeySequence(tr("Esc", "Abort")), this),SIGNAL(activated()),this, SLOT(abort()));
}

void Drawing :: paintEvent(QPaintEvent * event){
	QPainter paint(this); //use canvas for all these methods besides the line and circle one
	
	if(line || circle){
	    if(line&&mov){
		l->trigRen(&paint,board);
	    }else if(circle&&mov){
		//c->trigRen(&paint);
	    }
	    l->trigSnap(true, &paint, board);
	    if(ons){
	        l->bSnap(&paint,board,bs);
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
	    if(l->onSnap(event->pos())){//use canvas for this meth
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
	}
	else if(!circle){
	    line = true;
	}
	update();
}

void Drawing :: ctrig(){
	if(circle){
	    circle = false;
	}
	else if(!line){
	    circle = true;
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
