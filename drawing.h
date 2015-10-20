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
#include "canvas.h"

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
	bool obs, mov;
	shapes cur;
    protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
        QList<Qtdraw*> objs;
    public slots:
	void sLine();//for when window handle short cuts
	void sCirc();
        void abort();
    signals:
	void drawn();
	void tl();
	void tc();
};

#endif
