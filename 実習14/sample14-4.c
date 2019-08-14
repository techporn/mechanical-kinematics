#include <stdlib.h>
#include "glut.h"

double length = 0.3;
int y_0; 

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2d(-length, length);
	glVertex2d(-length, -length);
	glVertex2d(length, -length);
	glVertex2d(length, length);
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		y_0 = y;
}

void mouse_motion(int x, int y)
{
	int dy;
	dy = y - y_0;
	length += (double)dy/500;
	if(length < 0) length = 0;
	if(length >1) length = 1;
	y_0 = y;
	glutPostRedisplay();
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
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	init();
	glutMainLoop();
	return 0;
}
