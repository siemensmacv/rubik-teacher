#include "controllerrubik.h"

ControllerRubik::ControllerRubik(QObject *parent) : QObject(parent)
{

}

void ControllerRubik::setView3D(View3D *view3D)
{
    m_view3D = view3D;
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
    switch(face){
    case RubikFace::Back:
        m_view3D->BackC();
        break;
    case RubikFace::Up:
        m_view3D->UpC();
        break;
    case RubikFace::Down:
        m_view3D->DownC();
        break;
    case RubikFace::Front:
        m_view3D->FrontC();
        break;
    case RubikFace::Left:
        m_view3D->LeftC();
        break;
    case RubikFace::Right:
        m_view3D->RightC();
        break;
    }
}

void ControllerRubik::rotateFaceCounterClockwise(const RubikFace &face)
{
    model.rotateFaceCounterClockwise(face);
    switch(face){
    case RubikFace::Back:
        m_view3D->BackCC();
        break;
    case RubikFace::Up:
        m_view3D->UpCC();
        break;
    case RubikFace::Down:
        m_view3D->DownCC();
        break;
    case RubikFace::Front:
        m_view3D->FrontCC();
        break;
    case RubikFace::Left:
        m_view3D->LeftCC();
        break;
    case RubikFace::Right:
        m_view3D->RightCC();
        break;
    }
}

//void ControllerRubik::rotateFaceClockwiseFrom3D(const RubikFace &face)
//{
//    model.rotateFaceClockwise(face);

//}

//void ControllerRubik::rotateFaceCounterClockwiseFrom3D(const RubikFace &face)
//{
//    model.rotateFaceCounterClockwise(face);
//}
