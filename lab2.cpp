#include <stdio.h>
#include <GL/glut.h>
int choice;
float h=0,k=0,thetha;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void draw_traingle(); 
void draw_triangle()
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(100,100);
	glVertex2i(400,100);
	glVertex2i(250,350);
	glEnd();
}
void display_about_origin()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_traingle();
	glRotatef(thetha,0,0,1);
	draw_traingle();
	glFlush();
}


void display_about_fixedpoint()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_traingle();
	glTranslatef(h,k,0);
	glRotatef(thetha,0,0,1);
	glTranslatef(-h,-k,0);
	draw_traingle();
	glFlush();
}
int main(int argc, char** argv) {
	printf("Enter 1 for Rotation about Origin");
	printf("Enter 2 for Rotation about Fixed Point");
	scanf("%d",&choice);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(20,30);
	if(choice==1)
	{
		glutCreateWindow("Rotation about Origin");
		printf("Enter the angle of Rotation");
		scanf("%f",&thetha);
		glutDisplayFunc(display_about_origin);
	}
	if(choice==2)
	{
		glutCreateWindow("Rotation about Fixed Point");
	
		printf("Enter the angle of Rotation");
		scanf("%f",&thetha);
		printf("Enter the values of pivot point");
		scanf("%f%f",&h,&k);
		glutDisplayFunc(display_about_fixedpoint);
	}
	else
		printf("Invalid choice");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glClearColor(1,1,0,1);
	glColor3f(0,0,1);
	glOrtho(-500,500,-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0;
}
