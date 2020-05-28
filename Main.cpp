#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]){
    QApplication *app = new QApplication(argc,argv);
    MainWindow *mw = new MainWindow( );
    mw->show();
    app->setApplicationVersion("2.5");
    return app->exec();
}
