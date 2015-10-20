#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWidget>
#include <QShortcut>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "drawing.h"
#include "menu.h"
#include "message.h"

class Window : public QWidget {

    Q_OBJECT

    public:
	explicit Window(QWidget * parent = 0);
    private:
	QVBoxLayout * vert;
	QHBoxLayout * hori;
	Drawing * d;
	Menu * m;
	Message * me;
	QShortcut *lshort, *cshort, *ashort;

};

#endif
