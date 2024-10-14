#include <GL/glut.h>

float angleCube1 = 0.0f;
float angleCube2 = 0.0f;
float cameraX = 0.0f;
float cameraZ = -5.0f;
float rotationSpeed1 = 0.5f;
float rotationSpeed2 = 1.0f;

float cameraSpeed = 1.0f;


void init() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawColoredCube() {
    glBegin(GL_QUADS);
        // Face da frente (vermelho)
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);

        // Face de trás (verde)
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);

        // Face da esquerda (azul)
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, -0.5f);

        // Face da direita (amarelo)
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);

        // Face de cima (ciano)
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, -0.5f);
        glVertex3f(0.5f, 0.5f, 0.5f);
        glVertex3f(-0.5f, 0.5f, 0.5f);

        // Face de baixo (magenta)
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-0.5f, -0.5f, -0.5f);
        glVertex3f(-0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, 0.5f);
        glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();
}

void drawCube(float x, float y, float z, float rotationAngle) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f);
    drawColoredCube();
    glPopMatrix();
}

void drawChessboardGround() {
    float size = 1.0f;
    for (int i = -10; i < 10; ++i) {
        for (int j = -10; j < 10; ++j) {
            glBegin(GL_QUADS);
                if ((i + j) % 2 == 0) {
                    glColor3f(0.9f, 0.9f, 0.9f);
                } else {
                    glColor3f(0.2f, 0.2f, 0.2f);
                }
                glVertex3f(i * size, -0.5f, j * size);
                glVertex3f(i * size + size, -0.5f, j * size);
                glVertex3f(i * size + size, -0.5f, j * size + size);
                glVertex3f(i * size, -0.5f, j * size + size);
            glEnd();
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(cameraX, 0.0, cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawChessboardGround();
    drawCube(-2.0f, 1.0f, 0.0f, angleCube1);
    drawCube(2.0f, 1.0f, 0.0f, angleCube2);

    glutSwapBuffers();
}

void update(int value) {
    angleCube1 += rotationSpeed1;
    angleCube2 += rotationSpeed2;

    if (angleCube1 > 360) angleCube1 -= 360;
    if (angleCube2 > 360) angleCube2 -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void keyboard(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT: cameraX += cameraSpeed; break;
        case GLUT_KEY_LEFT:  cameraX -= cameraSpeed; break;
        case GLUT_KEY_UP:    cameraZ += cameraSpeed; break;
        case GLUT_KEY_DOWN:  cameraZ -= cameraSpeed; break;
    }
}

void handleKeys(unsigned char key, int x, int y) {
    if (key == '1') rotationSpeed1 = (rotationSpeed1 == 0.0f) ? 0.5f : 0.0f;
    if (key == '2') rotationSpeed2 = (rotationSpeed2 == 0.0f) ? 1.0f : 0.0f;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cena 3D Interativa com Cubos");

    init();
    
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutKeyboardFunc(handleKeys);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
