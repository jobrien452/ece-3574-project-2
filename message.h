#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class Message : public QWidget {

    Q_OBJECT
    
    public:
	explicit Message(QWidget * parent = 0);
    private:
	QLabel * mbox;
	QHBoxLayout * l;
	QString scur1, scur2, s1, s2;
    public slots:
	void clear();
	void upMsg(QString, bool);
	void setCur(int);

};

#endif
