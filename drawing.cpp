#include "drawing.h"
#include "line.h"

#include <QAction>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	setMouseTracking(true);
	board = QPixmap(1000,1000);
	board.fill(Qt::white);
	setFixedSize(1000,1000);
	line = false;
	circle = false;
	mov = false;
	obs = false;
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
	static bool wasPressed = obs;	
	wasPressed = obs;
	if(wasPressed){
	    board = l->trigRen(&paint, board);
	    obs = false;
	    wasPressed = obs;
	}
	else if(!mov&&(line || circle)){
	    paint.drawPixmap(0,0,board);
	    l->trigSnap(&paint);
	}
	else if(mov&&(line || circle)){
            l->trigRen(&paint, board);
	    l->trigSnap(&paint);
        }else{
	    paint.drawPixmap(0,0, board);
	}	    	
			
}

void Drawing :: mousePressEvent(QMouseEvent * event){
        if((line || circle)&&!mov){
	     mov = true;
	     l -> setPressed(true, event->pos()); //create if for currently pressed, use canvas
	     update();
	}
	else if((line || circle) && mov){
	     sLine();
	     mov = false;
	     obs = true;
	     l->setPressed(false, event->pos());
	     update();
	}

}

void Drawing :: mouseMoveEvent(QMouseEvent * event){
	if(circle || line){
	    if(mov){
	        l->onMove(event->pos()); //create case for line and circle
	        update();
	    }
	}
}

void Drawing :: sLine(){
	line = line ? false : true;
	if(mov&&!line){
	    abort();
	}
	update();
}

void Drawing :: sCirc(){
	circle = circle ? false : true;
	update();
}

void Drawing :: ltrig(bool x){
	line = x;
	mov = false;
}

void Drawing :: ctrig(bool x){
	circle = x;
	mov = false;
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
