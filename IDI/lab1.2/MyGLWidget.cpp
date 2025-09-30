
//#include <GL/glew.h>
#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget(QWidget* parent) : QOpenGLWidget(parent), program(NULL) {
    setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
}

MyGLWidget::~MyGLWidget() {
    if (program != NULL)
        delete program;
}

void MyGLWidget::initializeGL() {
    // Cal inicialitzar l'ús de les funcions d'OpenGL
    initializeOpenGLFunctions();
    
    glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
    carregaShaders();
    creaBuffers();
}

void MyGLWidget::paintGL() {
    // En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
    // useu els paràmetres que considereu (els que hi ha són els de per defecte)
  
    glClear(GL_COLOR_BUFFER_BIT);  // Esborrem el frame-buffer
    
    // Activem l'Array a pintar 
    glBindVertexArray(VAO[0]);
    
    // Pintem l'escena
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    // Desactivem el VAO
    glBindVertexArray(VAO[1]);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void MyGLWidget::resizeGL(int w, int h) {
    // Aquest codi és necessari únicament per a MACs amb pantalla retina.
    ample = w;
    alt = h;
}

void MyGLWidget::creaBuffers() {
    glm::vec3 Vertices[6];
    Vertices[0] = glm::vec3(-1.0, -1.0, 0.0);
    Vertices[1] = glm::vec3(1.0, 0.0, 0.0);
    Vertices[2] = glm::vec3(1.0, -1.0, 0.0);
    Vertices[3] = glm::vec3(0.0, 1.0, 0.0);
    Vertices[4] = glm::vec3(0.0, 1.0, 0.0);
    Vertices[5] = glm::vec3(0.0, 0.0, 1.0);

    
    // Creació del Vertex Array Object (VAO) que usarem per pintar
    glGenVertexArrays(1, VAO);
    glBindVertexArray(VAO[0]);

    // Creació del buffer amb les dades dels vèrtexs
    GLuint VBO[1];
    glGenBuffers(1, VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(vertexLoc);
    glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(colorLoc);

    // Desactivem el VAO
    glBindVertexArray(0);
}

void MyGLWidget::carregaShaders()
{
    // Creem els shaders per al fragment shader i el vertex shader
    QOpenGLShader fs (QOpenGLShader::Fragment, this);
    QOpenGLShader vs (QOpenGLShader::Vertex, this);
    // Carreguem el codi dels fitxers i els compilem
    fs.compileSourceFile("shaders/basicShader.fs");
    vs.compileSourceFile("shaders/basicShader.vs");
    // Creem el program
    program = new QOpenGLShaderProgram(this);
    // Li afegim els shaders corresponents
    program->addShader(&fs);
    program->addShader(&vs);
    // Linkem el program
    program->link();
    // Indiquem que aquest és el program que volem usar
    program->bind();

    // Obtenim identificador per a l'atribut “vertex” del vertex shader
    vertexLoc = glGetAttribLocation(program->programId(), "vertex");
    colorLoc = glGetAttribLocation(program->programId(), "color");
}
