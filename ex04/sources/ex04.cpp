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
    std::cout << CYAN << BOLD << "=== Test norm_1 ===" << RESET << std::endl;
    {
        Vec v({-1.0f, 2.0f, -3.0f, 4.0f});
        std::cout << v << std::endl;
        float res = v.norm_1();
        std::cout << GREEN << "norm_1 = " << RESET << res << std::endl; 
    }

    std::cout << CYAN << BOLD << "=== Test norm (euclidienne) ===" << RESET << std::endl;
    {
        Vec v({3.0f, 4.0f});
        std::cout << v << std::endl;
        float res = v.norm();
        std::cout << GREEN << "norm = " << RESET << res << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test norm_inf ===" << RESET << std::endl;
    {
        Vec v({-1.0, 2.0, -5.0, 4.3});
        std::cout << v << std::endl;
        float res = v.norm_inf();
        std::cout << GREEN << "norm_inf = " << RESET << res << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test norm_1 pour vecteur nul ===" << RESET << std::endl;
    {
        Vec v({0.0f, 0.0f, 0.0f});
        std::cout << v << std::endl;
        float res = v.norm_1();
        std::cout << GREEN << "norm_1 = " << RESET << res << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test norm pour un seul élément ===" << RESET << std::endl;
    {
        Vec v({-7.0f});
        std::cout << v << std::endl;
        float res = v.norm();
        std::cout << GREEN << "norm = " << RESET << res << std::endl;
    }

    std::cout << CYAN << BOLD << "=== Test norm_inf pour valeurs négatives et positives ===" << RESET << std::endl;
    {
        Vec v({-2.5f, 1.1f, 0.0f, 2.4f});
        std::cout << v << std::endl;
        float res = v.norm_inf();
        std::cout << GREEN << "norm_inf = " << RESET << res << std::endl;
    }

    return 0;
}