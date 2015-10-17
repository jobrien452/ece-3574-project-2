#ifndef DRAWING_H
#define DRAWING_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QShortcut>
#include <QPoint>
#include "line.h"

class Drawing : public QWidget {
	
    Q_OBJECT
    
    public:
	explicit Drawing(QWidget * parent = 0);
    private:
	//Canvas * can;
	Line * l;
	//Circle * c;
	bool line, circle;
    protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
    public slots:
	void ltrig();
	void ctrig();
	void abort();

};

#endif
