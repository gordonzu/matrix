//


#include "matrix.h"

int main(int argc, char** argv) {   
    xy::Matrix m(10, 12);
    std::cout << xy::vector_size() << std::endl;

    XYLocation xy = XYLocation(9, 9);
    if (xy::has_xy(xy))
        std::cout << "Found!" << std::endl;
}






