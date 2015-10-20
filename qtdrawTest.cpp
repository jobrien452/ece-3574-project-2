#include <QTest>
#include <QPoint>
#include <QPainter>
#include <QPixmap>

#include "qtdraw.h"
#include "line.h"
#include "drawing.cpp"

class QtdrawTest : public QObject
{
    Q_OBJECT

    private slots:
	void initTestCase();
	void testIsRendered();
	void testOnMove();
	void testOnSnap();
	void testBSnap();
	void testTrigRen();
	void testTrigSnap();
    private:
	Qtdraw * q;
	QPoint p;
	bool x;
	QPixmap b;
	Line * l;
	Drawing d;//d.show() will make this work
}; 
