#include <tuple>
#include <vector>
#include <iostream>
#include <iomanip>

template<typename K>
class Vector {

    typedef std::vector<K> Vec;

    private:
        Vec vec;
        int size = 0;

    public:

        Vector() : vec(), size(0) {}
        Vector(Vec vec) : vec(vec) { size = vec.size(); }

        int getSize()            const { return (size); }
        Vec getVec()             const { return (vec); }
        K& operator[](size_t idx) { return vec[idx]; }
        const K& operator[](size_t idx) const { return vec[idx]; }
        bool isSameLength(Vector &v) const { return (this->getSize() == v.getSize()); }
        void append(K node) { vec.push_back(node); size++; }
        void remove(void) {vec.pop_back(); size--; }

        void printVec() {
            for (int i = 0; i < getSize(); i++)
                std::cout << std::fixed << std::setprecision(1) << "[" << vec[i] << "]" << std::endl;
        }
        void add(Vector<K> &vecx) {
            if (!isSameLength(vecx)) throw std::runtime_error("\e[31mVectors havn't the same length\e[0m");
            for (int i = 0; i != getSize(); i++) vec[i] += vecx.getVec()[i]; 
        };

        void sub(Vector<K> &vecx) {
            if (!isSameLength(vecx)) throw std::runtime_error("\e[31mVectors havn't the same length\e[0m");
            for (int i = 0; i != getSize(); i++) vec[i] -= vecx.getVec()[i];
        };

        void scl(K scalar) {
            for (int i = 0; i != getSize(); i++) vec[i] *= scalar;
        };
};

template<typename K>
std::ostream &operator<<(std::ostream &o, const Vector<K> &vec) {
    for (int i = 0; i < (int)vec.getSize(); i++) {
        o << std::fixed << std::setprecision(1) << "[" << vec[i] << "]";
        if (i + 1 != (int)vec.getSize())
            o << "\n";
    }
    return o;
}