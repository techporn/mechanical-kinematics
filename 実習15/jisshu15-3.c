#include <stdlib.h>
#include <math.h>
#include "glut.h"

double pos_x=0, pos_y=0, speed=0.05;
double delay = 33;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0, 1.0, 0.0);
    glPointSize (10.0) ;
    glBegin ( GL_POINTS );
    glVertex2d ( pos_x , pos_y );
	glEnd();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 27) exit(0);
	if(key == GLUT_KEY_UP) pos_y += speed;
	if(key == GLUT_KEY_DOWN) pos_y -= speed;
	if(key == GLUT_KEY_LEFT) pos_x -= speed;
	if(key == GLUT_KEY_RIGHT) pos_x += speed;

    // speed
	if(key == 'w') speed += 0.05;
	if(key == 'x') speed -= 0.05;
    
    // printf("%f\n", delay);
//	if(key == ' ') d_theta = 0;
}

void timer(int id)
{
		glutTimerFunc(delay, timer, 0);
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
    glutSpecialFunc(keyboard);
	glutTimerFunc(33, timer, 0);
	init();
	glutMainLoop();
	return 0;
}
