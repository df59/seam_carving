#include "seam_carve.h"
#include <math.h>
#include <iostream>

Seam::Seam(Image input)
    : input_image(input)
{
    // energy_matrix.resize(input_image.Size());
    cumulative_matrix.resize(input_image.Size());

}

int Seam::energy_length() {

}

int Seam::energy_width() {

}

int Seam::cumulative_length() {

}

int Seam::cumulative_width() {

}

void Seam::print_energy() {
    for(int i = 0; i < input_image.Length(); i++) {
        for(int j = 0; j < input_image.Width(); j++) {
            int index =((input_image.Width() * i) + j);
            std::cout << energy_matrix[index] << ' ';
        }
        std::cout << '\n';
    }
}


void Seam::print_cumulative() {

}

int Seam::energy_coordinate(int x, int y) {
    return energy_matrix[(input_image.Width() * y) + x];

}

int Seam::cumulative_coordinate(int x, int y) {
    return cumulative_matrix[(input_image.Width() * y) + x];

}


void Seam::fill_energy_matrix() {
    for(int i = 0; i < input_image.Length(); i++) {
        for(int j = 0; j < input_image.Width(); j++) {
            Coordinate here {j, i};
            Coordinate above {j, i-1};
            Coordinate below {j, i+1};
            Coordinate left {j-1, i};
            Coordinate right {j+1, i};
            if(i == 0) {
                above = here;
            }
            if(i == input_image.Length()-1) {
                below = here;
            }
            if(j == 0) {
                left = here;
            }
            if(j == input_image.Width()-1) {
                right = here;
            }
            // energy_matrix.push_back(input_image[below]);
            energy_matrix.push_back(
            abs(input_image[above] - input_image[here]) +
            abs(input_image[below] - input_image[here]) +
            abs(input_image[right] - input_image[here]) +
            abs(input_image[left] - input_image[here]));
            // std::cout << "energy matrix at " << j << "," << i << ' ' << energy_matrix[energy_coordinate(j, i)] << '\n';
        }
    }
}