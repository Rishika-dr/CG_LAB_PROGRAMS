#include <stdio.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float x1,y1,x2,y2,x3,y3,x4,y4;
int le[1000],re[1000];

void edgedetect(float x1,float y1,float x2,float y2)
{
	int mx,x;
	if((y2-y1)!=0)
	{
		mx=(x2-x1)/(y2-y1);
	}
	x=x1;
	for(int i=y1;i<=y2;i++)
	{
		if(x<=le[i])
			le[i]=x;
		else
			re[i]=x;
		x+=mx;
	}
}
void scanline(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
	int i,y;
	for(i=400;i<=800;i++)
	{
		le[i]=400;
		re[i]=400;
	}
	edgedetect(x1,y1,x2,y2);
	edgedetect(x2,y2,x3,y3);
	edgedetect(x4,y4,x3,y3);
	edgedetect(x1,y1,x4,y4);
	for(y=400;y<=800;y++)
	{
		for(i=le[y];i<=re[y];i++)
		{
			glColor3f(0,0,0);
			glBegin(GL_POINTS);
			glVertex2i(i,y);
			glEnd();
			glFlush();
		}
	}
}
void sub_menu(int c)
{
	switch(c)
	{
		case 1:
			glColor3f(0,0,0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
			glVertex2f(x3,y3);
			glVertex2f(x4,y4);
			glEnd();
			glFlush();
			break;
		case 2:
			glColor3f(0,0,0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
			glVertex2f(x3,y3);
			glVertex2f(x4,y4);
			glEnd();
			scanline(x1,y1,x2,y2,x3,y3,x4,y4);
			glFlush();
			break;
	}
}

void main_menu(int c)
{
	switch(c)
	{
		case 3:
			exit(0);
	}
}
void display()
{
	x1=400;
	y1=400;
	x2=200;
	y2=600;
	x3=400;
	y3=800;
	x4=600;
	y4=600;
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(20,30);
	glutCreateWindow("Scanline");
	glClearColor(1,1,1,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1000,0,1000);
	int submenu=glutCreateMenu(sub_menu);
	glutAddMenuEntry("Draw Polygon",1);
	glutAddMenuEntry("Fill Polygon",2);
	glutCreateMenu(main_menu);
	glutAddSubMenu("Program to",submenu);
	glutAddMenuEntry("Quit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
