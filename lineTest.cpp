#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QImage>
#include <QDebug>

#include "line.h"

class LineTest : public QObject
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
	QPoint p1,p2;
	QPixmap b1, b2, b3;
};

void LineTest::initTestCase()
{   
    l = new Line();
    p1 = QPoint(100,100);
    p2 = QPoint(1,1);
    b1 = QPixmap(200,200);
    b2 = QPixmap(200,200);
}

void LineTest::testSetPressed()
{  
   l -> setPressed(true, p1);
   l -> onMove(p2, true);
   l -> setPressed(false,p1);
   l -> setPressed(true, p1);
   l -> onMove(p2, true);
   l -> setPressed(false,p1);
   QVERIFY(l->onSnap(p1) == 0);
   QVERIFY(l->onSnap(p2) == 1);
}

void LineTest::testGetSnap()
{
   QVERIFY(l->getSnap(p1) == "Line's Start");
   QVERIFY(l->getSnap(p2) == "Line's End");
   QVERIFY(l->getSnap(QPoint(50,50)) == "");
}

void LineTest::testAbort()
{
   l -> setPressed(true, QPoint(50,50));
   l -> abort();
   QVERIFY(l->getSnap(QPoint(50,50)) == "");
}

void LineTest::testGetCenter()
{
   //unused function 
   QVERIFY(l->getCenter() == QPoint(0,0));
}

void LineTest::testRender()
{
   QPainter paint(&b1);
   l -> setPressed(true, p1);
   l -> onMove(QPoint(50,50), true);
   l -> trigRen(&paint, b1);
   l -> setPressed(false,p1);
   b2 = l -> trigRen(&paint, b1);
   QVERIFY(b1.toImage() == b2.toImage()); 
}

void LineTest::testOnMoveRen()
{
   QPainter paint(&b1);
   l -> setPressed(true, p1);
   l -> onMove(QPoint(50,50), true);
   l -> trigRen(&paint, b1);
   l -> setPressed(false,p1);
   b2 = l -> trigRen(&paint, b1);
   QVERIFY(b1.toImage() == b2.toImage()); 
}

void LineTest::cleanupTestCase()
{
   //do nothing
}

QTEST_MAIN(LineTest)
#include "lineTest.moc"
