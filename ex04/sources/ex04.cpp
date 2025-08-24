#include "Matrix.hpp"
#include "Vector.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

int main(void) {

    try {
        Vec vec1({0, 0, 0});
        Vec vec2({1, 2, 3});
        Vec vec3({-2, -1});

        std::cout << vec1.norm_1() << " " << vec1.norm() << " " << vec1.norm_inf() << std::endl;
        std::cout << vec2.norm_1() << " " << vec2.norm() << " " << vec2.norm_inf() << std::endl;
        std::cout << vec3.norm_1() << " " << vec3.norm() << " " << vec3.norm_inf() << std::endl;
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}