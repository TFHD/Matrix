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

        Vector(Vec vec) : vec(vec) { size = vec.size(); };

        int getSize()            const { return (size); }
        Vec getVec()             const { return (vec); }
        bool isSameLength(Vector<K> &v)const { return (getSize() == v.getSize()); }

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