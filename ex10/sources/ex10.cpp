#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {

        Mat mat({
                {1, 3, 2, 1},
                {2, 6, 5, 4},
                {1, 3, 1, 0}
            });
        std::cout << mat.toRowEchelonForm() << "\n" << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}