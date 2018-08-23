#include "stdafx.h"
#include "point.h"
#include <GL/glut.h>

Point::Point()
{
}

Point::Point(double x, double y)
{
	X = x;
	Y = y;
	R = 1.0;
	G = 1.0;
	B = 1.0;
}

Point::Point(double x, double y, double r, double g, double b)
{
	X = x;
	Y = y;
	R = r;
	G = g;
	B = b;
}


double Point::GetX()
{
	return X;
}

double Point::GetY()
{
	return Y;
}

double Point::GetR()
{
	return R;
}

double Point::GetG()
{
	return G;
}

double Point::GetB()
{
	return B;
}

void Point::SetX(double x)
{
	X = x;
}

void Point::SetY(double y)
{
	Y = y;
}

void Point::SetColour(double r, double g, double b)
{
	R = r;
	G = g;
	B = b;
}

void Point::Draw()
{
	glColor3f(R,G,B);
	glLoadIdentity();
	glBegin(GL_POINTS);
	glVertex2f(X,Y);
	glEnd();
}

void Point::Move(double x, double y)
{
	X = x;
	Y = y;
}
// End of Point class definition and the member function declaration ==========
