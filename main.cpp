#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

#include "seam_carve.h"

int main(int argc, char *argv[]) {

    std::string input_filename = argv[1];
    std::cout << input_filename;

    int input_vertical_seams = atoi(argv[2]);
    std::cout << input_vertical_seams;

    int input_horizontal_seams = atoi(argv[3]);
    std::cout << input_horizontal_seams;

    Image image_to_process(input_filename, input_vertical_seams, input_horizontal_seams);

    // Coordinate example_coord = {1, 2};
    // std::cout << image_to_process[example_coord];
    // image_to_process.print_matrix();

    for(int i = 0; i < input_vertical_seams; i++) {

    Seam seam(image_to_process);

    seam.fill_energy_matrix();
    // std::cout << "\n\n\n\n\n";
    // seam.print_energy();

    seam.fill_cumulative_matrix();

    // std::cout << "\n\n\n\n\n";
    // seam.print_cumulative();

    seam.find_seam();

    image_to_process.remove_seam(seam.removed_pixels);
    }
    // std::cout << "processed matrix:\n\n\n\n\n\n";
    image_to_process.print_matrix();
    image_to_process.write_to_file();



    // std::cout << "energy at 1" << seam.energy_matrix[1] << '\n';

// Coordinate coord {6, 38};
    // std::cout << '\n' << "index 4,37: " << image_to_process[coord]<< '\n';



}