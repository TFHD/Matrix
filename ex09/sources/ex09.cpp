#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main() {
    std::cout << CYAN << BOLD << "=== Test transpose: Matrice carrée 3x3 ===" << RESET << std::endl;
    Matrix<float> m1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
    std::cout << "M = \n" << m1 << std::endl;
    Matrix<float> t1 = m1.transpose();
    std::cout << GREEN << "Transpose(M) = \n" << RESET << t1 << std::endl;

    std::cout << CYAN << BOLD << "=== Test transpose: Matrice rectangulaire 2x3 ===" << RESET << std::endl;
    Matrix<float> m2({
        {10, 20, 30},
        {40, 50, 60}
    });
    std::cout << "M = \n" << m2 << std::endl;
    Matrix<float> t2 = m2.transpose();
    std::cout << GREEN << "Transpose(M) = \n" << RESET << t2 << std::endl;

    std::cout << CYAN << BOLD << "=== Test transpose: Matrice rectangulaire 3x2 ===" << RESET << std::endl;
    Matrix<float> m3({
        {7, 8},
        {9, 10},
        {11, 12}
    });
    std::cout << "M = \n" << m3 << std::endl;
    Matrix<float> t3 = m3.transpose();
    std::cout << GREEN << "Transpose(M) = \n" << RESET << t3 << std::endl;
    // attendu :
    // [7, 9, 11]
    // [8, 10, 12]

    std::cout << CYAN << BOLD << "=== Test transpose: Matrice ligne 1x4 ===" << RESET << std::endl;
    Matrix<float> m4({
        {5, 6, 7, 8}
    });
    std::cout << "M = \n" << m4 << std::endl;
    Matrix<float> t4 = m4.transpose();
    std::cout << GREEN << "Transpose(M) = \n" << RESET << t4 << std::endl;

    std::cout << CYAN << BOLD << "=== Test transpose: Matrice colonne 4x1 ===" << RESET << std::endl;
    Matrix<float> m5({
        {11},
        {12},
        {13},
        {14}
    });
    std::cout << "M = \n" << m5 << std::endl;
    Matrix<float> t5 = m5.transpose();
    std::cout << GREEN << "Transpose(M) = \n" << RESET << t5 << std::endl;

    std::cout << CYAN << BOLD << "=== Test transpose: Matrice vide ===" << RESET << std::endl;
    Matrix<float> m6({});
    std::cout << "M = " << m6 << std::endl;
    Matrix<float> t6 = m6.transpose();
    std::cout << GREEN << "Transpose(M) = \n" << RESET << t6 << std::endl;

    return 0;
}