#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>

#include "seam_carve.h"

int main(int argc, char *argv[]) {

    std::string input_filename = argv[1];
    int input_vertical_seams = atoi(argv[2]);
    int input_horizontal_seams = atoi(argv[3]);
    Image image_to_process(input_filename, input_vertical_seams, input_horizontal_seams);

    for(int i = 0; i < input_vertical_seams; i++) {
        Seam seam(image_to_process);
        seam.fill_energy_matrix();
        seam.fill_cumulative_matrix();
        seam.find_seam();
        image_to_process.remove_seam(seam.removed_pixels);
    }

    image_to_process.transpose();

    for(int i = 0; i < input_horizontal_seams; i++) {
        Seam seam(image_to_process);
        seam.fill_energy_matrix();
        seam.fill_cumulative_matrix();
        seam.find_seam();
        image_to_process.remove_seam(seam.removed_pixels);
    }

    image_to_process.transpose();
    image_to_process.write_to_file();

}