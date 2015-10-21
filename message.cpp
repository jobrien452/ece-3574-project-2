#include "message.h"

Message :: Message(QWidget * parent)
	 : QWidget(parent){
	scur1 = "";
	s1 = "";
	scur2 = "";
	s2 = "...";
	mbox = new QLabel(this);
	mbox -> setTextFormat(Qt::RichText);
	mbox -> setText("");
	mbox -> setAlignment(Qt::AlignVCenter);
	l = new QHBoxLayout();
	l -> addWidget(mbox);
	setLayout(l);
}

void Message :: clear(){
	scur1 = "";
	scur2 = "";
	s1 = "";
	s2 = "...";
	mbox -> setText("");
}

void Message :: upMsg(QString s, bool x){
	if(!x){
	    s1 = s;
	    mbox -> setText(scur1 + s + scur2 + "..."); 
	}
	else{
	    mbox -> setText(scur1 + s1 + scur2 + s);
	}	
	
}

void Message :: setCur(int x){
	if(x == 0){
	    scur1 = "Draw line from ";
	    scur2 = " to ";
	}
	else{
	    scur1 = "Draw circle centered at ";
	    scur2 = " and passing through ";
	}
	
}

QString Message :: getText(){ return mbox -> text(); }
