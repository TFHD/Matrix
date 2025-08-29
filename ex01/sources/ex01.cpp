#include "Matrix.hpp"
#include "Vector.hpp"

#include <cmath>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

template<typename K>
Vector<K> linear_combination(const std::vector<Vector<K>> &u, std::vector<K> &coefs) {
    std::vector<K> res;
    if (u.size() != coefs.size()) {
        std::cout << "\e[31mError, vectors size and coefs are not de same !\e[0m" << std::endl;
        return res;
    }

    int size = 0;
    for (int i = 0; i < (int)u.size(); i++) {
        if (!i)
            size = (int)u[i].getSize();
        else if (size != (int)u[i].getSize()) {
            std::cout << "\e[31mError, vectors size are not de same !\e[0m" << std::endl;
            return res;
        }
    }

    for (int i = 0; i < (int)u[u.size() - 1].getSize(); i++) {
        K res_nb = 0;
        for (int j = 0; j < (int)coefs.size(); j++)
            res_nb = std::fma(coefs[j], u[j][i], res_nb);
        res.push_back(res_nb);
    }
    return res;
}

int main(void) {
    std::cout << CYAN << BOLD << "=== Test linear_combination: base ===" << RESET << std::endl;
    {
        Vector<float> v1({1.0, 2.0, 3.0});
        Vector<float> v2({4.0, 5.0, 6.0});
        std::vector<Vector<float>> vectors = {v1, v2};
        std::vector<float> coefs = {2.0, -1.0};

        Vector<float> res = linear_combination(vectors, coefs);
        std::cout << GREEN << "linear_combination({v1,v2},{2,-1}) = " << RESET << std::endl;
        res.printVec();
    }

    std::cout << CYAN << BOLD << "=== Test linear_combination: erreur taille coef ===" << RESET << std::endl;
    {
        Vector<float> v1({1.0, 2.0});
        Vector<float> v2({3.0, 4.0});
        std::vector<Vector<float>> vectors = {v1, v2};
        std::vector<float> coefs = {2.0};

        Vector<float> res = linear_combination(vectors, coefs);
        std::cout << GREEN << "linear_combination({v1,v2},{2}) = " << RESET << std::endl;
        res.printVec();
    }

    std::cout << CYAN << BOLD << "=== Test linear_combination: erreur taille vector ===" << RESET << std::endl;
    {
        Vector<float> v1({1.0, 2.0, 3.0});
        Vector<float> v2({4.0, 5.0});
        std::vector<Vector<float>> vectors = {v1, v2};
        std::vector<float> coefs = {2.0, -1.0};

        Vector<float> res = linear_combination(vectors, coefs);
        std::cout << GREEN << "linear_combination({v1,v2},{2,-1}) = " << RESET << std::endl;
        res.printVec();
    }

    std::cout << CYAN << BOLD << "=== Test linear_combination: 3 vecteurs ===" << RESET << std::endl;
    {
        Vector<float> v1({1.0, 0.0, 0.0});
        Vector<float> v2({0.0, 1.0, 0.0});
        Vector<float> v3({0.0, 0.0, 1.0});
        std::vector<Vector<float>> vectors = {v1, v2, v3};
        std::vector<float> coefs = {3.0, 4.0, -2.0};

        Vector<float> res = linear_combination(vectors, coefs);
        std::cout << GREEN << "linear_combination({v1,v2,v3},{3,4,-2}) = " << RESET << std::endl;
        res.printVec();
    }

    std::cout << CYAN << BOLD << "=== Test linear_combination: int ===" << RESET << std::endl;
    {
        Vector<int> v1({1, 2, 3});
        Vector<int> v2({4, 5, 6});
        std::vector<Vector<int>> vectors = {v1, v2};
        std::vector<int> coefs = {2, 3};

        Vector<int> res = linear_combination(vectors, coefs);
        std::cout << GREEN << "linear_combination({v1,v2},{2,3}) = " << RESET << std::endl;
        res.printVec();
    }

    return 0;
}