#include <stdlib.h>
#include <math.h>
#include "glut.h"

#define PI 3.14159

double dt=0.01, m=1, l=0.5, c=0.3;
double x_k[2], x_k1[2];
double angle;
int x_0; 

void drawAxes(double length)
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3d(1.0, 1.0, 0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(length, 0.0, 0.0);
	glColor3d(1.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, length, 0.0);
	glColor3d(0.0, 0.0, 1.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, length);
	glEnd();
	glEnable(GL_LIGHTING);
}

void display(void)
{
	GLfloat material_blue[] = {0.0, 0.0, 1.0, 1.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.0*sin(angle), -0.5, 2.0*cos(angle),   // camera position
              0.0, -0.5, 0.0,   // 
              0.0, 1.0, 0.0);   // up vector
	
	drawAxes(5.0);
	
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
	glColor3d(1.0, 1.0, 0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(l*sin(x_k[0]), -l*cos(x_k[0]), 0);
	glEnd();
	glEnable(GL_LIGHTING);

	glRotated(x_k[0] *180.0/PI, 0, 0, 1);
	glTranslated(0, -l, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material_blue);
	glutSolidSphere(0.1, 10, 10);
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
		x_0 = x;
}

void mouse_motion(int x, int y)
{
	int dx, dy;
	dx = x - x_0;
	angle += (double)dx/50;
	x_0 = x;
}

void timer(int id)
{
	glutTimerFunc(dt*1000, timer, 0);
	x_k1[0] = x_k[0] + x_k[1]*dt;
	x_k1[1] = x_k[1] + (-9.8/l*sin(x_k[0]) - c/m*x_k[1])*dt;
	x_k[0] = x_k1[0];
	x_k[1] = x_k1[1];
	glutPostRedisplay();
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
	x_k[0] = 30.0/180.0*PI;
	x_k[1] = 0;
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
