#ifndef __CXX_DOJO_MATRIX_HPP__
#define __CXX_DOJO_MATRIX_HPP__

/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <iomanip>
#include <vector>

#include "./feq.hpp"
#include "./floatFormatter.hpp"
#include "./vector.hpp"
#include "./output.hpp"

class Matrix
{
public:
    Matrix() = default;
    Matrix(Matrix const &) = default;
    Matrix(Matrix &&) = default;

    Matrix & operator=(Matrix const &) = default;
    Matrix & operator=(Matrix &&) = default;

    Matrix(unsigned rows, unsigned columns, double init = 0.0)
        : matrix_(rows, Vector(columns, init))
    {
    }

    Matrix(std::initializer_list<std::initializer_list<double>> const & data)
        : matrix_(data.begin(), data.end())
    {
    }

    Vector & operator[](unsigned i){
        return matrix_.at(i);
    }

    Vector const & operator[](unsigned i)const{
        return matrix_.at(i);
    }

    unsigned rows()const{
        return matrix_.size();
    }

    unsigned columns()const{
        if(rows() == 0){
            return 0;
        }

        return matrix_[0].size();
    }

private:
    std::vector<Vector> matrix_;
};

inline
std::ostream & operator<<(std::ostream & out, Matrix const & matrix){
    out << "[";

    if(matrix.rows() != 0){
        out << matrix[0];

        for(unsigned i = 1; i < matrix.rows(); ++i){
            out << "\n ";
            out << matrix[i];
        }
    }

    out << "]";

    return out;
}

inline
bool operator==(Matrix const & matrix1, Matrix const & matrix2){
    unsigned const rows1 = matrix1.rows();
    unsigned const rows2 = matrix2.rows();

    if(rows1 != rows2){
        return false;
    }

    for(unsigned row = 0; row < rows1; ++row){
        unsigned const columns1 = matrix1[row].size();
        unsigned const columns2 = matrix2[row].size();

        if(columns1 != columns2){
            return false;
        }

        for(unsigned column = 0; column < columns1; ++column){
            if(!feq(matrix1[row][column], matrix2[row][column])){
                return false;
            }
        }
    }

    return true;
}

inline
bool operator!=(Matrix const & matrix1, Matrix const & matrix2){
    return !(matrix1 == matrix2);
}

inline
Matrix operator+(Matrix const & matrix1, double d){
    Matrix result = Matrix(matrix1.rows(), matrix1.columns());

    for(unsigned i = 0; i < matrix1.rows(); ++i){
        for(unsigned j = 0; j < matrix1[0].size(); ++j){
            result[i][j] = matrix1[i][j] + d;
        }
    }

    return result;
}

inline
Matrix operator+(Matrix const & matrix1, Matrix const & matrix2){
    Matrix result = Matrix(matrix1.rows(), matrix1.columns());

    for(unsigned i = 0; i < matrix1.rows(); ++i){
        for(unsigned j = 0; j < matrix1.columns(); ++j){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

inline
Matrix operator*(Matrix const & matrix1, double d){
    Matrix result = Matrix(matrix1.rows(), matrix1.columns());

    for(unsigned i = 0; i < matrix1.rows(); ++i){
        for(unsigned j = 0; j < matrix1[0].size(); ++j){
            result[i][j] = matrix1[i][j] * d;
        }
    }

    return result;
}

inline
Matrix operator*(Matrix const & matrix1, Matrix const & matrix2){
    Matrix result = Matrix(matrix1.rows(), matrix1.columns());

    for(unsigned i = 0; i < matrix1.rows(); ++i){
        for(unsigned j = 0; j < matrix2.columns(); ++j){
            for(unsigned k = 0; k < matrix2.rows(); ++k){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

inline
Matrix dot(Matrix const & matrix1, Matrix const & matrix2){
    return matrix1 * matrix2;
}

inline
Matrix transpose(Matrix const & matrix){
    Matrix result = Matrix(matrix.rows(), matrix.columns());

    for(unsigned i = 0; i < matrix.rows(); ++i){
        for(unsigned j = 0; j < matrix.columns(); ++j){
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}

inline
Matrix eye(unsigned size){
    Matrix result(size, size, 0);

    for(unsigned i = 0; i < size; ++i){
        result[i][i] = 1;
    }

    return result;
}

#endif
