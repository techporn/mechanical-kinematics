#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glut.h"

#define PI 3.14159
#define M 3.0
#define m 1.0
#define l 0.5
#define c 0.5
#define C 1.0
#define g 9.8
#define f 0
#define D ((M + m) * m*l*l - m*m*l)


double  x1_k1,
		x2_k1,
		x3_k1,
		x4_k1, tim;

double x1_k = 0.0;
double x2_k = 30.0/180.0*PI;
double x3_k = 0.0;
double x4_k = 0.0;
double dt = 10e-3;


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// daisya
	glBegin(GL_POINTS);
		glColor3d(1.0, 0.0, 0.0);
		glVertex2d(x1_k, 0);
	glEnd();

	glBegin(GL_LINES);
		glColor3d(1.0, 1.0, 1.0);
		// x axis
		glVertex2d(-0.6, 0);
		glVertex2d(0.6, 0);

		// y axis
		glVertex2d(0, -1.0);
		glVertex2d(0, 1.0);

		// himo
		glVertex2d(x1_k, 0);
		glVertex2d(l*sin(x2_k) + x1_k, -l*cos(x2_k));
	glEnd();


	// tama
	glPointSize(30);
	glBegin(GL_POINTS);
		glColor3d(1.0, 1.0, 0.0);
		glVertex2d(l*sin(x2_k) + x1_k, -l*cos(x2_k));
	glEnd();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void timer(int id)
{
	glutTimerFunc(10, timer, 0);
	x1_k1 = x1_k + x3_k * dt;
	x2_k1 = x2_k + x4_k * dt;
	x3_k1 = x3_k + (m*l*l * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) + 
					m*l*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;
	x4_k1 = x4_k + (-m * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) -
					(M + m)*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;
	glutPostRedisplay();
	// printf("%f\n", x1_k);

	x1_k = x1_k1;
	x2_k = x2_k1;
	x3_k = x3_k1;
	x4_k = x4_k1;
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.6, 0.6, -0.8, 0.4, -1.0, 1.0);
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
	glutTimerFunc(10, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
