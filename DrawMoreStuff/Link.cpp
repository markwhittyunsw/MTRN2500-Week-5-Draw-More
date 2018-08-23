#include "stdafx.h"
#include <GL/glut.h>
#include <math.h>
#include "link.h"
#include "line.h"
#include "circle.h"
#include "point.h"

#define PI 3.14159265358979323846


Link::Link(): Line()
{
}

Link::Link(double x, double y, double length, double angle, double radius)
: Line(x,y,length,angle)
{
	Radius = radius;
}

Link::Link(double x, double y, double length, double angle, double radius,
		   double r, double g, double b):Line(x,y,length,angle,r,g,b)
{
	Radius = radius;
}

Link::Link(Point start, double length, double angle, double radius):Line(start,length,angle)
{
	Radius = radius;
}

Link::Link(Point start, double length, double angle, double radius,
		   double r, double g, double b):Line(start, length, angle, r, g, b)
{
	Radius = radius;
}

void Link::Draw()
{
	Circle Start, End;
	Line Top, Bottom;
	Start = Circle(X,Y,Radius, R,G,B);
	End = Circle(GetEnd(), Radius, R,G,B);
	Top = Line(X-Radius*sin(Angle), Y+Radius*cos(Angle),Length, Angle, R,G,B);
	Bottom = Line(X+Radius*sin(Angle), Y-Radius*cos(Angle),Length, Angle, R,G,B);
	Start.Draw();
	End.Draw();
	Top.Draw();
	Bottom.Draw();
}

//End of Link Class ==========================================================
