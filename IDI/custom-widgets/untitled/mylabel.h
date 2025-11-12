#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent);

public slots:
    void setTrunc(int trunc);
    void setText(QString text);
private:
    int trunc = INT_MAX;
};

#endif // MYLABEL_H
