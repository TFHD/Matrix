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
    std::cout << CYAN << BOLD << "=== Test mul_mat: Produit de matrices compatibles ===" << RESET << std::endl;
    try {
        Matrix<float> m1({
            {1, 2, 3},
            {4, 5, 6}
        });
        Matrix<float> m2({
            {7, 8},
            {9, 10},
            {11, 12}
        });
        std::cout << "M1 = \n" << m1 << std::endl;
        std::cout << "M2 = \n" << m2 << std::endl;
        Matrix<float> result = m1.mul_mat(m2);
        std::cout << GREEN << "M1 * M2 = \n" << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test mul_mat: Produit de matrices incompatibles ===" << RESET << std::endl;
    try {
        Matrix<float> m1({
            {1, 2},
            {3, 4}
        });
        Matrix<float> m2({
            {5, 6, 7}
        });
        std::cout << "M1 = \n" << m1 << std::endl;
        std::cout << "M2 = \n" << m2 << std::endl;
        Matrix<float> result = m1.mul_mat(m2);
        std::cout << GREEN << "M1 * M2 = \n" << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test mul_vec: Produit matrice * vecteur compatible ===" << RESET << std::endl;
    try {
        Matrix<float> m({
            {1, 2, 3},
            {4, 5, 6}
        });
        Vector<float> v({7, 8, 9});
        std::cout << "M = \n" << m << std::endl;
        std::cout << "v = \n" << v << std::endl;
        Vector<float> result = m.mul_vec(v);
        std::cout << GREEN << "M * v = \n" << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test mul_vec: Produit matrice * vecteur incompatible ===" << RESET << std::endl;
    try {
        Matrix<float> m({
            {1, 2},
            {3, 4}
        });
        Vector<float> v({5, 6, 7});
        std::cout << "M = \n" << m << std::endl;
        std::cout << "v = \n" << v << std::endl;
        Vector<float> result = m.mul_vec(v);
        std::cout << GREEN << "M * v = \n" << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test mul_mat: Produit identité ===" << RESET << std::endl;
    try {
        Matrix<float> id({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        });
        Matrix<float> m({
            {3, 2, 1},
            {1, 0, 2},
            {4, 1, 0}
        });
        std::cout << "Id = \n" << id << std::endl;
        std::cout << "M = \n" << m << std::endl;
        Matrix<float> result = id.mul_mat(m);
        std::cout << GREEN << "Id * M = \n" << RESET << result << std::endl;
    } catch (const std::exception& e) { std::cout << RED << e.what() << RESET << std::endl; }

    return 0;
}