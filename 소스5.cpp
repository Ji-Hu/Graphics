/*
#include <gl/glut.h>
#include <stdlib.h>



void init();
void display();

int main(int argc, char* argv[])
{
glutInit(&argc, (char**)argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutCreateWindow("Prog07: first 3D program");
glutDisplayFunc(display);		//�׷��ִ�

init();
glutMainLoop(); //�̺�Ʈ loop

return 0;
}

void init() //�ʱ�ȭ
{
glClearColor(1.0, 1.0, 1.0, 1.0); //RGB ����
glOrtho(0.0, 50.0, 0.0, 50.0, -50.0, 50.0);//��ǥ�� ����
glEnable(GL_DEPTH_TEST);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void display()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(15, 15, 35); glVertex3f(35, 15, 35); glVertex3f(35, 35, 35); glVertex3f(15, 35, 35);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(15,15,35); glVertex3f(35,15,35); glVertex3f(40,20,15); glVertex3f(20,20,15);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(20,20,15); glVertex3f(40,20,15); glVertex3f(40,40,15); glVertex3f(20,40,15);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(20,40,15); glVertex3f(40,40,15); glVertex3f(35,35,35); glVertex3f(15,35,35);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(15,35,35); glVertex3f(15,35,35); glVertex3f(20,20,15); glVertex3f(20,40,15);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(35,15,35); glVertex3f(40,20,15); glVertex3f(40,40,15); glVertex3f(35,35,35);
	glEnd();


glFlush();
}
*/