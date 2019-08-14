#include <stdlib.h>
#include "glut.h"

double dt = 25;
double ang = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(1.0, 1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glColor3d(1.0, 1.0, 0.0);
	glRotated(ang, 0, 1.0, 0);	// 回転
	glutWireTeapot(2.5);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void timer(int val) {
	ang += 2.0;
	glutTimerFunc(dt, timer, 0);
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(dt, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
