#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QList>

#include "canvas.h"
#include "drawing.h"

class CanvasTest: public QObject
{
    Q_OBJECT

    private slots:
	void initTestCase();
	void testOverload();
	void testSetPressed();
	void testGetSnap();
	void testAbort();
	void testGetCenter();
	void testRender();
	void testOnMoveRen();
	void cleanupTestCase();

    private:
	Canvas * l;
	QList<QPoint> pts;
	QList<QString> nm;
	QPixmap b1,b2;
};

void CanvasTest::initTestCase()
{   
    l = new Canvas();
    pts << QPoint(0,0) << QPoint(2,0) << QPoint(4,0);
    pts << QPoint(0,2) << QPoint(2,2) << QPoint(4,2);
    pts << QPoint(0,4) << QPoint(2,4) << QPoint(4,4);
    nm << "top-left corner"<< "top-edge" << "top-right corner";
    nm << "left edge" << "center" << "right edge";
    nm << "bottom-left corner" << "bottom edge" << "bottom-right corner";
    b1 = QPixmap(200,200);
    b2 = QPixmap(200,200);
}

void CanvasTest::testOverload()
{
    l = new Canvas(pts.first(),pts.last());
    for(int i = 0; i<pts.size(); ++i){
       QVERIFY(l->onSnap(pts[i]) != -1);
    }
}

void CanvasTest::testSetPressed()
{  
   //unused function
   l->setPressed(true,QPoint(0,0));
   l->setPressed(false,QPoint(0,0));
}

void CanvasTest::testGetSnap()
{
   //also tests if create label's worked correctly
   for(int i = 0; i < pts.size(); ++i){
	QVERIFY(l->getSnap(pts[i]) == nm[i]);  
   }
   QVERIFY(l->getSnap(QPoint(50,50)) == ""); 
}

void CanvasTest::testAbort()
{
   //unused function
   l->abort();
}

void CanvasTest::testGetCenter()
{ 
   QVERIFY(l->getCenter() == pts[4]);
}

void CanvasTest::testRender()
{
   QPainter paint(&b1);
   b2 = l->trigRen(&paint, b2);
   //convert to image and check bits?
   QVERIFY(b1.cacheKey() == b2.cacheKey()); 
}

void CanvasTest::testOnMoveRen()
{
   //unusedfunction
   l->onMove(QPoint(0,0), true); 
   l->onMove(QPoint(0,0), false); 
}

void CanvasTest::cleanupTestCase()
{
   //do nothing
}

QTEST_MAIN(CanvasTest)
#include "canvasTest.moc"
