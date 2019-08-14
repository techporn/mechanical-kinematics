#include <stdlib.h>
#include <math.h>
#include "glut.h"

double theta = 0;
double d_theta = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(cos(theta), sin(theta));
	glVertex2d(-sin(theta), cos(theta));
	glVertex2d(-cos(theta), -sin(theta));
	glVertex2d(sin(theta), -cos(theta));
	glEnd();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
	if(key == 'a') d_theta += 0.05;
	if(key == 'd') d_theta -= 0.05;
	if(key == ' ') d_theta = 0;
}

void timer(int id)
{
		glutTimerFunc(33, timer, 0);
		theta += d_theta;
		glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
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
	glutTimerFunc(33, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
