#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include "glm/glm.hpp"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();
    
  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL();

    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL();
 
    // resize - Es cridat quan canvia la mida del widget
    virtual void resizeGL(int width, int height);  

  private:
    void creaBuffers();
    void carregaShaders();
    void keyPressEvent(QKeyEvent *event) override;
    
    // attribute locations
    GLuint vertexLoc, colorLoc;
    
    // Program
    QOpenGLShaderProgram *program;

    GLuint VAO[2];
    GLint ample, alt;
    glm::mat4 scale = glm::mat4(1.0);
    float rot = 0.0f;
    glm::vec3 trans = glm::vec3(0.0, 0.0, 0.0);
};

