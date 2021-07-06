#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>

//672019320	Rivaldo Pranandito
//672018347	Bramastya Arya G
//672019309	Febrina Tesalonika N

void init(void);
void tampil(void);
void mouse(int button,int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void ukuran (int, int);
void mouseMotion(int x,int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;
int z = 0;
int p = 10;
int h = 0;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;
float skalaX = 1, skalaY = 1, skalaZ = 1;

int main(int argc, char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800,600);
	glutInitWindowPosition(250,80);
	glutCreateWindow("Universitan of bern");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6);
}

void tampil (void){
	if (is_depth)
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(p, h, z);
	glRotatef(sudut, x1, y1, z1);
	glScalef(skalaX, skalaY, skalaZ);
	gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);
    glPushMatrix();
	//depan bawah
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(20,-50,10);
	glVertex3f(20,95,10); //tembok putih 1
	glVertex3f(30,95,10);
	glVertex3f(30,-50,10);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-70,30,10);
	glVertex3f(-70,40,10); //tembok putih tengah
	glVertex3f(20,40,10);
	glVertex3f(20,30,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-10,-35,10);
	glVertex3f(-10,95,10);
	glVertex3f(0,95,10); //tembok putih 2
	glVertex3f(0,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-40,-35,10);
	glVertex3f(-40,95,10);
	glVertex3f(-30,95,10);
	glVertex3f(-30,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-70,-50,10);
	glVertex3f(-70,95,10);
	glVertex3f(-60,95,10);
	glVertex3f(-60,-50,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-60,-35,0);
	glVertex3f(-60,30,0);
	glVertex3f(-60,30,10);
	glVertex3f(-60,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-40,-35,0);
	glVertex3f(-40,30,0);
	glVertex3f(-40,30,10);
	glVertex3f(-40,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-30,-35,0);
	glVertex3f(-30,30,0);
	glVertex3f(-30,30,10);
	glVertex3f(-30,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-10,-35,0);
	glVertex3f(-10,30,0);
	glVertex3f(-10,30,10);
	glVertex3f(-10,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(0,-35,0);
	glVertex3f(0,30,0);
	glVertex3f(0,30,10);
	glVertex3f(0,-35,10);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(20,-35,0);
	glVertex3f(20,30,0);
	glVertex3f(20,30,10);
	glVertex3f(20,-45,10);
	glEnd();

//pintu
glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-60,-35,0);
	glVertex3f(-60,-17,0);
	glVertex3f(-40,-17,0);
	glVertex3f(-40,-35,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-60,-17,0);
	glVertex3f(-60,13,0);
	glVertex3f(-58,13,0);
	glVertex3f(-58,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-60,8,0);
	glVertex3f(-60,13,0);
	glVertex3f(-40,13,0);
	glVertex3f(-40,8,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-42,-17,0);
	glVertex3f(-42,13,0);
	glVertex3f(-40,13,0);
	glVertex3f(-40,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-52,-17,0);
	glVertex3f(-52,13,0);
	glVertex3f(-48,13,0);
	glVertex3f(-48,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-60,30,0);
	glVertex3f(-60,29,0);
	glVertex3f(-40,29,0);
	glVertex3f(-40,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-60,30,0);
	glVertex3f(-60,13,0);
	glVertex3f(-59,13,0);
	glVertex3f(-59,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-41,30,0);
	glVertex3f(-41,13,0);
	glVertex3f(-40,13,0);
	glVertex3f(-40,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-50.5,30,0);
	glVertex3f(-50.5,13,0);
	glVertex3f(-49.5,13,0);
	glVertex3f(-49.5,30,0);
	glEnd();
