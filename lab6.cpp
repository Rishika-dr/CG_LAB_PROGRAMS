#include <stdio.h>
#include <GL/glut.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void tableLeg(GLfloat thick,GLfloat width)
{
	glPushMatrix();
	glScaled(thick,width,thick);
	glutSolidCube(1.0);
	glPopMatrix();
}

void table(GLfloat topWidth,GLfloat topThick,GLfloat legThick,GLfloat legLen)
{
	glPushMatrix();
	glTranslated(0,legLen,0);
	glScaled(topWidth,topThick,topWidth);
	glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.28,0.15,0.28);
	tableLeg(legThick,legLen);
	glTranslated(0.0,0.0,-2*0.28);
	tableLeg(legThick,legLen);
	glTranslated(-2*0.28,0.0,0.0);
	tableLeg(legThick,legLen);
	glTranslated(0.0,0.0,2*0.28);
	tableLeg(legThick,legLen);
	glPopMatrix();
}
void displaysolid()
{
	GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_diffuse[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_specular[]={0.0f,1.0f,0.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	GLfloat lightIntensity[]={0.7f,0.7f,0.7f,0.0f};
	GLfloat lightPosition[]={2.0f,6.0f,3.0f,0.0f};
	glLightfv(GL_FRONT,GL_POSITION,lightPosition);
	glLightfv(GL_FRONT,GL_DIFFUSE,lightIntensity);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3,1.3,2.0,0.0,0.25,0.0,0.0,1.0,0.0);
	glPushMatrix();
	glTranslated(0.6,0.38,0.5);
	glRotated(30,0,1,0);
	glutSolidTeapot(0.08);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.4,0.0,0.4);
	table(0.6,0.02,0.02,0.3);
	glPopMatrix();
	glFlush();
	
}
int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Teapot");
	glutDisplayFunc(displaysolid);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0,0.0,0.0,0.0);
	glutMainLoop();
	return 0;
}







