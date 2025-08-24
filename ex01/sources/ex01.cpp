#include "Matrix.hpp"
#include "Vector.hpp"

#include <cmath>

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

    try {
        Vector<float> e1({1., 0., 0.});
        Vector<float> e2({0., 1., 0.});
        Vector<float> e3({0., 0., 1.});

        Vector<float> v1({1., 2., 3.});
        Vector<float> v2({0., 10., -100.});

        std::vector<Vector<float>> base{e1, e2, e3};
        std::vector<Vector<float>> base2{v1, v2};
        std::vector<float> coefs{10.0, -2.0, 0.5};
        std::vector<float> coefs2{10.0, -2.0};

        Vector<float> res = linear_combination<float>(base, coefs);
        res.printVec();
        res = linear_combination<float>(base2, coefs2);
        std::cout << "========" << std::endl;
        res.printVec();
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
}