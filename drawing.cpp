#include "drawing.h"

#include <QDebug>
#include <QPoint>
#include <QShortcut>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	
	setMouseTracking(true);
	board = QPixmap(884,624);
	board.fill(Qt::white);
	setFixedSize(884,624);
	mov = false;
	obs = false;
        cur = CANVAS;
	QPalette pal(palette());
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	objs.append(new Line());
	objs.append(new Circle());
        objs.append(new Canvas());
        //qDebug() << objs[2]->getCenter();
	update();
	//will move to menu widget later
	/*connect(new QShortcut(QKeySequence(tr("x", "Line")), this),SIGNAL(activated()),this,SLOT(sLine()));
	connect(new QShortcut(QKeySequence(tr("c", "Circle")), this),SIGNAL(activated()),this, SLOT(sCirc()));
	connect(new QShortcut(QKeySequence(tr("Esc", "Abort")), this),SIGNAL(activated()),this, SLOT(abort()));*/
}

void Drawing :: paintEvent(QPaintEvent * event){
	QPainter paint(this);
	static bool wasPressed = obs;	
	wasPressed = obs;
	if(cur == CANVAS){
	    board = objs[cur]->trigRen(&paint, board);
	    cur = NONE;
	}else if(wasPressed){
	    board = objs[cur]->trigRen(&paint, board);
	    obs = false;
	    wasPressed = obs;
	    cur = NONE;
	    emit drawn();
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
	     objs[cur] -> setPressed(true, event->pos());
	    // emit clshape(cur);
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
	if(cur != NONE&& cur != CANVAS){
	     objs[cur]->onMove(event->pos(),mov); //create case for line and circle
	     msg(event->pos());
	     update();
	}
}

void Drawing :: sLine(){
	if(!mov&&cur == NONE){
	    cur = (cur == LINE) ? NONE : LINE;
	    emit tl();
	    emit clshape(cur);
	    update();
	}

}

void Drawing :: sCirc(){
	if(!mov&&cur == NONE){
	     cur = (cur == CIRCLE) ? NONE : CIRCLE;
	     emit tc(); 
	     emit clshape(cur);
	     update();
	}
}

void Drawing :: abort(){
	if(cur != NONE){
	    obs = false;
	    objs[cur] -> abort();
	    emit clear();
	    cur = NONE;
	    mov = false;
 	    update();
	}
}

void Drawing :: msg(QPoint p){
	QString r = "";
	QString ts = "";
	QPoint tc,t;
	for(int i = 0; i < objs.size(); ++i){
	    ts = objs[i] -> getSnap(p);
	    if(!ts.isEmpty()){
	        r = ts;
	    }
	}
	if(r.isEmpty()){
	    tc = objs[CANVAS] -> getCenter();
            r = QString("(%1, %2)").arg(p.x()-tc.x()).arg((-1*p.y())+tc.y());
	    emit disp(r,mov);
	}
	else{
	    emit disp(r,mov);
	}	

}
