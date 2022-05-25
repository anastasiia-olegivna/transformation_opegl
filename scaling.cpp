#include <GL/glut.h>
#include <Windows.h>

char myChar[] = { "OpenGL scaling" };

void myInt() {
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
	glClear(GL_COLOR_BUFFER_BIT);
}
void getBitmapRexn() {
	glRasterPos2d(100, 450);
	for (int i = 0; i < strlen(myChar);++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, myChar[i]);
	}
}
void figure() //originalPrimitve
{
	glColor3f(0, 0, 1);
	glRecti(100, 10, 200, 50);
}
void getTranslation() {
	glTranslatef(30, 20, 0);
}
void getScaling() {
	glScalef(3, 5, 0);
	figure();
}
void getTransformation() {
	figure();
	getScaling();
	glFlush();
}
void getMyTransformation() {
	glPushMatrix();
	figure();
	glPopMatrix();

	glPushMatrix();
	getTranslation();
	glPopMatrix();

	glFlush();
}

int main(int arg, char*argv[]) {
	glutInit(&arg, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutCreateWindow("Scaling algo");
	myInt();
	glutDisplayFunc(getTransformation);
	//glutDisplayFunc(getMyTransformation);
	glutMainLoop();
	return 0;
}