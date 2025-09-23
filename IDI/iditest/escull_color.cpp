#include "escull_color.h"
#include "ui_escull_color.h"

EscullColor::EscullColor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EscullColor)
{
    ui->setupUi(this);
}

EscullColor::~EscullColor()
{
    delete ui;
}


