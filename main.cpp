#include "drawing.h"
#include <QApplication>

int main(int argc, char **argv){
    
     QApplication app (argc, argv);
     
     Drawing d;
     d.show();
     return app.exec();
}
