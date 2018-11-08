#include <GL/freeglut.h>
#include <GL/gl.h>
 
void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);

    glBegin(GL_LINE_STRIP);
      glVertex3f (10 , 10, 0.0);
      glVertex3f (-10, 10, 0.0);
      glVertex3f (-10,-10, 0.0);
      glVertex3f (10 ,-10, 0.0);
      glVertex3f (10 , 10, 0.0);
    glEnd();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Abdullah Line Strip");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
