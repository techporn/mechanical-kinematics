#include "GLUT/glut.h"

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-0.5, 0.5);
	glVertex2d(-0.5, -0.5);
	glVertex2d(0.5, -0.5);
	glVertex2d(0.5, 0.5);
	glEnd();
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glLoadIdentity();
	glOrtho(-5.0*w/500, 5.0*w/500, -5.0*h/500, 5.0*h/500, -1.0, 1.0);
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
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
