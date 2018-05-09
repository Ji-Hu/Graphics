#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include <math.h>
#define PI 3.141592

int delay = 20;

GLfloat e[3] = { 0.0,0.0,0.0 };
GLfloat a[3] = { 0.0,0.0,-1.0 };
GLfloat theta[2] = { 0.0,0.0 };
GLfloat delta1[2];
GLfloat delta2[2];
GLfloat delta3[2];

void reshape() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glFrustum(-1, 1, -1, 1, 1, 20.0);
	glEnable(GL_DEPTH_TEST);

	//glMatrixMode(GL_MODELVIEW);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(e[0], e[1], e[2], a[0], a[1], a[2], 0, 1, 0);


	glPushMatrix();
	glTranslatef(0, 0, 2);
	glColor3f(0.0, 0.8, 0.7);
	glutWireTeapot(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -2);
	glRotatef(90.0, 1,1 , 0);
	glColor3f(0.1, 0.2, 0.3);
	glutWireSphere(0.7, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0.5, 0);
	glColor3f(0.0, 1.0, 5.0);
	glutWireTeapot(0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.2, -1.5);
	glColor3f(0.3, 0.3, 1.0);
	glutWireCone(0.1, 0.2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0, 0);
	glRotatef(90, 1.0, 0.0, 1.0);
	glColor3f(0.3, 0.5, 1.0);
	glutWireCone(0.1, 0.2, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, 0.2, -0.1);
	glRotatef(90, 1.0, 0.0, 1.0);
	glColor3f(0.3, 0.5, 1.0);
	glutWireCube(0.8);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3, 0.1);
	glRotatef(90, 1.0, 0.0, 1.0);
	glColor3f(0.3, 0.4, 0.1);
	glutWireCube(1);
	glPopMatrix();

	glutSwapBuffers();
	glFlush();
}


void keyboard_handler(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		printf("x theta %f \n", theta[0]);
		e[0] += 0.01*sin((theta[0] * PI) / 180);
		e[2] -= 0.01*cos((theta[0] * PI )/ 180);
		a[0] += 0.01*sin((theta[0] * PI) / 180);
		a[2] -= 0.01*cos((theta[0] * PI )/ 180);
		printf("w pressed %f %f %f\n", e[0], e[1], e[2]);
		printf("pressed %f %f %f\n", a[0], a[1], a[2]);
		break;
	case 'a':
		e[0] -= 0.01*sin((theta[0] - 90) * PI / 180);
		e[2] += 0.01*cos((theta[0] - 90) * PI / 180);
		a[0] -= 0.01*sin((theta[0] - 90) * PI / 180);
		a[2] += 0.01*cos((theta[0] - 90) * PI / 180);
		printf("a pressed %f %f %f\n", e[0], e[1], e[2]);
		printf("pressed %f %f %f\n", a[0], a[1], a[2]);
		break;
	case 's':
		e[0] -= 0.01*sin(theta[0] * PI / 180);
		e[2] += 0.01*cos(theta[0] * PI / 180);
		a[0] -= 0.01*sin(theta[0] * PI / 180);
		a[2] += 0.01*cos(theta[0] * PI / 180);
		printf("s pressed %f %f %f\n", e[0], e[1], e[2]);
		printf("pressed %f %f %f\n", a[0], a[1], a[2]);
		break;
	case 'd':
		e[0] += 0.01*sin((theta[0] - 90) * PI / 180);
		e[2] -= 0.01*cos((theta[0] - 90) * PI / 180);
		a[0] += 0.01*sin((theta[0] - 90) * PI / 180);
		a[2] -= 0.01*cos((theta[0] - 90) * PI / 180);
		printf("d pressed %f %f %f\n", e[0], e[1], e[2]);
		printf("pressed %f %f %f\n", a[0], a[1], a[2]);
		break;
	case 'r':
		e[0] = 0.0; e[1] = 0.0; e[2] = 0.0;
		a[0] = 0.0, a[1] = 0.0; a[2] = -1.0;
		theta[0] = 0.0; theta[1] = 0.0;
	default:
		break;
	}
}


void mouse_handler(int btn, int state, int x, int y)
{

	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		delta1[0] = x;
		delta1[1] = y;
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {

		delta2[0] = x;
		delta2[1] = y;

		delta3[0] = (delta2[0] - delta1[0]) /100;
		delta3[1] = (delta2[1] - delta1[1]) /100;

		theta[0] += delta3[0]*5;
		theta[1] += delta3[1]*5;


			if (theta[0] > 360)
				theta[0] -= 360;
			if (theta[0] < -360)
				theta[0] += 360;
			if (theta[1] > 360)
				theta[1] -= 360;
			if (theta[1] < -360)
				theta[1] += 360;
	
		printf("mouse %f %f\n", delta1[0], delta1[1]);
		printf("mouse %f %f\n", delta2[0], delta2[1]);


		printf("theta %f %f\n", theta[0], theta[1]);

		a[0] = e[0] + sin((theta[0] * PI) / 180);
		a[1] = e[1] + sin((theta[1] * PI )/ 180);
		a[2] = e[2] + cos((360-theta[0] * PI) / 180);

	}
}

void timer(int t) {

	glutPostRedisplay();
	glutTimerFunc(delay, timer, t);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("assignment2 : FPS interface");

	glutTimerFunc(delay, timer, 0);
	glutKeyboardFunc(keyboard_handler);
	glutMouseFunc(mouse_handler);

	glutDisplayFunc(display);
	reshape();
	glutMainLoop();
	return 0;
}

