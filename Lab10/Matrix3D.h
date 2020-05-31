#pragma once
#include "MatrixBase.h"

class Matrix3D : public MatrixBase {
private:
    static const int unsigned m_size = 3;
    int matrix[m_size][m_size];

public:
    Matrix3D();

    int element(unsigned int i, unsigned int j) const override { return matrix[i][j]; }

    int& element(unsigned int i, unsigned int j) override { return matrix[i][j]; }
};