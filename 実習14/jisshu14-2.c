#include <stdlib.h>
#include "glut.h"

double mouse_x = 0, mouse_y = 0;
int shift_active = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    if (shift_active) {
        glColor3d(1.0, 0.0, 0.0);
    } else {
        glColor3d(1.0, 1.0, 0.0);
    }
    
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2d(mouse_x, mouse_y);
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
	{
		mouse_x = ((double)x - 250)/250;
		mouse_y = -((double)y - 250)/250;
        shift_active = (glutGetModifiers() == GLUT_ACTIVE_SHIFT);

		glutPostRedisplay();
	}
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
	init();
	glutMainLoop();
	return 0;
}