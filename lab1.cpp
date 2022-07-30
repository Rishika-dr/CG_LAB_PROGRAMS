#include <stdio.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int x1,y1,x2,y2;

void drawpixel(int x,int y)
{
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void drawline(int x1,int y1,int x2,int y2)
{
	int dx,dy,x,y,incx,incy,inc1,inc2,e;
	incx=1;
	incy=1;
	dx=x2-x1;
	dy=y2-y1;
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
	if(x2<x1)
		incx=-1;
	if(y2<y1)
		incy=-1;
	x=x1;
	y=y1;
	if(dx>dy)
	{
		drawpixel(x,y);
		e=2*dy-dx;
		inc1=2*(dy-dx);
		inc2=2*dy;
		for(int i=0;i<dx;i++)
		{
			if(e>=0)
			{
				e+=inc1;
				y+=incy;
			}
			else
				e+=inc2;
			x+=incx;
			drawpixel(x,y);
		}
	}
	else
	{
		drawpixel(x,y);
		e=2*dx-dy;
		inc1=2*(dx-dy);
		inc2=2*dx;
		for(int i=0;i<dy;i++)
		{
			if(e>=0)
			{
				e+=inc1;
				x+=incx;
			}
			else
				e+=inc2;
			y+=incy;
			drawpixel(x,y);
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawline(x1,y1,x2,y2);
	glFlush();
}

int main(int argc, char** argv) {
	printf("Enter the end points");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Line");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,100,0,100);
	glClearColor(0.0,0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
	
}
