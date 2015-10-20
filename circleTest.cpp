#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>

#include "circle.h"
#include "drawing.h"

class CircleTest: public QOjbect
{
    Q_OBJECT

    private slots:
	void initTestCase();
	void testSetPressed();
	void testGetSnap();
	void testAbort();
	void testGetCenter();
	void testRender();
	void testOnMoveRen();
	void cleanupTestCase();

    private:
	Circle * l;
	bool x;
	QPoint p;
	QPixmap b;
	QPainter * p;
	Drawing d;
};
