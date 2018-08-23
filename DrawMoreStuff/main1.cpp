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

Link L1(0.0,-100.0,200.0, PI/2, 40.0, 1.0, 0.0, 0.0);
Link L2(0.0,-100.0,200.0, PI/4, 35.0, 1.0, 1.0, 0.0);
Link L3(0.0,-100.0,200.0, 0, 30.0, 1.0, 0.0, 1.0);
Link L4(0.0, 50.0, 200.0, PI/5, 10.0, 1.0, 0.0, 0.0);


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
	double theta = 0;
	double Radius = 10.0;
	glClearColor (0.0,0.0,0.0,1.0);
	glClear (GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

// Draw
	L1.Move(L1.GetX(), L1.GetY(), L1.Getangle()-0.01);
	L1.Draw();
	L2.Move(L1.GetEnd().GetX(), L1.GetEnd().GetY(),L2.Getangle()+0.01); 
	L2.Draw();
	L3.Move(L2.GetEnd().GetX(), L2.GetEnd().GetY(),L2.Getangle()*3);
	L3.Draw();
// End of Draw
	glFlush();
	glutSwapBuffers();
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Draw Links");
	init();
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}
