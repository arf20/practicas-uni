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

    public slots:
        void animar();
        void setFov(int fov);
        void setModelPatricio();
        void setModelLegoman();
        void setProjectionPerspective();
        void setProjectionOrthogonal();
        void setScale(int scale);
        void setPhi(int phi);
        void setTheta(int theta);

    signals:
        void scaleChanged(int scale);
        void phiChanged(int phi);
        void thetaChanged(int theta);

    private:
        int printOglError(const char file[], int line, const char func[]);

        GLuint VAO_model[2] = { };
        GLuint VAO_terra = 0;

        GLuint projLoc = 0, viewLoc = 0;
        Model m[2];

        float rotacion = 0.0f, theta = 0.0f, phi = 0.0f, zoom = 1.0f;

        glm::vec3 model_bounding_box_center;

        QTimer timer;

        float fov = M_PI*60.0f/180.0f;
        int mid = 0, projid = 0;
};

