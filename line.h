#ifndef LINE_H
#define LINE_H

#include "qtdraw.h"
#include <QLine>
class Line : public Qtdraw {
    
    Q_OBJECT
    
    public:
	Line();
	void setPressed(bool, QPoint);
	QString getSnap(QPoint);
	void abort();
    private:
        QList<QLine> lines;
    protected:
	QPixmap render(QPainter *, QPixmap);
	void onMoveRen(QPoint );
};

#endif
