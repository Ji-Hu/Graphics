/*
#include <gl/glut.h>
#include <stdlib.h>
#include <time.h>

static int delay = 100;

void timer(int);
void init();
void display();

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog02: random boxes");
	glutDisplayFunc(display);		//그려주는
	glutTimerFunc(delay, timer, 0);	//화면을 갱신시켜줘 delay,timer(호출되는)

	init();
	glutMainLoop(); //이벤트 loop

	return 0;
}

void init() //초기화
{
	srand(time(0));
	glClearColor(1.0, 1.0, 0.5, 1.0); //RGB 투명도
	gluOrtho2D(0.0, 50.0, 0.0, 50.0); //좌표계 설정
	glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	int x1, x2, y1, y2, r,  g,  b;

	x1 = rand() % 50;	y1 = rand() % 50;	x2 = rand() % 50;	y2 = rand() % 50;
	r = rand() % 256;	g = rand() % 256;	b = rand() % 256;

	glColor3f((GLfloat)r / 255, (GLfloat)g / 255, (GLfloat)b/255);

	glBegin(GL_POLYGON);


	glVertex2f(x1, y1); glVertex2f(x1, y2); // draw vertices
	glVertex2f(x2, y2); glVertex2f(x2, y1);// draw vertices
	glEnd(); // finish polygon
	glFlush();
}

void timer(int t)
{
	glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
	glutTimerFunc(delay, timer, t); // set timer function again
}
*/