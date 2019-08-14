#include "glut.h"
#include <math.h>

void display(void)
{
	double theta;
	double x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	for (theta=0;theta<=360;theta+=10)
	{
		x = 0.5*cos(theta/180*3.14);
		y = 0.5*sin(theta/180*3.14);
		glVertex2d(x, y);
	}
	glEnd();
	glFlush();
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
	init();
	glutMainLoop();
	return 0;
}
