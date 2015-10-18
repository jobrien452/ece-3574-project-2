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

class Drawing : public QWidget {
	
    Q_OBJECT
    
    public:
	explicit Drawing(QWidget * parent = 0);
    private:
	QPixmap board;
	QPoint bs;
	//Canvas * can;
	Line * l;
	//Circle * c;
	bool line, circle, ons, mov, fbs;
    protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
//	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void ltrig(bool);
	void ctrig(bool);
    public slots:
	void sLine();
	void sCirc();
        void abort();
};

#endif
