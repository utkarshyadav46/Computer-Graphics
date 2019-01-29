#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
#define MAX 2000
int day=1,x=0,acc=0,pause=0,up=0,sit=0,enemy=0;

void background()
{
//day mode
if(day==1)
{
glColor3f(0.0,0.7,1);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,MAX);
glVertex2f(MAX,MAX);
glVertex2f(MAX,0);
glVertex2f(0,0);
glEnd();
}
if(day==0)
{
glColor3f(0,0,0);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,MAX);
glVertex2f(MAX,MAX);
glVertex2f(MAX,0);
glVertex2f(0,0);
glEnd();
}






	
}

void display()
{
background();	
}




void timer()
{
glutPostRedisplay();
glClearColor(1,1,1,1);
glColor3f(0,0,1);

if(x>6000 && pause)
{
x=x-10-acc;
}
else if (x==6000 && pause)
{
day=(day+1)%2;
}
else if(x>0 && pause)
x=x-10-acc;
if(x==0)
x=10000;


if(up>0)
{
	up=up-1;
}

}





void keyboardFunc(unsigned char key,int x,int y)
{
if(key=='W' || key=='w')
up=300;
if(key=='s'|| key=='S')
sit=100;
if(key=='d' || key=='D')
acc=acc+10;
if(key=='a' || key=='A')
acc=acc-10;
if(key=='p' || key=='P')
pause=(pause+1)%2;
if(key=='e' || key=='E')
enemy=(enemy+1)%2;	
}





void init()
{
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(1000,1000);
glutCreateWindow("GAME");
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,1000,0,1000);	
}




int main(int argc,char **argv)
{
while(1)
{	
cout<<"Welcome to game\n";
cout<<"follow following instruction\n";
cout<<"A->Retardation\nS->Sit\nD->Acceleration\nW->Jump\nF->Fireball\nL->Laser\n";
cout<<"Press Y to start The game\n";
char ch;
cin>>ch;
if(ch=='Y' || ch=='y')
{
glutInit(&argc, argv);
init();
glutDisplayFunc(display);
glutIdleFunc(timer);
glutKeyboardFunc(keyboardFunc);
glutMainLoop();
}
else
cout<<"Worng Choice Try Again\n";
}
return 0;
}
