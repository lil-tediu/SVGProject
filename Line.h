#pragma once
#include"Figure.h"
#include "math.h"
#include <iostream>

class Line: public Figure
{
private:
	double xRight;
	double yRight;
	double length = sqrt((topLeftxCoordinate - xRight) * (topLeftxCoordinate - xRight) + (topLeftyCoordinate - yRight) * (topLeftyCoordinate - yRight));
public:
	Line(double xLeft, double yLeft, double _xRight, double _yRight, std::string _colour );
	Line();
	bool isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height);
	bool isInsideCircle(double xCenter, double yCenter, double _radius);
	void translate(double horizontal, double vertical);
	void print();
	void saveInFile(std::string fileName);





};