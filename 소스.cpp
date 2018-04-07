#include <gl/glut.h>
#include <math.h>
#include <stdlib.h>


void init();
void display();
void timer(int);

GLint day = 0.0;
static int delay = 1;

int main(int argc, char* argv[])
{
glutInit(&argc, (char**)argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(500, 500);
glutCreateWindow("Solar System");
glutDisplayFunc(display);
glutTimerFunc(delay, timer, 0);
init();
glutMainLoop();
return 0;
}

void init()
{
glMatrixMode(GL_PROJECTION);
glClearColor(1.0, 1.0, 1.0, 1.0);
glOrtho(-1.0, 1.0, -1.0, 1.0, -5.0, 5.0);
glEnable(GL_DEPTH_TEST);
glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//축 90도 회전해서 자전축 세우기
	glLoadIdentity();
	glRotatef(90, 1.0, 0.0, 0.0);

	//태양 생성
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 20, 16);

	//지구 공전축
	glRotatef(5.5, 0.0, 1.0, 0.0);
	//지구 공전
	glRotatef((GLfloat)day/365.0, 0.0, 0.0, -1.0);

		glPushMatrix();
		//지구 좌표로 이등
		glTranslatef(0.7, 0.0, 0.0);
		//지구 공전축 상쇄
		glRotatef((GLfloat)day /365.0, 0.0, 0.0, 1.0);
		//지구 자전축
		glRotatef(-23.5, 0.0, 1.0, 0.0);
		//지구 자전
		glRotatef((GLfloat)day, 0.0, 0.0, -1.0);
		//지구 생성
		glColor3f(0.5, 0.6, 0.7);
		glutWireSphere(0.1, 10, 8);

		//달 공전
		glRotatef((GLfloat)day/30.0, 0.0, 0.0, -1.0);
			glPushMatrix();
					//달 좌표로 이등
					glTranslatef(0.2, 0.0, 0.0);
					//지구 자전축 상쇄
					glRotatef(23.5, 0.0, 1.0, 0.0);
					//달 자전
					glRotatef((GLfloat)day, 0.0, 0.0, -1.0);
					//달 그리기
					glColor3f(0.9, 0.8, 0.2);
					glutWireSphere(0.04, 10, 8);
				glPopMatrix();
		glPopMatrix();
	glutSwapBuffers();

	glFlush();
}

void timer(int t)
{
glutPostRedisplay(); // redraw graphics (rather than calling display() itself)
glutTimerFunc(delay, timer, t); // set timer function again
day += 1;
}
