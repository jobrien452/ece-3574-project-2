#include <QTest>

#include "menu.h"

class MenuTest : public QObject
{
   Q_OBJECT

   private slots:
	void initTestCase();
	void testTrigLine();
	void testTrigCirle();
	void testTrigAbort();
   private:
	Menu m;
};
