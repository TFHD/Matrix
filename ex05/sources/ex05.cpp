#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Vec vec1({1, 2, 3});
        Vec vec2({4, 5, 6});

        std::cout << Math::angle_cos(vec1, vec2) << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}