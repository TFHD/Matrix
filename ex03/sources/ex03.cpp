#include "Matrix.hpp"
#include "Vector.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main(void) {
    std::cout << CYAN << BOLD << "=== Test dot(Vector<float>) ===" << RESET << std::endl;
    try {
        Vector<float> v1({1.0f, 2.0f, 3.0f});
        Vector<float> v2({4.0f, 5.0f, 6.0f});
        std::cout << GREEN << "dot([1,2,3], [4,5,6]) = " << RESET << v1.dot(v2) << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test dot(Vector<float>) avec un zéro ===" << RESET << std::endl;
    try {
        Vector<float> v1({0.0f, 0.0f, 0.0f});
        Vector<float> v2({4.0f, 5.0f, 6.0f});
        std::cout << GREEN << "dot([0,0,0], [4,5,6]) = " << RESET << v1.dot(v2) << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test dot(Vector<float>) erreur longueur ===" << RESET << std::endl;
    try {
        Vector<float> v1({1.0f, 2.0f});
        Vector<float> v2({4.0f, 5.0f, 6.0f});
        std::cout << GREEN << "dot([1,2], [4,5,6]) = " << RESET << v1.dot(v2) << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test dot(Vector<int>) ===" << RESET << std::endl;
    try {
        Vector<int> v1({1, 2, 3});
        Vector<int> v2({4, 5, 6});
        std::cout << GREEN << "dot([1,2,3], [4,5,6]) = " << RESET << v1.dot(v2) << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test dot(Vector<int>) erreur longueur ===" << RESET << std::endl;
    try {
        Vector<int> v1({1, 2});
        Vector<int> v2({4, 5, 6});
        std::cout << GREEN << "dot([1,2], [4,5,6]) = " << RESET << v1.dot(v2) << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    return 0;
}