#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <GL/freeglut.h>

// Status untuk menyalakan atau mematikan pencahayaan
bool light1On = true; // Menyalakan cahaya 1
bool light2On = false; // Menyalakan cahaya 2

// Inisialisasi pencahayaan
void initLighting() {
    glEnable(GL_LIGHTING); // Aktifkan pencahayaan
    glEnable(GL_DEPTH_TEST); // Aktifkan depth test

    // Set parameter cahaya 1 (meja 1)
    GLfloat light1Ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light1Diffuse[] = { 1.0f, 0.0f, 0.0f, 1.0f }; // Cahaya merah untuk meja 1
    GLfloat light1Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light1Position[] = { 15.0f, 0.0f, 0.0f, 1.0f }; // Posisi cahaya 1

    glLightfv(GL_LIGHT0, GL_AMBIENT, light1Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light1Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light1Specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light1Position);

    // Set parameter cahaya 2 (meja 2)
    GLfloat light2Ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light2Diffuse[] = { 0.0f, 0.0f, 1.0f, 1.0f }; // Cahaya biru untuk meja 2
    GLfloat light2Specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light2Position[] = { -15.0f, 0.0f, 0.0f, 1.0f }; // Posisi cahaya 2

    glLightfv(GL_LIGHT1, GL_AMBIENT, light2Ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light2Diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light2Specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light2Position);
}

// Fungsi untuk menggambar objek
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up perspektif
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // Menyalakan cahaya yang aktif
    if (light1On) {
        glEnable(GL_LIGHT0); // Nyalakan cahaya 1
        glDisable(GL_LIGHT1); // Matikan cahaya 2
    } else if (light2On) {
        glDisable(GL_LIGHT0); // Matikan cahaya 1
        glEnable(GL_LIGHT1);  // Nyalakan cahaya 2
    }

    // Gambar meja 1 (terkena cahaya 1)
    glPushMatrix();
    glTranslatef(3.0f, -1.0f, 0.0f);  // Posisi meja 1
    glutSolidCube(2.0); // Gambar meja 1
    glPopMatrix();

    // Gambar meja 2 (terkena cahaya 2)
    glPushMatrix();
    glTranslatef(-3.0f, -1.0f, 0.0f);  // Posisi meja 2
    glutSolidCube(2.0); // Gambar meja 2
    glPopMatrix();

    glutSwapBuffers();
}

// Fungsi untuk menangani keyboard (untuk mengubah status pencahayaan)
void keyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        light1On = true;
        light2On = false;
    } else if (key == '2') {
        light1On = false;
        light2On = true;
    }
    glutPostRedisplay(); // Refresh tampilan
}

// Setup awal
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Background hitam
    initLighting();
}

// Fungsi utama
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Pencahayaan Dua Meja");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Menambahkan fungsi keyboard
    glutMainLoop();
    return 0;
}

