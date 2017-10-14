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

    _front = _matrix[static_cast<int>(RubikFace::Front)];
    _back = _matrix[static_cast<int>(RubikFace::Back)];
    _left = _matrix[static_cast<int>(RubikFace::Left)];
    _right = _matrix[static_cast<int>(RubikFace::Right)];
    _up = _matrix[static_cast<int>(RubikFace::Up)];
    _down = _matrix[static_cast<int>(RubikFace::Down)];
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
    rotateFaceClockwise(_front, _up, _down, _left, _right);
}

void ModelRubik_Matrix::rotateFrontCounterClockwise()
{
    rotateFaceCounterClockwise(_front, _up, _down, _left, _right);
}

void ModelRubik_Matrix::rotateBackClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_up));
    rotateMatrixClockwise(rotateMatrixClockwise(_down));
    rotateFaceClockwise(_back, _up, _down, _right, _left);
    rotateMatrixClockwise(rotateMatrixClockwise(_up));
    rotateMatrixClockwise(rotateMatrixClockwise(_down));
}

void ModelRubik_Matrix::rotateBackCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_up));
    rotateMatrixClockwise(rotateMatrixClockwise(_down));
    rotateFaceCounterClockwise(_back, _up, _down, _right, _left);
    rotateMatrixClockwise(rotateMatrixClockwise(_up));
    rotateMatrixClockwise(rotateMatrixClockwise(_down));
}

void ModelRubik_Matrix::rotateUpClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixClockwise(_left);
    rotateMatrixCounterClockwise(_right);
    rotateFaceClockwise(_up, _back, _front, _left, _right);
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixCounterClockwise(_left);
    rotateMatrixClockwise(_right);
}

void ModelRubik_Matrix::rotateUpCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixClockwise(_left);
    rotateMatrixCounterClockwise(_right);
    rotateFaceCounterClockwise(_up, _back, _front, _left, _right);
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixCounterClockwise(_left);
    rotateMatrixClockwise(_right);
}

void ModelRubik_Matrix::rotateDownClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixCounterClockwise(_left);
    rotateMatrixClockwise(_right);
    rotateFaceClockwise(_down, _front, _back, _left, _right);
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixClockwise(_left);
    rotateMatrixCounterClockwise(_right);
}

void ModelRubik_Matrix::rotateDownCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixCounterClockwise(_left);
    rotateMatrixClockwise(_right);
    rotateFaceCounterClockwise(_down, _front, _back, _left, _right);
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixClockwise(_left);
    rotateMatrixCounterClockwise(_right);
}

void ModelRubik_Matrix::rotateLeftClockwise()
{
    rotateMatrixCounterClockwise(_up);
    rotateMatrixClockwise(_down);
    rotateFaceClockwise(_left, _up, _down, _back, _front);
    rotateMatrixClockwise(_up);
    rotateMatrixCounterClockwise(_down);
}

void ModelRubik_Matrix::rotateLeftCounterClockwise()
{
    rotateMatrixCounterClockwise(_up);
    rotateMatrixClockwise(_down);
    rotateFaceCounterClockwise(_left, _up, _down, _back, _front);
    rotateMatrixClockwise(_up);
    rotateMatrixCounterClockwise(_down);
}

void ModelRubik_Matrix::rotateRightClockwise()
{
    rotateMatrixClockwise(_up);
    rotateMatrixCounterClockwise(_down);
    rotateFaceClockwise(_right, _up, _down, _front, _back);
    rotateMatrixCounterClockwise(_up);
    rotateMatrixClockwise(_down);
}

void ModelRubik_Matrix::rotateRightCounterClockwise()
{
    rotateMatrixClockwise(_up);
    rotateMatrixCounterClockwise(_down);
    rotateFaceCounterClockwise(_right, _up, _down, _front, _back);
    rotateMatrixCounterClockwise(_up);
    rotateMatrixClockwise(_down);
}

void ModelRubik_Matrix::rotateXAxisClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_up));
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixCounterClockwise(_left);
    rotateMatrixClockwise(_right);
    int **aux = _front;
    _front = _down;
    _down = _back;
    _back = _up;
    _up = aux;
}

void ModelRubik_Matrix::rotateXAxisCounterClockwise()
{
    rotateMatrixClockwise(rotateMatrixClockwise(_back));
    rotateMatrixClockwise(rotateMatrixClockwise(_down));
    rotateMatrixClockwise(_left);
    rotateMatrixCounterClockwise(_right);
    int **aux = _front;
    _front = _up;
    _up = _back;
    _back = _down;
    _down = aux;
}

void ModelRubik_Matrix::rotateYAxisClockwise()
{
    rotateMatrixClockwise(_up);
    rotateMatrixCounterClockwise(_down);
    int **aux = _front;
    _front = _right;
    _right = _back;
    _back = _left;
    _left = aux;
}

void ModelRubik_Matrix::rotateYAxisCounterClockwise()
{
    rotateMatrixCounterClockwise(_up);
    rotateMatrixClockwise(_down);
    int **aux = _front;
    _front = _left;
    _left = _back;
    _back = _right;
    _right = aux;
}

void ModelRubik_Matrix::rotateZAxisClockwise()
{
    rotateMatrixClockwise(_front);
    rotateMatrixCounterClockwise(_back);
    rotateMatrixClockwise(_left);
    rotateMatrixClockwise(_up);
    rotateMatrixClockwise(_right);
    rotateMatrixClockwise(_down);
    int **aux = _up;
    _up = _left;
    _left = _down;
    _down = _right;
    _right = aux;
}

void ModelRubik_Matrix::rotateZAxisCounterClockwise()
{
    rotateMatrixCounterClockwise(_front);
    rotateMatrixClockwise(_back);
    rotateMatrixCounterClockwise(_left);
    rotateMatrixCounterClockwise(_up);
    rotateMatrixCounterClockwise(_right);
    rotateMatrixCounterClockwise(_down);
    int **aux = _up;
    _up = _right;
    _right = _down;
    _down = _left;
    _left = aux;
}
