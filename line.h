#ifndef LINE_H
#define LINE_H

#include "qtdraw.h"
class Line : public Qtdraw {
    
    Q_OBJECT
    
    public:
	Line(QWidget * parent);
	void abort();
    protected:
	void render(QPainter *);
	void onMoveRen(QPoint);
        

};

#endif
