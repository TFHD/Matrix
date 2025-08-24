#include <tuple>
#include <vector>
#include <iostream>
#include <iomanip>

template<typename K>
class Vector {

    typedef std::vector<K> Vec;

    private:
        int size = 0;
        Vec vec;

    public:

        Vector() : vec(), size(0) {}
        Vector(Vec vec) : vec(vec) { size = vec.size(); }

        int getSize()            const { return (size); }
        Vec getVec()             const { return (vec); }
        K& operator[](size_t idx) { return vec[idx]; }
        const K& operator[](size_t idx) const { return vec[idx]; }

        void printVec() {
            for (int i = 0; i < getSize(); i++)
                std::cout << std::fixed << std::setprecision(1) << "[" << vec[i] << "]" << std::endl;
        }
        void add(const Vector<K> &vecx) {
            for (int i = 0; i != getSize(); i++) vec[i] += vecx.getVec()[i]; 
        };
        void sub(const Vector<K> &vecx) {
            for (int i = 0; i != getSize(); i++) vec[i] -= vecx.getVec()[i];
        };
        void scl(const K scalar) {
            for (int i = 0; i != getSize(); i++) vec[i] *= scalar;
        };
};