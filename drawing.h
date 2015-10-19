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
#include "qtdraw.h"
#include "line.h"
#include "circle.h"

class Drawing : public QWidget {
	
    Q_OBJECT
    
    enum shapes{
	LINE, 
        CIRCLE,
        CANVAS,
	NONE
    };

    public:
	explicit Drawing(QWidget * parent = 0);
    private:
	QPixmap board;
//	Canvas * can;
//	Line * l;
//	Circle * c;
	bool obs, mov;
	shapes cur;
    protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
        QList<Qtdraw*> objs;
	//void ltrig(bool);
	//void ctrig(bool);
    public slots:
	void sLine();//for when window handle short cuts
	void sCirc();
        void abort();
};

#endif
