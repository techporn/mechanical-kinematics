// jisshu14-1
#include <stdlib.h>
#include "glut.h"

#define W 500
#define H 500
unsigned char moji;
double mouse_x=0 , mouse_y=0 ;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 0.0);
	glRasterPos2d(mouse_x , mouse_y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, moji);
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
	moji = key;
    mouse_x = ((double)x - 0.5*W) / (0.5*W);
    mouse_y = -((double)y - 0.5*H) / (0.5*H);
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
	glutInitWindowSize(W, H);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}