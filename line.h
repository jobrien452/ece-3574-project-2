#ifndef LINE_H
#define LINE_H

#include "qtdraw.h"
#include <QPainter>
#include <QObject>

class Line : public Qtdraw {
    
    Q_OBJECT
    
    public:
	Line(QWidget * parent);
	void render();

};

#endif
