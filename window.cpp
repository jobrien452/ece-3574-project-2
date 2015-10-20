#include "window.h"
#include <QKeySequence>

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
	lshort = new QShortcut(QKeySequence(tr("x", "Line")),this);
        cshort = new QShortcut(QKeySequence(tr("c", "Circle")),this);
	ashort = new QShortcut(QKeySequence(tr("Esc", "Abort")),this);
	connect(lshort, SIGNAL(activated()), d, SLOT(sLine()));
	connect(cshort, SIGNAL(activated()), d, SLOT(sCirc()));
	connect(ashort, SIGNAL(activated()), d, SLOT(abort()));
	connect(d, SIGNAL(tl()), m, SLOT(trigLine()));
	connect(d, SIGNAL(tc()), m, SLOT(trigCircle()));
	connect(ashort, SIGNAL(activated()), m, SLOT(trigAbort()));	
        connect(d, SIGNAL(drawn()), m, SLOT(trigAbort()));	
}
