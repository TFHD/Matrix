#include "Matrix.hpp"
#include "Vector.hpp"
#include "MathUtils.hpp"

typedef Vector<float> Vec;
typedef Matrix<float> Mat;

#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

int main() {
    std::cout << CYAN << BOLD << "=== Test rang: Matrice identité 3x3 ===" << RESET << std::endl;
    Matrix<float> id({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    std::cout << "M =\n" << id << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << id.rank() << RESET << " (attendu: 3)\n\n";

    std::cout << CYAN << BOLD << "=== Test rang: Matrice nulle 3x3 ===" << RESET << std::endl;
    Matrix<float> zero({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    std::cout << "M =\n" << zero << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << zero.rank() << RESET << " (attendu: 0)\n\n";

    std::cout << CYAN << BOLD << "=== Test rang: Matrice 2x2 pleine ===" << RESET << std::endl;
    Matrix<float> full({
        {2, 1},
        {1, 1}
    });
    std::cout << "M =\n" << full << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << full.rank() << RESET << " (attendu: 2)\n\n";

    std::cout << CYAN << BOLD << "=== Test rang: Matrice 2x2 (lignes proportionnelles) ===" << RESET << std::endl;
    Matrix<float> prop({
        {1, 2},
        {2, 4}
    });
    std::cout << "M =\n" << prop << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << prop.rank() << RESET << " (attendu: 1)\n\n";

    // Matrice rectangulaire (rang 1)
    std::cout << CYAN << BOLD << "=== Test rang: Matrice rectangulaire 2x3 ===" << RESET << std::endl;
    Matrix<float> rect({
        {1, 2, 3},
        {2, 4, 6}
    });
    std::cout << "M =\n" << rect << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << rect.rank() << RESET << " (attendu: 1)\n\n";

    // Matrice rectangulaire (rang 2)
    std::cout << CYAN << BOLD << "=== Test rang: Matrice rectangulaire 3x2 ===" << RESET << std::endl;
    Matrix<float> rect2({
        {1, 2},
        {3, 4},
        {5, 6}
    });
    std::cout << "M =\n" << rect2 << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << rect2.rank() << RESET << " (attendu: 2)\n\n";

    // Matrice vide (rang 0)
    std::cout << CYAN << BOLD << "=== Test rang: Matrice vide ===" << RESET << std::endl;
    Matrix<float> empty({});
    std::cout << "M =\n" << empty << std::endl;
    std::cout << GREEN << "Rang(M) = \n" << empty.rank() << RESET << " (attendu: 0)\n\n";

    return 0;
}