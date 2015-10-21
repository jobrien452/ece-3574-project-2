#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QWidget>
#include <QShortcut>
#include <QLabel>
#include <QVBoxLayout>

class Menu : public QWidget {

    Q_OBJECT
    public:
	explicit Menu(QWidget * parent = 0);
	QString getText();
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
