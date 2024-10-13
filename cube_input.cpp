#include <GL/glut.h>

float angleX = 0.0f; // Ângulo de rotação ao longo do eixo X
float angleY = 0.0f; // Ângulo de rotação ao longo do eixo Y
float posX = 0.0f;   // Posição do cubo ao longo do eixo X
float posY = 0.0f;   // Posição do cubo ao longo do eixo Y
float posZ = -5.0f;  // Posição do cubo ao longo do eixo Z

void drawCube() {
    glBegin(GL_QUADS);
    
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5 + posX, -0.5 + posY,  0.5 + posZ);
    glVertex3f( 0.5 + posX, -0.5 + posY,  0.5 + posZ);
    glVertex3f( 0.5 + posX,  0.5 + posY,  0.5 + posZ);
    glVertex3f(-0.5 + posX,  0.5 + posY,  0.5 + posZ);
    
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5 + posX, -0.5 + posY, -0.5 + posZ);
    glVertex3f(-0.5 + posX,  0.5 + posY, -0.5 + posZ);
    glVertex3f( 0.5 + posX,  0.5 + posY, -0.5 + posZ);
    glVertex3f( 0.5 + posX, -0.5 + posY, -0.5 + posZ);
    
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f( 0.5 + posX, -0.5 + posY, -0.5 + posZ);
    glVertex3f( 0.5 + posX,  0.5 + posY, -0.5 + posZ);
    glVertex3f( 0.5 + posX,  0.5 + posY,  0.5 + posZ);
    glVertex3f( 0.5 + posX, -0.5 + posY,  0.5 + posZ);
    
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.5 + posX, -0.5 + posY, -0.5 + posZ);
    glVertex3f(-0.5 + posX, -0.5 + posY,  0.5 + posZ);
    glVertex3f(-0.5 + posX,  0.5 + posY,  0.5 + posZ);
    glVertex3f(-0.5 + posX,  0.5 + posY, -0.5 + posZ);
    
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.5 + posX,  0.5 + posY, -0.5 + posZ);
    glVertex3f( 0.5 + posX,  0.5 + posY, -0.5 + posZ);
    glVertex3f( 0.5 + posX,  0.5 + posY,  0.5 + posZ);
    glVertex3f(-0.5 + posX,  0.5 + posY,  0.5 + posZ);
    
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5 + posX, -0.5 + posY, -0.5 + posZ);
    glVertex3f(-0.5 + posX, -0.5 + posY,  0.5 + posZ);
    glVertex3f( 0.5 + posX, -0.5 + posY,  0.5 + posZ);
    glVertex3f( 0.5 + posX, -0.5 + posY, -0.5 + posZ);

    glEnd();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    drawCube();
    glutSwapBuffers();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            angleX += 5.0f; 
            break;
        case GLUT_KEY_DOWN:
            angleX -= 5.0f;
            break;
        case GLUT_KEY_LEFT:
            angleY -= 5.0f;
            break;
        case GLUT_KEY_RIGHT:
            angleY += 5.0f;
            break;
    }
    glutPostRedisplay();
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
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
