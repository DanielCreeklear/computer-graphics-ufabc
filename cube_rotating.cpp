#include <GL/glut.h>


float angle = 0.0f;


void drawCube() {
    glBegin(GL_QUADS);
        // Face da frente
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f( 0.5,  0.5,  0.5);
        glVertex3f(-0.5,  0.5,  0.5);

        // Face de trás
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5,  0.5, -0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f( 0.5, -0.5, -0.5);

        // Face da direita
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f( 0.5, -0.5, -0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f( 0.5,  0.5,  0.5);
        glVertex3f( 0.5, -0.5,  0.5);

        // Face da esquerda
        glColor3f(1.0, 1.0, 0.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f(-0.5,  0.5,  0.5);
        glVertex3f(-0.5,  0.5, -0.5);

        // Face de cima
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(-0.5,  0.5, -0.5);
        glVertex3f( 0.5,  0.5, -0.5);
        glVertex3f( 0.5,  0.5,  0.5);
        glVertex3f(-0.5,  0.5,  0.5);

        // Face de baixo
        glColor3f(0.0, 1.0, 1.0);
        glVertex3f(-0.5, -0.5, -0.5);
        glVertex3f(-0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5,  0.5);
        glVertex3f( 0.5, -0.5, -0.5);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Define a posição da câmera
    gluLookAt(0.0, 0.0, 5.0, // Posição da câmera
              0.0, 0.0, 0.0, // Para onde a câmera está olhando
              0.0, 1.0, 0.0); // Direção "cima" da câmera

    glRotatef(angle, 1.0, 1.0, 0.0);
    drawCube();

    glutSwapBuffers();
}

void timer(int value) {
    angle += 1.0f;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Cubo 3D");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
