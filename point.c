#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int r,x,y;

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
glPointSize(4);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
}

void init(void)
{
glClearColor(0,0,1,1);  
glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
glColor3f(0.0f,0.0f,0.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glPointSize(3);
gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
//printf("");
printf("Enter the co-ordinate of point (less than 50 to observe the change)  : ");
scanf("%d%d",&x,&y); 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (400, 400);
glutInitWindowPosition (0,0);
glutCreateWindow ("Window View ");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}

