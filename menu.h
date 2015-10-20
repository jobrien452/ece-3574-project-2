#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QWidget>
#include <QShortcut>
#include <QLabel>
#include <QVBoxLayout>

class Menu : public QWidget {

    Q_OBJECT
    /*in window connect signals to drawing for correct triggering
     *in top display remeber to make a signal for mousemove  and connect in window
     *so data is only displayed for the drawing area 
     */
    public:
	explicit Menu(QWidget * parent = 0);
    private:
	QVBoxLayout * vmenu;
	QLabel * head;
	QString line, circle, abort, draw;
	bool l, c;
    public slots:
	void trigLine();
	void trigCircle();
	void trigAbort();
};

#endif	
