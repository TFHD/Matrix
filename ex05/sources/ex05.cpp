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
    std::cout << CYAN << BOLD << "=== Test angle_cos(Vector<float>, Vector<float>) ===" << RESET << std::endl;
    try {
        Vector<float> v1({1.0f, 0.0f});
        Vector<float> v2({0.0f, 1.0f});
        std::cout << v1 << "\n------" << std::endl;
        std::cout << v2 << std::endl;
        double ac = Math::angle_cos(v1, v2);
        std::cout << GREEN << "angle_cos([1,0],[0,1]) = " << RESET << ac << std::endl; // Attend 0
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try {
        Vector<float> v1({1.0f, 1.0f});
        Vector<float> v2({1.0f, 1.0f});
        std::cout << v1 << "\n------" << std::endl;
        std::cout << v2 << std::endl;
        double ac = Math::angle_cos(v1, v2);
        std::cout << GREEN << "angle_cos([1,1],[1,1]) = " << RESET << ac << std::endl; // Attend 1
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    try {
        Vector<float> v1({1.0f, 2.0f, 4.0f});
        Vector<float> v2({4.0f, 5.0f, 6.0f});
        std::cout << v1 << "\n------" << std::endl;
        std::cout << v2 << std::endl;
        double ac = Math::angle_cos(v1, v2);
        std::cout << GREEN << "angle_cos([1,2,3],[4,5,6]) = " << RESET << ac << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test erreur taille ===" << RESET << std::endl;
    try {
        Vector<float> v1({1.0f, 2.0f});
        Vector<float> v2({3.0f, 4.0f, 5.0f});
        std::cout << v1 << "\n------" << std::endl;
        std::cout << v2 << std::endl;
        double ac = Math::angle_cos(v1, v2);
        std::cout << GREEN << "angle_cos([1,2],[3,4,5]) = " << RESET << ac << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test vecteur nul ===" << RESET << std::endl;
    try {
        Vector<float> v1({0.0f, 0.0f});
        Vector<float> v2({0.0f, 0.0f});
        std::cout << v1 << "\n------" << std::endl;
        std::cout << v2 << std::endl;
        double ac = Math::angle_cos(v1, v2);
        std::cout << GREEN << "angle_cos([0,0],[0,0]) = " << RESET << ac << std::endl;
    } catch (const std::exception &e) {
        std::cout << RED << e.what() << RESET << std::endl;
    }

    return 0;
}