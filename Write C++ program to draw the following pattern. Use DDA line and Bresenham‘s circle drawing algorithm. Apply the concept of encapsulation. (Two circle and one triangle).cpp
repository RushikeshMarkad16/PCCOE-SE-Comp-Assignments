#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
class shape
{
public:

    void line(float x1,float y1,float x2,float y2)
    {
	float x,y,dx,dy,step;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
	    step=abs(dy);
	dx=dx/step;
	dy=dy/step;
	x=x1;
	y=y1;
	int i=0;
	do{
		putpixel(x,y,GREEN);
		x=x+dx;
		y=y+dy;
		i=i+1;
		delay(30);
	  }while(i<step);
    }

    void circle(float xc ,float yc,float r)
    {
			float x,y,p;
			x=0;
			y=r;
			p=3-(2*r);
			do{
				putpixel(xc+x,yc+y,GREEN);
				putpixel(xc-x,yc+y,GREEN);
				putpixel(xc-x,yc-y,GREEN);
				putpixel(xc+x,yc-y,GREEN);
				putpixel(xc+y,yc+x,GREEN);
				putpixel(xc-y,yc+x,GREEN);
				putpixel(xc-y,yc-x,GREEN);
				putpixel(xc+y,yc-x,GREEN);
				x=x+1;
				if(p<0)
					p=p+4*x+6;
				else{
					p=p+4*(x-y)+10;
					y=y-1;
			}
				delay(100);
			}while(x<=y);
    }
      void triangle(float xc ,float yc ,float r)
      {
			line(xc,yc-r,xc-sqrt(3)*r/2,yc+r/2);
			line(xc-sqrt(3)*r/2,yc+r/2,xc+sqrt(3)*r/2,yc+r/2);
			line(xc+sqrt(3)*r/2,yc+r/2,xc,yc-r);
      }
};

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	float xc,yc,r;
	cout<<"Enter center of circle : ";
	cin>>xc>>yc;
	cout<<"Enter the radius of circle : ";
	cin>>r;
	shape obj;
	obj.circle(xc,yc,r);
	obj.triangle(xc,yc,r);
	obj.circle(xc,yc,r/2);
	delay(100);
	getch();
	closegraph();
	return 0;
}
