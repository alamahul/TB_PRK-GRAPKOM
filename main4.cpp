#include <GL/glut.h>
#include <cmath>

// Posisi kamera
float camX = 0.0f, camY = 1.0f, camZ = 5.0f;

// Sudut rotasi kamera
float yaw = 0.0f;   // Rotasi horizontal (mengitari sumbu Y)
float pitch = 0.0f; // Rotasi vertikal (mengitari sumbu X)

// Sensitivitas gerakan
const float sensitivity = 0.1f;
const float speed = 0.1f; // Kecepatan pergerakan

void updateCamera() {
    // Arah kamera berdasarkan yaw dan pitch
    float radYaw = yaw * M_PI / 180.0f;
    float radPitch = pitch * M_PI / 180.0f;

    float lookX = cos(radPitch) * sin(radYaw);
    float lookY = sin(radPitch);
    float lookZ = cos(radPitch) * cos(radYaw);

    gluLookAt(
        camX, camY, camZ,                // Posisi kamera
        camX + lookX, camY + lookY, camZ + lookZ, // Titik pandang
        0.0f, 1.0f, 0.0f                 // Arah atas kamera
    );
}

void mouseMove(int x, int y) {
    static bool isWarp = false;
    static int lastX = 400, lastY = 300;

    if (isWarp) {
        isWarp = false;
        return;
    }

    int dx = x - lastX;
    int dy = y - lastY;

    yaw += dx * sensitivity;
    pitch -= dy * sensitivity;

    // Batasi pitch agar tidak melebihi 90 derajat
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    lastX = x;
    lastY = y;

    glutWarpPointer(400, 300); // Kembalikan pointer ke tengah layar
    isWarp = true;

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    float radYaw = yaw * M_PI / 180.0f;

    switch (key) {
    case 'w': // Maju
        camX += cos(radYaw) * speed;
        camZ -= sin(radYaw) * speed;
        break;
    case 's': // Mundur
        camX -= cos(radYaw) * speed;
        camZ += sin(radYaw) * speed;
        break;
    case 'a': // Ke kiri
        camX -= sin(radYaw) * speed;
        camZ -= cos(radYaw) * speed;
        break;
    case 'd': // Ke kanan
        camX += sin(radYaw) * speed;
        camZ += cos(radYaw) * speed;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("FPS Camera");

    glutDisplayFunc([]() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        updateCamera();

        // Gambar adegan
        glutSolidTeapot(3.0);

        glutSwapBuffers();
    });

    glutPassiveMotionFunc(mouseMove);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);
    glutSetCursor(GLUT_CURSOR_NONE); // Sembunyikan kursor
    glutWarpPointer(400, 300);       // Set kursor di tengah layar

    glutMainLoop();
    return 0;
}


