//2016kucp1023
/*
Q1--> Draw The figure as given :-
Q2--> Draw The same figure Figure in window To viewPort :-

*/


#include<GL/glut.h>//library for opengl
#include<stdlib.h>
#include<stdio.h>  
float x1,x2,y3,y2;
int x=0,y=0;
void init1(void)
{
glClearColor(0,0,1,1);  
glClear(GL_COLOR_BUFFER_BIT);       //to put color of screen
glColor3f(0.0f,0.0f,0.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-50,50,-50,50);
}

 
void line(int xi ,int yi ,int xf,int yf)   //line using  dda algorithm
{
float dy,dx,step,x,y,k,Xin,Yin;    
dx=xf-xi;
dy=yf-yi;

if(abs(dx)> abs(dy))
{
step = abs(dx);
}
else
step = abs(dy);
 
Xin = dx/step;
Yin = dy/step;
 
x= xi;
y=yi;
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
 

void displayg()
{
glColor3f(0,0,0);
line(0,0,0,200);
line(0,200,200,200);
line(200,200,200,0);
line(200,0,0,0);
glColor3f(0,1,0);
line(100,100,100,300);
line(100,300,300,300);
line(300,300,300,100);
line(300,100,100,100);
glColor3f(0,0,1);
line(100,100,0,0);
line(200,0,300,100);
line(100,300,0,200);
line(200,200,300,300);
glColor3f(1,0,0);
line(100,300,200,450);
line(200,450,300,300);
}
void init(void)
{
glClearColor(1,1,1,0);  
glClear(GL_COLOR_BUFFER_BIT);   
glColor3f(0.0f,0.0f,1.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,1000,0);
}


int main(int argc, char** argv)
{
printf("\tCUBE\n");
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("LAB wndow to viewport");
init();
glutDisplayFunc(displayg);
glutMainLoop();

return 0;
}

