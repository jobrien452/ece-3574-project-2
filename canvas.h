#ifndef CANVAS_H
#define CANVAS_H

#include "qtdraw.h"
#include <QRect>
#include <QMap>

class Canvas : public Qtdraw {

    Q_OBJECT

    public:
	Canvas();
	Canvas(QPoint, QPoint);
	void setPressed(bool, QPoint);
	QString getSnap(QPoint);
	void abort();
	QPoint getCenter();
    private:
	void createLabels();
	void overload(QPoint, QPoint);
	QRect border;
	QMap<int, QString> labels;
	QList<QPoint> cpoints;
    protected:
	QPixmap render(QPainter *, QPixmap);
	void onMoveRen(QPoint);

};

#endif
