#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y3,y2;
 
void display(void)
{
float dy,dx,step,x,y,k,Xin,Yin;
dx=x2-x1;
dy=y2-y3;

for(int j=0;j<500;j++)
{
glBegin(GL_POINTS);
glVertex2i(0,j);
glVertex2i(j,0);
glVertex2i(0,-j);
glVertex2i(-j,0);

glEnd();
}
if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);
 
Xin = dx/step;
Yin = dy/step;
 
x= x1;
y=y3;
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
 
for (k=1 ;k<=step;k++)
{
x= x + Xin;
y= y + Yin;
 
glBegin(GL_POINTS);
glVertex2i(x,y);
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

void init1(void)
{
glClearColor(0,0,1,1);  
glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
glColor3f(0.0f,1.0f,0.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,200,0,200);
} 

int main(int argc, char** argv) {
printf("Enter the value of x1 : ");
scanf("%f",&x1);
printf("Enter the value of y1 : ");
scanf("%f",&y3);
printf("Enter the value of x2 : ");
scanf("%f",&x2);
printf("Enter the value of y2 : ");
scanf("%f",&y2);
 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("DDA Line Algo");
init();
glutDisplayFunc(display);
//viewport 
glutInitWindowSize (200, 200);
glutInitWindowPosition (500,100);
glutCreateWindow ("Viewport View ");
init1();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}