//pintu 2
glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-30,-35,0);
	glVertex3f(-30,-17,0);
	glVertex3f(-10,-17,0);
	glVertex3f(-10,-35,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-30,-17,0);
	glVertex3f(-30,13,0);
	glVertex3f(-28,13,0);
	glVertex3f(-28,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-30,8,0);
	glVertex3f(-30,13,0);
	glVertex3f(-10,13,0);
	glVertex3f(-10,8,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-12,-17,0);
	glVertex3f(-12,13,0);
	glVertex3f(-10,13,0);
	glVertex3f(-10,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-22,-17,0);
	glVertex3f(-22,13,0);
	glVertex3f(-18,13,0);
	glVertex3f(-18,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-30,30,0);
	glVertex3f(-30,29,0);
	glVertex3f(-10,29,0);
	glVertex3f(-10,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-30,30,0);
	glVertex3f(-30,13,0);
	glVertex3f(-29,13,0);
	glVertex3f(-29,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-11,30,0);
	glVertex3f(-11,13,0);
	glVertex3f(-10,13,0);
	glVertex3f(-10,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(-20.5,30,0);
	glVertex3f(-20.5,13,0);
	glVertex3f(-19.5,13,0);
	glVertex3f(-19.5,30,0);
	glEnd();

//pintu 3
glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(0,-35,0);
	glVertex3f(0,-17,0);
	glVertex3f(20,-17,0);
	glVertex3f(20,-35,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(0,-17,0);
	glVertex3f(0,13,0);
	glVertex3f(2,13,0);
	glVertex3f(2,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(0,8,0);
	glVertex3f(0,13,0);
	glVertex3f(20,13,0);
	glVertex3f(20,8,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(18,-17,0);
	glVertex3f(18,13,0);
	glVertex3f(20,13,0);
	glVertex3f(20,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(8,-17,0);
	glVertex3f(8,13,0);
	glVertex3f(12,13,0);
	glVertex3f(12,-17,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(0,30,0);
	glVertex3f(0,29,0);
	glVertex3f(20,29,0);
	glVertex3f(20,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(0,30,0);
	glVertex3f(0,13,0);
	glVertex3f(1,13,0);
	glVertex3f(1,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(19,30,0);
	glVertex3f(19,13,0);
	glVertex3f(20,13,0);
	glVertex3f(20,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(150,75,0);
	glVertex3f(9.5,30,0);
	glVertex3f(9.5,13,0);
	glVertex3f(10.5,13,0);
	glVertex3f(10.5,30,0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-60,30,0);
	glVertex3f(-60,30,10);
	glVertex3f(20,30,10);
	glVertex3f(20,30,0);
	glEnd();

//tangga
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-35,0);
	glVertex3f(-65,-35,30);
	glVertex3f(25,-35,30);
	glVertex3f(25,-35,0);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-60,-50,10);
	glVertex3f(-60,-35,10);
	glVertex3f(20,-35,10);
	glVertex3f(20,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-38,30);
	glVertex3f(-65,-35,30);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-35,30);
	glVertex3f(25,-38,30);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-38,30);
	glVertex3f(-65,-38,35);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-38,35);
	glVertex3f(25,-38,30);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-38,35);
	glVertex3f(-65,-41,35);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-41,35);
	glVertex3f(25,-38,35);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-41,35);
	glVertex3f(-65,-41,40);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-41,40);
	glVertex3f(25,-41,35);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-41,40);
	glVertex3f(-65,-44,40);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-44,40);
	glVertex3f(25,-41,40);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-44,40);
	glVertex3f(-65,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-44,45);
	glVertex3f(25,-44,40);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-44,45);
	glVertex3f(-65,-47,45);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-47,45);
	glVertex3f(25,-44,45);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-47,50);
	glVertex3f(-65,-47,45);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-47,45);
	glVertex3f(25,-47,50);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-47,50);
	glVertex3f(-65,-50,50);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-50,50);
	glVertex3f(25,-47,50);
	glEnd();

