// matrix.cpp
//

#include "matrix.h"


namespace xy {

///////////////////////////////////////////////////////////////////////////////

    Vector Matrix::vec = Vector();

    Matrix::Matrix(unsigned w, unsigned h) {
        for (unsigned x = 1; x <= w; ++x) {
            for (unsigned y = 1; y <= h; ++y) {
                xy = std::make_unique<XYLocation>(x, y);
                setobj = std::make_unique<std::set<Object*>>();
                vec.push_back(std::make_pair(*xy, *setobj));
            }
        }
    }

    Matrix::~Matrix() {

    }


   /* bool Matrix::has_xy(XYLocation& loc) {
        it = std::find_if(
            vec.begin(), 
            vec.end(), 
            [loc](std::pair<XYLocation, std::set<Object*>>& mypair) {
                return (mypair.first == loc);
        });

        if (it != vec.end()) {
            return true;
        } 
        return false;
    }
    */

    std::set<Object*>& Matrix::get_set(XYLocation& xy) {
        ;;
    }

    std::vector<std::pair<XYLocation, std::set<Object*>>>& Matrix::get_vector() {
        return vec;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////

    bool has_xy(XYLocation& loc) {
        auto it = std::find_if(
            Matrix::get_vector().begin(), 
            Matrix::get_vector().end(), 
            [loc](std::pair<XYLocation, std::set<Object*>>& mypair) {
                return (mypair.first == loc);
        });

        if (it != Matrix::get_vector().end()) {
            return true;
        } 
        return false;
    }

    bool has_object(std::set<Object*>& theset) {
        ;;
    }

    unsigned vector_size() {
        return Matrix::get_vector().size();
    }

}












