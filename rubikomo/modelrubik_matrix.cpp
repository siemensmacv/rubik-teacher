#include "modelrubik_matrix.h"

ModelRubik_Matrix::ModelRubik_Matrix()
{
    _matrix = new int**[6];
    for(auto face = 0; face < 6; ++face)
    {
        _matrix[face] = new int*[3];
        for(auto row = 0; row < 3; ++row)
        {
            _matrix[face][row] = new int[3];
            for(auto column = 0; column < 3; ++column)
                _matrix[face][row][column] = face;
        }
    }
}

ModelRubik_Matrix::~ModelRubik_Matrix()
{
    for(auto face = 0; face < 6; ++face)
    {
        for(auto row = 0; row < 3; ++row)
            delete[] _matrix[face][row];
        delete[] _matrix[face];
    }
    delete[] _matrix;
}

int ModelRubik_Matrix::getMatrixValue(const RubikFace &face, const int &row, const int &column) const
{
    return _matrix[static_cast<int>(face)][row][column];
}

void ModelRubik_Matrix::setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value)
{
    _matrix[static_cast<int>(face)][row][column] = value;
}

void ModelRubik_Matrix::setMatrix(std::string input)
{
    int pos = 0;
    int row = 0;
    int col = 0;
    while(pos < 54)
    {
        row = 0;
        while(row < 3)
        {
            col = 0;
            while(col < 3)
            {
                _matrix[pos/9][row][col] = RubikFaceUtils::colorLetterToDigit(input[pos]);
                ++col;
                ++pos;
            }
            ++row;
        }
    }
}

std::string ModelRubik_Matrix::getMatrix()
{
    std::string output;
    for(int face = 0; face < 6; ++face)
    {
        for(int row = 0; row < 3; ++row)
        {
            for(int col = 0; col < 3; ++col)
            {
                output += RubikFaceUtils::colorDigitToLetter(_matrix[face][row][col]);
            }
        }
    }

    return output;
}

void ModelRubik_Matrix::rotateFaceClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        _rotateBackClockwise();
        break;
    case RubikFace::Down:
        _rotateDownClockwise();
        break;
    case RubikFace::Front:
        _rotateFrontClockwise();
        break;
    case RubikFace::Left:
        _rotateLeftClockwise();
        break;
    case RubikFace::Right:
        _rotateRightClockwise();
        break;
    case RubikFace::Up:
        _rotateUpClockwise();
        break;
    }
}

void ModelRubik_Matrix::rotateFaceCounterClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        _rotateBackCounterClockwise();
        break;
    case RubikFace::Down:
        _rotateDownCounterClockwise();
        break;
    case RubikFace::Front:
        _rotateFrontCounterClockwise();
        break;
    case RubikFace::Left:
        _rotateLeftCounterClockwise();
        break;
    case RubikFace::Right:
        _rotateRightCounterClockwise();
        break;
    case RubikFace::Up:
        _rotateUpCounterClockwise();
        break;
    }
}

int**& ModelRubik_Matrix::_rotateMatrixClockwise(int**& matrix)
{
    std::swap(matrix[0][0], matrix[0][2]);
    std::swap(matrix[0][0], matrix[2][2]);
    std::swap(matrix[0][0], matrix[2][0]);

    std::swap(matrix[0][1], matrix[1][2]);
    std::swap(matrix[0][1], matrix[2][1]);
    std::swap(matrix[0][1], matrix[1][0]);
    return matrix;
}

int**& ModelRubik_Matrix::_rotateMatrixCounterClockwise(int**& matrix)
{
    std::swap(matrix[0][0], matrix[2][0]);
    std::swap(matrix[0][0], matrix[2][2]);
    std::swap(matrix[0][0], matrix[0][2]);

    std::swap(matrix[0][1], matrix[1][0]);
    std::swap(matrix[0][1], matrix[2][1]);
    std::swap(matrix[0][1], matrix[1][2]);
    return matrix;
}

void ModelRubik_Matrix::_rotateFaceClockwise(int**& front, int**& up, int**& down, int**& left, int**& right)
{
    std::swap(up[2][0], right[0][0]);
    std::swap(up[2][0], down[0][2]);
    std::swap(up[2][0], left[2][2]);

    std::swap(up[2][1], right[1][0]);
    std::swap(up[2][1], down[0][1]);
    std::swap(up[2][1], left[1][2]);

    std::swap(up[2][2], right[2][0]);
    std::swap(up[2][2], down[0][0]);
    std::swap(up[2][2], left[0][2]);


    _rotateMatrixClockwise(front);
}

void ModelRubik_Matrix::_rotateFaceCounterClockwise(int**& front, int**& up, int**& down, int**& left, int**& right)
{
    std::swap(up[2][0], left[2][2]);
    std::swap(up[2][0], down[0][2]);
    std::swap(up[2][0], right[0][0]);

    std::swap(up[2][1], left[1][2]);
    std::swap(up[2][1], down[0][1]);
    std::swap(up[2][1], right[1][0]);

    std::swap(up[2][2], left[0][2]);
    std::swap(up[2][2], down[0][0]);
    std::swap(up[2][2], right[2][0]);

    _rotateMatrixCounterClockwise(front);
}

void ModelRubik_Matrix::_rotateFrontClockwise()
{
    _rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::_rotateFrontCounterClockwise()
{
    _rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::_rotateBackClockwise()
{
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
    _rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
}

void ModelRubik_Matrix::_rotateBackCounterClockwise()
{
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
    _rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
}

void ModelRubik_Matrix::_rotateUpClockwise()
{
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    _rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::_rotateUpCounterClockwise()
{
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    _rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::_rotateDownClockwise()
{
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    _rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::_rotateDownCounterClockwise()
{
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    _rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    _rotateMatrixClockwise(_rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::_rotateLeftClockwise()
{
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    _rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::_rotateLeftCounterClockwise()
{
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    _rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::_rotateRightClockwise()
{
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    _rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::_rotateRightCounterClockwise()
{
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    _rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)]);
    _rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    _rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}
