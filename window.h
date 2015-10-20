#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWidget>
#include <QShortcut>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "drawing.h"
#include "menu.h"

class Window : public QWidget {

    Q_OBJECT

    public:
	explicit Window(QWidget * parent = 0);
    private:
	QVBoxLayout * virt;
	QHBoxLayout * hori;
	Drawing * d;
	Menu * m;
    signals:
	//?
    public slots:
	//?
};

#endif
