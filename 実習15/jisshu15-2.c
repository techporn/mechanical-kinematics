#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "glut.h"

time_t t; 
struct tm now;
double hour, min, sec;
double pi = 3.14159, step=0.05, r=1.0;

void display(void)
{
	double sec_rad, min_rad, hour_rad;
	glClear(GL_COLOR_BUFFER_BIT);
	sec_rad = (15 - sec)/15*3.14159/2;	// 15秒の時が0度なので15からの差で表現
	min_rad = (15 - min)/15*3.14159/2;	// 
	hour_rad = (3 - hour)/3*3.14159/2;	// 

	// フレームの表示
	glBegin(GL_POLYGON);
		glColor3d(1.0, 1.0, 1.0);

        for(double i=0; i<2*pi; i+=step) {
            glVertex2d(r*cos(i), r*sin(i));
        }
	glEnd();

	// 目盛りの表示
	glBegin(GL_LINES);
        glColor3d(0.0, 0.0, 0.0);
		for(int i=0; i<12; i++) {
			glVertex2d(cos(i*pi/6), sin(i*pi/6));
			if (i % 3 == 0) {
				glVertex2d(0.9*cos(i*pi/6), 0.9*sin(i*pi/6));
			} else {
				glVertex2d(0.95*cos(i*pi/6), 0.95*sin(i*pi/6));
			}
		}
	glEnd();


	glBegin(GL_LINES);
        // 秒針の表示
        glColor3d(1.0, 0.0, 0.0);
        glVertex2d(0, 0);
        glVertex2d(0.9*cos(sec_rad), 0.9*sin(sec_rad));

        // 分針の表示
        glColor3d(0.0, 1.0, 0.0);
        glVertex2d(0, 0);
        glVertex2d(0.9*cos(min_rad), 0.9*sin(min_rad));

        // 時針の表示
        glColor3d(0.0, 0.0, 1.0);
        glVertex2d(0, 0);
        glVertex2d(0.9*cos(hour_rad), 0.9*sin(hour_rad));
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
	sec = now.tm_sec; 
	min = now.tm_min + sec/60; 
	hour = now.tm_hour % 12 + min/60; 
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
