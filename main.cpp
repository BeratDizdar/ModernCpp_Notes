#include <iostream>
#include <ranges>

template<typename _Type, int _Row, int _Col>
class Matrix {
private:
    std::array<std::array<_Type, _Col>, _Row> m;

public:
    _Type& operator()(int i, int j) {
        return m[i][j];
    }

    const _Type& operator()(int i, int j) const {
        return m[i][j];
    }

    void fill(_Type val) {
        for (auto& row : m)
            row.fill(val);
    }
    _Type& operator[](int index) {
        int row = index / _Col;
        int col = index % _Col;
        return m[row][col];
    }
    
    void print() const {
        for (int i = 0; i < _Row; ++i) {
            for (int j = 0; j < _Col; ++j) {
                std::cout << m[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < _Row; ++i)
            for (int j = 0; j < _Col; ++j)
                result.m[i][j] = m[i][j] + other.m[i][j];
        return result;
    }

    Matrix operator+(const _Type& other) const {
        Matrix result;
        for (int i = 0; i < _Row; ++i)
            for (int j = 0; j < _Col; ++j)
                result.m[i][j] = m[i][j] + other;
        return result;
    }


};

int main() {

    Matrix<int, 3, 4> mat1;
    mat1.fill(5);

    std::cout << "Matris 1:\n";
    mat1.print();

    Matrix<int, 3, 4> mat2;
    mat2.fill(2);

    std::cout << "\nMatris 2:\n";
    mat2.print();

    Matrix<int, 3, 4> mat3 = mat1 + mat2;

    std::cout << "\nMatris 1 + Matris 2:\n";
    mat3.print();

    Matrix<int, 3, 4> mat4 = mat1 + 10;

    std::cout << "\nMatris 1 + 10 (Skalar ile):\n";
    mat4.print();

    return 0;
}
