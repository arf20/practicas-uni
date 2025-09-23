#include "numero_i_texto.h"
#include "ui_numero_i_texto.h"

NumeroITexto::NumeroITexto(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NumeroITexto)
{
    ui->setupUi(this);

}

NumeroITexto::~NumeroITexto()
{
    delete ui;
}

