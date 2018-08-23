#include "stdafx.h"
#include <Windows.h>
#include <GL/glut.h>
#include <math.h>
#include "point.h"
#include "circle.h"
#include "line.h"
#include "link.h"

#define PI 3.14159265358979323846

//Global data Declaration

Point P(100,200);
Circle C(100,200,50,1,0,0);
Line L(100,200,400,PI/4);
Link Lk(100.0,200.0,400.0, PI/4, 30.0, 0.0, 1.0, 0.0);

//OpenGL related functions 

void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) 
	{
	case 27:
		exit(0);
	}
}


void display (void) 
{
	static double Xx = Lk.GetX();
	static double Ang = Lk.Getangle();
	static int i = 0;
	double theta = 0;
	double Radius = 10.0;
	glClearColor (0.0,0.0,0.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

// Draw
	P.Draw();
	C.Draw();
	L.Draw();
	Lk.Draw();
// End of Draw
	glFlush();
	glutSwapBuffers();
	Lk.Move(Xx--,Lk.GetY(),Ang+i++*0.01);
	Sleep(10);

}


void reshape (int w, int h) 
{
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D(-(GLdouble) w,(GLdouble) w,-(GLdouble) h,(GLdouble) h);
	glMatrixMode (GL_MODELVIEW);
}


int main (int argc, char **argv) 
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("An OpenGL Example Window");
	init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc (display);
	glutReshapeFunc (reshape);
	glutIdleFunc(display);
	glutMainLoop ();
	return 0;
}
