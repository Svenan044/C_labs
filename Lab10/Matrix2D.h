#pragma once
#include "MatrixBase.h"

class Matrix2D : public MatrixBase {
private:
    static const int unsigned m_size = 2;
    int matrix2d[m_size][m_size];

public:
    Matrix2D();

    int element(unsigned int i, unsigned int j) const override { return matrix2d[i][j]; }

    int& element(unsigned int i, unsigned int j) override { return matrix2d[i][j]; }
};