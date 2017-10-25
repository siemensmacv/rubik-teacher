#include "modelrubik.h"
#include "modelrubik_cornersedges.h"
#include "modelrubik_matrix.h"

ModelRubik::ModelRubik(QObject *parent) : QObject(parent)
{

}

ModelRubik_Matrix* ModelRubik::getMatrix()
{
    return &matrix;
}

void ModelRubik::rotateFaceClockwise(const RubikFace &face)
{
    matrix.rotateFaceClockwise(face);
    corners_edges.rotateFaceClockwise(face);
    emit cubeChanged();
}

void ModelRubik::rotateFaceCounterClockwise(const RubikFace &face)
{
    matrix.rotateFaceCounterClockwise(face);
    corners_edges.rotateFaceCounterClockwise(face);
    emit cubeChanged();
}

int ModelRubik::getMatrixValue(const RubikFace &face, const int &row, const int &column) const
{
    return matrix.getMatrixValue(face, row, column);
}

void ModelRubik::setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value)
{
    matrix.setMatrixValue(face, row, column, value);
    emit cubeChanged();
}

void ModelRubik::setModel(std::string input)
{
    matrix.setMatrix(input);
    corners_edges.setCornersEdges(input);
    emit cubeChanged();
}

std::string ModelRubik::getModel()
{
    return matrix.getMatrix();
}

void ModelRubik::rotateXAxisClockwise()
{
    matrix.rotateXAxisClockwise();
    emit cubeChanged();
}

void ModelRubik::rotateXAxisCounterClockwise()
{
    matrix.rotateXAxisCounterClockwise();
    emit cubeChanged();
}

void ModelRubik::rotateYAxisClockwise()
{
    matrix.rotateYAxisClockwise();
    emit cubeChanged();
}

void ModelRubik::rotateYAxisCounterClockwise()
{
    matrix.rotateYAxisCounterClockwise();
    emit cubeChanged();
}

void ModelRubik::rotateZAxisClockwise()
{
    matrix.rotateZAxisClockwise();
    emit cubeChanged();
}

void ModelRubik::rotateZAxisCounterClockwise()
{
    matrix.rotateZAxisCounterClockwise();
    emit cubeChanged();
}

Corner ModelRubik::getCorner(const Corner &position) const
{
    return corners_edges.getCorner(position);
}

CornerOrientation ModelRubik::getCornerOrientation(const Corner &position) const
{
    return corners_edges.getCornerOrientation(position);
}

Edge ModelRubik::getEdge(const Edge &position) const
{
    return corners_edges.getEdge(position);
}

EdgeOrientation ModelRubik::getEdgeOrientation(const Edge &position) const
{
    return corners_edges.getEdgeOrientation(position);
}

RubikFace ModelRubik::getCenter(const RubikFace &position) const
{
    return corners_edges.getCenter(position);
}
