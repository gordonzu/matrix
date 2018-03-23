#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "object.h"
#include "agent.h"
#include "xy_location.h"

using Vector = std::vector<std::pair<XYLocation, std::set<Object*>>>;

namespace xy {

    class Matrix {
    private:
        static Vector       vec;
        Vector::iterator    it;

    public:
        Matrix(unsigned w, unsigned h);
        virtual ~Matrix(); 
        std::set<Object*>* get_set(XYLocation& loc);
        static Vector& get_vector();
        Vector::iterator has_xy(XYLocation& loc);
        bool add_object(Object* obj, XYLocation& xy);
    };

/////////// namespace functions /////////////////
    size_t vector_size();
    //size_t set_size(XYLocation& xy);
}

#endif

