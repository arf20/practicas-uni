// MyGLWidget.h
#include "BL2GLWidget.h"
#include <QTimer>

#include "model.h"

class MyGLWidget : public BL2GLWidget {
    Q_OBJECT

    public:
        MyGLWidget(QWidget *parent=0);
        ~MyGLWidget();

        void initializeGL();
        void paintGL();
        void resizeGL(int width, int height);
        void keyPressEvent(QKeyEvent *event);
        //void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void creaBuffers();
        void modelTransform();
        void carregaShaders();

        void modelBoundinxBox();

        void init_camera();


        GLuint VAO_model = 0;
        GLuint VAO_terra = 0;

        GLuint projLoc = 0, viewLoc = 0;
        Model m;

        float rotacion = 0.0f, theta = 0.0f, psi = 0.0f, zoom = 1.0f;

        glm::vec3 model_bounding_box_center;

        QTimer timer;

    public slots:
        void animar();

    private:
        int printOglError(const char file[], int line, const char func[]);
};

