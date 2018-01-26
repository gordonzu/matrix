//

#include <memory>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "object.h"
#include "agent.h"
#include "xy_location.h"

namespace env {
    class Matrix {
    private:
        std::unique_ptr<XYLocation>                             xy;
        std::unique_ptr<std::set<Object*>>                      setobj;
        std::vector<std::pair<XYLocation, std::set<Object*>>>   vec;
        std::vector<std::pair<XYLocation, std::set<Object*>>>::iterator it;

    public:
        Matrix(unsigned w, unsigned h) {
            for (unsigned x = 1; x <= w; ++x) {
                for (unsigned y = 1; y <= h; ++y) {
                    xy = std::make_unique<XYLocation>(x, y);
                    setobj = std::make_unique<std::set<Object*>>();
                    vec.push_back(std::make_pair(*xy, *setobj));
                }
            }
        }

        unsigned num_rows() {
            return vec.size();
        }

        bool has_xy(XYLocation& loc) {
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
 
    };
}

int main(int argc, char** argv) {   
    env::Matrix mat(10, 12);
    std::cout << mat.num_rows() << std::endl;

    XYLocation xy = XYLocation(9, 9);
    if (mat.has_xy(xy))
        std::cout << "Found!" << std::endl;
}






