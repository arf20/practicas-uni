#include "MyGLWidget.h"
#include <iostream>
#include <stdio.h>

#include <glm/gtc/type_ptr.hpp>

#include <QElapsedTimer>

#define printOpenGLError() printOglError(__FILE__, __LINE__)
#define CHECK() printOglError(__FILE__, __LINE__,__FUNCTION__)
#define DEBUG() std::cout << __FILE__ << " " << __LINE__ << " " << __FUNCTION__ << std::endl;

MyGLWidget::MyGLWidget(QWidget *parent=0) : LL2GLWidget(parent) {
    connect(&timer, SIGNAL(timeout()), this, SLOT(girarRoda())); // per al moviment de la roda
    timer.start(16); 
}

int MyGLWidget::printOglError(const char file[], int line, const char func[]) {
    GLenum glErr;
    int    retCode = 0;

    glErr = glGetError();
    const char * error = 0;
    switch (glErr)
    {
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
    if (glErr != GL_NO_ERROR)
    {
        printf("glError in file %s @ line %d: %s function: %s\n",
                             file, line, error, func);
        retCode = 1;
    }
    return retCode;
}

MyGLWidget::~MyGLWidget() {

}

void MyGLWidget::iniEscena() {
    LL2GLWidget::iniEscena();

    // Paràmetres moviment roda
    angleRoda = 0;
    velocitatRoda = 0.25;
}

void MyGLWidget::keyPressEvent(QKeyEvent* event) {
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_Left: {
        if (fantasmaX < 0.4f)
            fantasmaX += 0.4f;
    } break;
    case Qt::Key_Right: {
        if (fantasmaX > -0.4f)
            fantasmaX -= 0.4f;
    } break;
    case Qt::Key_C: { 
        if (cam == 1) cam = 2;
        else cam = 1;
    } break;
    case Qt::Key_A: { 
        velocitatRoda = 0.0f;
    } break;
    case Qt::Key_E: {
        velocitatRoda = 0.25f;
    } break;
    case Qt::Key_R: {
        psi = 0.0f;
        theta = M_PI / 4.0f;
        velocitatRoda = 0.25f;
    } break;
    default: event->ignore(); break;
  }
  update();
}

void MyGLWidget::mousePressEvent(QMouseEvent *e) {
    xClick = e->x();
    yClick = e->y();
    lastx = lasty = 0;

    if (e->button() & Qt::LeftButton &&
        ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
    {
        DoingInteractive = ROTATE;
    }
}

void MyGLWidget::mouseReleaseEvent(QMouseEvent *) {
    DoingInteractive = NONE;
    lastx = lasty = 0;
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e) {
    makeCurrent();

    xClick = e->x();
    yClick = e->y();

    update();
}


void MyGLWidget::girarRoda() {
    // mètode que implementa el que ha de fer l'aplicació cada cop que el timer
    // fa timeout.
    makeCurrent();
    //printf("test\n");
    static QElapsedTimer deltaTimer;
    angleRoda += velocitatRoda;// * float(deltaTimer.restart()) * 0.001f;
    update();
}

void MyGLWidget::paintGL() {
    glViewport(0, 0, ample, alt);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    iniCamera();

    // Rodas - La roda té 72 cubs, un cub cada 5 graus
    glBindVertexArray(VAO_Cub);

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 360; i += 5) {
            modelTransformCub(alcades[j][i/5], float(i) + angleRoda, 20.0f, float((2*j) - 2));
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
    }
    
    // Fantasma
    glBindVertexArray(VAO_Fantasma);
    modelTransformFantasma();
    glDrawArrays(GL_TRIANGLES, 0, fantasma.faces().size()*3);

    glBindVertexArray(0);
}

void MyGLWidget::modelTransformFantasma() {
    glm::mat4 TG(1.f);
    TG = glm::scale(TG, glm::vec3(escalaFantasma/5.0f, escalaFantasma/5.0f, escalaFantasma/5.0f));
    TG = glm::translate(TG, -centreBaseFantasma);
    TG = glm::rotate(TG, float(M_PI)/2.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    TG = glm::translate(TG, glm::vec3(fantasmaX, 3.75f, 0.0f));
    
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &TG[0][0]);
}

void MyGLWidget::iniCamera() {
    if (cam == 1) {
        projectTransform1();
        viewTransform1();
    } else {
        projectTransform2();
        viewTransform2();
    }
}

void MyGLWidget::projectTransform1() {
    glm::mat4 Proj(1.0f);
    Proj = glm::perspective(float(M_PI/3.0), ra, d, d + 70.0f);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform1() {
    glm::vec3 vrp(0, 20, 50);
 
    if (DoingInteractive == ROTATE && lastx != 0) {
        theta -= factorAngleY * float(lasty - yClick);
        psi -= factorAngleX * float(lastx - xClick);
        lastx = xClick;
        lasty = yClick;
    } else {
        lastx = xClick;
        lasty = yClick;
    }


    glm::mat4 VM(1.0f);

    //View = glm::lookAt(glm::vec3(10,10,50), glm::vec3(10,10,0), glm::vec3(0,1,0));
   
    VM = glm::translate(VM, -vrp);
    VM = glm::rotate(VM, psi, glm::vec3(0.0f, 1.0f, 0.0f));
    VM = glm::rotate(VM, theta, glm::vec3(1.0f, 0.0f, 0.0f));
    VM = glm::rotate(VM, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
    VM = glm::translate(VM, glm::vec3(0.0f, 0.0f, -float(d)));

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(VM));
}

void MyGLWidget::projectTransform2() {
    glm::mat4 Proj(1.0f);
    Proj = glm::perspective(float(M_PI/3.0), ra, 0.1f, 40.0f);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::viewTransform2() {
    glm::mat4 VM = glm::lookAt(glm::vec3(-5.0f, 25.0f, 0.0f), glm::vec3(0.0f, 23.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(VM));
}


