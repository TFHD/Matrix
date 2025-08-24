#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <tuple>
# include <vector>
# include <iostream>
# include <iomanip>


template<typename K>
class Matrix {

    typedef std::vector<K> SubMat;
    typedef std::vector<SubMat> Mat;

    private:
        int sizeY = 0;
        int sizeX = 0;
        Mat mat;

    public:

        Matrix() : mat() {}
        Matrix(Mat mat) : mat(mat) {
            sizeY = mat.size();
            for (SubMat &submat : mat) {
                if (sizeX != 0 && sizeX != (int)submat.size()) {
                    throw std::runtime_error("\e[31mError Matrice Construction\e[0m");
                    return;
                }
                sizeX = submat.size();
            }
        };

        std::tuple<int, int> size() const { return {sizeX, sizeY}; }
        int getSizeX()              const { return (sizeX); }
        int getSizeY()              const { return (sizeY); }
        Mat getMat()                const { return (mat); }
        bool isSquare()             const { return (sizeX == sizeY); }
        bool isSameLength(Matrix &m)const { return ((m.getSizeX() == this->getSizeX()) && (m.getSizeY() == this->getSizeY())); }

        void printMat() {
            for (int i = 0; i < getSizeY(); i++) {
                std::cout << "[";
                for (int j = 0; j < getSizeX(); j++) {
                    std::cout << std::fixed << std::setprecision(1) << mat[i][j];
                    if (j + 1 != getSizeX()) std::cout << ", ";
                }
                std::cout << "]" << std::endl;
            }
        }
        
        void add(const Matrix<K> &matx) {
            for (int i = 0; i < getSizeY(); i++) {
                for (int j = 0; j < getSizeX(); j++)
                    mat[i][j] += matx.getMat()[i][j];
            }
        };

        void sub(const Matrix<K> &matx) {
            for (int i = 0; i < getSizeY(); i++) {
                for (int j = 0; j < getSizeX(); j++)
                    mat[i][j] -= matx.getMat()[i][j];
            }
        };
        void scl(const K scalar) {
            for (int i = 0; i < getSizeY(); i++) {
                for (int j = 0; j < getSizeX(); j++)
                    mat[i][j] *= scalar;
            }
        };
        
};

template<typename K>
std::ostream &operator<<(std::ostream &o, const Matrix<K> &m) {
    for (int i = 0; i < m.getSizeY(); i++) {
        o << "[";
        for (int j = 0; j < m.getSizeX(); j++) {
            o << std::fixed << std::setprecision(1) << m.getMat()[i][j];
            if (j + 1 != m.getSizeX()) o << ", ";
        }
        o << "]" << std::endl;
    }
    return o;
}

#endif