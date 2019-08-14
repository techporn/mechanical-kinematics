#include <stdlib.h>
#include "glut.h"

#define WIDTH 500
#define HEIGHT 500
double dt = 25;
double ang = 0;
int flag = 0;
int last_y = 0, last_x = 0;
double scale_y=1.0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(1.0, 1.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glColor3d(1.0, 1.0, 0.0);

	// モデルの変形
	glRotated(ang, 0, 1.0, 0);	// 回転
//	glScaled(1.0, scale_y, 1.0);	// スケール
	glutWireTeapot(2.5);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

// void timer(int val) {
// 	ang += 2.0;
// 	glutTimerFunc(dt, timer, 0);
// 	glutPostRedisplay();
// }

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		flag = 0;
		// last_x = -1.0 + (1.0-(-1.0))/WIDTH*(double)x;
		// last_y = 1.8 - (1.8 - (-0.2))/HEIGHT*(double)y;
		last_x = x;
		last_y = y;
	}
	else
	{
		flag = 1;
	}
}

void mouse_motion(int x, int y)
{
	double dx, dy;
	// 移動量の計算
	// int dy = y - last_y;
    dx = x - last_x;

	// scale_y += (double)dy;
	ang += dx;
	printf("%.2f\n", dx;);


	// // 引き継ぐための値の更新
	// last_y = y;
    // last_x = x;

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
	// glutTimerFunc(dt, timer, 0);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	init();
	glutMainLoop();
	return 0;
}
