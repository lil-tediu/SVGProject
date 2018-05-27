#include "Application.h"
#include <fstream>

Application::Application() :figures(nullptr), numberOfFigures(0)
{
	figures = new Figure*[10000000];
	
}
Application::~Application()
{
	for (int i = 0; i < numberOfFigures; i++)
	{
		delete figures[i];
	}
	delete[] figures;
}



Figure * Application::create(std::string type, double x, double y, double r, double a, double b, std::string _colour)
{
	

	if (type == "Circle")
	{
		figures[numberOfFigures] = new Circle(x, y, r, _colour);
		numberOfFigures++;
		return figures[numberOfFigures - 1];
	}

	if (type == "Square")
	{
		figures[numberOfFigures] = new Square(x, y, a, b, _colour);
		numberOfFigures++;
		return figures[numberOfFigures - 1];
	}

	if (type == "Line")
	{ 
		figures[numberOfFigures]= new Line(x, y, a, b, _colour);
		numberOfFigures++;
		return figures[numberOfFigures - 1];
	}

	return nullptr;
}

Figure** Application::erase(unsigned int number)
{

	Figure** figures1 = new Figure*[numberOfFigures];
	for (int i = 0; i < numberOfFigures; i++)
	{
		figures1[i] = figures[i];
	}

	for (int i = 0; i < number; i++)
	{
		figures[i] = figures1[i];
	}
	for (int i = number; i < numberOfFigures-1; i++)
	{
		figures[i] = figures1[i + 1];
	}
	delete[] figures1;
	numberOfFigures--;
	return figures;
}

void Application::translate(unsigned int number, double horizontal, double vertical)
{
	figures[number]->translate(horizontal, vertical);

}

void Application::translate(double horizontal, double vertical)
{
	for (int i = 0; i < numberOfFigures; i++)
	{
		figures[i]->translate(horizontal, vertical);
	}
}

void Application::print()
{
	for (int i = 0; i < numberOfFigures; i++)
	{
		figures[i]->print();
	}
}

void Application::within(double xCoordinateCenter, double yCoordinateCnter, double radius)
{
	for (int i = 0; i < numberOfFigures; i++)
	{
		if (figures[i]->isInsideCircle(xCoordinateCenter, yCoordinateCnter, radius))
		{
			figures[i]->print();
		}
	}
}

void Application::within(double xCoordinaTetopLeft, double yCoordinateTopLeft, double width, double height)
{
	for (int i = 0; i < numberOfFigures; i++)
	{
		if (figures[i]->isInsideRectangle(xCoordinaTetopLeft, yCoordinateTopLeft, width, height))
		{
			figures[i]->print();
		}
	}
}


Figure * Application::getFigure(int number)
{
	return figures[number];
}

unsigned int Application::getnumberOfFigures()
{
	return numberOfFigures;
}

void Application::savInFile(std::string fileName)
{
	for (int i = 0; i < getnumberOfFigures(); i++)
	{
		figures[i]->saveInFile(fileName);
	}
}
