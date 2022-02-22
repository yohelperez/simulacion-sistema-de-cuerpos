/*este programa sirve para simular el rebote de unos cuerpos.
 * requiere:clases, interfaz grafica y librerias especiales.
 * garantiza: simular correctamente el movimiento de cada bola.*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
