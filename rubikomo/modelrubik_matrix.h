#ifndef MODELRUBIK_MATRIX_H
#define MODELRUBIK_MATRIX_H

#include "rubikface.h"
#include <algorithm>
#include <vector>

class ModelRubik_Matrix
{
private:
    int ***_matrix = nullptr;

    int**& rotateMatrixClockwise(int**& matrix);
    int**& rotateMatrixCounterClockwise(int**& matrix);
    void rotateFaceClockwise(int**& front, int**& up, int**& down, int**& left, int**& right);
    void rotateFaceCounterClockwise(int**& front, int**& up, int**& down, int**& left, int**& right);
    void rotateFrontClockwise();
    void rotateFrontCounterClockwise();
    void rotateBackClockwise();
    void rotateBackCounterClockwise();
    void rotateUpClockwise();
    void rotateUpCounterClockwise();
    void rotateDownClockwise();
    void rotateDownCounterClockwise();
    void rotateLeftClockwise();
    void rotateLeftCounterClockwise();
    void rotateRightClockwise();
    void rotateRightCounterClockwise();
    void rotateXAxisClockwise();
    void rotateXAxisCounterClockwise();
    void rotateYAxisClockwise();
    void rotateYAxisCounterClockwise();
    void rotateZAxisClockwise();
    void rotateZAxisCounterClockwise();

public:
    ModelRubik_Matrix();
    ~ModelRubik_Matrix();
    int getMatrixValue(const RubikFace &face, const int &row, const int &column) const;
    void setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value);

    void rotateClockwise(const RubikFace &face);
    void rotateCounterClockwise(const RubikFace &face);
};

#endif // MODELRUBIK_MATRIX_H
