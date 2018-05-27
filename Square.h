#pragma once
#include "Figure.h"
#include <iostream>


class Square: public Figure
{
private:
	double width;
	double height;
public:
	Square(double x, double y, double a, double b, std::string _colour);
	Square();
	 bool isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height);
	 bool isInsideCircle(double xCenter, double yCenter, double radius);
	 void print();
	 void  saveInFile(std::string fileName);





};
