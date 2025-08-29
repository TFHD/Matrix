#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

Matrix<float> projection(float fov, float ratio, float near, float far) {

    float scale = 1.0 / tan(fov / 2.0);
    
    return (Matrix<float>(
        {
            {scale / ratio, .0, .0, .0},
            {.0, scale, .0, .0},
            {.0, .0, (far + near) / (near - far), -1.},
            {.0, .0, (2.0f * far * near) / (near - far), .0}
        }
    ));
}


int main(void) {

    try {

        float fov = 90.0;
        float ratio = 1080.0 / 1080.0;
        float near = 1.0;
        float far = 100.0;

        projection(fov, ratio, near, far).printMat();
        
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}