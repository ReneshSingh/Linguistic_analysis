#include <QApplication>
#include "projectx.h"

int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    ProjectX *a = new ProjectX;
    QObject::connect(a->submit, SIGNAL(clicked()), a, SLOT(analysis( )));
    QObject::connect(a->report, SIGNAL(clicked()), a, SLOT(results( )));
    QObject::connect(a->quit, SIGNAL(clicked()), &app, SLOT(quit()));
    return app.exec();
}