//tangga kiri
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-35,10);
	glVertex3f(-65,-35,30);
	glColor3ub(92, 138, 138);
	glVertex3f(-65,-38,30);
	glVertex3f(-65,-38,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-38,10);
	glVertex3f(-65,-38,35);
	glColor3ub(92, 138, 138);
	glVertex3f(-70,-38,35);
	glVertex3f(-70,-38,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-70,-38,10);
	glVertex3f(-70,-38,35);
	glColor3ub(92, 138, 138);
	glVertex3f(-70,-41,35);
	glVertex3f(-70,-41,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-41,35);
	glVertex3f(-65,-38,35);
	glColor3ub(92, 138, 138);
	glVertex3f(-70,-38,35);
	glVertex3f(-70,-41,35);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-65,-41,10);
	glVertex3f(-65,-41,40);
	glColor3ub(92, 138, 138);
	glVertex3f(-75,-41,40);
	glVertex3f(-75,-41,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-75,-41,10);
	glVertex3f(-75,-41,40);
	glColor3ub(92, 138, 138);
	glVertex3f(-75,-44,40);
	glVertex3f(-75,-44,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-75,-41,40);
	glVertex3f(-75,-44,40);
	glColor3ub(92, 138, 138);
	glVertex3f(-65,-44,40);
	glVertex3f(-65,-41,40);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-80,-44,10);
	glVertex3f(-80,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(-65,-44,45);
	glVertex3f(-65,-44,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-80,-44,10);
	glVertex3f(-80,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(-80,-47,45);
	glVertex3f(-80,-47,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-80,-47,45);
	glVertex3f(-80,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(-65,-44,45);
	glVertex3f(-65,-47,45);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-85,-47,10);
	glVertex3f(-85,-47,50);
	glColor3ub(92, 138, 138);
	glVertex3f(-65,-47,50);
	glVertex3f(-65,-47,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-85,-50,10);
	glVertex3f(-85,-50,50);
	glColor3ub(92, 138, 138);
	glVertex3f(-85,-47,50);
	glVertex3f(-85,-47,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-85,-50,50);
	glVertex3f(-85,-47,50);
	glColor3ub(92, 138, 138);
	glVertex3f(-65,-47,50);
	glVertex3f(-65,-50,50);
	glEnd();

//tangga kanan
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-35,10);
	glVertex3f(25,-35,30);
	glColor3ub(92, 138, 138);
	glVertex3f(25,-38,30);
	glVertex3f(25,-38,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-38,10);
	glVertex3f(25,-38,35);
	glColor3ub(92, 138, 138);
	glVertex3f(30,-38,35);
	glVertex3f(30,-38,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(30,-41,10);
	glVertex3f(30,-41,35);
	glColor3ub(92, 138, 138);
	glVertex3f(30,-38,35);
	glVertex3f(30,-38,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-41,35);
	glVertex3f(25,-38,35);
	glColor3ub(92, 138, 138);
	glVertex3f(30,-38,35);
	glVertex3f(30,-41,35);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-41,10);
	glVertex3f(25,-41,40);
	glColor3ub(92, 138, 138);
	glVertex3f(35,-41,40);
	glVertex3f(35,-41,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(35,-41,10);
	glVertex3f(35,-41,40);
	glColor3ub(92, 138, 138);
	glVertex3f(35,-44,40);
	glVertex3f(35,-44,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-44,40);
	glVertex3f(25,-41,40);
	glColor3ub(92, 138, 138);
	glVertex3f(35,-41,40);
	glVertex3f(35,-44,40);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-44,10);
	glVertex3f(25,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(40,-44,45);
	glVertex3f(40,-44,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(40,-44,10);
	glVertex3f(40,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(40,-47,45);
	glVertex3f(40,-47,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-47,45);
	glVertex3f(25,-44,45);
	glColor3ub(92, 138, 138);
	glVertex3f(40,-44,45);
	glVertex3f(40,-47,45);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-47,10);
	glVertex3f(25,-47,50);
	glColor3ub(92, 138, 138);
	glVertex3f(45,-47,50);
	glVertex3f(45,-47,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(45,-47,10);
	glVertex3f(45,-47,50);
	glColor3ub(92, 138, 138);
	glVertex3f(45,-50,50);
	glVertex3f(45,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(25,-50,50);
	glVertex3f(25,-47,50);
	glColor3ub(92, 138, 138);
	glVertex3f(45,-47,50);
	glVertex3f(45,-50,50);
	glEnd();

//tembok depan kiri
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-85,-50,10);
	glVertex3f(-85,160,10);
	glVertex3f(-70,160,10);
	glVertex3f(-70,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-100,-50,10);
	glVertex3f(-100,-40,10);
	glVertex3f(-70,-40,10);
	glVertex3f(-70,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-100,-30,10);
	glVertex3f(-100,-20,10);
	glVertex3f(-70,-20,10);
	glVertex3f(-70,-30,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-115,-50,10); // tembok e iki
	glVertex3f(-115,160,10);
	glVertex3f(-100,160,10);
	glVertex3f(-100,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-100,40,10);
	glVertex3f(-100,30,10);
	glVertex3f(-70,30,10);
	glVertex3f(-70,40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,-20,10);
	glVertex3f(-100,-20,5);
	glVertex3f(-85,-20,5);
	glVertex3f(-85,-20,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,-30,10);
	glVertex3f(-100,-30,5);
	glVertex3f(-85,-30,5);
	glVertex3f(-85,-30,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,-40,10);
	glVertex3f(-100,-40,5);
	glVertex3f(-85,-40,5);
	glVertex3f(-85,-40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,30,10);
	glVertex3f(-100,30,5);
	glVertex3f(-85,30,5);
	glVertex3f(-85,30,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-85,30,10);
	glVertex3f(-85,30,5);
	glVertex3f(-85,-20,5);
	glVertex3f(-85,-20,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,30,10);
	glVertex3f(-100,30,5);
	glVertex3f(-100,-20,5);
	glVertex3f(-100,-20,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-85,-30,10);
	glVertex3f(-85,-30,5);
	glVertex3f(-85,-40,5);
	glVertex3f(-85,-40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,-30,10);
	glVertex3f(-100,-30,5);
	glVertex3f(-100,-40,5);
	glVertex3f(-100,-40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,-40,5);
	glVertex3f(-100,-30,5);
	glVertex3f(-85,-30,5);
	glVertex3f(-85,-40,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,-20,5);
	glVertex3f(-100,-10,5);
	glVertex3f(-85,-10,5);
	glVertex3f(-85,-20,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-93,-20,5);
	glVertex3f(-93,15,5);
	glVertex3f(-92,15,5);
	glVertex3f(-92,-20,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,15,5);
	glVertex3f(-100,16,5);
	glVertex3f(-85,16,5);
	glVertex3f(-85,15,5);
	glEnd();
//tembok kiri depan	1
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-115,-50,10);
	glVertex3f(-115,140,10);
	glVertex3f(-115,140,-10);
	glVertex3f(-115,-50,-10);
	glEnd();
//tembok kiri depan	2
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-230,-50,-50);
	glVertex3f(-230,140,-50);
	glVertex3f(-115,140,-10);
	glVertex3f(-115,-50,-10);
	glEnd();
//tembok kiri depan	3
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-310,-50,-80);
	glVertex3f(-310,140,-80);
	glVertex3f(-230,140,-50);
	glVertex3f(-230,-50,-50);
	glEnd();
//tembok kiri samping 1
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-310,-50,-380);
	glVertex3f(-310,140,-380);
	glVertex3f(-310,140,-80);
	glVertex3f(-310,-50,-80);
	glEnd();

