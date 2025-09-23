#include "rellotge_digital.h"
#include "ui_rellotge_digital.h"

RellotgeDigital::RellotgeDigital(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RellotgeDigital)
{
    ui->setupUi(this);
}

RellotgeDigital::~RellotgeDigital()
{
    delete ui;
}


