#ifndef RELLOTGE_DIGITAL_H
#define RELLOTGE_DIGITAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RellotgeDigital;
}
QT_END_NAMESPACE

class RellotgeDigital : public QMainWindow
{
    Q_OBJECT

public:
    RellotgeDigital(QWidget *parent = nullptr);
    ~RellotgeDigital();

private:
    Ui::RellotgeDigital *ui;
};
#endif // RELLOTGE_DIGITAL_H
