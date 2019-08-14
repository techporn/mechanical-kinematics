#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include "glut.h"
#include <math.h>

char moji[21];

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0, 1.0, 0.0);
    glRasterPos2d(-0.2, 0.0);

    char* p = moji;
    while(*p != '\0') {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18 , *p);
        p++;
    }

    glFlush();
}

void resize(int w, int h) {
    sprintf(moji, "%d x %d", w, h);

    glViewport(0, 0, w, h);
    glLoadIdentity();
	glOrtho(-1.0*w/500, 1.0*w/500, -1.0*h/500, 1.0*h/500, -1.0, 1.0);
    display();

}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
    return 0;
} 