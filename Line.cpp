#include "Line.h"
#include <fstream>

Line::Line(double xLeft, double yLeft, double _xRight, double _yRight, std::string _colour)
{
	topLeftxCoordinate = xLeft;
	topLeftyCoordinate = yLeft;
	xRight = _xRight;
	yRight = _yRight;
	colour = _colour;
}

Line::Line()
{
	topLeftxCoordinate = 0;
	topLeftyCoordinate = 0;
	xRight = 1;
	yRight = 1;
	colour = "black";
}

bool Line::isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height)
{
	return (xTopLeft <= topLeftxCoordinate && yTopLeft <= topLeftyCoordinate &&
			xTopLeft + width >= xRight && yTopLeft + height >= yRight);
}

bool Line::isInsideCircle(double xCenter, double yCenter, double _radius)
{
	return (sqrt((xRight - xCenter)*(xRight - xCenter) + (yRight - yCenter)*(yRight - yCenter)) <= _radius &&
			sqrt((topLeftxCoordinate - xCenter)*(topLeftxCoordinate - xCenter) + (topLeftyCoordinate - yCenter)*(topLeftyCoordinate - yCenter)) <= _radius);
}

void Line::translate(double horizontal, double vertical)
{
	topLeftxCoordinate = topLeftxCoordinate + horizontal;
	topLeftyCoordinate = topLeftyCoordinate + vertical;
	xRight = xRight + horizontal;
	yRight = yRight + vertical;
}

void Line::print()
{
	std::cout << "Line " << topLeftxCoordinate << " " << topLeftyCoordinate << " " << xRight << " " << yRight << " " << colour << std::endl;
}

void Line::saveInFile(std::string fileName)
{
	std::ofstream myFile;
	myFile.open(fileName, std::ios::app);
//	myFile << std::endl;
	myFile << "  <line x1=\"" << topLeftxCoordinate << "\" y1=\"" << topLeftyCoordinate << "\" x2=\"" << xRight <<"\" y2=\""<<yRight << "\" fill=\"" << colour << "\" />" << std::endl;
}

