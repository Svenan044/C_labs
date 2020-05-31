#pragma once
#include <iostream>

using namespace std;

class MatrixBase {
protected:
    MatrixBase() = delete;
    MatrixBase(unsigned int iSize) :m_size(iSize) {}

private:
    const unsigned int m_size;

public:
    // Возвращает размер матрицы
    unsigned int size();

    // Возвращает элемент матрицы
    virtual int element(unsigned int i, unsigned int j) const = 0;

    // Возвращает ссылку на элемент матрицы
    virtual int& element(unsigned int i, unsigned int j) = 0;

    // Умножение всех элементов на iMult
    void operator*=(int iMult);

    // Сложение матрицы с матрицей iAdd
    void operator+=(MatrixBase& iAdd);

    friend ostream& operator<<(ostream& stream, const MatrixBase& iMatrix);
};

ostream& operator<<(ostream& stream, const MatrixBase& iMatrix);




