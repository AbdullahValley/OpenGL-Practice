#include <GL/freeglut.h>
#include <GL/gl.h>

static GLfloat spin = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_LINE_STRIP);
      glVertex3f ( 0, 10, 0.0);
      glVertex3f (-10.0, -10, 0.0);
      glVertex3f (10.0,-10.0, 0.0);
      glVertex3f ( 0, 10, 0.0);


	glEnd();

	glFlush();
}


void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Abdullah Triangle Strip");
	
init();

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
