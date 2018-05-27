#include "Square.h"
#include <fstream>

Square::Square(double x, double y, double a, double b, std::string _colour)
{
	topLeftxCoordinate = x;
	topLeftyCoordinate = y;
	width = a;
	height = b;
	colour = _colour;
	
}
Square::Square()
{
	topLeftxCoordinate = 0;
	topLeftyCoordinate = 0;
	width = 1;
	height = 1;
	colour = "black";
}

bool Square::isInsideRectangle(double xTopLeft, double yTopLeft, double _width, double _height)
{
	return(	topLeftxCoordinate >= xTopLeft &&
			topLeftyCoordinate >= yTopLeft &&
			topLeftxCoordinate + width <= xTopLeft + _width &&
			topLeftyCoordinate + height <= yTopLeft + _height);
}

bool Square::isInsideCircle(double xCenter, double yCenter, double radius)
{
	double topRightxCoordinate = topLeftxCoordinate + width;
	double topRightyCoordinate = topLeftyCoordinate;
	double downLeftxCoordinate = topLeftxCoordinate;
	double downLeftyCoordinate = topLeftyCoordinate + height;
	double downRightxCoordinate = topRightxCoordinate;
	double downRightyCoordinate = downLeftyCoordinate;
	
	return (
		sqrt((topRightxCoordinate - xCenter)*(topRightxCoordinate - xCenter) + (topRightyCoordinate - yCenter)*(topRightyCoordinate - yCenter)) <= radius &&
		sqrt((topLeftxCoordinate - xCenter)*(topLeftxCoordinate - xCenter) + (topLeftyCoordinate - yCenter)*(topLeftyCoordinate - yCenter)) <= radius &&
		sqrt((downRightxCoordinate - xCenter)*(downRightxCoordinate - xCenter) + (downRightyCoordinate - yCenter)*(downRightyCoordinate - yCenter)) <= radius &&
		sqrt((downLeftxCoordinate - xCenter)*(downLeftxCoordinate - xCenter) + (downLeftyCoordinate - yCenter)*(downLeftyCoordinate - yCenter)) <= radius
		);
}

void Square::print()
{
	std::cout <<"Rectangle " << topLeftxCoordinate << " " << topLeftyCoordinate << " " << width << " " << height << " " << colour << std::endl;
}

void Square::saveInFile(std::string fileName)
{
	std::ofstream myFile;
	myFile.open(fileName, std::ios::app);
//	myFile << std::endl;
	myFile << "  <rect x=\"" << topLeftxCoordinate << "\" y=\"" << topLeftyCoordinate << "\" width=\"" << width << "\" height=\"" << height<<"\" fill=\""<<colour << "\" />" << std::endl;
}


