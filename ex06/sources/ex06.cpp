#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main(void) {
    std::cout << CYAN << BOLD << "=== Test cross_product: standard basis vectors ===" << RESET << std::endl;
    try {
        Vector<float> u({1.0f, 0.0f, 0.0f});
        Vector<float> v({0.0f, 1.0f, 0.0f});
        std::cout << "u =\n" << u << std::endl;
        std::cout << "v =\n" << v << std::endl;
        Vector<float> result = Math::cross_product(u, v);
        std::cout << GREEN << "cross_product(u, v) =\n" << RESET;
        std::cout << result << std::endl;
    } catch (const std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test cross_product: anti-commutativity ===" << RESET << std::endl;
    try {
        Vector<float> u({1.0f, 2.0f, 3.0f});
        Vector<float> v({4.0f, 5.0f, 6.0f});
        std::cout << "u =\n" << u << std::endl;
        std::cout << "v =\n" << v << std::endl;
        Vector<float> result1 = Math::cross_product(u, v);
        Vector<float> result2 = Math::cross_product(v, u);
        std::cout << GREEN << "cross_product(u, v) =\n" << RESET;
        std::cout << result1 << std::endl;
        std::cout << GREEN << "cross_product(v, u) =\n" << RESET;
       std::cout << result2 << std::endl;
    } catch (const std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test cross_product: vector with itself ===" << RESET << std::endl;
    try {
        Vector<float> u({1.0f, 2.0f, 3.0f});
        Vector<float> result = Math::cross_product(u, u);
        std::cout << GREEN << "cross_product(u, u) =\n" << RESET;
        std::cout << result << std::endl;
    } catch (const std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test cross_product: wrong length ===" << RESET << std::endl;
    try {
        Vector<float> u({1.0f, 2.0f});
        Vector<float> v({3.0f, 4.0f});
        Vector<float> result = Math::cross_product(u, v);
        std::cout << result << std::endl;
    } catch (const std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    std::cout << CYAN << BOLD << "=== Test cross_product: different sizes ===" << RESET << std::endl;
    try {
        Vector<float> u({1.0f, 2.0f, 3.0f});
        Vector<float> v({4.0f, 5.0f, 6.0f, 7.0f});
        Vector<float> result = Math::cross_product(u, v);
        std::cout << result << std::endl;
    } catch (const std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    return 0;
}