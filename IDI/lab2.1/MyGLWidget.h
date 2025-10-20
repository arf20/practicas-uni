// MyGLWidget.h
#include "BL2GLWidget.h"

#include "model.h"

class MyGLWidget : public BL2GLWidget {
    Q_OBJECT

    public:
        MyGLWidget(QWidget *parent=0) : BL2GLWidget(parent) {}
        ~MyGLWidget();

        void initializeGL();
        void paintGL();
        void resizeGL(int width, int height);
        void keyPressEvent(QKeyEvent *event);
        void creaBuffers();
        void modelTransform();
        void carregaShaders();

        void projectTransform();
        void viewTransform();

        GLuint VAO_model = 0;
        GLuint VAO_terra = 0;

        GLuint projLoc = 0, viewLoc = 0;
        Model m;

        float rotacion = 0.0f;

    private:
        int printOglError(const char file[], int line, const char func[]);
};

