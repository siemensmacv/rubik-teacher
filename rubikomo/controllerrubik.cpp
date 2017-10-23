#include "controllerrubik.h"

ControllerRubik::ControllerRubik(QObject *parent) : QObject(parent)
{

}

void ControllerRubik::setModel(std::string input)
{
    model.setModel(input);
}

std::string ControllerRubik::getModel()
{
    return model.getModel();
}

int ControllerRubik::getMatrixValue(const RubikFace &face, const int &row, const int &column) const
{
    return model.getMatrixValue(face, row, column);
}

void ControllerRubik::rotateFaceClockwise(const RubikFace &face)
{
    model.rotateFaceClockwise(face);
}

void ControllerRubik::rotateFaceCounterClockwise(const RubikFace &face)
{
    model.rotateFaceCounterClockwise(face);
}

void ControllerRubik::rotateXAxisClockwise()
{
    model.rotateXAxisClockwise();
}

void ControllerRubik::rotateXAxisCounterClockwise()
{
    model.rotateXAxisCounterClockwise();
}

void ControllerRubik::rotateYAxisClockwise()
{
    model.rotateYAxisClockwise();
}

void ControllerRubik::rotateYAxisCounterClockwise()
{
    model.rotateYAxisCounterClockwise();
}

void ControllerRubik::rotateZAxisClockwise()
{
    model.rotateZAxisClockwise();
}

void ControllerRubik::rotateZAxisCounterClockwise()
{
    model.rotateZAxisCounterClockwise();
}
