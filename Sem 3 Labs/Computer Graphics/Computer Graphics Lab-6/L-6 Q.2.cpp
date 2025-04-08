#include <GL/glut.h>

// Rotation angles
float angleX = 0.0f;
float angleY = 0.0f;

void initR() {
    glEnable(GL_DEPTH_TEST);  // Enable depth testing
    glClearColor(0.1, 0.1, 0.1, 1.0); // Dark background
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Set the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0); // Perspective projection
    glMatrixMode(GL_MODELVIEW);
}

void drawCube() {
    glBegin(GL_QUADS);

    // Front (Red)
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back (Green)
    glColor3f(0, 1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    // Left (Blue)
    glColor3f(0, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    // Right (Yellow)
    glColor3f(1, 1, 0);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    // Top (Cyan)
    glColor3f(0, 1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    // Bottom (Magenta)
    glColor3f(1, 0, 1);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);

    glEnd();
}

void displayR() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Move back and rotate
    glTranslatef(0.0f, 0.0f, -7.0f);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);

    drawCube();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP: angleX -= 5; break;
        case GLUT_KEY_DOWN: angleX += 5; break;
        case GLUT_KEY_LEFT: angleY -= 5; break;
        case GLUT_KEY_RIGHT: angleY += 5; break;
    }
    glutPostRedisplay();
}
/*
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Rotating Cube");

    initR();

    glutDisplayFunc(displayR);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}  */
