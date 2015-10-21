#include <QTest>
#include <QString>

#include "message.h"

class MessageTest: public QObject
{
    Q_OBJECT

    private slots:
	void initTestCase();
	void testGetText();
	void testSetCur();
	void testUpMsg();
	void testClear();
	void cleanupTestCase();
    private:
	Message m;
	QString line, linealt, circle, circlealt;
	
};
	
void MessageTest :: initTestCase()
{
    line = "Draw line from line's end to ...";
    linealt = "Draw line from (0,0) to (1,1)";
    circle = "Draw circle centered at canvas's center and passing through ...";
    circlealt = "Draw circle centered at (0,0) and passing through (1,1)";
    m.show();
}

void MessageTest :: testGetText()
{
    QVERIFY(m.getText() == "");
}

void MessageTest :: testSetCur()
{
    m.clear();
    m.setCur(0);
    m.upMsg("line's end", false);
    QVERIFY(m.getText() == line);
    m.setCur(1);
    m.upMsg("canvas's center", false);
    QVERIFY(m.getText() == circle);  
}

void MessageTest :: testUpMsg()
{
    m.clear();
    m.setCur(0);
    m.upMsg("line's end", false);
    QVERIFY(m.getText() == line);
    m.upMsg("(0,0)", false);
    m.upMsg("(1,1)", true);
    QVERIFY(m.getText() == linealt);
    m.setCur(1);
    m.upMsg("canvas's center", false);
    QVERIFY(m.getText() == circle);
    m.upMsg("(0,0)", false);
    m.upMsg("(1,1)", true);
    QVERIFY(m.getText() == circlealt);
    

}

void MessageTest :: testClear()
{
    m.clear();
    m.setCur(0);
    m.upMsg("line's end", false);
    QVERIFY(m.getText() == line);
    m.clear();
    QVERIFY(m.getText() == "");
}

void MessageTest :: cleanupTestCase()
{
   //do nothing
}

QTEST_MAIN(MessageTest)
#include "messageTest.moc"
