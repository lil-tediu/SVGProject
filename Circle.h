#pragma once
#include "Figure.h"
#include <iostream>

class Circle: public Figure
{
private:
	double radius;
public:
	 Circle (double x, double y, double r, std::string _colour);
	 Circle();
	 bool	isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height);
	 bool	isInsideCircle(double xCenter, double yCenter, double _radius);
	 void print();
	 void saveInFile(std::string fileName);
};