#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main() {
    std::cout << CYAN << BOLD << "=== Test determinant: Matrice 2x2 ===" << RESET << std::endl;
    Matrix<float> m2x2({
        {3, 8},
        {4, 6}
    });
    std::cout << "M = \n" << m2x2 << std::endl;
    float det2x2 = m2x2.determinant();
    std::cout << GREEN << "det(M) = \n" << RESET << det2x2 << std::endl; // attendu : 3*6 - 8*4 = 18 - 32 = -14

    std::cout << CYAN << BOLD << "=== Test determinant: Matrice 3x3 ===" << RESET << std::endl;
    Matrix<float> m3x3({
        {6, 1, 1},
        {4, -2, 5},
        {2, 8, 7}
    });
    std::cout << "M = \n" << m3x3 << std::endl;
    float det3x3 = m3x3.determinant();
    std::cout << GREEN << "det(M) = \n" << RESET << det3x3 << std::endl; // attendu : -306

    std::cout << CYAN << BOLD << "=== Test determinant: Matrice 4x4 ===" << RESET << std::endl;
    Matrix<float> m4x4({
        {3, 2, 0, 1},
        {4, 0, 1, 2},
        {3, 0, 2, 1},
        {9, 2, 3, 1}
    });
    std::cout << "M = \n" << m4x4 << std::endl;
    float det4x4 = m4x4.determinant();
    std::cout << GREEN << "det(M) = \n" << RESET << det4x4 << std::endl; // attendu : 24

    std::cout << CYAN << BOLD << "=== Test determinant: Matrice identité ===" << RESET << std::endl;
    Matrix<float> id({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    std::cout << "M = \n" << id << std::endl;
    float det_id = id.determinant();
    std::cout << GREEN << "det(M) = \n" << RESET << det_id << std::endl; // attendu : 1

    std::cout << CYAN << BOLD << "=== Test determinant: Matrice nulle ===" << RESET << std::endl;
    Matrix<float> zero({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    std::cout << "M = \n" << zero << std::endl;
    float det_zero = zero.determinant();
    std::cout << GREEN << "det(M) = \n" << RESET << det_zero << std::endl; // attendu : 0

    std::cout << CYAN << BOLD << "=== Test determinant: Matrice non carrée ===" << RESET << std::endl;
    Matrix<float> non_square({
        {1, 2, 3},
        {4, 5, 6}
    });
    std::cout << "M = \n" << non_square << std::endl;
    try {
        float det_non_square = non_square.determinant();
        std::cout << GREEN << "det(M) = \n" << RESET << det_non_square << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    return 0;
}