//atap kiri samping 1
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(-310,140,-380);
	glVertex3f(-270,180,-380);
	glVertex3f(-270,180,-150);
	glVertex3f(-310,140,-150);
	glEnd();

//atap kanan samping 1
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(150,140,-380);
	glVertex3f(210,180,-380);
	glVertex3f(210,180,-150);
	glVertex3f(150,140,-150);
	glEnd();

//tembok belakang kiri 1
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-200,-50,-380);
	glVertex3f(-200,140,-380);
	glVertex3f(-310,140,-380);
	glVertex3f(-310,-50,-380);
	glEnd();
//Atap belakang kiri 1
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(-200,140,-380);
	glVertex3f(-200,170,-370);
	glVertex3f(-310,170,-370);
	glVertex3f(-310,140,-380);
	glEnd();

//Atap kanan kiri 1
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(250,140,-380);
	glVertex3f(250,180,-380);
	glVertex3f(150,180,-380);
	glVertex3f(150,140,-380);
	glEnd();

//tembok belakang kiri 2
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-200,-50,-380);
	glVertex3f(-200,140,-380);
	glVertex3f(-200,140,-150);
	glVertex3f(-200,-50,-150);
	glEnd();
//Atap belakang kiri 2
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(-200,-50,-380);
	glVertex3f(-200,140,-380);
	glVertex3f(-200,140,-150);
	glVertex3f(-200,-50,-150);
	glEnd();


