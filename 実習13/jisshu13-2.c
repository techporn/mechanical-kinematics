#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include "glut.h"
#include <math.h>

void display(void)
{
	double theta, r=0, N=5;
	double x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);

	for (theta=0; theta<=(360*N); theta+=10)
	{
		x = r*cos((theta/180)*3.14);
		y = r*sin((theta/180)*3.14);
		r = theta / (360*N);
		glVertex2d(x, y);
	}
	
	glEnd();
	glFlush();
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
	glOrtho(-1.0*w/500, 1.0*w/500, -1.0*h/500, 1.0*h/500, -1.0, 1.0);
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
	return 0;
}
