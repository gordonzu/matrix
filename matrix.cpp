// matrix.cpp

#include "matrix.h"

namespace xy {

    Vector Matrix::vec = Vector();

    Matrix::Matrix(unsigned w, unsigned h) {
        for (unsigned x = 1; x <= w; ++x) {
            for (unsigned y = 1; y <= h; ++y) {
                vec.emplace_back(XYLocation(x, y), std::set<Object*>());
            }
        }
    }

    Matrix::~Matrix() = default;

    std::vector<std::pair<XYLocation, std::set<Object*>>>& Matrix::get_vector() {
        return vec;
    }

    Vector::iterator Matrix::has_xy(XYLocation& loc) {
        it = std::find_if(
            Matrix::get_vector().begin(), 
            Matrix::get_vector().end(), 
            [loc](std::pair<XYLocation, std::set<Object*>>& mypair) {
                return (mypair.first == loc);
        });
        return it;
    }

    std::set<Object*>* Matrix::get_set(XYLocation& xy) {
        if (has_xy(xy) != get_vector().end()) {
            return &(*it).second;
        }
        else {
            return nullptr;
        }
    }


    //bool has_object(Object* obj) {
/*        auto it = Matrix::get_set().find(obj);
        if (it != Matrix::get_set().end())
            return true;
*/
      //  return false;
    //}

    unsigned vector_size() {
        return Matrix::get_vector().size();
    }

}












