#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>

#include "line.h"
#include "drawing.h"

class LineTest: public QOjbect
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
	Line * l;
	bool x;
	QPoint p;
	QPixmap b;
	QPainter * p;
	Drawing d;
};
