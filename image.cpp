#include <stdexcept>
#include <string>
#include <vector>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "image.h"

Image::Image(const std::string input_filename, const int input_vertical_seams, const int input_horizontal_seams) {
    filename = input_filename;
    num_horizontal_seams = input_horizontal_seams;
    num_vertical_seams = input_vertical_seams;
    std::ifstream input_file(filename);


    // get P2 header
    getline(input_file, header, '\n');

    // get comment header
    getline(input_file, comment, '\n');

    // get width
    while(input_file.peek() != ' ') {
    input_file >> temp_line;
    }
    width = std::stoi(temp_line);
    temp_line.clear();

    // get length
    while(input_file.peek() != '\n') {
    input_file >> temp_line;
    }
    length = std::stoi(temp_line);
    temp_line.clear();

    // get max pixel value
    input_file.ignore();
    while(input_file.peek() != '\n') {
    input_file >> temp_line;
    }
    max_val = std::stoi(temp_line);
    temp_line.clear();

    // get pixel values
    for(int i = 0; i < (length*width); i++) {
        assert(temp_line.empty());
        while(input_file.peek() == ' ' || input_file.peek() == '\n') {
            input_file.ignore();
        }
        while(input_file.peek() != ' ' && input_file.peek() != '\n'){
            input_file >> temp_line;
        }
        assert(!temp_line.empty());
        pixels.push_back(std::stoi(temp_line));
        temp_line.clear();
        assert(pixels[i] <= max_val);
    }

}

int Image::Width() const {
    return width;
}

int Image::Length() const {
    return length;
}

int Image::MaxVal() const {
    return max_val;
}
int Image::Size() const {
    return pixels.size();
}


int Image::operator[](Coordinate &coordinate) {
    return pixels[(width * coordinate.y) + coordinate.x];
}

void Image::print_matrix() {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < width; j++) {
            int index =((width * i) + j);
            std::cout << pixels[index] << ' ';
        }
        std::cout << '\n';
    }
}

void Image::remove_seam(std::vector<Coordinate> removed_pixels) {
    for(int i = 0; i < length-1; i++) {
        assert(removed_pixels[i].y > removed_pixels[i+1].y);
    }

    for(auto i : removed_pixels) {
        pixels[(width * i.y) + i.x] = max_val + 100;
    }

    for(int i = 0; i < pixels.size(); i++) {
        if(pixels[i] > max_val) {
            pixels.erase(pixels.begin() + i);
        }
    }

    width = width-1;
}

void Image::write_to_file() {
    std::string output_filename = filename;
    int dot = output_filename.find(".pgm");
    output_filename.resize(dot);
    output_filename = output_filename + "_" + "processed_" + std::to_string(num_vertical_seams) +
    "_" + std::to_string(num_horizontal_seams) + ".pgm";


    std::ofstream output_file;

    output_file.open(output_filename);

    output_file << header << '\n' << comment << '\n';
    output_file << width << ' ' << length << '\n';
    output_file << max_val << '\n';

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < width; j++) {
            output_file << pixels[((width * i) + j)] << ' ';
        }
        output_file << '\n';
    }
}

void Image::transpose() {
    // reverse width and length
    int prev_width = width;
    int prev_length = length;
    int new_width = prev_length;
    int new_length = prev_width;
    std::vector<int> new_pixels;
    new_pixels.resize(pixels.size());

    for(int i = 0; i < new_length; i++) {
        for(int j = 0; j < new_width; j++) {
            new_pixels[(new_width * i) + j] = pixels[(prev_width * j) + i];
        }
    }
    pixels.clear();
    pixels = new_pixels;

    width = new_width;
    length = new_length;
}

