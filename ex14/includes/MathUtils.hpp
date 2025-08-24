#ifndef MATHUTILS_HPP
# define MATHUTILS_HPP

# include <Vector.hpp>

template <typename T>
class Vector;

struct Math {

    static double dabs(double x) {
        return (x < 0) ? -x : x; 
    }

    static int getMin(float x, float y) {
        return (x < y) ? x : y;
    }

    static int getMax(float x, float y) {
        return (x > y) ? x : y;
    }

    static int myAbs(double x, double y) {

        x = dabs(x);
        y = dabs(y);

        if (x > y)  return x - y;
        else        return y - x;
    }

    static double my_sqrt(double x) {

        if (x < 0)
            return -1;
        if (x == 0)
            return 0;
        double guess = x;
        double epsilon = 1e-10;
        int i = 10000;
        while (Math::dabs(guess * guess - x) > epsilon && i > 0) {
            guess = (guess + x / guess) / 2.0;
            i--;
        }
        return guess;
    }

    static double pow(double x, int e) {

        int res = 1;
        while (e-- > 0) {
            res *= x;
        }
        return res;
    }

    template <typename K>
    static double scalarProduct(Vector<K> &vec1, Vector<K> &vec2) {

        if (!vec1.isSameLength(vec2))
            throw std::runtime_error("\e[31mError, vectors size are not the same !\e[0m");
        double res = 0;
        for (int i = 0; i < vec1.getSize(); i++)
            res = std::fma(vec1[i], vec2[i], res);
        return res; 
    }

    template <typename K>
    static double angle_cos(Vector<K> &vec1, Vector<K> &vec2) {
        double scalar_product = 0;
        double norm = 0;

        scalar_product = scalarProduct(vec1, vec2);
        norm = vec1.norm() * vec2.norm();

        if (!norm || !vec1.norm_1() || !vec2.norm_1())
            throw std::runtime_error("\e[31mImpossible calcul !\e[0m");
        
        return scalar_product / norm;
    }

    template <typename K>
    static Vector<K> cross_product(Vector<K> &u, Vector<K> &v) {

        if (!u.isSameLength(v))
            throw std::runtime_error("\e[31mError, vectors size are not the same !\e[0m");
        if (v.getSize() != 3 || u.getSize() != 3)
            throw std::invalid_argument("\e[31mCross product is only for vectors of length 3 !\e[0m");
        return Vector<K>({
            u[1] * v[2] - u[2] * v[1],
            u[2] * v[0] - u[0] * v[2],
            u[0] * v[1] - u[1] * v[0]
        });
    }
};

#endif