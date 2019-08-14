/*
    反発ありの放物運動シミュレーション
    マウスの位置によって物体の初速度が変わる
	原点からマウス座標までをゴム紐のように表現する

 */

#include <stdlib.h>
#include "glut.h"

double mouse_x = 0, mouse_y = 1.5;
double dt=0.01;
int flag=0;
double e=0.8;
double M=1.0, c = 0.2;
double x1_k, x1_k1, x2_k, x2_k1, x3_k, x3_k1, x4_k, x4_k1, tim=0;
double IKIOI = 2.0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex2d(0, 0);
		glVertex2d(7.5, 0);
		glVertex2d(0, 0);
		glVertex2d(0, 4.0);
	glEnd();
	glColor3d(1.0, 1.0, 0.0);
	glPointSize(10);
		glBegin(GL_POINTS);
		glVertex2d(x1_k, x3_k);
	glEnd();


    glColor3d(1.0, 1.0, 0.5);
    glBegin(GL_LINES);
        glVertex2d(0, 0);
        glVertex2d(mouse_x, mouse_y);
    glEnd();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void mouse_motion(int x, int y) {
	mouse_x = -0.5 + (7.5-(-0.5))/800*(double)x;
	mouse_y =  4.5 - (4.5-(-0.5))/500*(double)y;
	x1_k = 0;   	  // x座標
	x2_k = mouse_x*IKIOI;   // x方向の初速度
	x3_k = 0;   	  // y座標
	x4_k = mouse_y*IKIOI;   // y方向の初速度
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		mouse_x = -0.5 + (7.5-(-0.5))/800*(double)x;
		mouse_y =  4.5 - (4.5-(-0.5))/500*(double)y;
		flag = 0;
		x1_k = 0;   // x座標
		x2_k = mouse_x;   // x方向の初速度
		x3_k = 0;   // y座標
		x4_k = mouse_y;   // y方向の初速度
		glutPostRedisplay();
	}
	else
	{
		flag = 1;
		printf("%f, %f\n", x2_k, x4_k);
	}
}

void timer(int id)
{
	glutTimerFunc(dt*1000, timer, 0);
	if(flag == 1)
	{
		x1_k1 = x1_k + x2_k*dt;
		x2_k1 = x2_k + (-c/M*x2_k)*dt;
		x3_k1 = x3_k + x4_k*dt;
		x4_k1 = x4_k + (-c/M*x4_k - 9.8)*dt;
		x1_k = x1_k1;
		x2_k = x2_k1;
		x3_k = x3_k1;
		x4_k = x4_k1;

		// 反発処理
		if(x3_k <= 0)
		{
      		x3_k = 0;
			x4_k = -e * x4_k;
		}
	}
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-0.5, 7.5, -0.5, 4.5, -1.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	init();
	glutTimerFunc(dt*1000, timer, 0);
	glutMainLoop();
	return 0;
}
