/*
#include <gl/glut.h>
#include <stdlib.h>
#include <time.h>

static int delay = 100;

void timer(int);
void init();
void display();
void retri(float[], float[], float[], int);
int main(int argc, char* argv[])
{
glutInit(&argc, (char**)argv);
glutInitWindowSize(500, 500);
glutCreateWindow("Prog04:recursive triangles");
glutDisplayFunc(display);		//그려주는

init();
glutMainLoop(); //이벤트 loop

return 0;
}

void init() //초기화
{
srand(time(0));
glClearColor(1.0, 1.0, 1.0, 1.0); //RGB 투명도
gluOrtho2D(0.0, 50.0, 0.0, 50.0); //좌표계 설정
glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
	float angle0[2] = { 0,0 };
	float angle1[2] = { 25,50 };
	float angle2[2] = { 50,0 };

	glColor3f(1,0.0,0.0);

	glBegin(GL_TRIANGLES);

	retri(angle0, angle1, angle2, 5);

	glEnd(); // finish polygon
	glFlush();
}

void retri(float a[], float b[], float c[], int t) {
	float x[2], y[2], z[2];
	if (t == 0) {
		glVertex2fv(a);
		glVertex2fv(b);
		glVertex2fv(c);
	}
	else{
		t--;
		x[0] = (b[0] + a[0]) / 2;
		x[1] = (b[1] + a[1]) / 2;
		y[0] = (b[0] + c[0]) / 2;
		y[1] = (b[1] + c[1]) / 2;
		z[0] = (c[0] + a[0]) / 2;
		z[1] = c[1];
		retri(a, x, z, t);
		retri(x, b, y, t);
		retri(z, y, c, t);
	}
}*/
