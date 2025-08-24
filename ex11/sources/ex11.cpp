#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {

        Mat mat({   { 8., 5., -2., 4.},
                    { 4., 2.5, 20., 4.},
                    { 8., 5., 1., 4.},
                    {28., -4., 17., 1.},
                });
        
        std::cout << mat << "\n" << std::endl;
        std::cout << mat.determinant() << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}