#include<windows.h> 
#include <glut.h> 
#include<stdlib.h> 
double rotate_y = 0;
double rotate_x = 0;
double rotate_z = 0;
int cx = 0, cy = 0, cz = 0;
float angle = 45.0f;
float cameraAngle = 0.0f;
float angle1 = 0.0, scale = 1.0;
float rotation = 0.0;
void specialkeys(int key, int x, int y)
{
	if (key == GLUT_KEY_RIGHT)
		rotate_y -= 5;
	else if (key == GLUT_KEY_LEFT)
		rotate_y += 5;
	else if (key == GLUT_KEY_UP)
		rotate_x += 5;
	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;
	else if (key == GLUT_KEY_PAGE_UP)
		rotate_z += 5;
	else if (key == GLUT_KEY_PAGE_DOWN)
		rotate_z -= 5;
	glutPostRedisplay();
}void DrawScene()//��� 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// ������� ����� ����� � ������� 
	glLoadIdentity();// ��������� ��������� ������� 
	glRotatef(rotation, 0.0, 1.0, 0.0);// ��������� ��� �������� (x, y, z) 
	glBegin(GL_TRIANGLES);// ������ ����� 
	glColor3f(1.0, 0.2, 0.0); // ����� ����� ���� ��� ������ ��������� 
	glVertex3f(0.0, 2.5, 0.0);
	glVertex3f(2.0, 1.5, -2.0);
	glVertex3f(2.0, 1.5, 2.0);
	glColor3f(1.0, 0.3, 0.0);
	glVertex3f(-2.0, 1.5, -2.0);
	glVertex3f(-2.0, 1.5, 2.0);
	glVertex3f(0.0, 2.5, 0.0);
	glColor3f(1.0, 0.4, 0.0);
	glVertex3f(0.0, 2.5, 0.0);
	glVertex3f(2.0, 1.5, -2.0);
	glVertex3f(-2.0, 1.5, -2.0);
	glColor3f(1.0, 0.1, 0.0);
	glVertex3f(0.0, 2.5, 0.0);
	glVertex3f(-2.0, 1.5, 2.0);
	glVertex3f(2.0, 1.5, 2.0);
	glEnd();
	// �������� ����� ���� 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(2.0, 1.5, -2.0);
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 1.5, -2.0);
	glEnd();
	// ������ ����� ���� 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.8, 0.0);
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 1.5, 2.0);
	glVertex3f(2.0, 1.5, -2.0);
	glEnd();
	// ������ ����� ���� 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.7, 0.0);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glVertex3f(-2.0, 1.5, 2.0);
	glVertex3f(2.0, 1.5, 2.0);
	glEnd();
	// ����� ����� ����glBegin(GL_POLYGON); 
	glColor3f(1.0, 0.9, 0.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glVertex3f(-2.0, 1.5, 2.0);
	glVertex3f(-2.0, 1.5, -2.0);
	glEnd();
	// ����� (�������� �����) 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(0.3, 0.0, -2.01);
	glVertex3f(-0.3, 0.0, -2.01);
	glVertex3f(-0.3, 1.2, -2.01);
	glVertex3f(0.3, 1.2, -2.01);
	glEnd();
	//�������� 
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex3f(-10.0, 0.0, -10.0);
	glVertex3f(10.0, 0.0, -10.0);
	glVertex3f(10.0, 0.0, 10.0);
	glVertex3f(-10.0, 0.0, 10.0);
	glEnd();
	rotation += 1.5f; // ���� ��������� �� 1 ���� 
	glFlush();
	glutSwapBuffers();
}
void init()
{
	GLfloat mat_specular[] = { 1.0, 0.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 100.0 };
	GLfloat light_position[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat white_light[] = { 1.0, 0.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.0, 1.0, 0.0, 0.0 };
	glClearColor(0.0, 1.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void Ayarlar(void) //��� 
{
	glClearColor(0.3, 0.6, 1.0, 1.0);
	glShadeModel(GLU_FLAT);
}
void CizimFonksiyonu(void) //���
{ 
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}
void Matrix()
{
	glMatrixMode(GL_PROJECTION);// ������� ������� �������� 
	glLoadIdentity(); // ��������� ������� ��� ����������� �������������� 
	gluPerspective(60.0f, 1, 0.01, 100.0);// �������������� 
	// ������ ������� ��������� ���������� ������ � � ��������� 
	gluLookAt(-5, 3, -6, // ������� ����� ������ (x, y, z) 
		0, 1, 0, // �����������, ���� �� ������� 
		0, 2, 0); // ���� ������ 
	glMatrixMode(GL_MODELVIEW);// ������� ������ ����������� 
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// glutInitWindowPosition(50, 100); 
	glutInitWindowSize(800, 800);
	glutCreateWindow("3D Pyramid!");
	Matrix();
	init();
	glutDisplayFunc(DrawScene);
	glutSpecialFunc(specialkeys);
	CizimFonksiyonu();
	Ayarlar();
	glutMainLoop();
	system("pause");
	return 0;
}