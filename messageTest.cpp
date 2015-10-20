#include <QTest>
#include <QString>

#include "message.h"

class MessageTest: public QObject
{
    Q_OBJECT

    private slots:
	void initTestCase();
	void testClear();
	void testUpMsg();
	void testSetCur();
    private:
	Message m;
	QString msg;
	bool x;
	int i;
};
	
