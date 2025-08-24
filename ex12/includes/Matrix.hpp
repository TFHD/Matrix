#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <tuple>
# include <vector>
# include <iostream>
# include <iomanip>
# include <cmath>
# include "Vector.hpp"

template <typename K>
class Vector;

template<typename K>
class Matrix {

    typedef std::vector<K> SubMat;
    typedef std::vector<SubMat> Mat;

    private:
        size_t sizeY = 0;
        size_t sizeX = 0;
        Mat mat;

    public:

        Matrix() : mat() {}
        Matrix(Matrix<K> &mat) : sizeY(mat.getSizeY()), sizeX(getSizeX()), mat(mat.getMat()) {}
        Matrix(Mat mat) : mat(mat) {
            sizeY = mat.size();
            for (SubMat &submat : mat) {
                if (sizeX != 0 && sizeX != submat.size()) {
                    throw std::runtime_error("\e[31mError Matrice Construction\e[0m");
                    return;
                }
                sizeX = submat.size();
            }
        };

        std::tuple<size_t, size_t> size() const { return {sizeX, sizeY}; }
        size_t getSizeX()              const { return sizeX; }
        size_t getSizeY()              const { return sizeY; }
        Mat getMat()                const { return mat; }
        bool isSquare()             const { return sizeX == sizeY; }
        bool isSameLength(Matrix &m)const { return ((m.getSizeX() == this->getSizeX()) && (m.getSizeY() == this->getSizeY())); }

        void printMat(void) {
            for (size_t i = 0; i < getSizeY(); i++) {
                std::cout << "[";
                for (size_t j = 0; j < getSizeX(); j++) {
                    std::cout << std::fixed << std::setprecision(1) << mat[i][j];
                    if (j + 1 != getSizeX()) std::cout << ", ";
                }
                std::cout << "]" << std::endl;
            }
        }
        
        void add(const Matrix<K> &matx) {
            for (size_t i = 0; i < getSizeY(); i++) {
                for (size_t j = 0; j < getSizeX(); j++)
                    mat[i][j] += matx.getMat()[i][j];
            }
        };

        void sub(const Matrix<K> &matx) {
            for (size_t i = 0; i < getSizeY(); i++) {
                for (size_t j = 0; j < getSizeX(); j++)
                    mat[i][j] -= matx.getMat()[i][j];
            }
        };
        void scl(const K scalar) {
            for (size_t i = 0; i < getSizeY(); i++) {
                for (size_t j = 0; j < getSizeX(); j++)
                    mat[i][j] *= scalar;
            }
        };

        void div(const K scalar) {
            if (!scalar)
                throw std::runtime_error("Matrix division: division by 0 is forbiden");
            for (size_t i = 0; i < getSizeY(); i++) {
                for (size_t j = 0; j < getSizeX(); j++)
                    mat[i][j] /= scalar;
            }
        };

        Matrix<K> mul_mat(Matrix<K> &matx) const {
            if (getSizeX() != matx.getSizeY())
                throw std::runtime_error("Matrix multiplication: incompatible size");
            Mat res(getSizeY(), SubMat(matx.getSizeX(), 0.0));
            for (size_t i = 0; i < (size_t)getSizeY(); ++i)
                for (size_t j = 0; j < (size_t)matx.getSizeX(); ++j)
                    for (size_t k = 0 ; k < (size_t)getSizeX(); ++k)
                        res[i][j] = std::fma(mat[i][k], matx.getMat()[k][j], res[i][j]);
            return Matrix<K>(res);
        }

        Vector<K> mul_vec(Vector<K> &vec) const {
            if (getSizeX() != vec.getSize())
                throw std::runtime_error("Matrix multiplication: incompatible size");
            std::vector<float> res(getSizeY(), 0.0);
            for (size_t i = 0; i < (size_t)getSizeY(); ++i)
                for (size_t j = 0; j < (size_t)vec.getSize(); ++j)
                    res[i] = std::fma(mat[i][j], vec[j], res[i]);
            return Vector<K>(res);
        }
        K trace(void) const {
            if (!isSquare())
                throw std::runtime_error("\e[31mError, Matrice is not a square matrix !\e[0m");
            K res = 0;
            for (size_t i = 0; i < getSizeY(); i++)
                res += mat[i][i];
            return res;
        }

