#ifndef DRAWING_H
#define DRAWING_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QShortcut>
#include <QPoint>
#include <QPixmap>
#include <QMouseEvent>
#include <QPaintEvent>
#include "line.h"
#include "circle.h"

class Drawing : public QWidget {
	
    Q_OBJECT
    
    public:
	explicit Drawing(QWidget * parent = 0);
    private:
	QPixmap board;
//	Canvas * can;
	Line * l;
	//Circle * c;
	bool line, circle, obs, mov;
    protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void ltrig(bool);
	void ctrig(bool);
    public slots:
	void sLine();//for when window handle short cuts
	void sCirc();
        void abort();
};

#endif
