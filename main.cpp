//


#include "matrix.h"

int main(int argc, char** argv) {   
    xy::Matrix m(10, 12);
    std::cout << xy::vector_size() << std::endl;

    XYLocation xy = XYLocation(9, 9);
    XYLocation loc = XYLocation(15, 10);


    // test has_xy
    if (m.has_xy(xy) != m.get_vector().end())
        std::cout << "Found!" << std::endl;
    if (m.has_xy(loc) == m.get_vector().end())
        std::cout << "Not Found!" << std::endl;

    // test get_set
    if (m.get_set(xy))
        std::cout << "Set Found!" << std::endl;
    if (!m.get_set(loc))
        std::cout << "Set Not Found!" << std::endl;
}






