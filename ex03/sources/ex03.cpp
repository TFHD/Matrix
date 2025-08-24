#include "Matrix.hpp"
#include "Vector.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Vec vec1({-1, 6});
        Vec vec2({3, 2});
        std::cout << vec1.dot(vec2) << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}