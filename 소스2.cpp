/*	
#include <gl/glut.h>
#include <stdlib.h>
#include <time.h>

static int delay = 1;
float x, y;
float xinc, yinc;

void timer(int);
void init();
void display();

int main(int argc, char* argv[])
{
	srand(time(0));
	x = rand() % 50;	y = rand() % 50;
	xinc = (rand() % 200)*0.001-0.1;
	yinc = (rand() % 200)*0.001-0.1;

	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog03: bouncing pixel");
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
glBegin(GL_POINTS);
glColor3f(x / 50, y / 50, 0.0);
glVertex2f(x, y);
if (x < 0 || x > 50) {
	xinc = xinc * -1;
}
if (y < 0 || y > 50) {
	yinc = yinc * -1;
}
glEnd(); // finish
x += xinc;
y += yinc;
glFlush();
}

void timer(int t)
{
glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
glutTimerFunc(delay, timer, t); // set timer function again
}*/
