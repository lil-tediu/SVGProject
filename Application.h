#pragma once
#include<iostream>
#include "Figure.h"
#include<string>
#include "Square.h"
#include "Circle.h"
#include "Line.h"


class Application
{
private:
	Figure** figures;
	unsigned int numberOfFigures;

public:
	Application();
	~Application();
	Figure*  create(std::string type, double x, double y, double r, double a, double b, std::string _colour);
	Figure** erase(unsigned int number);
	void translate(unsigned int number, double horizontal, double vertical);
	void translate(double horizontal, double vertical);
	void print();
	void within(double xCoordinateCenter, double yCoordinateCnter, double radius );
	void within(double xCoordinaTetopLeft, double yCoordinateTopLeft, double width, double height);
	Figure* getFigure(int number);
	unsigned int getnumberOfFigures();
	void savInFile(std::string fileName);





};