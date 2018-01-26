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
        static Vector                       vec;
        Vector::iterator                    it;
        std::unique_ptr<XYLocation>         xy;
        std::unique_ptr<std::set<Object*>>  setobj;

    public:
        Matrix(unsigned w, unsigned h);
        virtual ~Matrix(); 
        std::set<Object*>& get_set(XYLocation& loc);
        static Vector& get_vector(); 
    };

unsigned vector_size();

bool has_xy(XYLocation& loc);

bool has_object(std::set<Object*>& theset);

}

#endif

