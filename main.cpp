#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

#include "seam_carve.h"

int main() {
    std::cout << "hello world\n";

    Image bug_image("testimage.pgm");

    // Coordinate example_coord = {1, 2};
    // std::cout << bug_image[example_coord];
    bug_image.print_matrix();

    Seam seam(bug_image);

    seam.fill_energy_matrix();
    std::cout << "\n\n\n\n\n";
    seam.print_energy();

    seam.fill_cumulative_matrix();

    std::cout << "\n\n\n\n\n";
    seam.print_cumulative();



    // std::cout << "energy at 1" << seam.energy_matrix[1] << '\n';

// Coordinate coord {6, 38};
    // std::cout << '\n' << "index 4,37: " << bug_image[coord]<< '\n';



}