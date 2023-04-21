#include <vector>
#include <string>

struct Coordinate {
  int x;
  int y;
};

class Image {
    public:

    Image(const std::string input_filename, const int num_vertical_seams, const int num_horizontal_seams);
    std::string filename;
    int Width() const;
    int Length() const;
    int MaxVal() const;
    void print_matrix();
    int Size() const;
    void remove_seam(std::vector<Coordinate> removed_pixels);
    void write_to_file();
    void transpose();

    int operator[](Coordinate &coordinate);

    private:

    int length;
    int width;
    int max_val;
    int num_vertical_seams;
    int num_horizontal_seams;
    std::string header;
    std::string comment;
    std::vector<int> pixels;
    std::string temp_line;

};