#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {

        Mat mat({   {1, 2, 0, 0},
                    {2, 4, 0, 0},
                    {-1, 2, 1, 1}
                });
        
        std::cout << mat.toRowEchelonForm() << "\n" << std::endl;
        std::cout << mat.rank() << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}