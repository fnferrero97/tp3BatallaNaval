#include "Ventana/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow ventanaBatallaNaval;
    ventanaBatallaNaval.show();
    return a.exec();
}
