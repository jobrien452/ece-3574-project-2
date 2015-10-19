#include "drawing.h"

#include <QAction>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	setMouseTracking(true);
	board = QPixmap(880,660);
	board.fill(Qt::white);
	setFixedSize(880,660);
//	line = false;
	//circle = false;
	mov = false;
	obs = false;
        cur = NONE;
	QPalette pal(palette());
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	//can = new Canvas(this);
	objs.append(new Line(this));
	objs.append(new Circle(this));
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
	    board = objs[cur]->trigRen(&paint, board);
	    obs = false;
	    wasPressed = obs;
	    cur = NONE;
	}
	else if(!mov&&(cur != NONE)){
	    paint.drawPixmap(0,0,board);
	    objs[cur]->trigSnap(&paint);
	}
	else if(mov&&(cur != NONE)){
            objs[cur]->trigRen(&paint, board);
	    objs[cur]->trigSnap(&paint);
        }else{
	    paint.drawPixmap(0,0, board);
	}	    	
			
}

void Drawing :: mousePressEvent(QMouseEvent * event){
        if((cur != NONE)&&!mov){
	     mov = true;
	     objs[cur] -> setPressed(true, event->pos()); //create if for currently pressed, use canvas
	     update();
	}
	else if((cur != NONE) && mov){
	     mov = false;
	     //sOBJ(cur);
	     obs = true;   
	     objs[cur] -> setPressed(false, event->pos());  
	     update();
	}

}

void Drawing :: mouseMoveEvent(QMouseEvent * event){
	if(cur != NONE){
	     objs[cur]->onMove(event->pos(),mov); //create case for line and circle
	     update();
	}
}

/*void Drawing :: sOBJ(shapes x){
	if(!mov){	
	update();	
	}
}*/

void Drawing :: sLine(){
	if(!mov){
	cur = cur == LINE ? NONE : LINE;
	update();
	}

}

void Drawing :: sCirc(){
	if(!mov){
	cur = (cur == CIRCLE) ? NONE : CIRCLE;
	update();
	}
}

void Drawing :: abort(){
	obs = false;
	objs[cur] -> abort();
	cur = NONE;
	mov = false;
	update();	//rewrite to canvas disp later
}
