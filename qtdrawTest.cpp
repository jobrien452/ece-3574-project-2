#include <QTest>
#include <QPoint>
#include <QPainter>
#include <QPixmap>

#include "qtdraw.h"
#include "line.h"


class QtdrawTest : public QObject
{
    Q_OBJECT

    private slots:
	void initTestCase();
	void testIsRendered();
	void testOnMove();
	void testOnSnap();
	void testInSnap();
        void testGetBS();
	void testBSnap();
	void testTrigRen();
	void testTrigSnap();
	void cleanupTestCase();
    private:
	Qtdraw * q;
	Line * l;
	QPoint p;
	QPixmap b;
};

void QtdrawTest :: initTestCase()
{
    l = new Line();
    l->setPressed(true, QPoint(0,0));
    q = l;
}

void QtdrawTest :: testIsRendered()
{
    QVERIFY(q->isRendered() == false);
}

void QtdrawTest :: testOnMove()
{
    q->onMove(QPoint(1,1), true);
    q->setPressed(false,QPoint(0,0));
    QVERIFY(q->onSnap(QPoint(1,1)) != -1);
    q->onMove(QPoint(0,0), false);
    QVERIFY(q->getBS() == 0);   
}

void QtdrawTest :: testOnSnap()
{
    QVERIFY(q->onSnap(QPoint(10,10)) == -1);
    QVERIFY(q->onSnap(QPoint(0,0)) == 0); 
}

void QtdrawTest :: testInSnap()
{
    QVERIFY(q->onSnap(QPoint(10,10)) == -1);
    QVERIFY(q->onSnap(QPoint(0,0)) == 0);
}

void QtdrawTest :: testGetBS()
{
    q->onMove(QPoint(25,25), false);
    QVERIFY(q->getBS() == -1);
    q->onMove(QPoint(0,0), false);
    QVERIFY(q->getBS() == 0);
}

void QtdrawTest :: testTrigRen()
{
    q = new Line();
    QPixmap b = QPixmap(100,100);
    QPixmap c = QPixmap(100,100);
    QPainter cpix;
    cpix.begin(&c);
    cpix.drawLine(QLine(QPoint(12,12),QPoint(19,19)));
    cpix.end();
    q->setPressed(true,QPoint(12,12));
    q->onMove(QPoint(19,19), true);
    cpix.begin(&b);
    q->trigRen(&cpix, QPixmap(100,100));
    cpix.end();
    QVERIFY(c.toImage() == b.toImage());   
}

void QtdrawTest :: testTrigSnap()
{
    q = new Line();
    q->setPressed(true, QPoint(0,0));
    q->onMove(QPoint(10,10),true);
    q->setPressed(true, QPoint(0,0));
    q->setPressed(true, QPoint(20,20));
    q->onMove(QPoint(0,0), true);
    QPainter pix;
    QPainter cpix;
    QPixmap * b = new QPixmap(100,100);
    QPixmap * c = b;
    pix.begin(b);
    q->trigSnap(&pix);
    pix.end();
    cpix.begin(c);
    cpix.setBrush(Qt::yellow);
    cpix.drawEllipse(QPoint(0,0), 4,4);
    cpix.drawEllipse(QPoint(10,10), 4,4);
    q->bSnap(&cpix, QPoint(0,0));
    q->bSnap(&cpix, QPoint(20,20));
    cpix.end();
    QVERIFY(c->toImage() == b->toImage()); 

}

void QtdrawTest :: testBSnap()
{
    QPainter pix;
    QPixmap * b = new QPixmap(100,100);
    QPixmap * c = b;
    pix.begin(b);
    q->bSnap(&pix, QPoint(10,10));
    pix.end();
    pix.begin(c);
    q->bSnap(&pix, QPoint(10,10));
    pix.end();

    QVERIFY(c->toImage() == b->toImage());
}

void QtdrawTest :: cleanupTestCase()
{
 //do nothing
}

QTEST_MAIN(QtdrawTest)
#include "qtdrawTest.moc"
