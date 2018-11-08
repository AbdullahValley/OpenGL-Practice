#include <GL/freeglut.h>
#include <GL/gl.h>

int Position;

void RED_Square()
{
	glColor3f(1, 0, 0);

	glPushMatrix();
	glRectf(0.5, 0.5, 5, 5);
	glPopMatrix();
}

void GREEN_Square()
{
	glColor3f(0, 1, 0);

	glPushMatrix();
	glRectf(0.5, 0.5, 5, 5);
	glPopMatrix();
}

void BLUE_Square()
{
	glColor3f(0, 0, 1);

	glPushMatrix();
	glRectf(0.5, 0.5, 5, 5);
	glPopMatrix();
}

void Cross_Line()
{
    glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(192.0f, 192.0f, 192.0f); // Gray Color Code

	glBegin(GL_LINES);
      glVertex3f (50 , 0, 0.0);
      glVertex3f (-50, 0, 0.0);
      glVertex3f (0 , 50, 0.0);
      glVertex3f (0, -50, 0.0);
	glEnd();

	glFlush();
}

void Combination_One()
{
    glPushMatrix();

	    RED_Square();

	    	glTranslatef(5, 0, 0);

	    GREEN_Square();

	    	glTranslatef(5, 0, 0);

	    BLUE_Square();

    glPopMatrix();
}

void Combination_Two()
{
    glPushMatrix();

	    BLUE_Square();

	    	glTranslatef(5, 0, 0);

	    RED_Square();

	    	glTranslatef(5, 0, 0);

	    GREEN_Square();

    glPopMatrix();
}

void Combination_Three()
{
    glPushMatrix();

	    GREEN_Square();

	     	glTranslatef(5, 0, 0);

	    BLUE_Square();

	     	glTranslatef(5, 0, 0);

	    RED_Square();

    glPopMatrix();
}


void Row_First()
{
    for(Position=0; Position<=45; Position = Position + 15)
	{
	     glPushMatrix();

	     	Combination_One();

	     		glTranslatef(Position, 0, 0);
	     
		Combination_One();

	     glPopMatrix();
    	}
}

void Row_Second()
{
    for(Position=0; Position<=45; Position = Position + 15)
	{
	     glPushMatrix();

	     	Combination_Two();

	     		glTranslatef(Position, 0, 0);
	     
		Combination_Two();

	     glPopMatrix();
    	}
}

void Row_Third()
{
    for(Position=0; Position<=45; Position = Position + 15)
	{
	     glPushMatrix();

	     	Combination_Three();

	     		glTranslatef(Position, 0, 0);
	     
		Combination_Three();

	     glPopMatrix();
    	}
}

void Sequence()
{
	glPushMatrix();

	      	Row_First();
		 	glTranslatef(0,5,0);

		Row_Second();
		 	glTranslatef(0,5,0);

		Row_Third();
		 	glTranslatef(0,5,0);

		Row_First();
		 	glTranslatef(0,5,0);

		Row_Second();
		 	glTranslatef(0,5,0);

		Row_Third();
		  	glTranslatef(0,5,0);

		Row_First();
		 	glTranslatef(0,5,0);

		Row_Second();
		 	glTranslatef(0,5,0);

		Row_Third();
		   	glTranslatef(0,5,0);

		Row_First();

	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	Cross_Line();
	Sequence();

	glutSwapBuffers();
}

void init(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}


int main(int argc, char *argv[])
{
   glutInit(&argc, argv);    
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Abdullah Al Noman");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}

