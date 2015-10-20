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
	QPainter paint;
};

void LineTest::initTestCase()
{
    l = new Line();
    x = false;
    p = QPoint(100,100);
    b = QPixmap(200,200);
    paint = paint(&b);

}

void LineTest::testSetPressed()
{
    
}

void LineTest::testGetSnap()
{
}

void LineTest::testAbort()
{
}

void LineTest::testGetCenter()
{


}

void LineTest::testRender()
{
}

void LineTest::testOnMoveRen()
{
}

void LineTest::cleanupTestCase()
{
}

QTEST_MAIN(LineTest)
#include "linetest.moc"
