#include <vector>
#include <string>

struct Coordinate {
  int x;
  int y;
};

class Image {
    public:

    Image(const std::string filename);
    int Width() const;
    int Length() const;
    int MaxVal() const;
    void print_matrix();
    int Size() const;

    int operator[](Coordinate &coordinate);

    private:

    int length;
    int width;
    int max_val;
    std::string header;
    std::string comment;
    std::vector<int> pixels;
    std::string temp_line;

};