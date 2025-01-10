/*
Ramdhani = 84 baris
Agna = 81 baris
Alamahul = 98 baris
*/
//-------------------------------------------------------
// Ramdhani Sulaeman Burhanudin
// 2306161
#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut.h>
using namespace std;

bool varKartesius = false;

const int width = 600;
const int height = 800;

float rot = 0;

bool lampu = false;

float eyeX = 0;
float eyeY = 7;
float eyeZ = 7;

float lookX = 0;
float lookY = 7;
float lookZ = 0;
//----------------------------------------------------end

//-------------------------------------------------------
// Alamahul Bayan
// 2306163
void drawText(float x, float y, float z, string text, int fontSize)
{
	glColor3ub(255, 255, 255); // ubah warna
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(fontSize / 8.0f, fontSize / 13.0f, 1.0f); // Set Ukuran font sesuai dengan paramenter fontsize
	glRasterPos2f(0, 0);	// Tentukan posisi raster sesuai dengan ukuran font yang disesuaikan
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char *)text.c_str());
	glPopMatrix();
	glEnd();
}

void balok(float merah = 0.0, float hijau = 0.0, float biru = 0.0, float kilauan = 0.0) {
    glPushMatrix();
    // Atur properti material objek
    float mat_ambient[] = {merah*0.2, hijau*0.2, biru*0.2, 1.0f}; // Warna ambient
    float mat_diffuse[] = {merah, hijau, biru, 1.0f}; // Warna diffuse
    float mat_specular[] = {kilauan, kilauan, kilauan, 1.0f}; // Warna specular
    float mat_shininess[] = {35.0f}; // Tingkat kilauan
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

void light(){
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    // Atur posisi sumber cahaya
    GLfloat light_position[] = {0.0f, 7.0f, 0.0f, 1.0f}; // Posisi sumber cahaya
    GLfloat light_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Warna ambient
    GLfloat light_diffuse[] = {0.7f, 0.7f, 0.7f, 1.0f}; // Warna diffuse
    GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f}; // Warna specular
    GLfloat light_off[] = {0.0f, 0.0f, 0.0f, 0.0f}; // lampu mati
 
    if (lampu == true){
    	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
		glLightfv(GL_LIGHT0,  GL_SPECULAR, light_specular);	
	}else{
    	glLightfv(GL_LIGHT0, GL_AMBIENT, light_off);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_off);
		glLightfv(GL_LIGHT0,  GL_SPECULAR, light_off);		
	} 
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

//---------------------------------------------------end

//-------------------------------------------------------
// Ramdhani Sulaeman Burhanudin
// 2306161

void lantai (){
	glPushMatrix();
	glTranslatef(0.0, 0.0, 5.0);
	glScalef(15.0, 1.0, 25.0);
	balok(0.2f, 0.2f, 0.2f);
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

void bor (){
	glPushMatrix();
	glTranslatef(0.0, 5.0, -6.5);
	glScalef(6.0, 5.0, 0.5);
	balok(0.8f, 0.8f, 0.8f, 0.7f);
	glPopMatrix();
}

//-------------------------------------------------------
// Agna Fadia
// 2306145

void AC (){
	glPushMatrix();
	glTranslatef(-6.0, 8.0, 0.0);
	glScalef(1.0, 2.0, 4.0);
	balok(0.92f, 0.92f, 0.92f, 0.0f);
	glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, 1, 2.0, 100.0);
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
//----------------------------------------------------end

//-------------------------------------------------------
// Ramdhani Sulaeman Burhanudin
// 2306161

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

//----------------------------------------------------end
