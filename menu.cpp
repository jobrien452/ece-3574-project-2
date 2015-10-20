#include "menu.h"

Menu :: Menu ( QWidget * parent )
      : QWidget( parent ) {
    
    head = new QLabel(this);
    head -> setTextFormat(Qt::RichText);
    l = true;
    c = true;
   /* circle -> setTextFormat(Qt::RichText);
    abort -> setTextFormat(Qt::RichText);*/
    draw = "<b><u>DRAW</u></b><br>";
    line = "Line&nbsp;&nbsp;&nbsp;x<br>";
    circle = "Circle&nbsp;c<br><br>";
    abort = "Abort&nbsp;&nbsp;esc";
    head -> setText(draw+line+circle+abort);
   /* line -> setText("Line   x");
    circle -> setText("Circle c <br><br>");
    abort -> setText("Abort esc");*/
    
    head -> setAlignment(Qt::AlignTop);
   /* line -> setAlignment(Qt::AlignTop);
    circle -> setAlignment(Qt::AlignTop);
    abort -> setAlignment(Qt::AlignTop);*/

    vmenu = new QVBoxLayout();
    vmenu -> addWidget(head);
    /*vmenu -> addWidget(line);
    vmenu -> addWidget(circle);
    vmenu -> addWidget(abort);*/
    setLayout(vmenu);    
    //connect here
}

void Menu :: trigLine(){ //create somesort of signal scheme to unbold labels
    //l = l ? false : true;
    //static bool l = true;
    if(l){
	head->setText(draw+"<b>Line&nbsp;&nbsp;&nbsp;x</b><br>"+circle+abort);	
	l = false;
    }else{
        trigAbort();
	l = true;
    }
    update();
}

void Menu :: trigCircle(){
    //static bool c = true;
    if(c){
	head -> setText(draw+line+"<b>Circle&nbsp;c<br><br></b>"+abort);
	c = false;
    }else{
	trigAbort();
	c = true;
    }
    update();
}

void Menu :: trigAbort(){
    l = true;
    c = true;
    head -> setText(draw+line+circle+abort);
}
