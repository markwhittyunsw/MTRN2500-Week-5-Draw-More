#include "stdafx.h"
#include <GL/glut.h>
#include <math.h>
#include "point.h"
#include "circle.h"

#define PI 3.14159265358979323846


Circle::Circle():Point()
{
}

Circle::Circle(double x, double y,  double radius, double r, double g, double b):Point(x,y)
{
	SetColour(r,g,b);
	Radius = radius;
}

Circle::Circle(Point c, double radius, double r, double g, double b)
{
	X = c.GetX();
	Y = c.GetY();
	Radius = radius;
	R = r;
	G = g;
	B = b;
}

double Circle::GetRadius()
{
	return Radius;
}
void Circle::SetRadius(double radius)
{
	Radius = radius;
}
void Circle::Draw()
{
	double p, q, theta = 0.0;
	glColor3f(R,G,B);
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
	do
	{
		p = X + Radius*cos(theta);
		q = Y + Radius*sin(theta);
		glVertex2f(p,q);
		theta += 0.005;
	}
	while(theta < 2*PI);
	glEnd();
}

// This function is redundant however provides better readability
void Circle::Move(double x, double y) 
{
	Point::Move(x,y);
}

