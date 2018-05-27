#include "Figure.h"

// Figure* Figure::getNext()
//{
//
//	return next;
//}
//
//void Figure::setNext(Figure& other)
//{
//	next = other.getNext();
//}

bool Figure::isInsideRectangle(double xTopLeft, double yTopLeft, double width, double height)
{
	return false;
}

 bool Figure::isInsideCircle(double xCenter, double yCenter, double radius)
{
	return false;
}

 double Figure::getTopLeftXCoordinate()
 {
	 return topLeftxCoordinate;
 }

 double Figure::getTopLeftYCoordinate()
 {
	 return topLeftyCoordinate;
 }

 void Figure::translate(double horizontal, double vertical)
 {
	 topLeftxCoordinate = topLeftxCoordinate + horizontal;
	 topLeftyCoordinate = topLeftyCoordinate + vertical;
 }
