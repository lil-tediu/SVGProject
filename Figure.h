#pragma once
#include<string>
#include<math.h>

class Figure
{
protected:
	double topLeftxCoordinate; 
	double topLeftyCoordinate;
	std::string colour;
	
public:
	//Figure* next; 
	/*virtual Figure* getNext();
	virtual void setNext(Figure& other);*/
	virtual bool isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height) = 0;
	virtual bool isInsideCircle(double xCenter, double yCenter, double radius) = 0;
	double getTopLeftXCoordinate();
	double getTopLeftYCoordinate();
	virtual void translate(double horizontal, double vertical);
	virtual void print() = 0;
	virtual void saveInFile(std::string fileName) = 0;

};