/////////////////////////////////          
// box.cpp
//
// This program draws a wire box.
//
// Sumanta Guha.
/////////////////////////////////
#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h> 

GLfloat angle = 0.0f;

void drawBalok(GLfloat width, GLfloat height, GLfloat depth) {
    GLfloat halfWidth = width / 2.0f;
    GLfloat halfHeight = height / 2.0f;
    GLfloat halfDepth = depth / 2.0f;

    glBegin(GL_QUADS);

    //glColor3f(0.0, 0.5, 1.0);

    // Sisi depan
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, halfHeight, halfDepth);

    // Sisi belakang
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Sisi kiri
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);

    // Sisi kanan
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);

    // Sisi atas
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f(-halfWidth, halfHeight, -halfDepth);
    glVertex3f(halfWidth, halfHeight, -halfDepth);
    glVertex3f(halfWidth, halfHeight, halfDepth);
    glVertex3f(-halfWidth, halfHeight, halfDepth);

    // Sisi bawah
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex3f(-halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, -halfDepth);
    glVertex3f(halfWidth, -halfHeight, halfDepth);
    glVertex3f(-halfWidth, -halfHeight, halfDepth);

    glEnd();
}

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);     //berputar pada poros y

    //5 horizontal
    glPushMatrix();
    glTranslatef(0.0, 1.0, 0.0);
    drawBalok(0.15f, 0.15f, 5.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.5, 0.0);
    drawBalok(0.15f, 0.15f, 4.5f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    drawBalok(0.15f, 0.15f, 4.5f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -0.5, 0.0);
    drawBalok(0.15f, 0.15f, 4.5f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    drawBalok(0.15f, 0.15f, 4.5f);
    glPopMatrix();

    //4 vertikal
    //pojok kanan
    glPushMatrix();
    glTranslatef(0.0, -0.17, 2.3);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //belakang pojok kanan
    glPushMatrix();
    glTranslatef(1.0, -0.3, 2.3);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //pojok kiri
    glPushMatrix();
    glTranslatef(0.0, -0.17, -2.3);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //belakang pojok kiri
    glPushMatrix();
    glTranslatef(1.0, -0.3, -2.3);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //kiri kedua
    glPushMatrix();
    glTranslatef(0.0, -0.17, -0.8);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();
    //kanan kedua
    glPushMatrix();
    glTranslatef(0.0, -0.17, 0.8);
    drawBalok(0.15f, 2.5f, 0.15f);
    glPopMatrix();

    //sambungan kanan
    glPushMatrix();
    glTranslatef(0.5, 0.9, 2.3);
    drawBalok(1.0f, 0.1f, 0.15f);
    glPopMatrix();
    //sambungan kiri
    glPushMatrix();
    glTranslatef(0.5, 0.9, -2.3);
    drawBalok(1.0f, 0.1f, 0.15f);
    glPopMatrix();

    glutSwapBuffers();

    angle += 0.07f;

    if (angle > 360.0f) angle -= 360.0f;


    //glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);

    //glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    //glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    //glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    //glutInitWindowPosition(100, 100);
    glutCreateWindow("Pagar.cpp");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutIdleFunc(drawScene);
    //glutKeyboardFunc(keyInput);

    //glewExperimental = GL_TRUE;
    //glewInit();

    //setup();

    glutMainLoop();
}

