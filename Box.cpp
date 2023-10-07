#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

GLfloat angle = 0.0f;

void drawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glRotatef(angle, 1.0f, 1.0f, 1.0f);

	glColor3f(0.0f, 0.5f, 1.0f);
	glutWireCube(5.0f);

	glutSwapBuffers();

	angle += 0.5f;

	if (angle > 360.0f) angle -= 360.0f;

}

void setup(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Box.cpp");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);
	glutIdleFunc(drawScene);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
	
}