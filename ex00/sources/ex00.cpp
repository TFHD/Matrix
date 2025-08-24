#include "Matrix.hpp"
#include "Vector.hpp"

int main(void) {

    try {
        Vector<float> u({2, 3});
        Vector<float> v({5, 7});

        u.add(v);
        u.printVec();
        std::cout << "============" << std::endl;

        Vector<float> u1({2, 3});
        Vector<float> v1({5, 7});

        u1.sub(v1);
        u1.printVec();
        std::cout << "============" << std::endl;

        Vector<float> u2({2, 3.34});

        u2.scl(2.);
        u2.printVec();
        std::cout << "============" << std::endl;

        Matrix<float> mat({{1, 2},
                        {3, 4}});
                            
        Matrix<float> mat1({{7, 4},
                            {-2, 2}});

        mat.add(mat1);
        mat.printMat();

        std::cout << "============" << std::endl;

        Matrix<float> mat2({{1, 2},
                        {3, 4}});
                            
        Matrix<float> mat3({{7, 4},
                            {-2, 2}});
        
        mat2.sub(mat3);
        mat2.printMat();

        std::cout << "============" << std::endl;

        Matrix<float> mat4({{100}, {3}});

        mat4.scl(2.0f);
        mat4.printMat();
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}