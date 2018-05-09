
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>

GLfloat v[][3] = { {0.58,0.58,0.58}, {-0.58,-0.58,0.58}, {0.58,-0.58,-0.58}, {-0.58, 0.58, -0.58} };

typedef struct {
	GLfloat pos[4]; //postition
	GLfloat amb[4]; //ambient
	GLfloat dif[4]; //diffuse
	GLfloat spe[4]; //specular
} Light;

typedef struct {
	GLfloat amb[4];
	GLfloat dif[4];
	GLfloat spe[4];
	GLfloat shin;
} Material;


int level = 0, mode =0;

Light light = {
	{ 0.0, 2.0, 2.0, 1.0 },
{ 1.0, 1.0, 1.0, 1.0 },
{ 1.0, 1.0, 1.0, 1.0 },
{ 1.0, 1.0, 1.0, 1.0 },
};

Material mat = {
	{0.2, 0.0, 0.0 ,1.0},
{1.0, 1.0, 0.0, 1.0},
{1.0, 1.0, 0.0, 1.0},
{100.0},
};

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.5, 0.5, 0.5);
	glOrtho(-2.0, 2.0, -2.0,2.0, -10.0, 10.0);
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
GLfloat inter(GLfloat *a, GLfloat *b) {
	GLfloat x = a[0] + b[0];
	GLfloat y = a[1] + b[1];
	GLfloat z = a[2] + b[2];
	return  sqrt((x * x) + (y * y) + (z * z));
}
void triangle(GLfloat  a[], GLfloat b[], GLfloat c[])
{
	if (mode != 2)glShadeModel(GL_FLAT); else glShadeModel(GL_SMOOTH);
	if (mode == 0)glBegin(GL_LINE_LOOP);
	else glBegin(GL_POLYGON);

	glNormal3fv(a); glVertex3fv(a);
	glNormal3fv(b); glVertex3fv(b);
	glNormal3fv(c); glVertex3fv(c);
	

	glEnd();
}

void recurv(GLfloat a[], GLfloat b[], GLfloat c[], int num) {
	GLfloat v1[3], v2[3], v3[3];
	for (int i = 0; i < 3; i++) {
		v1[i] = (a[i]+b[i])/inter(a, b);
		v2[i] = (a[i] + c[i]) / inter(a, c);
		v3[i] = (b[i] + c[i]) / inter(b, c);
	}
	if (num == 0) {
		triangle(a, b, c);
	}
	else {
		num--;
		recurv(a, v1, v2,num);
		recurv(c, v2, v3,num);
		recurv(b, v3, v1,num);
		recurv(v1, v3, v2,num);
	}
}

void keyboard_handler(unsigned char key, int x, int y)
{
	switch (key) {
	case 'x':
		light.pos[0] -= 0.1;
		printf("x\n");
		break;
	case 'X':
		light.pos[0] += 0.1;
		printf("X\n");
		break;
	case 'y':
		light.pos[1] -= 0.1;
		break;
	case 'Y':
		light.pos[1] += 0.1;
		break;
	case 'z':
		light.pos[2] -= 0.1;
		break;
	case 'Z':
		light.pos[2] += 0.1;
		break;
	case 'm':
		mode++;
		mode = mode % 3;
		printf("m\n");
		break;
	case 'n':
		level--;
		if (level < 0) level = 0;
		printf("n %d\n",level);
		break;
	case 'N':
		level++;
		if (level > 5) level = 5;
		printf("N %d\n",level);
		break;
	default:
		break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLightfv(GL_LIGHT0, GL_POSITION, light.pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light.amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light.dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light.spe);

	glPushMatrix();
	glTranslatef(light.pos[0], light.pos[1], light.pos[2]);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat.amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat.dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat.spe);
	glMaterialf(GL_FRONT, GL_SHININESS, mat.shin);
	 
	recurv(v[0], v[1], v[2], level);
	recurv(v[3], v[2], v[1], level);
	recurv(v[0], v[3], v[1], level);
	recurv(v[0], v[2], v[3], level);

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Prog23: Light");

	glutDisplayFunc(display);

	glutKeyboardFunc(keyboard_handler);


	init();
	glutMainLoop();

	return 0;
}
