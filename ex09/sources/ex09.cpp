#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Mat mat1({{1, 0}, {0, 1}});
        Mat mat2({{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}});
        Mat mat3({{-2, -8}, {1, -23}, {0, 6}});

        std::cout << mat1.transpose() << "\n" << std::endl;
        std::cout << mat2.transpose() << "\n" << std::endl;
        std::cout << mat3.transpose() << "\n" << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}