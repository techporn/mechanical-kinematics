#include "glut.h"

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3d(0, 0, 0.8);
		glVertex2d(-0.5, -0.5);
		glVertex2d(-0.5, 0.5);
		glVertex2d(0.5, 0.5);
		glVertex2d(0.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3d(0, 0.5, 0.8);
		glVertex2d(-0.4, -0.4);
		glVertex2d(-0.4, 0);
		glVertex2d(0.4, 0.4);
		glVertex2d(0.4, -0.4);
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
