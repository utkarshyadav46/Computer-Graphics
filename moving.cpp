/* 

  Author : Gaurav Khandelwal
  Roll Number : 2016KUCP1002
  Assignment Question : Moving Man

*/

/* Header Files */

#include<iostream>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

#define PI 3.14159265

// Angle Declare

double fleg=30,bleg=-30;
double fhand=35,bhand=-35;
double i=-1000;

// coordinate Declare

double a1=0,a2=120,fl1=0,fl2=0,bl1=0,bl2=0,c1=0,c2=250,b1=0,b2=210,fh1=0,bh1=0,fh2=120,bh2=120;

// init method

void init(string windowName)
{
  //glClearColor (0.0, 0.0, 0.0, 0.0);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(0,0);
  glutInitWindowSize(800,800);  
  int n = windowName.length(); 
  char name[n+1];
  strcpy(name, windowName.c_str()); 
  glutCreateWindow(name);
  glClearColor(0,0,0,0);  
  glClear(GL_COLOR_BUFFER_BIT);        //glClearColor ( float red, float green, float blue, float alpha ) ;
  glColor3f(0.0f,1.0f,0.0f);   
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1000,1000,-1000,1000);
}

//  function to set the pixel

void setPixel(double x,double y)
{
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  glEnd();
}

// display circle method

void drawCircle(double h,double k,double r)
{
   

    double x = 0;
    double y = r;

    double xprev,yprev;

    double p = 1-r;

    while(x<y)
    {
        //cout << x << " " << y << endl;
        setPixel(h+x,k+y);
        setPixel(h+y,k+x);
        setPixel(h+x,k-1*y);
        setPixel(h-1*y,k+x);
        setPixel(h-1*x,k+y);
        setPixel(h-1*x,k-1*y);
        setPixel(h-1*y,k-1*x);
        setPixel(h+y,k-1*x);
        xprev = x;
        yprev = y;

        x = x+1;
        if(p>=0)
            y = y-1;    // mid point lie outside circle

        p = p + 2*(xprev+1) + (y*y - yprev*yprev) - (y-yprev) + 1;    
    }

}


void drawCoordinateAxis()
{
  double vertical=0;
  double horizontal=0;

  while(horizontal<=1000)
  {
    setPixel(horizontal,0);
    setPixel(-1*horizontal,0);
    horizontal++;
  }
}

void moveMan()
{   
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 0.0, 0.0); 
  drawCoordinateAxis();
  
  double d,m;
  d=fleg;
  m=bleg;
  
  if(fleg<=-30){
    d=-30;
  }
  if(bleg>=30){
    m=30;
    swap(bleg,fleg);
    swap(m,d);
  }


  double d1,m1;
  d1=fhand;
  m1=bhand;
  
  if(fhand<=-35){
    d1=-35;
  }
  if(bhand>=35){
    m1=35;
    swap(bhand,fhand);
    swap(m1,d1);
  }  

  double result,param,resultB,paramB;
  result = (cos ( d * PI / 180.0 )); 
  param = (sin ( d * PI / 180.0 ));

  resultB = (cos ( m * PI / 180.0 )); 
  paramB = (sin ( m * PI / 180.0 ));

  double result1,param1,resultB1,paramB1;

  result1 = (cos ( d1 * PI / 180.0 )); 
  param1 = (sin ( d1 * PI / 180.0 )); 

  resultB1 = (cos ( m1 * PI / 180.0 )); 
  paramB1 = (sin ( m1 * PI / 180.0 ));
  
  double tan = param/result;
  double tanB = paramB/resultB;

  double tan1 = param1/result1;
  double tanB1 = paramB1/resultB1;
  
  double a11,a12,fl11,fl12,bl11,bl12,b11,b12,fh11,fh12,bh11,bh12;

  a11 = a1 + tan*a2 - a2*tan;  
  a12 = a2;

  fl11 = fl1 + tan*fl2 - a2*tan;
  fl12 = fl2;

  bl11 = bl1 + tanB*bl2 - a2*tanB;
  bl12 = bl2;


  b11 = b1 + tan1*b2 - b2*tan1;  
  b12 = b2;

  fh11 = fh1 + tan1*fh2 - b2*tan1;
  fh12 = fh2;

  bh11 = bh1 + tanB1*bh2 - b2*tanB1;
  bh12 = bh2;

  glBegin(GL_LINES);
  glColor3f(0.0f, 1.0f, 1.0f);
  glVertex2i(i+a11, a12);
   glVertex2i(i+fl11, fl12);
   glEnd();

   glBegin(GL_LINES);
   glColor3f(0.0f, 1.0f, 1.0f);
   glVertex2i(i+a11, a12);
   glVertex2i(i+bl11, bl12);
   glEnd();

   glBegin(GL_LINES);
   glColor3f(1.0f, 0.0f, 1.0f);
   glVertex2i(i+a11, a12);
   glVertex2i(i+c1, c2);
   glEnd();

   glBegin(GL_LINES);
   glColor3f(1.0f, 1.0f, 0.0f);
   glVertex2i(i+b11, b12);
   glVertex2i(i+fh11, fh12);
   glEnd();


   glBegin(GL_LINES);
   glColor3f(1.0f, 1.0f, 0.0f);
   glVertex2i(i+b11, b12);
   glVertex2i(i+bh11, bh12);
   glEnd();

   glColor3f(0.0f, 0.0f, 1.0f); 
   drawCircle(i,300,50); 
  
  glFlush(); 
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/5,timer,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    if(i<=1000)
        i=i+10;

    if(fleg>=-30){
        fleg=fleg-5;
    } 

    if(bleg<=30) 
    {
        bleg=bleg+5;
    }  

    if(fleg>=-35){
        fhand=fhand-5;
    } 

    if(bhand<=35) 
    {
        bhand=bhand+5;
    } 

}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  string windowName="Moving";
  init(windowName);
  glutDisplayFunc(moveMan);
  glutTimerFunc(0,timer,0);
  glutMainLoop();
  return 0;  
}
