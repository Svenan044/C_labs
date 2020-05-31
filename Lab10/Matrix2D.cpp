#include "Matrix2D.h"

Matrix2D::Matrix2D():MatrixBase(m_size) {
    int num = 1;
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            this->element(i, j) = num;
            num++;
        }
    }
}