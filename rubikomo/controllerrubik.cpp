#include "controllerrubik.h"

ControllerRubik::ControllerRubik(QObject *parent) : QObject(parent)
{

}

int ControllerRubik::getMatrixValue(const RubikFace &face, const int &row, const int &column) const
{
    model.matrix.getMatrixValue(face, row, column);
}

void ControllerRubik::setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value)
{
    model.matrix.setMatrixValue(face, row, column, value);
}

void ControllerRubik::rotateFaceClockwise(const RubikFace &face)
{
    model.matrix.rotateFaceClockwise(face);
}

void ControllerRubik::rotateFaceCounterClockwise(const RubikFace &face)
{
    model.matrix.rotateFaceCounterClockwise(face);
}

void ControllerRubik::rotateXAxisClockwise()
{
    model.matrix.rotateXAxisClockwise();
}

void ControllerRubik::rotateXAxisCounterClockwise()
{
    model.matrix.rotateXAxisCounterClockwise();
}

void ControllerRubik::rotateYAxisClockwise()
{
    model.matrix.rotateYAxisClockwise();
}

void ControllerRubik::rotateYAxisCounterClockwise()
{
    model.matrix.rotateYAxisCounterClockwise();
}

void ControllerRubik::rotateZAxisClockwise()
{
    model.matrix.rotateZAxisClockwise();
}

void ControllerRubik::rotateZAxisCounterClockwise()
{
    model.matrix.rotateZAxisCounterClockwise();
}
