#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glut.h"

double dt=0.01, m=1, l=0.5, c=0.5;
double x_k[2], x_k1[2], tim=0;
int x_0, flag=0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_LINES);
	glColor3d(1.0, 1.0, 1.0);
	glVertex2d(-0.6, 0);
	glVertex2d(0.6, 0);
	glVertex2d(0, 0);
	glVertex2d(l*sin(x_k[0]), -l*cos(x_k[0]));
	glEnd();
	glPointSize(30);
	glBegin(GL_POINTS);
	glColor3d(1.0, 1.0, 0.0);
	glVertex2d(l*sin(x_k[0]), -l*cos(x_k[0]));
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
		flag = 0;
		x_0 = x;
		x_k[1] = 0;
	}
	else {
		flag = 1;
	}
}

void mouse_motion(int x, int y)
{
	int dx;
	dx = x - x_0;
	x_k[0] += (double)dx/400;
	x_0 = x;
}

void timer(int id)
{
	glutTimerFunc(dt*1000, timer, 0);
	tim += dt;
	if(flag == 1)
	{
		x_k1[0] = x_k[0] + x_k[1]*dt;
		x_k1[1] = x_k[1] + (-9.8/l*sin(x_k[0]) - c/m*x_k[1])*dt;
		x_k[0] = x_k1[0];
		x_k[1] = x_k1[1];
	}
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.6, 0.6, -0.8, 0.4, -1.0, 1.0);
	x_k[0] = 0;
	x_k[1] = 0;
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
	glutMotionFunc(mouse_motion);
	glutTimerFunc(dt*1000, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
