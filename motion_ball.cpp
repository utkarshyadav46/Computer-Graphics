/*
NAME :UTKARSH YADAV
ID : 2016kucp1023
Q:IMPLEMENT MOVING BALL 
*/
#include<GL/glut.h>//library for opengl
#include<stdlib.h>
#include<stdio.h> 
#include<unistd.h>
#include<math.h>
#include<iostream>
using namespace std;
float x1,x2,y3,y2;
int x=0,y=0,r=100;
int k=0;
float i=0,j=500;
void linedraw(int xi ,int yi ,int xf,int yf)   //linedraw using  dda algorithm
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
 
 
void SpeedBreaker(int xc,int yc)     //xc ,yc for shiftint center coordinate
{
int x=0;
int y=r;
int h=1-r;
glBegin(GL_POINTS);
glColor3f(0,0,0);
glVertex2i(xc+x,yc+y);
glVertex2i(xc+y,yc+x);
glVertex2i(xc-x,yc+y);
glVertex2i(xc-y,yc+x);
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
glColor3f(0,0,0);
glVertex2i(xc+x,yc+y);
glVertex2i(xc+y,yc+x);
glVertex2i(xc-x,yc+y);
glVertex2i(xc-y,yc+x);
glEnd();
}
glFlush();
}
//Ball Normal Circle with center xc,yc
void circle(int xc,int yc)
{
int x=0;
int y=r;
int h=1-r;
glBegin(GL_POINTS);
glColor3f(0,1,0);
glVertex2i(xc+x,yc+y);
glVertex2i(xc+y,yc+x);
glVertex2i(xc-x,yc+y);
glVertex2i(xc+y,yc-x);
glVertex2i(xc-x,yc-y);
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
glColor3f(0,1,0);
glVertex2i(xc+x,yc+y);
glVertex2i(xc+x,yc-y);
glVertex2i(xc+y,yc+x);
glVertex2i(xc+y,yc-x);
glVertex2i(xc-x,yc+y);
glVertex2i(xc-x,yc-y);
glVertex2i(xc-y,yc-x);
glVertex2i(xc-y,yc+x);

glEnd();
}
glFlush();
}


void square(int xc,int yc)
{
//rotate();
int y=400;
int a1=0,a2=0,b1=100,b2=0,c1=100,c2=100,d1=0,d2=100;
float e11,f11,g11,h11,e12,f12,g12,h12;
e11=a1*cos(k)-a2*sin(k);
e12=a1*sin(k)+a2*cos(k);
f11=b1*cos(k)-b2*sin(k);
f12=b1*sin(k)+b2*cos(k);
g11=c1*cos(k)-c2*sin(k);
g12=c1*sin(k)+c2*cos(k);
g11=d1*cos(k)-d2*sin(k);
g12=d1*sin(k)+d2*cos(k);

glColor3f(0.0f, 0.0f, 1.0f);
linedraw(i+e11,y+e12,i+f11,y+f12);
glColor3f(0.0f, 0.0f, 1.0f);
linedraw(i+f11,y+f12,i+g11,y+g12);
glColor3f(0.0f, 0.0f, 1.0f);
linedraw(i+g11,y+g12,i+h11,y+h12);
glColor3f(0.0f, 0.0f, 1.0f);
linedraw(i+h11,y+h12,i+e11,y+e12);
}

void road()
{
for(int i=0;i<400;i++)
{
glBegin(GL_POINTS);
glColor3f(0,0,0);
glVertex2i(i,400);
glEnd();
}
//Breaker Function
SpeedBreaker(500,400);

for(int i=600;i<800;i++)
{

glBegin(GL_POINTS);
glColor3f(0,0,0);
glVertex2i(i,400);
glEnd();
}
for(int k=0;k<400;k++)
{
glBegin(GL_POINTS);
glColor3f(0,0,0);
glVertex2i(800,k);
glEnd();
}
glFlush();
} 
//Making Ball ANd Surface 

void ball()
{
road();
circle(i,j);
//square(i,j);
}

//Making Timer Function For Automatic Motion
void timer(int)
{glPointSize(5);
glutPostRedisplay();
glutTimerFunc(1000/7,timer,0);   //Define 1000/7 milisecond Delay
glClear(GL_COLOR_BUFFER_BIT);   
glClearColor(1,1,1,1);
if(i<=350)
i=i+10;
if(i>=330 && i<=670)
{
i=i+10;
j=400+sqrt(200*200 -(500-i)*(500-i));  //200*200=(500-i)*(500-i)+(400-j)(400-j)
}
if(i>=670 && i<900)
{
i=i+10;
j=500;
}
if(i>=900)
{
if(j>0)
j=j-10;
}
if(j==0)
{
i=0;
j=500;
}

if(k<360)
{
k=k+10;
}
}


//initialize the Window
void init(void)
{
glClearColor(1,1,1,0);  
glClear(GL_COLOR_BUFFER_BIT);   
glColor3f(0.0f,0.0f,1.0f);   
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,0,1000);
}


//Main Function
int main(int argc, char** argv)
{
printf("\tMoving BALL\n");   	//Moving BALL
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700, 700);
glutInitWindowPosition (0,0);
glutCreateWindow ("LAB");
init();
glutDisplayFunc(ball);
glutTimerFunc(0,timer,0);
glutMainLoop();
return 0;
}

