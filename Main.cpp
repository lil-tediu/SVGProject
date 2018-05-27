#include<iostream>
#include "Circle.h"
#include "Square.h"
#include "Figure.h"
#include "Application.h"
#include "Line.h"
#include <string>
#include <fstream>


void Commands(std::string& commands, std::string& name, Application& application)
{
	if (commands == "exit")
	{
		std::cout << "Exit" << std::endl;
	}
	else if(commands=="print")
	{
		application.print();
	}
	else if (commands == "translate")
	{
		std::string horizontalstring;
		std::string verticalstring;
		std::cin >> horizontalstring;
		std::cin >> verticalstring;

		double horizontal = std::stod(horizontalstring.substr(11, 5));
		double vertical = std::stod(verticalstring.substr(9, 5));

		application.translate(horizontal, vertical);
		std::cout << "Translated all figures" << std::endl;
	}
	else if (commands == "translate_figure")
	{
		unsigned int numberToTranslate;
		std::cin >> numberToTranslate;
		if (numberToTranslate >= application.getnumberOfFigures())
		{
			std::cout << "There is no figure number: " << numberToTranslate << std::endl;
		}
		else
		{
			std::string horizontalstring;
			std::string verticalstring;
			std::cin >> horizontalstring;
			std::cin >> verticalstring;

			double horizontal = std::stod(horizontalstring.substr(11, 5));
			double vertical = std::stod(verticalstring.substr(9, 5));

			application.translate(numberToTranslate,horizontal, vertical);
			std::cout << "Translated figure number: " << numberToTranslate<< std::endl;
		}
	}
	else if (commands == "erase")
	{
		size_t numberToDelete;
		std::cin >> numberToDelete;
		if (numberToDelete < application.getnumberOfFigures())
		{
			application.erase(numberToDelete);
			std::cout << "Erased figure number: " << numberToDelete << std::endl;
		}
		else
		{
			std::cout << "There is no figure number: " << numberToDelete << std::endl;
		}
	}
	else if (commands == "within")
	{
		std::string withinFigure;
		std::cin >> withinFigure;
		if (withinFigure == "rectangle")
		{
			double x, y, width, height;
			std::cin>>x>>y>>width>>height;
			application.within(x, y, width, height);
		}
		else if (withinFigure == "circle")
		{
			double x, y, radius;
			std::cin >> x >> y >> radius;
			application.within(x, y, radius);
		}
	}
	else if (commands == "create")
	{
		std::string type, fill;
		std::cin >> type;
		if (type == "rectangle")
		{
			double x, y, width, height;
			std::cin >> x >> y >> width >> height >> fill;
			application.create("Square", x, y, 0, width, height, fill);
			std::cout << "Successfully created rectangle (" << application.getnumberOfFigures()-1 << ")" << std::endl;
		}
		else if (type == "circle")
		{
			double x, y, radius;
			std::cin >> x >> y >> radius >> fill;
			application.create("Circle", x, y, radius, 0, 0, fill);
			std::cout << "Successfully created circle (" << application.getnumberOfFigures()-1 << ")" << std::endl;
		}
		else if (type == "line")
		{
			double x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2 >> fill;
			application.create("Line", x1, y1, 0, x2, y2, fill);
			std::cout << "Successfully created line (" << application.getnumberOfFigures()-1 << ")" << std::endl;
		}
	}
	else if (commands == "save_as")
	{
		std::string nameToSaveAs;
		std::cin >> nameToSaveAs;
		std::ofstream myFile;
		myFile.open(nameToSaveAs, std::ios::app);
		myFile << "<?xml version = \"1.0\" standalone =\"no\" ?>" << std::endl;
		myFile << "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl;
		myFile << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl;
		myFile << "<svg>" << std::endl;
		application.savInFile(nameToSaveAs);
		myFile << "</svg>" << std::endl;
		myFile.close();
	}
	else if (commands == "save")
	{
		std::ofstream myFile;
		myFile.open(name, std::ios::trunc);
		myFile.clear();
		myFile << "<?xml version = \"1.0\" standalone =\"no\" ?>" << std::endl;
		myFile << "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"" << std::endl;
		myFile << "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << std::endl;
		myFile << "<svg>" << std::endl;
		application.savInFile(name);
		//myFile << "</svg>" << std::endl;
		myFile.close();
		myFile.open(name, std::ios::app);
		myFile << "</svg>" << std::endl;
	}
	else
	{
		std::cout << "Invalid command, try again" << std::endl;
	}
}

int main ()
{
	Application application;
	std::string command, name;
	std::string line;
	std::cin >> command >> name;
	if (command == "open")
	{
		std::ifstream myfile (name);
		if (myfile.is_open())
		{
			std::cout << "Successfully opened " << name << std::endl;
			while (getline(myfile, line))
			{
				if(line.find("<rect") == 2)
				{
					double x = std::stod(line.substr(line.find("x=") + 3));
					double y = std::stod(line.substr(line.find("y=") + 3));
					double width = std::stod(line.substr(line.find("width=") + 7));
					double height = std::stod(line.substr(line.find("height=") + 8));
					std::string fill = line.substr(line.find("fill=") + 6, (line.find("/")-2)- (line.find("fill=")+6));
					application.create("Square", x, y, 0, width, height, fill);
				}
				else if (line.find("<circle") == 2)
				{
					double cx = std::stod(line.substr(line.find("x=") + 3));
					double cy = std::stod(line.substr(line.find("y=") + 3));
					double r =  std::stod(line.substr(line.find("r=") + 3));
					std::string fill = line.substr(line.find("fill=") + 6, 5);
					application.create("Circle", cx, cy, r, 0, 0, fill);
				}
				else if (line.find("<line") == 2)
				{
					double x1 = std::stod(line.substr(line.find("x1=") + 4));
					double y1 = std::stod(line.substr(line.find("y1=") + 4));
					double x2 = std::stod(line.substr(line.find("x2=") + 4));
					double y2 = std::stod(line.substr(line.find("y2=") + 4));
					std::string fill = line.substr(line.find("fill=") + 6, 5);
					application.create("Line", x1, y1, 0, x2, y2, fill);
				}
			}
		}
		/*std::cout << application.getnumberOfFigures() << std::endl;
		application.print();*/
		myfile.close();
		
	}
	//std::cout << "---" << std::endl;
	std::string commands;
	while (commands != "exit")
	{
		std::cin >> commands;
		Commands(commands, name , application);
	}
	return 0;
}