//tembok belakang kiri 2
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(-200,140,-380);
	glVertex3f(-270,180,-380);
	glVertex3f(-270,180,-150);
	glVertex3f(-200,140,-150);
	glEnd();


//tembok belakang kiri 3
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(-200,-50,-150);
	glVertex3f(-200,145,-150);
	glVertex3f(150,145,-150);
	glVertex3f(150,-50,-150);
	glEnd();

//tembok kiri depan	2 X JENDELA 1
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(-231,90,-50);
	glVertex3f(-231,130,-50);
	glVertex3f(-116,130,-10);
	glVertex3f(-116,90,-10);
	glEnd();

//tembok kiri depan	2 X JENDELA 2
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(-231,40,-50);
	glVertex3f(-231,80,-50);
	glVertex3f(-116,80,-10);
	glVertex3f(-116,40,-10);
	glEnd();

//tembok kiri depan	2 X JENDELA 3
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(-231,-10,-50);
	glVertex3f(-231,30,-50);
	glVertex3f(-116,30,-10);
	glVertex3f(-116,-10,-10);
	glEnd();

//tembok kiri depan	3 X JENDELA 1
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(-309.5,90,-80);
	glVertex3f(-309.5,130,-80);
	glVertex3f(-234.5,130,-50);
	glVertex3f(-234.5,90,-50);
	glEnd();

//tembok kiri depan	3 X JENDELA 2
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(-309.5,40,-80);
	glVertex3f(-309.5,80,-80);
	glVertex3f(-234.5,80,-50);
	glVertex3f(-234.5,40,-50);
	glEnd();

//tembok kiri depan	3 X JENDELA 2
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(-309.5,-10,-80);
	glVertex3f(-309.5,30,-80);
	glVertex3f(-234.5,30,-50);
	glVertex3f(-234.5,-10,-50);
	glEnd();

