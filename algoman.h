#define r 20 
int x=0,i1=0,j=0,sun=0;
float a=0.0;
int al1=45,al2=-45,ah1=30,ah2=-30;
double fleg=30,bleg=-30;
double fhand=35,bhand=-35;
double a1=0,a2=120,fl1=0,fl2=50,bl1=0,bl2=50,c1=0,c2=250,b1=0,b2=210,fh1=0,bh1=0,fh2=120,bh2=120;
void motion()                                  //motion of ball
{   
  double d,m;
  d=fleg;                                  //fhand=forward hand 
  m=bleg;					//bleg=backward leg
  
  if(fleg<=-30){
    d=-30;
  }
  if(bleg>=30){
    m=30;
    swap(bleg,fleg);
    swap(m,d);
  }


  double d1,m1;                        //fhand=forward hand
  d1=fhand;
  m1=bhand;	    			//backward hand
  
  if(fhand<=-45){
    d1=-45;
  }
  if(bhand>=45){
    m1=45;
    swap(bhand,fhand);
    swap(m1,d1);
  }  
// function for shearing and translation 
  double cosa,sina,cosb,sinb;
  cosa = (cos ( d * PI / 180.0 )); 
  sina = (sin ( d * PI / 180.0 ));

  cosb = (cos ( m * PI / 180.0 )); 
  sinb = (sin ( m * PI / 180.0 ));

  double cosa1,sina1,cosb1,sinb1;

  cosa1 = (cos ( d1 * PI / 180.0 )); 
  sina1 = (sin ( d1 * PI / 180.0 )); 

  cosb1 = (cos ( m1 * PI / 180.0 )); 
  sinb1 = (sin ( m1 * PI / 180.0 ));
 /*
using shearing concept
*/
  double tan = sina/cosa;
  double tanB = sinb/cosb;

  double tan1 = sina1/cosa1;
  double tanB1 = sinb1/cosb1;
  
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
//LEGS
glColor3f(0.0f, 0.0f, 1.0f);
linedraw(x+a11,a12,x+fl11,fl12);
glColor3f(0.0f, 0.0f, 1.0f);
linedraw(x+a11,a12,x+bl11,bl12);
//glColor3f(0.0f, 1.0f, 1.0f);
//CenTER
//linedraw(x+a11,a12,x+c1,c2);
glColor3f(1.0f, 0.0f, 1.0f);
linedraw(x+b11,b12,x+fh11,fh12);
glColor3f(1.0f, 0.0f, 1.0f);
linedraw(x+b11,b12,x+bh11,bh12);
glFlush();
}


void face(int xc,int yc)
{

int x=0;
int y=r;
int h=1-r;
glPointSize(5);
glBegin(GL_POINTS);
glColor3f(0,1,0);                       //circle algorithm 
glVertex2i(xc+x,yc+y-20);
glEnd();
glBegin(GL_POINTS);
glColor3f(0,1,0);                       //circle algorithm 
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
glPointSize(3);
glBegin(GL_POINTS);
glColor3f(0,0,1);
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
}

void body(int x)                         //implement road
{
glPointSize(5);
glColor3f(0,1,1);
linedraw(x,290,x,120);
glPointSize(1);
} 
void man()
{
face(x,350);
body(x);
motion();
}
