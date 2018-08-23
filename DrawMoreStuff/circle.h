#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

// Start of Circle class definition ===========================================
class Circle : public Point //Circle inherits everything from Point class.
{
protected:
	double Radius;

public:
	Circle();
	Circle(double x, double y, double radius, double r, double g, double b);
	Circle(Point c, double radius, double r, double g, double b);
	double GetRadius();
	void SetRadius(double radius);
	void Draw();
	void Move(double x, double y); //inherited move is sufficient - see definition
};

#endif