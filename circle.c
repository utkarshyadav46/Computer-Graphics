#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int r;

void display(void)
{
for(int j=0;j<500;j++)
{
glBegin(GL_POINTS);
glVertex2i(0,j);
glVertex2i(j,0);
glVertex2i(0,-j);
glVertex2i(-j,0);
glEnd();
}
for(int j=0;j<500;j++)
{
glBegin(GL_POINTS);
glVertex2i(0,j);
glVertex2i(j,0);
glVertex2i(0,-j);
glVertex2i(-j,0);
glEnd();
}

int x=0;
int y=r;
int h=1-r;
glBegin(GL_POINTS);
glVertex2i(x,y);
glVertex2i(y,x);
glVertex2i(-x,y);
glVertex2i(y,-x);
glVertex2i(-x,-y);
glEnd();
while(y>x)
{
	if(h<0)
		h=h+2*x+3;
	else
	{
		h=h+2*x-2*y+5;
		y=y-1;
	}
x=x+1;
glBegin(GL_POINTS);
glVertex2i(x,y);
glVertex2i(x,-y);
glVertex2i(y,x);
glVertex2i(y,-x);
glVertex2i(-x,y);
glVertex2i(-x,-y);
glVertex2i(-y,-x);
glVertex2i(-y,x);

glEnd();
}
glFlush();
}

void init(void)
{
glClearColor(0,0,1,0);  
glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
glColor3f(0.0f,1.0f,0.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-200,200,-200,200);
}


int main(int argc, char** argv) {
printf("\n\t\tRadius<200\nEnter the value of radius: ");
scanf("%d",&r); 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("Circle using Mid Point Algorithm in First octant");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}

