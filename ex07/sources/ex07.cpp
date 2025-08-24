#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Vec vec1({4., 2., -3.});
        Vec vec2({-2., -5., 16.});
        Vec vec3({4., 2.});

        Mat mat1({{3, -5}, {6, 8}, {1, 10}});
        Mat mat2({{2, 1, 3}, {4, 2, 5}});
        Mat mat3({{2, -2}, {-2, 2}});

        std::cout << Math::cross_product(vec1, vec2) << std::endl << std::endl;
        std::cout << mat1.mul_mat(mat2) << std::endl << std::endl;
        std::cout << mat3.mul_vec(vec3) << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}