        Matrix<K> transpose(void) const {
            Mat transpose(getSizeX(), SubMat(getSizeY(), 0.0));
            for (size_t i = 0; i < getSizeX(); i++) {
                for (size_t j = 0; j < getSizeY(); j++)
                    transpose[i][j] = mat[j][i];
            }
            return Matrix<K>(transpose);
        }

        Matrix<K> toRowEchelonForm(void) {
            size_t n = getSizeY();
            size_t m = getSizeX();
            size_t row = 0;

            Mat mat(getMat());
            for (size_t col = 0; col < m && row < n; ++col) {
                size_t pivotRow = row;

                while (pivotRow < n && Math::dabs(mat[pivotRow][col]) == 0) ++pivotRow;
                if (pivotRow == n) continue;
                std::swap(mat[row], mat[pivotRow]);

                double pivot = mat[row][col];
                for (size_t j = col; j < m; ++j)
                    mat[row][j] /= pivot;

                for (size_t i = 0; i < n; ++i) {
                    if (i != row) {
                        double factor = mat[i][col];
                        for (size_t j = col; j < m; ++j) {
                            mat[i][j] -= factor * mat[row][j];
                        }
                    }
                }
                row++;
            }
            return Matrix<K>(mat);
        }
        
        Matrix<K> toMinor(size_t row, size_t col) {
            Mat minor(getSizeY() - 1, SubMat(getSizeX() - 1, 0.0));
            size_t minor_row = 0;
            for (size_t i = 0; i < getSizeY(); i++) {
                size_t minor_col = 0;
                bool is_find = false;
                for (size_t j = 0; j < getSizeX(); j++)
                        if (i != row - 1 && j != col - 1) {
                        minor[minor_row][minor_col++] = mat[i][j];
                        is_find = true;
                    }
                if (is_find)
                    minor_row++;
            }
            return Matrix<K>(minor);
        }

        K cofactor(size_t row, size_t col) {
            return Math::pow(-1, row + col) * toMinor(row, col).determinant();
        }

        K determinant(void) {
            if (!isSquare())
                throw std::runtime_error("\e[31mError, Matrice is not a square matrix !\e[0m");
            K res = 0;
            if (getSizeX() == 2)
                return std::fma(mat[0][0], mat[1][1], -std::fma(mat[0][1], mat[1][0], 0));
            for (size_t i = 0; i < getSizeY(); i++)
                res += mat[0][i] * cofactor(1, i + 1);
            return res;
        }

        Matrix<K> inverse() {
            K det = determinant();
            if (!det)
                throw std::runtime_error("Inverse : Determinant is null");
            Mat inv(getSizeY(), SubMat(getSizeX(), 0.0));
            for (size_t i = 0; i < getSizeY(); i++) {
                for (size_t j = 0; j < getSizeY(); j++) {
                    inv[i][j] = cofactor(i + 1, j + 1);
                }
            }
            Matrix<K> transposeMat(Matrix<K>(inv).transpose());
            transposeMat.div(det); 

            return transposeMat;
        }
};

template<typename K>
std::ostream &operator<<(std::ostream &o, const Matrix<K> &m) {
    for (size_t i = 0; i < m.getSizeY(); i++) {
        o << "[";
        for (size_t j = 0; j < m.getSizeX(); j++) {
            o << std::setw(7) << std::fixed << std::setprecision(4) << m.getMat()[i][j];
            if (j + 1 != m.getSizeX()) o << ", ";
        }
        o << "]";
        if (i + 1 != m.getSizeY()) o << std::endl;
    }
    return o;
}

#endif