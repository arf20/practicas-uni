#include "LL2GLWidget.h"

#include <vector>

#include <QTimer>

class MyGLWidget : public LL2GLWidget {
  Q_OBJECT

  public:
    MyGLWidget(QWidget *parent);
    ~MyGLWidget();

    void paintGL() override;
    void modelTransformFantasma() override;
    void projectTransform1();
    void viewTransform1();
    void projectTransform2();
    void viewTransform2();

    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    void iniCamera() override;

  protected:
  
    virtual void keyPressEvent (QKeyEvent *event);
    virtual void iniEscena ();

    // per al moviment automàtic
    QTimer timer;

    // per moure la roda     
    float angleRoda;
    float velocitatRoda;
    bool girant;
    
  public slots:
    void girarRoda();

  private:
  
    int printOglError(const char file[], int line, const char func[]);
    int lastx = 0, lasty = 0;
    float psi = 0.0f, theta = M_PI/4.0f;
   
    // Aquí tots els atributs privats que necessitis
    float d = 10.0f;
	int cam = 1;
    float fantasmaX = 0.0f;
};

