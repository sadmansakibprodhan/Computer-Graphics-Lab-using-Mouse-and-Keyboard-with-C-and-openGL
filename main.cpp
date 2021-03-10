#include<windows.h>
#include <GL/glut.h>

#include <stdlib.h>

#include <math.h>


static GLfloat spin = 0.0;//initial degree for spinning
static float	tx	=  0.0;
static float	ty	=  0.0;


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(0.0, 1.0, 0.0);

//	glTranslatef(tx,ty,0);
       glRectf(2.0,2.0,-2.0,-2.0);
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
   if (spin < 0.0)
      spin = spin +360.0;
   glutPostRedisplay();
}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-25.0, 25.0, -25.0, 25.0, -25.0, 25.0);
}


void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			spinDisplay_left();
			//glutIdleFunc(spinDisplay_left);
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

void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
//            spinDisplay_left();
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
//            spinDisplay_right();
			glutIdleFunc(spinDisplay_right);
         break;
      default:
         break;
   }
}
int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Use of Mouse and Keyboard");
	init();
    glutDisplayFunc(display);
	glutKeyboardFunc(my_keyboard);
	glutMouseFunc(my_mouse);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

