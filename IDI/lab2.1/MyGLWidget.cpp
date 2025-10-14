// MyGLWidget.cpp
#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

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

    glEnable(GL_DEPTH_TEST);
}

void MyGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    modelTransform();
    projectTransform();
    viewTransform();

    /*
    glBindVertexArray(VAO_Casa);
    glDrawArrays(GL_TRIANGLES, 0, 9);
    glBindVertexArray(0);
    */

    glBindVertexArray(VAO_model);
    glDrawArrays(GL_TRIANGLES, 0, m.faces().size() * 3);
}

void MyGLWidget::resizeGL(int width, int height) {
    BL2GLWidget::resizeGL(width, height);
}

void MyGLWidget::keyPressEvent(QKeyEvent *event) {
    BL2GLWidget::keyPressEvent(event);
}

void MyGLWidget::creaBuffers() {
    //BL2GLWidget::creaBuffers();

    m.load("../models/HomerProves.obj");


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
   
}



void MyGLWidget::modelTransform() {
    BL2GLWidget::modelTransform();
}


void MyGLWidget::carregaShaders() {
    BL2GLWidget::carregaShaders();
    projLoc = glGetUniformLocation(program->programId(), "proj");
    viewLoc = glGetUniformLocation(program->programId(), "view");
}

void MyGLWidget::projectTransform() {
    glm::mat4 proj = glm::perspective(float(M_PI)/2.0f, 1.0f, 0.4f, 3.0f);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}
void MyGLWidget::viewTransform() {
    glm::mat4 view = glm::lookAt(
        glm::vec3(0, 0, 1),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 1, 0)
    );

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}

