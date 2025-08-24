#include "Matrix.hpp"
#include "Vector.hpp"

#include <cmath>

int getMin(float x, float y) {
    return (x < y) ? x : y;
}

template<typename V>
int myAbs(V x, V y) {
    x = (x < 0) ? -x : x;
    y = (y < 0) ? -y : y;

    if (x > y)  return x - y;
    else        return y - x;
}

template<typename V>
V lerp(const V u, V v, float t) {
    if constexpr (std::is_same<V, float>::value) {
        return (std::fma(
            myAbs(u, v),
            t,
            getMin(u, v)
        ));
    }
    else if constexpr (std::is_same<V, Vector<float>>::value) {
        if (!u.isSameLength(v)) {
            std::cout << "\e[31m[lerp] Error, vectors size are not de same !\e[0m" << std::endl;
            return Vector<float>();
        }
        Vector<float> res;
        for (int i = 0; i < u.getSize(); i++)
            res.append(
                std::fma(myAbs(u[i], v[i]),
                t,
                getMin(u[i], v[i])
            ));
        return res;

    }
    else if constexpr (std::is_same<V, Matrix<float>>::value) {
        if (!u.isSameLength(v)) {
            std::cout << "\e[31m[lerp] Error, matrices size are not de same !\e[0m" << std::endl;
            return Matrix<float>();
        }
        std::vector<std::vector<float>> mat;
        for (int i = 0; i < u.getSizeX(); i++) {
            std::vector<float> subMat;
            for (int j = 0; j < u.getSizeY(); j++) {
                subMat.push_back(
                    std::fma(myAbs(u.getMat()[i][j], v.getMat()[i][j]),
                    t,
                    getMin(u.getMat()[i][j], v.getMat()[i][j])
                ));
            }
            mat.push_back(subMat);
        }
        return mat;
    }
    std::cout << "\e[31m[lerp] Unsupported type\e[0m" << std::endl;
    return V{};
}

int main(void) {

    try {
        Vector<float> vec1({2., 1.});
        Vector<float> vec2({4., 2.});
        Matrix<float> mat1({{2, 1}, {3, 4}});
        Matrix<float> mat2({{20, 10}, {30, 40}});

        std::cout << lerp<float>(21, 42, 0.3) << std::endl;
        std::cout << lerp<Vector<float>>(vec1, vec2, 0.3) << std::endl;
        std::cout << lerp<Matrix<float>>(mat2, mat1, 0.5) << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}