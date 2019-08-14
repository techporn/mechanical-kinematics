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

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {

    scanf("%s", &moji);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
} 