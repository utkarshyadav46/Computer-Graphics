#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
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

for(int j=0;j<50;j++)
{
glBegin(GL_POINTS);
glVertex2i(0,j);
glVertex2i(5,j);
glVertex2i(15,j);
glVertex2i(20,j);
glEnd();
}
for(int j=0;j<20;j++)
{
glBegin(GL_POINTS);
glVertex2i(j,0);
glVertex2i(j,10);
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
gluOrtho2D(-100,100,-100,100);
}


int main(int argc, char** argv) {
//printf("Enter the length of major and minor axis:");
//scanf("%d%d",&a,&b); 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("Ellipse using Mid Point Algorithm in First octant");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}

