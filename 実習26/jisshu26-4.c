#include <stdlib.h>
#include "glut.h"

#define WIDTH 500
#define HEIGHT 500

double dt = 25;
double ang = 0;	
double scale=1.0;

int last_y,
    last_x,
	dx, dy;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(1.0, 1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glColor3d(1.0, 1.0, 0.0);

	// モデルの変形
	glRotated(ang, 0, 1.0, 0);		// 回転 
	glScaled(scale, scale, scale);	// スケール 
	glutWireTeapot(2.5);

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
		last_x = x;
		last_y = y;
	}
}

void mouse_motion(int x, int y)
{
	// printf("%.2f\n", y, last_y, dy);

	// 移動量の計算   
	dy = y - last_y;
    dx = x - last_x;

	scale += (double)dy / 100;
	ang += dx;

	// 引き継ぐための値の更新
	last_y = y;
    last_x = x;

	printf("%.2f\n", scale);
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
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
