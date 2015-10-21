#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>

#include "circle.h"

class CircleTest: public QObject
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
	QPoint p1,p2;
	QPixmap b1, b2;
};

void CircleTest::initTestCase()
{   
    l = new Circle();
    p1 = QPoint(4,4);
    p2 = QPoint(8,4);
    b1 = QPixmap(200,200);
    b2 = QPixmap(200,200);
}

void CircleTest::testSetPressed()
{  
   l -> setPressed(true, p1);
   l -> onMove(p2, true);
   l -> setPressed(false, p1);
   l -> setPressed(true, p1);
   l -> onMove(p2, true);
   l -> setPressed(false,p1);
   QVERIFY(l->onSnap(p1) == 0);
   QVERIFY(l->onSnap(QPoint(4,0)) == 1);
   QVERIFY(l->onSnap(QPoint(4,8)) == 2);
   QVERIFY(l->onSnap(QPoint(0,4)) == 3);
   QVERIFY(l->onSnap(QPoint(8,4)) == 4);
}

void CircleTest::testGetSnap()
{
   QVERIFY(l->getSnap(p1) == "Circle's Center");
   QVERIFY(l->getSnap(QPoint(4,0)) == "Circle's Top");
   QVERIFY(l->getSnap(QPoint(4,8)) == "Circle's Bottom"); 
   QVERIFY(l->getSnap(QPoint(0,4)) == "Circle's Left"); 
   QVERIFY(l->getSnap(QPoint(8,4)) == "Circle's Right"); 
   QVERIFY(l->getSnap(QPoint(50,50)) == "");
}

void CircleTest::testAbort()
{
   l -> setPressed(true, QPoint(50,50));
   l -> abort();
   QVERIFY(l->getSnap(QPoint(50,50)) == "");
}

void CircleTest::testGetCenter()
{ 
   QVERIFY(l->getCenter() == p1);
}

void CircleTest::testRender()
{
   QPainter paint(&b1);
   l -> setPressed(true, p1);
   l -> onMove(QPoint(50,50), true);
   l -> trigRen(&paint, b1);
   l -> setPressed(false,p1);
   b2 = l -> trigRen(&paint, b1);
   //convert to image and check bits
   QVERIFY(b1.toImage() == b2.toImage()); 
}

void CircleTest::testOnMoveRen()
{
   QPainter paint(&b1);
   l -> setPressed(true, p1);
   l -> onMove(QPoint(50,50), true);
   l -> trigRen(&paint, b1);
   l -> setPressed(false,p1);
   b2 = l -> trigRen(&paint, b1);
   //convert to image and check bits?
   QVERIFY(b1.toImage() == b2.toImage()); 
}

void CircleTest::cleanupTestCase()
{
   //do nothing
}

QTEST_MAIN(CircleTest)
#include "circleTest.moc"
