#include "Matrix3D.h"

Matrix3D::Matrix3D():MatrixBase(m_size) {
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