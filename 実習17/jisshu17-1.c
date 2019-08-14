#include <stdio.h>
#include <math.h>
#include "glut.h"

double mouse_x = 0, mouse_y = 1.5;
double dt=0.01;
int flag=0;
double x1_k, x2_k, x1_k1, x2_k1;
double e = 0.8;
double vy_0=0;
int y_0;
double pi = 3.14159, step=0.05, r=0.03;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2d(-0.8, 0);
	glVertex2d(0.8, 0);
	glEnd();

	glBegin(GL_POLYGON);
	    glColor3d(1.0, 1.0, 0.0);

        for(double i=0; i<2*pi; i+=step) {
            glVertex2d(mouse_x + r*cos(i), x1_k + r*sin(i));
        }
	glEnd();

	// glColor3d(1.0, 1.0, 0.0);
	// glPointSize(10);
	// glBegin(GL_POINTS);
	// glVertex2d(mouse_x, x1_k);
	// glEnd();
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
		x1_k = mouse_y;
		glutPostRedisplay();
	}
	else
	{
		flag = 1;
		x1_k = mouse_y;
		x2_k = vy_0;
	}
}

void mouse_motion(int x, int y)
{
	double dy;
	dy = y - y_0;
	vy_0 = -(double)dy/10;
	y_0 = y;
}

void timer(int id)
{
	glutTimerFunc(dt*1000, timer, 0);
	if(flag == 1)
	{
		x1_k1 = x1_k + x2_k*dt;
		x2_k1 = x2_k - 9.8*dt;
		x1_k = x1_k1;
		x2_k = x2_k1;
		if(x1_k <= 0)
		{
      		x1_k = 0;
			x2_k = -e * x2_k;
		}
	}
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
	glutMotionFunc(mouse_motion);
	init();
	glutTimerFunc(dt*1000, timer, 0);
	glutMainLoop();
	return 0;
}
