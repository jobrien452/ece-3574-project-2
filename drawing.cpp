#include "drawing.h"
#include "line.h"

#include <QAction>

Drawing :: Drawing ( QWidget * parent )
: QWidget( parent ) {
	//setFixedSize(1250,750);
	QAction * cline = new QAction(this);
	cline -> setShortcut(QKeySequence(tr("x")));
	addAction(cline);
	QPalette pal(palette());
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	l = new Line(this);
	connect(cline, SIGNAL(triggered()), l, SLOT(trigRen()));	
}

void Drawing :: paintEvent(QPaintEvent * event){
 	//l->trigRen();   
}

void Drawing :: mousePressEvent(QMouseEvent * event){
	update();
}
