#ifndef LINE_H
#define LINE_H

#include "qtdraw.h"
#include <QLine>
class Line : public Qtdraw {
    
    Q_OBJECT
    
    public:
	Line(QWidget * parent);
	void setPressed(QPoint );
	QString getSnap(QPoint i);
	void abort();
    protected:
	void render(QPainter *);
	void onMoveRen(QPoint );
        QList<QLine> lines;
	counter = 0;
};

#endif
