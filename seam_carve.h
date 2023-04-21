#include "image.h"
#include <vector>

class Seam {

    public:
    Seam(Image input_image);
    void fill_energy_matrix();
    void fill_cumulative_matrix();
    void find_seam();
    int energy_coordinate(Coordinate coord);
    int cumulative_coordinate(Coordinate coord);
    void print_energy();
    void print_cumulative();

    std::vector<Coordinate> removed_pixels;

    private:
    Image input_image;
    std::vector<int> energy_matrix;
    std::vector<int> cumulative_matrix;


};