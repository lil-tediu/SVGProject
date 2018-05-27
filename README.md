# SVGProject
C++ project working with svg files. The application works with only square, circle and line figures. 
Functionality:
print - prints information for all figures that are in the file
create - creates new figure
erase - deletes a figure
translate - translates one figure or all figures by given vertical and horizontal values
within - prints all figures which are in given area. The area can be either square or circle
open - open existing svg file
save as - saves file with name chosen by the user
save - saves the changes in the current file

Example of the application:

 open figures.svg
Successfully opened figures.svg

 print
1. rectangle are5 5 10 10 green
2. circle 5 5 10 blue
3. rectangle 100  60 10 10 red

 create rectangle -1000 -1000 10 20 yellow
Successfully created rectangle (4)

 print
1. rectangle 1 1 10 20 green
2. circle 5 5 10 blue
3. rectangle 100 60 10 10 red
4. rectangle 1000 1000 10 20 yellow

 within rectangle 0 0 30 30
1. rectangle 5 5 10 10 green
2. circle 5 5 10 blue

 within circle 0 0 5
No figures are located within circle 0 0 5

 erase 2
Erased a circle (2)

 erase 100
There is no figure number 100!

 print
1. rectangle 5 5 10 10 green
2. rectangle 100 60 10 10 red
3. rectangle 1000 1000 10 20 yellow

 translate vertical=10 horizontal=100
Translated all figures

 print
1. rectangle 105 15 10 10 green
2. rectangle 200 70 10 10 red
3. rectangle 1100 1010 10 20 yellow

 save
Successfully saved the changes to figures.svg

 exit
Exit


