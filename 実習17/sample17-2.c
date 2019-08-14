#include <stdlib.h>
#include "glut.h"

double mouse_x = 0, mouse_y = 1.5;
double dt=0.01;
int flag=0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(-0.8, 0);
	glVertex2d(0.8, 0);
	glEnd();
	glColor3d(1.0, 1.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2d(mouse_x, mouse_y);
	glEnd();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		mouse_x = -1.0 + (1.0-(-1.0))/500*(double)x;
		mouse_y = 1.8 - (1.8 - (-0.2))/500*(double)y;
		flag = 0;
		glutPostRedisplay();
	}
	else
		flag = 1;
}

void timer(int id)
{
	glutTimerFunc(dt*1000, timer, 0);
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -0.2, 1.8, -1.0, 1.0);
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
	glutMouseFunc(mouse);
	init();
	glutTimerFunc(dt*1000, timer, 0);
	glutMainLoop();
	return 0;
}
