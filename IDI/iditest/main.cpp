#include "mainwindow.h"
#include "rellotge_digital.h"
#include "escull_color.h"
#include "numero_i_texto.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NumeroITexto w;
    w.show();
    return a.exec();
}
