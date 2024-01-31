Image Seam Carver

Dustin Franklin

df59@uakron.edu

This program takes in a black and white .pgm image and removes a user specified number
of vertical and horizontal seams, making the resulting image smaller in the least 
humanly detectable way possible.

To compile run:

mkdir build

cd build

cmake ..

make

To run:

./seam_carve (image file and directory) (number of vertical seams) (number of horizontal seams)
