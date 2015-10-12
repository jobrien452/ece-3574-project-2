#ifndef DRAWING_H
#define DRAWING_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include "line.h"

class Line;
class Drawing : public QWidget {
	
    Q_OBJECT
    
    public:
	explicit Drawing(QWidget *parent = 0);
    private:
	QPainter * paint;
	Line * l;
    protected:
	void paintEvent(QPaintEvent * event);
	void mousePressEvent(QMouseEvent * event);

};

#endif
