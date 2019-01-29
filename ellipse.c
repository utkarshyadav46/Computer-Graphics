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
glVertex2i(-j,0);`
glEnd();
}

//R1
int p=b*b-a*a*b+a*a/4;
while(px<2*a*a*y)
{
x++;
px=px+2*b*b;
if(p<0)
{
p=p+b*b+px;
}
else
{
y--;
py=py-2*a*a;
p=p+2*b*b+px-py;
}
pp(xc+x,xc+y);
pp(xc+x,xc-y);
pp(xc-x,xc+y);
pp(xc-x,xc-y);
}8
//R2
p=b*b*(x+1/2)*(x+1/2)+a*a*(y-1)*(y-1)-a*a*b*b;
while(y>0)
{
y--;
py=py-2*a*a;
if(p>0)
{
p=p+a*a-py;
}
else
{
x++;
px=px+2*b*b;
p=p+a*a-py+px;
}
pp(xc+x,xc+y);
pp(xc+x,xc-y);
pp(xc-x,xc+y);
pp(xc-x,xc-y);
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
gluOrtho2D(-500,500,-500,500);
}


int main(int argc, char** argv) {
printf("Enter the length of major and minor axis:");
scanf("%d%d",&a,&b); 
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (0,0);
glutCreateWindow ("Ellipse");
init();
glutDisplayFunc(display);
glutMainLoop();
 
return 0;
}