//tembok depan kanan
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(30,-50,10);
	glVertex3f(30,160,10);
	glVertex3f(45,160,10);
	glVertex3f(45,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(40,-50,10);
	glVertex3f(40,-40,10);
	glVertex3f(70,-40,10);
	glVertex3f(70,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(40,-30,10);
	glVertex3f(40,-20,10);
	glVertex3f(70,-20,10);
	glVertex3f(70,-30,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(60,-50,10);
	glVertex3f(60,160,10);
	glVertex3f(75,160,10);
	glVertex3f(75,-50,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(40,40,10);
	glVertex3f(40,30,10);
	glVertex3f(70,30,10);
	glVertex3f(70,40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,-20,10);
	glVertex3f(45,-20,5);
	glVertex3f(60,-20,5);
	glVertex3f(60,-20,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,-30,10);
	glVertex3f(45,-30,5);
	glVertex3f(60,-30,5);
	glVertex3f(60,-30,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,-40,10);
	glVertex3f(45,-40,5);
	glVertex3f(60,-40,5);
	glVertex3f(60,-40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,30,10);
	glVertex3f(45,30,5);
	glVertex3f(60,30,5);
	glVertex3f(60,30,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,30,10);
	glVertex3f(45,30,5);
	glVertex3f(45,-20,5);
	glVertex3f(45,-20,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(60,30,10);
	glVertex3f(60,30,5);
	glVertex3f(60,-20,5);
	glVertex3f(60,-20,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,-30,10);
	glVertex3f(45,-30,5);
	glVertex3f(45,-40,5);
	glVertex3f(45,-40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(60,-30,10);
	glVertex3f(60,-30,5);
	glVertex3f(60,-40,5);
	glVertex3f(60,-40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,-40,5);
	glVertex3f(45,-30,5);
	glVertex3f(60,-30,5);
	glVertex3f(60,-40,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,-20,5);
	glVertex3f(45,-10,5);
	glVertex3f(60,-10,5);
	glVertex3f(60,-20,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(52,-20,5);
	glVertex3f(52,15,5);
	glVertex3f(53,15,5);
	glVertex3f(53,-20,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,15,5);
	glVertex3f(45,16,5);
	glVertex3f(60,16,5);
	glVertex3f(60,15,5);
	glEnd();
//depan kanan 1
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(75,-50,-20);
	glVertex3f(75,140,-20);
	glVertex3f(75,140,10);
	glVertex3f(75,-50,10);
	glEnd();
//depan kanan 2
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(180,-50,-50);
	glVertex3f(180,140,-50);
	glVertex3f(75,140,-20);
	glVertex3f(75,-50,-20);
	glEnd();
//depan kanan 3
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(180,-50,-50);
	glVertex3f(180,140,-50);
	glVertex3f(250,140,-80);
	glVertex3f(250,-50,-80);
	glEnd();
//tembok belakang kanan 1
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(150,-50,-380);
	glVertex3f(150,140,-380);
	glVertex3f(150,140,-150);
	glVertex3f(150,-50,-150);
	glEnd();

//tembok belakang kanan 2
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(250,-50,-380);
	glVertex3f(250,140,-380);
	glVertex3f(150,140,-380);
	glVertex3f(150,-50,-380);
	glEnd();
//tembok kanan samping 1
glBegin(GL_QUADS);
	glColor3ub(128,128,128);
	glVertex3f(250,-50,-380);
	glVertex3f(250,140,-380);
	glVertex3f(250,140,-80);
	glVertex3f(250,-50,-80);
	glEnd();
//Atap kanan samping 1
glBegin(GL_QUADS);
	glColor3ub(184,134,11);
	glVertex3f(250,140,-380);
	glVertex3f(220,180,-380);
	glVertex3f(220,180,-150);
	glVertex3f(250,140,-150);
	glEnd();

//depan kanan 2 X JENDELA 1
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(180.5,90,-50);
	glVertex3f(180.5,130,-50);
	glVertex3f(76,130,-20);
	glVertex3f(76,90,-20);
	glEnd();
//depan kanan 2 X JENDELA 2
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(180.5,40,-50);
	glVertex3f(180.5,80,-50);
	glVertex3f(76,80,-20);
	glVertex3f(76,40,-20);
	glEnd();
//depan kanan 2 X JENDELA 3
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(180.5,-10,-50);
	glVertex3f(180.5,30,-50);
	glVertex3f(76,30,-20);
	glVertex3f(76,-10,-20);
	glEnd();
//depan kanan 3 X JENDELA 1
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(185,90,-50);
	glVertex3f(185,130,-50);
	glVertex3f(249.5,130,-80);
	glVertex3f(249.5,90,-80);
	glEnd();
//depan kanan 3 X JENDELA 2
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(185,40,-50);
	glVertex3f(185,80,-50);
	glVertex3f(249.5,80,-80);
	glVertex3f(249.5,40,-80);
	glEnd();
//depan kanan 3 X JENDELA 3
glBegin(GL_QUADS);
	glColor3f(0,0,0.5019607843137255);
	glVertex3f(185,-10,-50);
	glVertex3f(185,30,-50);
	glVertex3f(249.5,30,-80);
	glVertex3f(249.5,-10,-80);
	glEnd();


//depan atas
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-115,40,10);
	glVertex3f(-115,40,15);
	glVertex3f(75,40,15);
	glVertex3f(75,40,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-115,45,15);
	glVertex3f(-115,40,15);
	glVertex3f(75,40,15);
	glVertex3f(75,45,15);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-115,45,10);
	glVertex3f(-115,45,15);
	glVertex3f(75,45,15);
	glVertex3f(75,45,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-115,45,10.5);
	glVertex3f(-115,50,10.5);
	glVertex3f(75,50,10.5);
	glVertex3f(75,45,10.5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-115,175,10);
	glVertex3f(-115,160,10);
	glVertex3f(75,160,10);
	glVertex3f(75,175,10);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(52,50,5);
	glVertex3f(52,80,5);
	glVertex3f(53,80,5);
	glVertex3f(53,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,80,5);
	glVertex3f(45,81,5);
	glVertex3f(60,81,5);
	glVertex3f(60,80,5);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,50,10);
	glVertex3f(45,50,5);
	glVertex3f(45,95,5);
	glVertex3f(45,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(60,50,10);
	glVertex3f(60,50,5);
	glVertex3f(60,95,5);
	glVertex3f(60,95,10);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110); // 0
	glVertex3f(45,95,10);
	glVertex3f(45,95,5);
	glVertex3f(60,95,5);
	glVertex3f(60,95,10);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,160,10);
	glVertex3f(45,160,5);	// 1
	glVertex3f(60,160,5);
	glVertex3f(60,160,10);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,50,11); // 0
	glVertex3f(45,50,5);
	glVertex3f(60,50,5);
	glVertex3f(60,50,11);
	glEnd();
//jendela atas3
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-115,95,10.5);
	glVertex3f(-115,100,10.5);
	glVertex3f(75,100,10.5);
	glVertex3f(75,95,10.5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(52,100,5);
	glVertex3f(52,130,5);
	glVertex3f(53,130,5);
	glVertex3f(53,100,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,130,5);
	glVertex3f(45,131,5);
	glVertex3f(60,131,5);
	glVertex3f(60,130,5);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(45,100,10);
	glVertex3f(45,100,5);
	glVertex3f(45,145,5);
	glVertex3f(45,145,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(60,100,10);
	glVertex3f(60,100,5);
	glVertex3f(60,145,5);
	glVertex3f(60,145,10);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110); // 0
	glVertex3f(45,145,10);
	glVertex3f(45,145,5);
	glVertex3f(60,145,5);
	glVertex3f(60,145,10);
	glEnd();




glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(45,100,11); // 0
	glVertex3f(45,100,5);
	glVertex3f(60,100,5);
	glVertex3f(60,100,11);
	glEnd();

//akhir
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(0,95,10); // 0
	glVertex3f(0,95,5);
	glVertex3f(20,95,5);
	glVertex3f(20,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(0,160,10); // 1
	glVertex3f(0,160,5);
	glVertex3f(20,160,5);
	glVertex3f(20,160,10);
	glEnd();



glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(0,145,10);
	glVertex3f(0,145,5);
	glVertex3f(20,145,5);
	glVertex3f(20,145,10);
	glEnd();



glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-30,95,10);
	glVertex3f(-30,95,5);
	glVertex3f(-10,95,5); // 0
	glVertex3f(-10,95,10);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-30,160,10);
	glVertex3f(-30,160,5); // 1
	glVertex3f(-10,160,5);
	glVertex3f(-10,160,10);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-60,95,10);
	glVertex3f(-60,95,5); // 0
	glVertex3f(-40,95,5);
	glVertex3f(-40,95,10);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-60,160,10);
	glVertex3f(-60,160,5); // 1
	glVertex3f(-40,160,5);
	glVertex3f(-40,160,10);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,95,10);
	glVertex3f(-100,95,5); // 0
	glVertex3f(-85,95,5);
	glVertex3f(-85,95,10);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,160,10);
	glVertex3f(-100,160,5); // 0
	glVertex3f(-85,160,5);
	glVertex3f(-85,160,10);
	glEnd();


glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(20,50,10);
	glVertex3f(20,50,5);
	glVertex3f(20,95,5);
	glVertex3f(20,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(0,50,10);
	glVertex3f(0,50,5);
	glVertex3f(0,95,5);
	glVertex3f(0,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-10,50,10);
	glVertex3f(-10,50,5);
	glVertex3f(-10,95,5);
	glVertex3f(-10,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-30,50,10);
	glVertex3f(-30,50,5);
	glVertex3f(-30,95,5);
	glVertex3f(-30,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-40,50,10);
	glVertex3f(-40,50,5);
	glVertex3f(-40,95,5);
	glVertex3f(-40,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-60,50,10);
	glVertex3f(-60,50,5);
	glVertex3f(-60,95,5);
	glVertex3f(-60,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-85,50,10);
	glVertex3f(-85,50,5);
	glVertex3f(-85,95,5);
	glVertex3f(-85,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,110,110);
	glVertex3f(-100,50,10);
	glVertex3f(-100,50,5);
	glVertex3f(-100,95,5);
	glVertex3f(-100,95,10);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,50,11);
	glVertex3f(-100,50,5);
	glVertex3f(-85,50,5);
	glVertex3f(-85,50,11);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-60,50,11);
	glVertex3f(-60,50,5);
	glVertex3f(-40,50,5);
	glVertex3f(-40,50,11);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-30,50,11);
	glVertex3f(-30,50,5);
	glVertex3f(-10,50,5);
	glVertex3f(-10,50,11);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(0,50,11);
	glVertex3f(0,50,5);
	glVertex3f(20,50,5);
	glVertex3f(20,50,11);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(13,50,5);
	glVertex3f(13,95,5);
	glVertex3f(14,95,5);
	glVertex3f(14,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(6,50,5);
	glVertex3f(6,95,5);
	glVertex3f(7,95,5);
	glVertex3f(7,50,5);
	glEnd();

glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-16,50,5);
	glVertex3f(-16,95,5);
	glVertex3f(-17,95,5);
	glVertex3f(-17,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-23,50,5);
	glVertex3f(-23,95,5);
	glVertex3f(-24,95,5);
	glVertex3f(-24,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-46,50,5);
	glVertex3f(-46,95,5);
	glVertex3f(-47,95,5);
	glVertex3f(-47,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-53,50,5);
	glVertex3f(-53,95,5);
	glVertex3f(-54,95,5);
	glVertex3f(-54,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(0,80,5);
	glVertex3f(0,81,5);
	glVertex3f(20,81,5);
	glVertex3f(20,80,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-30,80,5);
	glVertex3f(-30,81,5);
	glVertex3f(-10,81,5);
	glVertex3f(-10,80,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-60,80,5);
	glVertex3f(-60,81,5);
	glVertex3f(-40,81,5);
	glVertex3f(-40,80,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-93,50,5);
	glVertex3f(-93,80,5);
	glVertex3f(-94,80,5);
	glVertex3f(-94,50,5);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(110,90,110);
	glVertex3f(-100,80,5);
	glVertex3f(-100,81,5);
	glVertex3f(-85,81,5);
	glVertex3f(-85,80,5);
	glEnd();




//karpet
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0.392156862745098, 0);
	glTranslatef(10, -50, -20);
	glScalef(60, 10, 100);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

//Kotak P3K
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 0.2705882352941176 ,0);
	glTranslatef(-60, 20, -145.5);
	glScalef(78, 80, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();
glBegin(GL_QUADS);
    glColor3ub(110,90,110);
	glVertex3f(-115,145,-150);
	glVertex3f(-115,145,10);
	glVertex3f(75,145,10);
	glVertex3f(75,145,-150);
	glEnd();


//bawah
glBegin(GL_QUADS);
    glColor3ub(110,90,110);
	glVertex3f(-415,-50,-455);
	glColor3ub(124,252,0);
	glVertex3f(-415,-50,305);
    glColor3ub(124,252,0);
	glVertex3f(475,-50,305);
    glColor3ub(110,90,110);
	glVertex3f(475,-50,-455);
	glEnd();


	glPopMatrix();
        glutSwapBuffers();

}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key,int x, int y){
	if (key == 'q') z += 5;
	else if (key == 'e') z -= 5;
	else if (key == 'd') p -= 5;
	else if (key == 'a') p += 5;
	else if (key == 's') h += 5;
	else if (key == 'w') h -= 5;


}

void ukuran (int w1, int h1){
	glViewport(0, 0, w1, h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1, 1, 2000.0);
	glTranslatef(0.0,-5,-150);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
