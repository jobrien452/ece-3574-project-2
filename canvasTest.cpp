#include <QTest>
#include <QString>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QList>
#include <QDebug>

#include "canvas.h"
#include "drawing.h"

class CanvasTest: public QObject
{
    Q_OBJECT

    private slots:
	void testRender();
        void initTestCase();
	void testOverload();
	void testSetPressed();
	void testGetSnap();
	void testAbort();
	void testGetCenter();
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
    l = new Canvas(QPoint(0,0),QPoint(50,50));  
    pts << QPoint(0,0) << QPoint(25,0) << QPoint(50,0);
    pts << QPoint(0,25) << QPoint(25,25) << QPoint(50,25);
    pts << QPoint(0,50) << QPoint(25,50) << QPoint(50,50);
    //qDebug() << pts;
    nm << "Canvas's top-left corner"<< "Canvas's top-edge" << "Canvas's top-right corner";
    nm << "Canvas's left edge" << "Canvas's center" << "Canvas's right edge";
    nm << "Canvas's bottom-left corner" << "Canvas's bottom edge" << "Canvas's bottom-right corner";
    b1 = QPixmap(200,200);
    b2 = QPixmap(200,200);
}

void CanvasTest::testRender()
{
   QPainter paint(&b1);
   b2 = l->trigRen(&paint, b2);
   //convert to image and check bits?
   QVERIFY(b1.toImage() == b2.toImage()); 
}

void CanvasTest::testOverload()
{

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
	QVERIFY(l->getSnap(pts[i]).compare(nm[i])== 0);
   }
   QVERIFY(l->getSnap(QPoint(100,100)) == ""); 
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
