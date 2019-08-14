/*
    反発ありの放物運動シミュレーション
    マウスの位置によって物体の初速度が変わる
	複数個の物体を同時に存在させられる
 */

#include <stdlib.h>
#include "glut.h"


double mouse_x = 0, mouse_y = 1.5;
double dt=0.01;			// サンプリングタイム
int flag=0;				// マウスが押されているかのフラグ
double e=0.8;			// 反発係数
double M=1.0, c = 0.2;	//　定数
double tim=0, IKIOI=2.0;
double params[400];
int i,
	n=0,		// ボールの数
	PARAM_N=4;	// 状態変数の数

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

	for(i=0; i<n; ++i) {
		glColor3d(1.0, 1.0, 0.0);
		glPointSize(10);
			glBegin(GL_POINTS);
			glVertex2d(params[i*PARAM_N], params[i*PARAM_N+2]);
		glEnd();
	}

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void create_object() {

}

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		mouse_x = -0.5 + (7.5-(-0.5))/800*(double)x;
		mouse_y =  4.5 - (4.5-(-0.5))/500*(double)y;
		flag = 0;

		// 新しいボールの作成
		params[n*PARAM_N] = 0;
		params[n*PARAM_N+1] = mouse_x * IKIOI;
		params[n*PARAM_N+2] = 0;
		params[n*PARAM_N+3] = mouse_y * IKIOI;
		n++;
		glutPostRedisplay();
	}
	else
	{
		flag = 1;
	}
}

void timer(int id)
{
	glutTimerFunc(dt*1000, timer, 0);
	if(flag == 1)
	{
		// すべてのボールの軌道を計算する。
		for(i=0; i<n; ++i) {
			double x1_k = params[i*PARAM_N];
			double x2_k = params[i*PARAM_N+1];
			double x3_k = params[i*PARAM_N+2];
			double x4_k = params[i*PARAM_N+3];

			double x1_k1 = x1_k + x2_k*dt;
			double x2_k1 = x2_k + (-c/M*x2_k)*dt;
			double x3_k1 = x3_k + x4_k*dt;
			double x4_k1 = x4_k + (-c/M*x4_k - 9.8)*dt;

			// 反発処理
			if(x3_k1 <= 0)
			{
				x3_k1 = 0;
				x4_k1 = -e * x4_k1;
			}

			// 計算結果を保存する
			params[i*PARAM_N] = x1_k1;
			params[i*PARAM_N+1] = x2_k1;
			params[i*PARAM_N+2] = x3_k1;
			params[i*PARAM_N+3] = x4_k1;
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
	init();
	glutTimerFunc(dt*1000, timer, 0);
	glutMainLoop();
	return 0;
}
