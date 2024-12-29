#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

// Prototipe function
void drawText(float x, float y, float z, string text, int fontSize);

// Pembuatan Variable global

// Kartesius True/False
bool varKartesius = false;

const int width = 600;
const int height = 800;

float rot = 0;

bool lampu = false;

GLfloat eyeX = 0;
GLfloat eyeY = 7;
GLfloat eyeZ = 7;

GLfloat lookX = 0;
GLfloat lookY = 7;
GLfloat lookZ = 0;

void balok(float merah, float hijau, float biru) {
    glPushMatrix();


	
    // Atur properti material objek
    GLfloat mat_ambient[] = {merah*0.3, hijau*0.3, biru*0.3, 1.0f}; // Warna ambient
    GLfloat mat_diffuse[] = {merah, hijau, biru, 1.0f}; // Warna diffuse
    GLfloat mat_specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Warna specular
    
    GLfloat mat_shininess[] = {50.0f}; // Tingkat kilauan
 
     // Atur material objek
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    // Transformasi objek
    glLineWidth(1);
    glTranslated(0.0, 0.0, 0.0);
    glRotated(0, 0, 0, 0);
    glScalef(1.0, 1.0, 1.0);

    // Render kubus
    glutSolidCube(1.0);

    glPopMatrix();
}

void lantai (){
	glPushMatrix();
	glTranslatef(0.0, 0.0, 5.0);
	glScalef(15.0, 1.0, 25.0);
	balok(0.0f, 1.0f, 0.0f);
	glPopMatrix();
}

void dinding_kiri (){
	glPushMatrix();
	glTranslatef(-7.0, 5.0, 5.0);
	glScalef(1.0, 10.0, 25.0);
	balok(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void dinding_kanan(){
	glPushMatrix();
	glTranslatef(7.0, 5.0, 5.0);
	glScalef(1.0, 10.0, 25.0);
	balok(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void dinding_belakang(){
	glPushMatrix();
	glTranslatef(0.0, 5.0, -7.0);
	glScalef(15.0, 10.0, 1.0);
	balok(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void dinding_depan(){
	glPushMatrix();
	glTranslatef(0.0, 5.0, 17.0);
	glScalef(15.0, 10.0, 1.0);
	balok(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void atap (){
	glPushMatrix();
	glTranslatef(0.0, 10.0, 5.0);
	glScalef(15.0, 1.0, 25.0);
	balok(1.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void pintu (){
	glPushMatrix();
	glTranslatef(-6.5, 3.0, -4.0);
	glScalef(0.2, 7.0, 2.0);
	balok(0.3f, 0.3f, 0.3f);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-6.4, 3.0, -3.5);
	glScalef(0.1, 0.8, 0.1);
	balok(0.8f, 0.8f, 0.8f);
	glPopMatrix();
}

void bor (){
	glPushMatrix();
	glTranslatef(0.0, 5.0, -6.5);
	glScalef(6.0, 5.0, 0.5);
	balok(0.1f, 0.1f, 0.1f);
	glPopMatrix();
}

void AC (){
	glPushMatrix();
	glTranslatef(-6.0, 8.0, 0.0);
	glScalef(1.0, 2.0, 4.0);
	balok(0.9f, 0.2f, 0.2f);
	glPopMatrix();
}

void drawCartecius() {
	glDisable(GL_LIGHTING);
	
    glLineWidth(5);
    // Gambar teks untuk sumbu
    drawText(13.0, 0.5, 0.0, "X", 60);
    drawText(-13.0, 0.5, 0.0, "-X", 60);
    drawText(0.5, 13.0, 0.0, "Y", 60);
    drawText(0.5, -13.0, 0.0, "-Y", 60);
    drawText(0.0, 0.5, 23.0, "Z", 60);
    drawText(0.0, 0.5, -13.0, "-Z", 60);

    // Gambar garis untuk sumbu
    glBegin(GL_LINES);
    // x line
    glVertex3f(-30.0, 0.0, 0.0);
    glVertex3f(30.0, 0.0, 0.0);

    // y line
    glVertex3f(0.0, -30.0, 0.0);
    glVertex3f(0.0, 30.0, 0.0);

    // z line
    glVertex3f(0.0, 0.0, -30.0);
    glVertex3f(0.0, 0.0, 30.0);
    glEnd();

	glEnable(GL_LIGHTING);
}

void light(){
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // Atur posisi sumber cahaya
    GLfloat light_position[] = {0.0f, 10.0f, 0.0f, 1.0f};
    GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f}; // Warna ambient
    GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Warna diffuse
    GLfloat light_specular[] = {0.5f, 0.5f, 0.5f, 0.5f}; // Warna specular
    GLfloat light_off[] = {0.0f, 0.0f, 0.0f, 0.0f}; // lampu mati
    
    
    if (lampu == true){
    	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0,  GL_SPECULAR, light_specular);	
	}else{
		glLightfv(GL_LIGHT0, GL_POSITION, light_off);
    	glLightfv(GL_LIGHT0, GL_AMBIENT, light_off);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_off);
		glLightfv(GL_LIGHT0,  GL_SPECULAR, light_off);		
	}
    
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, 0, 1, 0);
    glRotatef(rot, 0, 1, 0);
    
    if (varKartesius == true ){
    	drawCartecius();
	}
    
    light();
    
	lantai();
	dinding_kiri();
	dinding_kanan();
	dinding_belakang();
	dinding_depan();
	atap();
	pintu();
	bor ();
	AC();
//	cout <<"Mata X :"<<eyeX<<" Lihat X :"<<lookX<<endl;
//	cout <<"Mata Y :"<<eyeY<<" Lihat Y :"<<lookY<<endl;
//	cout <<"Mata Z :"<<eyeZ<<" Lihat Z :"<<lookZ<<endl;
    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'q':
    	rot++;
        break;
    case 'e':
        rot--;
        break;	
    case 'd':
    	eyeX++;
    	lookX++;
        break;
    case 'a':
        eyeX--;
    	lookX--;
        break;
    case 'w':
        eyeY++;
        lookY++;
        break;
    case 's':
        eyeY--;
        lookY--;
        break;
    case 'z':
        eyeZ++;
        lookZ++;
        break;
    case 'x':
        eyeZ--;
        lookZ--;
        break;
	case 'k':
		if (varKartesius == false){
			varKartesius = true;
		}else{
			varKartesius = false;	
		}
        break;
    case 'l':
    	if (lampu == false){
    		lampu = true;
		}else if(lampu == true){
			lampu = false;
		}
		break;
	}
    glutPostRedisplay();
}

void drawText(float x, float y, float z, string text, int fontSize)
{
	glColor3ub(0, 255, 255); // ubah waena
	glPushMatrix();
	glTranslatef(x, y, z);
	// Set Ukuran font sesuai dengan paramenter fontsize
	glScalef(fontSize / 8.0f, fontSize / 13.0f, 1.0f);
	// Tentukan posisi raster sesuai dengan ukuran font yang disesuaikan
	glRasterPos2f(0, 0);	
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char *)text.c_str());
	glPopMatrix();
	glEnd();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(height, width);
    glutCreateWindow("Ruangan Kelas TB");
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

