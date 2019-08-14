#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glut.h"

const double PI = 3.14159,
		     M = 3.0,
		     m = 1.0,
		     l = 0.5,
		     c = 0.5,
		     C = 1.0,
		     g = 9.8,
		     ADJ = 0.1;	// 調整用の係数
             
double D, f,
       x1_k, x1_k1,
	   x2_k, x2_k1,
	   x3_k, x3_k1,
	   x4_k, x4_k1, 
	   tim, dt, dx, dy;

int last_x;

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
		glVertex2d(0, -6.0);
		glVertex2d(0, 6.0);

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

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) {
		last_x = x;
	} else {
		f = 0;
	}
}

void mouse_motion(int x, int y)
{
	int dx;
	dx = (x - last_x) * ADJ;
	f += dx;
	last_x = x;
}

void timer(int id)
{
    // 計算
	x1_k1 = x1_k + x3_k * dt;
	x2_k1 = x2_k + x4_k * dt;
	x3_k1 = x3_k + (m*l*l * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) + 
					m*l*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;
	x4_k1 = x4_k + (-m * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) -
					(M + m)*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;

    // 再描画
	glutPostRedisplay();

    // 値の更新
	x1_k = x1_k1;
	x2_k = x2_k1;
	x3_k = x3_k1;
	x4_k = x4_k1;

	glutTimerFunc(10, timer, 0);
}

void init(void)
{
	x1_k = 0.0;
	x2_k = 30.0/180.0*PI;
	x3_k = 0.0;
	x4_k = 0.0;
	dt = 10e-3;
	D = ((M + m) * m*l*l - m*m*l);

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
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	glutTimerFunc(10, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
