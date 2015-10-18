#ifndef LINE_H
#define LINE_H

#include "qtdraw.h"
#include <QLine>
class Line : public Qtdraw {
    
    Q_OBJECT
    
    public:
	Line(QWidget * parent);
	void setPressed(QPoint );
	QString getSnap(QPoint);
	void abort();
    protected:
	QPixmap render(QPainter *, QPixmap);
	void onMoveRen(QPoint );
        QList<QLine> lines;
        int counter;
};

#endif
