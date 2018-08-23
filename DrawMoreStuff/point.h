#ifndef POINT_H
#define POINT_H

//Start of Point class ====================================
class Point
{
protected:
	double X;
	double Y;
	double R;
	double G;
	double B;
public:
	Point();
	Point(double x, double y);
	Point(double x, double y, double r, double g, double b);
	// Any other constructors
	// Getters and setters
	double GetX();
	double GetY();
	double GetR();
	double GetG();
	double GetB();
	void SetX(double x);
	void SetY(double y);
	void SetColour(double r, double g, double b);
	// Point class capabilities
	void Draw();
	void Move(double x, double y);
	//any other capabilities
};
#endif
