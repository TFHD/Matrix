#include "Matrix.hpp"
#include "Vector.hpp"

#include <cmath>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

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
    std::cout << CYAN << BOLD << "=== Test lerp<float> ===" << RESET << std::endl;
    {
        float a = 2.0f, b = 8.0f;
        float t = 0.25f;
        float result = lerp(a, b, t);
        std::cout << GREEN << "lerp(" << a << ", " << b << ", " << t << ") = " << RESET << std::endl;
        std::cout << result << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test lerp<Vector<float>> ===" << RESET << std::endl;
    {
        Vector<float> v1({1.0f, 2.0f, 3.0f});
        Vector<float> v2({4.0f, 5.0f, 6.0f});
        float t = 0.5f;
        Vector<float> result = lerp(v1, v2, t);
        std::cout << GREEN << "lerp([1,2,3], [4,5,6], 0.5) = " << RESET << std::endl;
        std::cout << result << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test lerp<Vector<float>> erreur taille ===" << RESET << std::endl;
    {
        Vector<float> v1({1.0f, 2.0f});
        Vector<float> v2({3.0f, 4.0f, 5.0f});
        float t = 0.5f;
        Vector<float> result = lerp(v1, v2, t);
        std::cout << GREEN << "lerp([1,2], [3,4,5], 0.5) = " << RESET;
        std::cout << result << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test lerp<Matrix<float>> ===" << RESET << std::endl;
    {
        Matrix<float> m1({
            {1.0f, 2.0f},
            {3.0f, 4.0f}
        });
        Matrix<float> m2({
            {4.0f, 3.0f},
            {2.0f, 1.0f}
        });
        float t = 0.25f;
        Matrix<float> result = lerp(m1, m2, t);
        std::cout << GREEN << "lerp([[1,2],[3,4]], [[4,3],[2,1]], 0.25) = " << RESET << std::endl;
        std::cout << result << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test lerp<Matrix<float>> erreur taille ===" << RESET << std::endl;
    {
        Matrix<float> m1({
            {1.0f, 2.0f}
        });
        Matrix<float> m2({
            {4.0f, 3.0f},
            {2.0f, 1.0f}
        });
        float t = 0.5f;
        Matrix<float> result = lerp(m1, m2, t);
        std::cout << GREEN << "lerp([[1,2]], [[4,3],[2,1]], 0.5) = " << RESET << std::endl;
        std::cout << result << std::endl;
    }

    return 0;
}