//2016KUCP10
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#define FPS 1
// Global variables
// Window/viewport
const int startwinsize = 400; // Starting window width & height, in pixels

// Keyboard
const int ESCKEY = 27;        // ASCII value of escape character

// Globals affecting display
bool showtext = true;         // True if text (help) is shown
bool startclock = true;       // True if clock is running
int hour=0, min=0, sec=0;     // time variables
string timestring="00:00:00";

int a,b,xc=0,yc=0;
void pp(int x,int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

void display(void)
{
int x=0,y=b;
int px=0,py=2*a*a*b;


glBegin(GL_LINE_LOOP);
glVertex2i(10,0);
glVertex2i(5,40);
glVertex2i(10,40);
glVertex2i(15,15);
glVertex2i(25,25);
glVertex2i(35,15);
glVertex2i(40,40);
glVertex2i(45,40);
glVertex2i(40,0);
glVertex2i(25,15);
glVertex2i(10,0);
glEnd();

glBegin(GL_LINE_LOOP);
glVertex2i(50,100);
glVertex2i(400,100);
glEnd();

glFlush();
}

// keyboard
// The GLUT keyboard function
void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case ESCKEY:  // ESC: Quit
      exit(0);
      break;
   case 'h':  // h - toggle text (help)
   case 'H':  // upper- and lower-case are different!
      showtext = !showtext;
      break;
   case 's':  // s - toggle clock on/off
   case 'S':
      startclock = !startclock;
      break;
   case 'r':  // r - reset clock
   case 'R':
      hour=min=sec=0;
      break;
   }
   glutPostRedisplay();
}

void init(void)
{
glClearColor(0,0,1,0);  
glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
glColor3f(0.0f,1.0f,0.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,0,1000);
}


int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("POLYGON");
init();
glutDisplayFunc(display);
 glutKeyboardFunc(keyboard);
glutMainLoop();
 
return 0;
}

