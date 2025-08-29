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
    std::cout << CYAN << BOLD << "=== Test row_echelon: Matrice déjà échelonnée ===" << RESET << std::endl;
    Matrix<float> m1({
        {1, 2, 0},
        {0, 3, 4},
        {0, 0, 5}
    });
    std::cout << "M = \n" << m1 << std::endl;
    Matrix<float> echelon1 = m1.row_echelon();
    std::cout << GREEN << "Row echelon form(M) = \n" << RESET << echelon1 << std::endl;

    std::cout << CYAN << BOLD << "=== Test row_echelon: Matrice à réduire ===" << RESET << std::endl;
    Matrix<float> m2({
        {2, 4, 2},
        {4, 8, 6},
        {6, 12, 10}
    });
    std::cout << "M = \n" << m2 << std::endl;
    Matrix<float> echelon2 = m2.row_echelon();
    std::cout << GREEN << "Row echelon form(M) = \n" << RESET << echelon2 << std::endl;

    std::cout << CYAN << BOLD << "=== Test row_echelon: Matrice rectangulaire ===" << RESET << std::endl;
    Matrix<float> m3({
        {8., 5., -2., 4., 28.},
        {4., 2.5, 20., 4., -4.},
        {8., 5., 1., 4., 17.}
    });
    std::cout << "M = \n" << m3 << std::endl;
    Matrix<float> echelon3 = m3.row_echelon();
    std::cout << GREEN << "Row echelon form(M) = \n" << RESET << echelon3 << std::endl;

    std::cout << CYAN << BOLD << "=== Test row_echelon: Matrice nulle ===" << RESET << std::endl;
    Matrix<float> m4({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    std::cout << "M = \n" << m4 << std::endl;
    Matrix<float> echelon4 = m4.row_echelon();
    std::cout << GREEN << "Row echelon form(M) = \n" << RESET << echelon4 << std::endl;

    std::cout << CYAN << BOLD << "=== Test row_echelon: Matrice identité ===" << RESET << std::endl;
    Matrix<float> m5({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    std::cout << "M = \n" << m5 << std::endl;
    Matrix<float> echelon5 = m5.row_echelon();
    std::cout << GREEN << "Row echelon form(M) = \n" << RESET << echelon5 << std::endl;

    std::cout << CYAN << BOLD << "=== Test row_echelon: Matrice vide ===" << RESET << std::endl;
    Matrix<float> m6({});
    std::cout << "M = \n" << m6 << std::endl;
    Matrix<float> echelon6 = m6.row_echelon();
    std::cout << GREEN << "Row echelon form(M) = \n" << RESET << echelon6 << std::endl;

    return 0;
}