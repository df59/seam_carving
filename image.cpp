#include <vector>
#include <string.h>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "image.h"

Image::Image(const std::string filename) {
    std::ifstream input_file(filename);

    // get P2 header
    getline(input_file, header, '\n');
    std::cout << "header " << header << '\n';

    // get comment header
    getline(input_file, comment, '\n');
    std::cout << "comment " << comment << '\n';

    // get width
    while(input_file.peek() != ' ') {
    input_file >> temp_line;
    }
    width = std::stoi(temp_line);
    std::cout << "width: " << width << '\n';
    temp_line.clear();

    // get length
    while(input_file.peek() != '\n') {
    input_file >> temp_line;
    }
    length = std::stoi(temp_line);
    std::cout << "length: " << length << '\n';
    temp_line.clear();

    // get max pixel value
    input_file.ignore();
    while(input_file.peek() != '\n') {
    input_file >> temp_line;
    }
    max_val = std::stoi(temp_line);
    std::cout << "max_val: " << max_val << '\n';
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
        std::cout << "index " << i << " " << pixels[i] << '\n';
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
