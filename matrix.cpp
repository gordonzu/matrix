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

    bool Matrix::add_object(Object* obj, XYLocation& xy) {
        std::set<Object*>::iterator myit;
        std::set<Object*>* theset = get_set(xy);

        if (theset) {
            if ((myit = theset->find(obj)) != theset->end()) {
                theset->erase(myit);
            }
            theset->insert(obj);
            return true;
        }
        else
            return false;
    }
    /***************************************************************/

    size_t vector_size() {
        return Matrix::get_vector().size();
    }

   /* size_t set_size(XYLocation& xy) {
        if (Matrix::get_set(xy)) {
            return Matrix::get_set(xy)->size();
        }
        else
            return 0;
    }
    */
}












