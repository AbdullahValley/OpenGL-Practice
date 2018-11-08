#include <GL/freeglut.h>
#include <GL/gl.h>

GLfloat spin = 0.0;
float	tx	=  0.0;
float	ty	=  0.0;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	glTranslatef(tx,ty,0);

	glRectf(-25.0, -25.0, 25.0, 25.0);
	glPopMatrix();

	glFlush();
}

void spinDisplay_left(void)
{
   spin = spin + 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - 1;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void init(void)
{
	glClearColor (1.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			spinDisplay_left();
			break;

		case 'r':
			spinDisplay_right();
			break;

		case 's':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}
}

void spe_key(unsigned char key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_LEFT:
				tx -=5;
				glutPostRedisplay();
				break;


		case GLUT_KEY_RIGHT:
				tx +=5;
				glutPostRedisplay();
				break;
	  default:
			break;
	}
}


void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);
          //glutIdleFunc(NULL); // make idle function inactive
         break;
      default:
         break;
   }
}


void my_reshape(int w, int h)
{
	glViewport (0,0,250, 250);
	//glViewport (0,0,w, h);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Abdullah Rectangle");
init();
    glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutReshapeFunc(my_reshape);
	glutMouseFunc(my_mouse);
    glutMainLoop();    
    return 0;
}
