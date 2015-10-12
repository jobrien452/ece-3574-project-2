#include "line.h"
#include "qtdraw.h"

Line :: Line(QWidget * parent) 
:Qtdraw(parent){};

void Line :: render(){
   // paint.begin(parent);//
    paint.drawLine(10,10,10,50);
   // paint.end();
//have paint.begin and end in paint event method
//put render point for all shapes in paint event
//when activated use boolean to say if its line or circle render
}
