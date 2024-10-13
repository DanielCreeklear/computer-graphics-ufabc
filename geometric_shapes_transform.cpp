#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(-0.5, -0.5, 0.0);
    
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 0.5);
    glEnd();
    
    glPopMatrix();
    
    glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, 1.5);
        glVertex2f(-0.5, 1.5);
    glEnd();

    glFlush();
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL - Formas Geometricas");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
