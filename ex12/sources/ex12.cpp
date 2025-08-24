#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {

        Mat mat({   {2, 0},
                    {2, 0}
                });
        
        std::cout << mat << "\n" << std::endl;
        std::cout << mat.inverse() << std::endl;
        std::cout << mat.inverse().mul_mat(mat) << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}