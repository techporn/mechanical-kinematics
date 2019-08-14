#include "glut.h"
#include <math.h>

void display(void)
{
    double i,
           pi = 3.14,
           r = 0.5,
           step = 0.05;

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
		glColor3d(0.76, 0.13, 0.28, 0);

        for(i=0; i<2*pi; i+=step) {
            glVertex2d(r*cos(i), r*sin(i));
        }
	glEnd();
	glFlush();
}

void init(void)
{
	glClearColor(1,1,1, 1.0);
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
