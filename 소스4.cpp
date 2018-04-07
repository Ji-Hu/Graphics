/*
#include <gl/glut.h>
#include <stdlib.h>
#include <time.h>

static int delay = 1;
float x[3], y[3];
float xinc[3], yinc[3];

void timer(int);
void init();
void display();

int main(int argc, char* argv[])
{
srand(time(0));
for (int i = 0; i < 3; i++) {
	x [i]= rand() % 50;	y[i] = rand() % 50;
	xinc[i] = (rand() % 200)*0.001 - 0.1;
	yinc[i] = (rand() % 200)*0.001 - 0.1;
}

glutInit(&argc, (char**)argv);
glutInitWindowSize(500, 500);
glutCreateWindow("Prog06: bouncing triangle");
glutDisplayFunc(display);		//�׷�	�ִ�
glutTimerFunc(delay, timer, 0);	//ȭ���� ���Ž����� delay,timer(ȣ��Ǵ�)

init();
glutMainLoop(); //�̺�Ʈ loop

return 0;
}

void init() //�ʱ�ȭ
{
glClearColor(1.0, 1.0, 1.0, 1.0); //RGB ����
gluOrtho2D(0.0, 50, 0.0, 50.0); //��ǥ�� ����
glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	//glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);

glColor3f(x[0] / 50, y[0] / 50, 0.0);
for (int i = 0; i < 3; i++) {

	glVertex2f(x[i], y[i]);
	if (x[i] < 0 || x[i] > 50) {
		xinc[i] = xinc[i] * -1;
	}
	if (y[i] < 0 || y [i]> 50) {
		yinc[i] = yinc[i] * -1;
	}

	x[i] += xinc[i];
	y[i] += yinc[i];
}
glEnd(); // finish
glFlush();
}

void timer(int t)
{
glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
glutTimerFunc(delay, timer, t); // set timer function again
}*/