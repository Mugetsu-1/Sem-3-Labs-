#include <GL/glut.h>

void initT() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
     glClearColor(0.1, 0.1, 0.1, 1.0);
}

void displayT() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw original triangle in Blue
    glColor3f(0.0, 0.0, 1.0); // Blue
    glBegin(GL_TRIANGLES);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.3, 0.5);
    glEnd();

   
    glPushMatrix(); // Save current transformation matrix
    glTranslatef(0.1f, 0.1f, 0.0f); // Translate by (0.2, 0.2)
   
    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_TRIANGLES);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.3, 0.5);
    glEnd();
   
    glPopMatrix(); // Restore transformation matrix

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Original and Translated Triangle");
    initT();
    glutDisplayFunc(displayT);
    glutMainLoop();
    return 0;
}   
