#ifndef MODELRUBIK_MATRIX_H
#define MODELRUBIK_MATRIX_H

#include "rubikface.h"
#include <algorithm>
#include <vector>
#include <qstring.h>

class ModelRubik_Matrix
{
private:
    int ***_matrix = nullptr;

    int**& _rotateMatrixClockwise(int**& matrix);
    int**& _rotateMatrixCounterClockwise(int**& matrix);
    void _rotateFaceClockwise(int**& front, int**& up, int**& down, int**& left, int**& right);
    void _rotateFaceCounterClockwise(int**& front, int**& up, int**& down, int**& left, int**& right);
    void _rotateFrontClockwise();
    void _rotateFrontCounterClockwise();
    void _rotateBackClockwise();
    void _rotateBackCounterClockwise();
    void _rotateUpClockwise();
    void _rotateUpCounterClockwise();
    void _rotateDownClockwise();
    void _rotateDownCounterClockwise();
    void _rotateLeftClockwise();
    void _rotateLeftCounterClockwise();
    void _rotateRightClockwise();
    void _rotateRightCounterClockwise();

    void setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value);
    int colorLetterToDigit(char c);
    char colorDigitToLetter(int d);
public:
    ModelRubik_Matrix();
    ~ModelRubik_Matrix();
    int getMatrixValue(const RubikFace &face, const int &row, const int &column) const;
    void setMatrix(std::string input);
    std::string getMatrix();

    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);
    void rotateXAxisClockwise();
    void rotateXAxisCounterClockwise();
    void rotateYAxisClockwise();
    void rotateYAxisCounterClockwise();
    void rotateZAxisClockwise();
    void rotateZAxisCounterClockwise();
};

#endif // MODELRUBIK_MATRIX_H
