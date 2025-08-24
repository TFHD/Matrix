#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Vec vec1({4., 2., -3.});
        Vec vec2({-2., -5., 16.});

        std::cout << Math::cross_product(vec1, vec2) << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}