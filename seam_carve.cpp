#include "seam_carve.h"
#include <algorithm>
#include <math.h>
#include <iostream>

Seam::Seam(Image input)
    : input_image(input)
{
    // energy_matrix.resize(input_image.Size());
    // cumulative_matrix.resize(input_image.Size());

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
    for(int i = 0; i < input_image.Length(); i++) {
        for(int j = 0; j < input_image.Width(); j++) {
            int index =((input_image.Width() * i) + j);
            std::cout << cumulative_matrix[index] << ' ';
        }
        std::cout << '\n';
    }
}

int Seam::energy_coordinate(Coordinate coord) {
    return energy_matrix[(input_image.Width() * coord.y) + coord.x];

}

int Seam::cumulative_coordinate(Coordinate coord) {
    return cumulative_matrix[(input_image.Width() * coord.y) + coord.x];

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

void Seam::fill_cumulative_matrix() {
    for(int i = 0; i < input_image.Length(); i++) {
        for(int j = 0; j < input_image.Width(); j++) {
            int cumulative_here;
            Coordinate here {j, i};
            Coordinate above_left {j-1, i-1};
            Coordinate above_right {j+1, i-1};
            Coordinate above_middle {j, i-1};

            // left column
            if(j == 0) {
                above_left = above_middle;
            }
            // right column
            if(j == input_image.Width()-1) {
                above_right = above_middle;
            }
            // top row
            if(i == 0) {
                cumulative_here = energy_coordinate(here);
                // std::cout << "setting cumulative_here to " << energy_matrix[energy_coordinate(here)] <<'\n';
            } else {

            cumulative_here = std::min(
                cumulative_coordinate(above_left),
                std::min(cumulative_coordinate(above_middle),
                cumulative_coordinate(above_right))) +
                energy_coordinate(here);
            }

            cumulative_matrix.push_back(cumulative_here);
            std::cout << "success at " << j << ',' << i << "with value" << cumulative_here <<'\n';
        }
    }
}
