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
    std::cout << CYAN << BOLD << "=== Test inverse: Matrice identité ===" << RESET << std::endl;
    Matrix<float> id({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    std::cout << "M = \n" << id << std::endl;
    Matrix<float> inv_id = id.inverse();
    std::cout << GREEN << "Inverse(M) = \n" << RESET << inv_id << std::endl;

    std::cout << CYAN << BOLD << "=== Test inverse: Matrice 2x2 classique ===" << RESET << std::endl;
    Matrix<float> m2x2({
        {4.f, 7.f},
        {2.f, 6.f}
    });
    std::cout << "M = \n" << m2x2 << std::endl;
    Matrix<float> inv2x2 = m2x2.inverse();
    std::cout << GREEN << "Inverse(M) = \n" << RESET << inv2x2 << std::endl;

    std::cout << CYAN << BOLD << "=== Test inverse: Matrice 3x3 ===" << RESET << std::endl;
    Matrix<float> m3x3({
        {3, 0, 2},
        {2, 0, -2},
        {0, 1, 1}
    });
    std::cout << "M = \n" << m3x3 << std::endl;
    Matrix<float> inv3x3 = m3x3.inverse();
    std::cout << GREEN << "Inverse(M) = \n" << RESET << inv3x3 << std::endl;

    std::cout << CYAN << BOLD << "=== Test inverse: Matrice non inversible ===" << RESET << std::endl;
    Matrix<float> singular({
        {1, 2},
        {2, 4}
    });
    std::cout << "M = \n" << singular << std::endl;
    try {
        Matrix<float> inv_singular = singular.inverse();
        std::cout << GREEN << "Inverse(M) = \n" << RESET << inv_singular << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test inverse: Matrice non carrée ===" << RESET << std::endl;
    Matrix<float> non_square({
        {1, 2, 3},
        {4, 5, 6}
    });
    std::cout << "M = \n" << non_square << std::endl;
    try {
        Matrix<float> inv_non_square = non_square.inverse();
        std::cout << GREEN << "Inverse(M) = \n" << RESET << inv_non_square << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    return 0;
}