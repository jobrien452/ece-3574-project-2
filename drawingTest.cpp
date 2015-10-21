#include <QTest>
#include <QString>
#include <QPoint>
#include <QSignalSpy>
#include <QVariant>
#include <QList>
#include <QDebug>
#include <QPixmap>
#include <QFile>
#include <QIODevice>

#include "drawing.h"

class DrawingTest : public QObject
{
   Q_OBJECT

   private slots:
	void initTestCase();
	void testSLine();
        void testSCirc();
        void testAbort();
	void testTl();
	void testTc();
	void testDisp();
	void testClshape();
	void testClear();
        void testDrawn();
	void testMousePressEvent();
	void testMouseMoveEvent();
        void testPaintEvent();
	void cleanupTestCase();
   private:
	Drawing * d;
};

void DrawingTest :: initTestCase()
{
    d = new Drawing();
    d->show();
}

void DrawingTest :: testSLine()
{
    d->abort();
    QSignalSpy spy1(d, SIGNAL(tl()));
    QSignalSpy spy2(d, SIGNAL(clshape(int)));
    d->sLine();
    QVERIFY(spy1.count() == 1);
    QVERIFY(spy2.count() == 1);
    QVERIFY(spy2.takeFirst().at(0) == 0);
}

void DrawingTest :: testSCirc()
{
    d->abort();
    QSignalSpy spy1(d, SIGNAL(tc()));
    QSignalSpy spy2(d, SIGNAL(clshape(int)));
    d->sCirc();
    QVERIFY(spy1.count() == 1);
    QVERIFY(spy2.count() == 1);
    QVERIFY(spy2.takeFirst().at(0) == 1);

}

void DrawingTest :: testAbort()
{
    d->sLine();
    QSignalSpy spy(d, SIGNAL(clear()));
    d->abort();
    QVERIFY(spy.count() == 1); 
}

void DrawingTest :: testTl()
{
    d->abort();
    QSignalSpy spy(d, SIGNAL(tl()));
    d->sLine();
    QVERIFY(spy.count() == 1);    
}

void DrawingTest :: testTc()
{
    d->abort();
    QSignalSpy spy(d, SIGNAL(tc()));
    d->sCirc();
    QVERIFY(spy.count() == 1);  
}

void DrawingTest :: testDisp()
{
    d->abort();
    QSignalSpy spy(d, SIGNAL(disp(QString, bool)));
    d->sLine();
    QTest::mouseClick(d, Qt::LeftButton,0, QPoint(100,100));
    QTest::mouseMove(d, QPoint(115,115));
    QVERIFY(spy.at(1).at(0).type() == QVariant::String);
    QVERIFY(spy.at(1).at(0).toString() == "(-327, 197)");
    QVERIFY(spy.at(1).at(1).type() == QVariant::Bool);
    QVERIFY(spy.at(1).at(1).toBool() == true);
    QTest::mouseClick(d, Qt::LeftButton,0, QPoint(115,115));
    d->abort();
    d->sLine();
    QTest::mouseMove(d, QPoint(100,100));
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(300,300));
    QTest::mouseMove(d,QPoint(443,312));
    QVERIFY(spy.back().at(0).toString() == "Canvas's center");
}

void DrawingTest :: testClshape()
{
    d->abort();
    QSignalSpy spy(d, SIGNAL(clshape(int)));
    d->sCirc();
    d->abort();
    d->sLine();
    QVERIFY(spy.count() == 2);
    QVERIFY(spy.takeFirst().at(0) == 1);
    QVERIFY(spy.back().at(0) == 0);
}

void DrawingTest :: testClear()
{
    d->abort();
    d->sLine();
    QSignalSpy spy(d, SIGNAL(clear()));
    d->abort();
    QVERIFY(spy.count() == 1);    
}

void DrawingTest :: testMousePressEvent()
{
    d->sLine();
    QSignalSpy spy(d, SIGNAL(drawn()));
    QTest::mouseMove(d, QPoint(150,150));
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(150,150));
    QTest::qWait(500);
    QTest::mouseMove(d, QPoint(150,100));
    QTest::qWait(500);
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(150,100));
    QTest::qWait(500); 
    QVERIFY(spy.count() == 1);    
}

void DrawingTest :: testMouseMoveEvent()
{
    d->abort();
    d->sLine();
    QSignalSpy spy(d, SIGNAL(disp(QString, bool)));
    QTest::mouseMove(d, QPoint(110,110));
    QTest::mouseMove(d, QPoint(250,250));
    QVERIFY(spy.count() == 2);
}

void DrawingTest :: testDrawn()
{
    d->sLine();
    d->abort();
    d->sLine();
    QSignalSpy spy(d, SIGNAL(drawn()));
    QTest::mouseMove(d, QPoint(300,300));
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(300,300));
    QTest::qWait(500);
    QTest::mouseMove(d, QPoint(300,100));
    QTest::qWait(500);
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(300,100));
    QTest::qWait(500); 
    QVERIFY(spy.count() == 1);    

}

void DrawingTest :: testPaintEvent()
{
    d-> abort();
    //QTest::qWait(1500);
    d->sLine();
    QSignalSpy spy(d, SIGNAL(drawn()));
    QTest::mouseMove(d, QPoint(400,400));
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(400,400));
    QTest::qWait(500);
    QTest::mouseMove(d, QPoint(500,500));
    QTest::qWait(500);
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(500,500));
    QTest::qWait(500); 
    QVERIFY(spy.count() == 1);
    d->sCirc();
    QTest::mouseMove(d, QPoint(125,125));
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(125,125));
    QTest::qWait(500);
    QTest::mouseMove(d, QPoint(150,150));
    QTest::qWait(500);
    QTest::mouseClick(d, Qt::LeftButton, 0, QPoint(150,150));
    QTest::qWait(500); 
    QVERIFY(spy.count() == 2);   
    QPixmap src = QPixmap::grabWidget(d, QRect(QPoint(0,0),QPoint(884,624)));
    QFile file("test_capture.png");
    file.open(QIODevice::WriteOnly);
    src.save(&file, "PNG");

}

void DrawingTest :: cleanupTestCase()
{
   //do nothing
}

QTEST_MAIN(DrawingTest)
#include "drawingTest.moc"
