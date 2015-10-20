#include "menu.h"

Menu :: Menu ( QWidget * parent )
      : QWidget( parent ) {
    
    head = new QLabel(this);
/*    line = new QLabel(this);
    circle = new QLabel(this);
    abort = new QLabel(this);*/

   // line -> setTextFormat(Qt::RichText);
    head -> setTextFormat(Qt::RichText);
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
    l = l ? false : true;
    if(l){
	head->setText(draw+"<b>Line&nbsp;&nbsp;&nbsp;x</b>"+circle+abort);
    }else{
	head -> setText(draw+line+circle+abort);
    }
    update();
}

void Menu :: trigCircle(){
    c = c ? false : true;
    if(c){
	head -> setText(draw+line+"<b>Circle&nbsp;c<br><br></b>"+abort);
    }else{
	head -> setText(draw+line+circle+abort);
    }
    update();
}

void Menu :: trigAbort(){
    c = true;
    l = true;
    trigLine();
    trigCircle();
}
