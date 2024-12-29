// Code Name : E Class

#include <GL/glut.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float objects = 10.0;
float PI = 3.146;
float radius = 40.0;
float rotationAngle = 0.0;
float rotation = 0.0;
float rotationCube = 0.0;
float aspect;

// Fungsi untuk menangi perubahan ukuran window
void reshape(int w, int h)
{
	if (h == 0) h = 1;
	aspect = (float)w / (float)h;
	
	glMatrixMode(GL_PROJECTION);
	
	glViewport(0, 0, w, h);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 1.0, 200.0);
	gluLookAt(0.0, 20.0, 70.0, 0.0, -10.0, 0.0, 0.0, 1.0, 0.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Fungsi untuk menangani input keyboard
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);
			break;
		case 'l':
			glEnable(GL_LIGHT0);
			break;
		case 'f':
			glDisable(GL_LIGHT0);
			break;
	}
}

void display()
{
	/* -------------------------------- Cube --------------------------------
    */
 glPushMatrix();
 glLineWidth(1);
 glTranslated(15.0, 0.0, 0.0);
 glRotated(0, 1.0, 1.0, 1.0);
 glColor3ub(162, 148, 249);
 glScalef(10.0, 10.0, 10.0);
 glutSolidCube(3.0);
 glPopMatrix();
 
 /* ----------------------------------------------------------------------*/
	// Buffers
	glutSwapBuffers();
	glutPostRedisplay();
	
}

void inisialisasi ()
{
	// pencahayaan
//	glEnable(GL_LIGHTING);
//	
//	GLfloat light_diffuse[4] = {1.0, 1.0, 1.0, 1.0};
//	GLfloat light_ambient[4] = {0.0, 0.0, 0.0, 1.0};
//	GLfloat light_specular[4] = {1.0, 1.0, 1.0, 1.0};
//	GLfloat light_position[4] = {0.0, 50.0, 50.0, 1.0};
//	
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//	
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_COLOR_MATERIAL);
//	
//	glClearColor(0.1, 0.1, 0.1, 1.0);
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	
	glutCreateWindow("2306163 | Alamahul Bayan | Pertemuan 6");
	// display
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	// keyboard
	glutKeyboardFunc(keyboard);
	
	// glutFullScreen();
	inisialisasi();
	
	glutMainLoop();
	return 0;
}


