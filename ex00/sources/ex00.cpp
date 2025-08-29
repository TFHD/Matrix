#include "Matrix.hpp"
#include "Vector.hpp"

// Macros couleurs ANSI
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main(void) {
    try {
        std::cout << CYAN << BOLD << "[Vector add]" << RESET << std::endl;
        Vector<float> u({2, 3});
        Vector<float> v({5, 7});
        u.add(v);
        u.printVec();
        std::cout << YELLOW << "============" << RESET << std::endl;
    } catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    try {
        std::cout << CYAN << BOLD << "[Vector sub]" << RESET << std::endl;
        Vector<float> u({2, 3});
        Vector<float> v({5, 7});
        u.sub(v);
        u.printVec();
        std::cout << YELLOW << "============" << RESET << std::endl;
    } catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    try {
        std::cout << CYAN << BOLD << "[Vector scl]" << RESET << std::endl;
        Vector<float> u({2, 3});
        u.scl(2.);
        u.printVec();
        std::cout << YELLOW << "============" << RESET << std::endl;
    } catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    try {
        std::cout << GREEN << BOLD << "[Matrix add]" << RESET << std::endl;
        Matrix<float> mat({{1, 2}, {3, 4}});
        Matrix<float> mat1({{7, 4}, {-2, 2}});
        mat.add(mat1);
        mat.printMat();
        std::cout << YELLOW << "============" << RESET << std::endl;
    } catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    try {
        std::cout << GREEN << BOLD << "[Matrix sub]" << RESET << std::endl;
        Matrix<float> mat({{1, 2}, {3, 4}});
        Matrix<float> mat1({{7, 4}, {-2, 2}});
        mat.sub(mat1);
        mat.printMat();
        std::cout << YELLOW << "============" << RESET << std::endl;
    } catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    try {
        std::cout << GREEN << BOLD << "[Matrix scl]" << RESET << std::endl;
        Matrix<float> mat({{100}, {3}});
        mat.scl(2.0f);
        mat.printMat();
        std::cout << YELLOW << "============" << RESET << std::endl;
    } catch (std::exception &e) { std::cout << RED << e.what() << RESET << std::endl; }

    return 0;
}