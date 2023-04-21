#include "image.h"
#include <vector>

class Seam {

    public:
    Seam(Image input_image);
    void fill_energy_matrix();
    int energy_coordinate(int x, int y);
    int cumulative_coordinate(int x, int y);
    int energy_width();
    int energy_length();
    int cumulative_width();
    int cumulative_length();
    void print_energy();
    void print_cumulative();

    private:
    Image input_image;
    std::vector<int> energy_matrix;
    std::vector<int> cumulative_matrix;


};