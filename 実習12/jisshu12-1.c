#include "glut.h"

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3d(1, 1,1);

		glVertex2d(-0.4, 0.4);
		glVertex2d(0.4, 0.4);
		glVertex2d(0.4, 0.2);
		glVertex2d(-0.4, 0.2);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3d(1,1,1);

		glVertex2d(-0.1, 0.2);
		glVertex2d(-0.1, -0.4);
		glVertex2d(0.1, -0.4);
		glVertex2d(0.1, 0.2);
	glEnd();
	glFlush();
}

void init(void)
{
	glClearColor(0.0, 78/255, 162/255, 1.0);
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
