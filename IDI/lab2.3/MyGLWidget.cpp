// MyGLWidget.cpp
#include "MyGLWidget.h"


#include <iostream>
#include <stdio.h>
#include <limits.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

MyGLWidget::MyGLWidget(QWidget* parent) : BL2GLWidget(parent) {
    setMouseTracking(true);

    connect(&timer, SIGNAL(timeout()), this, SLOT(animar()));
    timer.start(16);
}

int MyGLWidget::printOglError(const char file[], int line, const char func[]) {
    GLenum glErr;
    int retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr) {
        case 0x0500:
            error = "GL_INVALID_ENUM";
            break;
        case 0x501:
            error = "GL_INVALID_VALUE";
            break;
        case 0x502: 
            error = "GL_INVALID_OPERATION";
            break;
        case 0x503:
            error = "GL_STACK_OVERFLOW";
            break;
        case 0x504:
            error = "GL_STACK_UNDERFLOW";
            break;
        case 0x505:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = "unknown error!";
    }

    if (glErr != GL_NO_ERROR) {
        printf("glError in file %s @ line %d: %s function: %s\n",
            file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {

}

void MyGLWidget::initializeGL() {
    BL2GLWidget::initializeGL();
    modelBoundinxBox();

    glEnable(GL_DEPTH_TEST);
}

void MyGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    init_camera();

    glm::mat4 transform(1.0f);
    transform = glm::scale(transform, glm::vec3(escala));
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);

    glBindVertexArray(VAO_terra);
    glDrawArrays(GL_TRIANGLES, 0, 9);
    glBindVertexArray(0);

    modelTransform();

    glBindVertexArray(VAO_model);
    glDrawArrays(GL_TRIANGLES, 0, m.faces().size() * 3);
}

void MyGLWidget::resizeGL(int width, int height) {
    BL2GLWidget::resizeGL(width, height);
}

void MyGLWidget::keyPressEvent(QKeyEvent *event) {
    makeCurrent();
    switch (event->key()) {
        case Qt::Key_S: { // escalar a més gran
            escala += 0.05;
        } break;
        case Qt::Key_D: { // escalar a més petit
            escala -= 0.05;
        } break;
        case Qt::Key_R: { // rotar 
            rotacion += M_PI/4.0;
        } break;
        case Qt::Key_Z: {
            zoom *= 0.95;
        } break;
        case Qt::Key_X: {
            zoom *= 1.05;
        } break;
        default: event->ignore(); break;
    }

    update();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event) {
    makeCurrent();

    static QPoint last_pos = { -1, -1 };
    QPoint pos = event->pos();
    if (last_pos.x() == -1) {
        last_pos = pos;
        return;
    }

    if (event->buttons() == Qt::LeftButton) {
        psi     += (M_PI/180.0f)*(pos.x() - last_pos.x());
        theta   += (M_PI/180.0f)*(pos.y() - last_pos.y());

    }

    update();
    last_pos = pos;
}

void MyGLWidget::animar() {
    makeCurrent();
    rotacion += M_PI/8.0f; // exemple del que es vol animar
    update();
}

void MyGLWidget::creaBuffers() {
    m.load("../models/Patricio.obj");

    glGenVertexArrays(1, &VAO_model);
    glBindVertexArray(VAO_model);

    GLuint VBO_model[2];
    glGenBuffers(2, VBO_model);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_model[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size() * 3 * 3,
        m.VBO_vertices(), GL_STATIC_DRAW);


    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_model[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size() * 3 * 3,
        m.VBO_matdiff(), GL_STATIC_DRAW);

    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);


    glGenVertexArrays(1, &VAO_terra);
    glBindVertexArray(VAO_terra);
   
    GLuint VBO_terra[2];
    glGenBuffers(2, VBO_terra);

    float terra_size = 5.0f;
    float terra_edges = terra_size / 2.0f;
    glm::vec3 terra_vertex[] = {
        { -terra_edges, 0.0f, -terra_edges },
        { terra_edges,  0.0f, -terra_edges },
        { terra_edges,  0.0f, terra_edges },
        { -terra_edges, 0.0f, -terra_edges },
        { terra_edges,  0.0f, terra_edges },
        { -terra_edges, 0.0f, terra_edges }
    };

    glm::vec3 terra_color[] = {
        {0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5},
        {0.5, 0.5, 0.5}
    };

    glBindBuffer(GL_ARRAY_BUFFER, VBO_terra[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(terra_vertex),
        terra_vertex, GL_STATIC_DRAW);
    
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertexLoc);

    glBindBuffer(GL_ARRAY_BUFFER, VBO_terra[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(terra_color),
        terra_color, GL_STATIC_DRAW);

    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(colorLoc);
}

void MyGLWidget::modelBoundinxBox() {
    //float x_min = FLT_MAX, x_max = FLT_MIN, y_min = FLT_MAX, y_max = FLT_MIN, z_min = FLT_MAX, z_max = FLT_MIN;

    auto v = m.vertices();
    float x_min = v[0], x_max = v[0], y_min = v[1], y_max = v[1], z_min = v[2], z_max = v[2];
    for (size_t i = 0; i < m.vertices().size(); i += 3) {
        if (v[i+0] < x_min) x_min = v[i+0];
        if (v[i+0] > x_max) x_max = v[i+0];
        if (v[i+1] < y_min) y_min = v[i+1];
        if (v[i+1] > y_max) y_max = v[i+1];
        if (v[i+2] < z_min) z_min = v[i+2];
        if (v[i+2] > z_max) z_max = v[i+2];
    }

    model_bounding_box_center = glm::vec3(
        (x_min + x_max) / 2.0f,
        y_min,
        (z_min + z_max) / 2.0f
    );
    
    escala = 4.0f / abs(y_max - y_min);

}

void MyGLWidget::modelTransform() {
    glm::mat4 transform(1.0f);
    transform = glm::scale(transform, glm::vec3(escala));
    transform = glm::rotate(transform, rotacion, glm::vec3(0.0f, 1.0f, 0.0f));
    transform = glm::translate(transform, -model_bounding_box_center);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}


void MyGLWidget::carregaShaders() {
    BL2GLWidget::carregaShaders();
    projLoc = glGetUniformLocation(program->programId(), "proj");
    viewLoc = glGetUniformLocation(program->programId(), "view");
}

void MyGLWidget::init_camera() {
    glm::vec3 obs = glm::vec3(0, 1, 8);
    glm::vec3 vrp = glm::vec3(0, 0, 0);
    glm::vec3 up  = glm::vec3(0, 1, 0);

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -8.0f));
    view = glm::rotate(view, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    view = glm::rotate(view, theta, glm::vec3(1.0f, 0.0f, 0.0f));
    view = glm::rotate(view, psi, glm::vec3(0.0f, 1.0f, 0.0f));
    view = glm::translate(view, -vrp);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    float d = 8;
    float r = d / 2.0f;
    float a = asin(r / d);
    float ratio = (float)ample / (float)alt;
    float fov = ratio > 1.0f ? 2.0f * a : 2.0f * atan(tan(a) / ratio);
    glm::mat4 proj = glm::perspective(zoom * fov, ratio, d - r, d + r);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

