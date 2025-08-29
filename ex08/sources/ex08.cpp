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
    std::cout << CYAN << BOLD << "=== Test trace: Matrice carrée 3x3 ===" << RESET << std::endl;
    try {
        Matrix<float> m({
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        });
        std::cout << "M = \n" << m << std::endl;
        float result = m.trace();
        std::cout << GREEN << "trace(M) = " << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test trace: Matrice carrée 2x2 ===" << RESET << std::endl;
    try {
        Matrix<float> m({
            {-1, 2},
            {3, 4}
        });
        std::cout << "M = \n" << m << std::endl;
        float result = m.trace();
        std::cout << GREEN << "trace(M) = " << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test trace: Matrice non carrée 2x3 ===" << RESET << std::endl;
    try {
        Matrix<float> m({
            {1, 2, 3},
            {4, 5, 6}
        });
        std::cout << "M = \n" << m << std::endl;
        float result = m.trace();
        std::cout << GREEN << "trace(M) = " << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test trace: Matrice identité 4x4 ===" << RESET << std::endl;
    try {
        Matrix<float> m({
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}
        });
        std::cout << "M = \n" << m << std::endl;
        float result = m.trace();
        std::cout << GREEN << "trace(M) = " << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test trace: Matrice vide ===" << RESET << std::endl;
    try {
        Matrix<float> m({});
        std::cout << "M = \n" << m << std::endl;
        float result = m.trace();
        std::cout << GREEN << "trace(M) = " << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    return 0;
}