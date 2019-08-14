#include <stdlib.h>
#include "glut.h"
#define ARM1_LENGTH 3
#define ARM2_LENGTH 2

double theta1=0, theta2=0;
int x_0, y_0; 

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
	GLfloat material_red[] = {1.0, 0.0, 0.0, 1.0};
	GLfloat material_blue[] = {0.0, 0.0, 1.0, 1.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glPushMatrix();
	
	drawAxes(5.0);
	
	glRotated(theta1, 0, 1, 0);
	glTranslated(ARM1_LENGTH*0.5, 0, 0);
	glPushMatrix();
	glScaled(ARM1_LENGTH, 1.0, 1.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material_red);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glTranslated(ARM1_LENGTH*0.5, 1.0, 0);
	glRotated(theta2, 0, 1, 0);
	glTranslated(ARM2_LENGTH*0.5, 0.0, 0);
	glScaled(ARM2_LENGTH , 1.0, 1.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material_blue);
	glutSolidCube(1.0);
	
	glPopMatrix();
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
		y_0 = y;
}

void mouse_motion(int x, int y)
{
	int dx, dy;
	dx = x - x_0;
	theta1 += (double)dx/5;
	x_0 = x;
	dy = y - y_0;
	theta2 += (double)dy/5;
	y_0 = y;
}

void timer(int id)
{
	glutTimerFunc(33, timer, 0);
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

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
	glutTimerFunc(33, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
