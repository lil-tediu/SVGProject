#include "Circle.h"
#include <fstream>

Circle::Circle(double x, double y, double r, std::string _colour)
{
	topLeftxCoordinate = x;
	topLeftyCoordinate = y;
	radius = r;
	colour = _colour;
	
}

Circle::Circle()
{
	topLeftxCoordinate = 0;
	topLeftyCoordinate = 0;
	radius = 1;
	colour = "black";
	
}

bool Circle::isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height)
{
	return (
		xTopLeft < topLeftxCoordinate && yTopLeft < topLeftyCoordinate &&
		topLeftxCoordinate + radius <= xTopLeft + width &&
		topLeftxCoordinate - radius >= xTopLeft &&
		topLeftyCoordinate + radius <= yTopLeft + height &&
		topLeftyCoordinate - radius >= yTopLeft
		);
}

bool Circle::isInsideCircle(double xCenter, double yCenter, double _radius)
{

	return (
		sqrt((topLeftxCoordinate - xCenter)*(topLeftxCoordinate - xCenter) + (topLeftyCoordinate - yCenter)*(topLeftyCoordinate - yCenter)) <= abs(_radius - radius)
		);
}

void Circle::print()
{
	std::cout <<"Circle " << topLeftxCoordinate << " " << topLeftyCoordinate << " " << radius << " " << colour << std::endl;
}

void Circle::saveInFile(std::string fileName)
{
	std::ofstream myFile;
	myFile.open(fileName, std::ios::app);
//	myFile << std::endl;
	myFile << "  <circle cx=\"" << topLeftxCoordinate << "\" cy=\"" << topLeftyCoordinate << "\" r=\"" << radius << "\" fill=\"" << colour << "\" />" << std::endl;
}






