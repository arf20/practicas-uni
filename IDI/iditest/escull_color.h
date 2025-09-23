#ifndef ESCULL_COLOR_H
#define ESCULL_COLOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class EscullColor;
}
QT_END_NAMESPACE

class EscullColor : public QMainWindow
{
    Q_OBJECT

public:
    EscullColor(QWidget *parent = nullptr);
    ~EscullColor();

private:
    Ui::EscullColor *ui;
};
#endif // ESCULL_COLOR_H
