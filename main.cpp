#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

#include "image.h"

int main() {
    std::cout << "hello world\n";

    Image bug_image("bug.pgm");

    // Coordinate example_coord = {1, 2};
    // std::cout << bug_image[example_coord];
    bug_image.print_matrix();

Coordinate coord {6, 38};
    std::cout << '\n' << "index 4,37: " << bug_image[coord]<< '\n';



}