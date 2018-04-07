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
	glutDisplayFunc(display);		//그려	주는
	glutTimerFunc(delay, timer, 0);	//화면을 갱신시켜줘 delay,timer(호출되는)

	init();
	glutMainLoop(); //이벤트 loop

return 0;
}

void init() //초기화
{
glClearColor(1.0, 1.0, 1.0, 1.0); //RGB 투명도
gluOrtho2D(0.0, 50, 0.0, 50.0); //좌표계 설정
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
