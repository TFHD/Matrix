#ifndef MATHUTILS_HPP
# define MATHUTILS_HPP

# include <Vector.hpp>

template <typename T>
class Vector;

struct Math {

    static double dabs(double x) {
        return (x < 0) ? -x : x; 
    }

    static float getMin(float x, float y) {
        return (x < y) ? x : y;
    }

    static float getMax(float x, float y) {
        return (x > y) ? x : y;
    }

    static double myAbs(double x, double y) {

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
        while (e-- > 0)
            res *= x;
        return res;
    }

    template <typename K>
    static double angle_cos(Vector<K> &vec1, Vector<K> &vec2) { // cos(0) = A . B / |A| * |B|
        double scalar_product = 0;
        double norm = 0;

        scalar_product = vec1.dot(vec2);
        norm = vec1.norm() * vec2.norm();

        if (!norm || !vec1.norm_1() || !vec2.norm_1())
            throw std::runtime_error("\e[31mImpossible calcul !\e[0m");
        
        return scalar_product / norm;
    }
};

#endif