#ifndef CANVAS_H
#define CANVAS_H

#include "qtdraw.h"
#include <QRect>
class Canvas : public Qtdraw {

    Q_OBJECT

    public:
	Canvas(QWidget * parent);
	void setPressed(bool, QPoint);
	QString getSnap(QPoint);
	void abort();
    protected:
	QPixmap render(QPainter *, QPixmap);
	void onMoveRen(QPoint);
	QList<QPoint> cpoints;
	QRect border;

};

#endif