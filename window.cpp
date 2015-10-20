#include "window.h"

Window :: Window(QWidget * parent)
	: QWidget(parent) {
	
	QPalette pal(palette());
	pal.setColor(QPalette::Background, Qt::white);
	setPalette(pal);
	hori = new QHBoxLayout();
	d = new Drawing(this);
	m = new Menu(this);
        hori-> setAlignment(Qt::AlignTop);
	hori->addWidget(d);
	hori->addWidget(m);
	setLayout(hori);
}
