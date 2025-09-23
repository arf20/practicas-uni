#ifndef NUMERO_I_TEXTO_H
#define NUMERO_I_TEXTO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class NumeroITexto;
}
QT_END_NAMESPACE

class NumeroITexto : public QMainWindow
{
    Q_OBJECT

public:
    NumeroITexto(QWidget *parent = nullptr);
    ~NumeroITexto();

private:
    Ui::NumeroITexto *ui;
};
#endif // NUMERO_I_TEXTO_H
