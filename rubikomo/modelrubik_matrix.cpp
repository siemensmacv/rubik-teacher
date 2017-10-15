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
                _matrix[face][row][column] = (face+1)*10 + 3*row + column + 1;
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

void ModelRubik_Matrix::rotateClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        rotateBackClockwise();
        break;
    case RubikFace::Down:
        rotateDownClockwise();
        break;
    case RubikFace::Front:
        rotateFrontClockwise();
        break;
    case RubikFace::Left:
        rotateLeftClockwise();
        break;
    case RubikFace::Right:
        rotateRightClockwise();
        break;
    case RubikFace::Up:
        rotateUpClockwise();
        break;
    }
}

void ModelRubik_Matrix::rotateCounterClockwise(const RubikFace &face)
{
    switch(face)
    {
    case RubikFace::Back:
        rotateBackCounterClockwise();
        break;
    case RubikFace::Down:
        rotateDownCounterClockwise();
        break;
    case RubikFace::Front:
        rotateFrontCounterClockwise();
        break;
    case RubikFace::Left:
        rotateLeftCounterClockwise();
        break;
    case RubikFace::Right:
        rotateRightCounterClockwise();
        break;
    case RubikFace::Up:
        rotateUpCounterClockwise();
        break;
    }
}

int**& ModelRubik_Matrix::rotateMatrixClockwise(int**& matrix)
{
    std::swap(matrix[0][0], matrix[0][2]);
    std::swap(matrix[0][0], matrix[2][2]);
    std::swap(matrix[0][0], matrix[2][0]);

    std::swap(matrix[0][1], matrix[1][2]);
    std::swap(matrix[0][1], matrix[2][1]);
    std::swap(matrix[0][1], matrix[1][0]);
    return matrix;
}

int**& ModelRubik_Matrix::rotateMatrixCounterClockwise(int**& matrix)
{
    std::swap(matrix[0][0], matrix[2][0]);
    std::swap(matrix[0][0], matrix[2][2]);
    std::swap(matrix[0][0], matrix[0][2]);

    std::swap(matrix[0][1], matrix[1][0]);
    std::swap(matrix[0][1], matrix[2][1]);
    std::swap(matrix[0][1], matrix[1][2]);
    return matrix;
}

void ModelRubik_Matrix::rotateFaceClockwise(int**& front, int**& up, int**& down, int**& left, int**& right)
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

    rotateMatrixClockwise(front);
}

void ModelRubik_Matrix::rotateFaceCounterClockwise(int**& front, int**& up, int**& down, int**& left, int**& right)
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

    rotateMatrixCounterClockwise(front);
}

void ModelRubik_Matrix::rotateFrontClockwise()
{
    rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::rotateFrontCounterClockwise()
{
    rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::rotateBackClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
    rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
}

void ModelRubik_Matrix::rotateBackCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
    rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
}

void ModelRubik_Matrix::rotateUpClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::rotateUpCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::rotateDownClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::rotateDownCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Right)]);
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
}

void ModelRubik_Matrix::rotateLeftClockwise()
{
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::rotateLeftCounterClockwise()
{
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Back)], _matrix[static_cast<int>(RubikFace::Front)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::rotateRightClockwise()
{
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    rotateFaceClockwise(_matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::rotateRightCounterClockwise()
{
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    rotateFaceCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)], _matrix[static_cast<int>(RubikFace::Up)], _matrix[static_cast<int>(RubikFace::Down)], _matrix[static_cast<int>(RubikFace::Front)], _matrix[static_cast<int>(RubikFace::Back)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
}

void ModelRubik_Matrix::rotateXAxisClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]));
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    int **aux = _matrix[static_cast<int>(RubikFace::Front)];
    _matrix[static_cast<int>(RubikFace::Front)] = _matrix[static_cast<int>(RubikFace::Down)];
    _matrix[static_cast<int>(RubikFace::Down)] = _matrix[static_cast<int>(RubikFace::Back)];
    _matrix[static_cast<int>(RubikFace::Back)] = _matrix[static_cast<int>(RubikFace::Up)];
    _matrix[static_cast<int>(RubikFace::Up)] = aux;
}

void ModelRubik_Matrix::rotateXAxisCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]));
    rotateMatrixClockwise(rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]));
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    int **aux = _matrix[static_cast<int>(RubikFace::Front)];
    _matrix[static_cast<int>(RubikFace::Front)] = _matrix[static_cast<int>(RubikFace::Up)];
    _matrix[static_cast<int>(RubikFace::Up)] = _matrix[static_cast<int>(RubikFace::Back)];
    _matrix[static_cast<int>(RubikFace::Back)] = _matrix[static_cast<int>(RubikFace::Down)];
    _matrix[static_cast<int>(RubikFace::Down)] = aux;
}

void ModelRubik_Matrix::rotateYAxisClockwise()
{
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    int **aux = _matrix[static_cast<int>(RubikFace::Front)];
    _matrix[static_cast<int>(RubikFace::Front)] = _matrix[static_cast<int>(RubikFace::Right)];
    _matrix[static_cast<int>(RubikFace::Right)] = _matrix[static_cast<int>(RubikFace::Back)];
    _matrix[static_cast<int>(RubikFace::Back)] = _matrix[static_cast<int>(RubikFace::Left)];
    _matrix[static_cast<int>(RubikFace::Left)] = aux;
}

void ModelRubik_Matrix::rotateYAxisCounterClockwise()
{
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    int **aux = _matrix[static_cast<int>(RubikFace::Front)];
    _matrix[static_cast<int>(RubikFace::Front)] = _matrix[static_cast<int>(RubikFace::Left)];
    _matrix[static_cast<int>(RubikFace::Left)] = _matrix[static_cast<int>(RubikFace::Back)];
    _matrix[static_cast<int>(RubikFace::Back)] = _matrix[static_cast<int>(RubikFace::Right)];
    _matrix[static_cast<int>(RubikFace::Right)] = aux;
}

void ModelRubik_Matrix::rotateZAxisClockwise()
{
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Front)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Back)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    int **aux = _matrix[static_cast<int>(RubikFace::Up)];
    _matrix[static_cast<int>(RubikFace::Up)] = _matrix[static_cast<int>(RubikFace::Left)];
    _matrix[static_cast<int>(RubikFace::Left)] = _matrix[static_cast<int>(RubikFace::Down)];
    _matrix[static_cast<int>(RubikFace::Down)] = _matrix[static_cast<int>(RubikFace::Right)];
    _matrix[static_cast<int>(RubikFace::Right)] = aux;
}

void ModelRubik_Matrix::rotateZAxisCounterClockwise()
{
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Front)]);
    rotateMatrixClockwise(_matrix[static_cast<int>(RubikFace::Back)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Left)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Up)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Right)]);
    rotateMatrixCounterClockwise(_matrix[static_cast<int>(RubikFace::Down)]);
    int **aux = _matrix[static_cast<int>(RubikFace::Up)];
    _matrix[static_cast<int>(RubikFace::Up)] = _matrix[static_cast<int>(RubikFace::Right)];
    _matrix[static_cast<int>(RubikFace::Right)] = _matrix[static_cast<int>(RubikFace::Down)];
    _matrix[static_cast<int>(RubikFace::Down)] = _matrix[static_cast<int>(RubikFace::Left)];
    _matrix[static_cast<int>(RubikFace::Left)] = aux;
}
