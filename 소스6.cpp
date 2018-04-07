#include <gl/glut.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


void init();
void display();
double getRadian(double);

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog07: first 3D program");
	glutDisplayFunc(display);		//그려주는

	init();
	glutMainLoop(); //이벤트 loop
	return 0;
}

void init() //초기화
{

	glClearColor(1.0, 1.0, 1.0, 1.0); //RGB 투명도
	glOrtho(0.0, 10.0, 0.0, 10.0, -10.0, 10.0);//좌표계 설정
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK|GL_GLINE);
}

void display()
{
	double x = 0, y = 0;

	glFlush();
}

double getRadian (double input) {
	return input * M_PI / 180;
}