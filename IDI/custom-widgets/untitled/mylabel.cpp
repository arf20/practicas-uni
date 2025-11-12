#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) {}



void MyLabel::setTrunc(int trunc) {
    this->trunc = trunc;
    setText(this->text());
}

void MyLabel::setText(QString text) {
    text.truncate(trunc);
    QLabel::setText(text);
}

