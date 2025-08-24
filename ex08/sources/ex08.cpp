#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Mat mat1({{1, 0}, {0, 1}});
        Mat mat2({{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}});
        Mat mat3({{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}});

        std::cout << mat1.trace() << std::endl;
        std::cout << mat2.trace() << std::endl;
        std::cout << mat3.trace() << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}