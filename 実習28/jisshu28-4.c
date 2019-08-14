#include <stdlib.h>
#include <math.h>
#include "glut.h"

const double PI = 3.14159,
		     M = 3.0,
		     m = 1.0,
		     l = 0.5,
		     c = 0.5,
		     C = 1.0,
		     g = 9.8,
		     ADJ = 0.1;	// 調整用の係数
             
double D, f,
       x1_k, x1_k1,
	   x2_k, x2_k1,
	   x3_k, x3_k1,
	   x4_k, x4_k1, 
	   tim, dt, dx, dy;

int last_x;
double angle=0;

void drawAxes(double length)
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		// x axis
		glColor3d(1.0, 1.0, 0.0);
		glVertex3d(-length, 0.0, 0.0);
		glVertex3d(length, 0.0, 0.0);

		// y axis
		glColor3d(1.0, 0.0, 0.0);
		glVertex3d(0.0, -length, 0.0);
		glVertex3d(0.0, length, 0.0);

		// z axis
		glColor3d(0.0, 0.0, 1.0);
		glVertex3d(0.0, 0.0, -length);
		glVertex3d(0.0, 0.0, length);

	glEnd();
	glEnable(GL_LIGHTING);
}

void display(void)
{
	// material color
	GLfloat material_blue[] = {0.0, 0.0, 1.0, 1.0};
	GLfloat material_red[] = {1.0, 0.0, 0.0, 1.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0*sin(angle), -0.2, 2.0*cos(angle),   // camera position
              0.0, -0.5, 0.0,   // 
              0.0, 1.0, 0.0);   // up vector
	
	drawAxes(5.0);
	
	// himo
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		glColor3d(1.0, 1.0, 0.0);
		glVertex3d(x1_k, 0.1, 0.0);
		glVertex3d(l*sin(x2_k) + x1_k, -l*cos(x2_k), 0);
	glEnd();
	glEnable(GL_LIGHTING);

	// blue tama
	glPushMatrix();
		glRotated(x2_k *180.0/PI, 0, 0, 1);
		glTranslated(x1_k, -l, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material_blue);
		glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	// daisya
	glPushMatrix();
		glTranslated(x1_k, 0.1, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material_red);
		glutSolidCube(0.2);
	glPopMatrix();


	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN) {
		last_x = x;
	}
}

void mouse_motion(int x, int y)
{
	int dx, dy;
	dx = x - last_x;

	angle += (double)dx/50;
	last_x = x;
}

void timer(int id)
{
    // 計算
	x1_k1 = x1_k + x3_k * dt;
	x2_k1 = x2_k + x4_k * dt;
	x3_k1 = x3_k + (m*l*l * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) + 
					m*l*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;
	x4_k1 = x4_k + (-m * (m*l*x4_k*x4_k*x2_k - C*x3_k + f) -
					(M + m)*(m*g*l*x2_k + c*l*l*x4_k))/D * dt;

    // 再描画
	glutPostRedisplay();

    // 値の更新
	x1_k = x1_k1;
	x2_k = x2_k1;
	x3_k = x3_k1;
	x4_k = x4_k1;

	glutTimerFunc(10, timer, 0);
}

void init(void)
{
	GLfloat light_position[]={100.0, 100.0, 0.0, 1};
	GLfloat light_ambient[]={0.2, 0.2, 0.2, 1.0};
	GLfloat light_specular[]={0.1, 0.1, 0.1, 1.0};
	GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 0.2, 20.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	x1_k = 0.0;
	x2_k = 30.0/180.0*PI;
	x3_k = 0.0;
	x4_k = 0.0;
	dt = 10e-3;
	D = ((M + m) * m*l*l - m*m*l);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	glutTimerFunc(dt*1000, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
