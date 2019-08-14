#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "glut.h"

time_t t; 
struct tm now;
double hour, min, sec;

void display(void)
{
	double sec_rad;
	glClear(GL_COLOR_BUFFER_BIT);
	sec_rad = (15 - sec)/15*3.14159/2;	// 15秒の時が0度なので15からの差で表現
	glBegin(GL_LINES);
	glColor3d(1.0, 0.0, 0.0);
	glVertex2d(0, 0);
	glVertex2d(0.9*cos(sec_rad), 0.9*sin(sec_rad));
	glEnd();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
}

void timer(int id)
{
	
	glutTimerFunc(500, timer, 0);
	t = time(0); 
	now = *localtime(&t); 
	hour = now.tm_hour; 
	min = now.tm_min; 
	sec = now.tm_sec; 
	glutPostRedisplay();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(500, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
