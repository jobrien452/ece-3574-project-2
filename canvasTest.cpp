#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>

#include "canvas.h"
#include "drawing.h"

class CanvasTest: public QOjbect
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
	Canvas * c;
	bool x;
	QPoint p;
	QPixmap b;
	QPainter * p;
	Drawing d;
};
