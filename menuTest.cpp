#include <QTest>
#include <QString>

#include "menu.h"

class MenuTest : public QObject
{
   Q_OBJECT

   private slots:
	void initTestCase();
	void testGetText();
	void testTrigLine();
	void testTrigCircle();
	void testTrigAbort();
	void cleanupTestCase();
   private:
	Menu m;
	QString draw, line, linealt, circle, circlealt, abort, head;
};

void MenuTest :: initTestCase()
{
    m.show();
    draw = "<b><u>DRAW</u></b><br>";
    line = "Line&nbsp;&nbsp;&nbsp;x<br>";
    linealt = "<b>Line&nbsp;&nbsp;&nbsp;x</b><br>";
    circle = "Circle&nbsp;c<br><br>";
    circlealt = "<b>Circle&nbsp;c<br><br></b>";
    abort = "Abort&nbsp;&nbsp;esc";
    head = draw+line+circle+abort;
}

void MenuTest :: testGetText()
{
    QVERIFY(m.getText() == head);
}

void MenuTest :: testTrigLine()
{
    m.trigLine();
    QVERIFY(m.getText() == (draw+linealt+circle+abort));
    m.trigLine();
    QVERIFY(m.getText() == head);  
}

void MenuTest :: testTrigCircle()
{
    m.trigCircle();
    QVERIFY(m.getText() == (draw+line+circlealt+abort));
    m.trigCircle();
    QVERIFY(m.getText() == head);  

}

void MenuTest :: testTrigAbort()
{
   m.trigLine();
   m.trigAbort();
   QVERIFY(m.getText() == head);
   m.trigCircle();
   m.trigAbort();
   QVERIFY(m.getText() == head);
}

void MenuTest :: cleanupTestCase()
{
   //do nothing
}

QTEST_MAIN(MenuTest)
#include "menuTest.moc"
