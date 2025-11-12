#ifndef MYLCDNUMBER_H
#define MYLCDNUMBER_H

#include <QLCDNumber>
#include <QObject>
#include <QWidget>

class MyLCDNumber : public QLCDNumber
{
    Q_OBJECT
public:
    MyLCDNumber(QObject *parent);


};

#endif // MYLCDNUMBER_H
