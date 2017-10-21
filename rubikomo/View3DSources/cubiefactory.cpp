#include "./View3DHeaders/cubiefactory.h"


CubieFactory::CubieFactory(Qt3DCore::QEntity *rootEntity)
{
    m_rootEntity=rootEntity;
}

ICubie* CubieFactory::getCornerCubie(int index, Corner corner, CornerOrientation cornerOrient)
{
    Corner3D* newCorner = new Corner3D(m_rootEntity);
    float scale=1.1f;
    switch(index){
    case 0:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,scale,-scale));
        break;
    case 1:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,scale,scale));
        break;
    case 2:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,scale,scale));
        break;
    case 3:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,scale,-scale));
        break;
    case 4:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,-scale,-scale));
        break;
    case 5:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,-scale,scale));
        break;
    case 6:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,-scale,scale));
        break;
    case 7:
        newCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,-scale,-scale));
        break;
    };
    return newCorner;
}

ICubie *CubieFactory::getEdgeCubie(int index, Edge edge, EdgeOrientation edgeOrient)
{
    Edge3D* newEdge = new Edge3D(m_rootEntity);
    float scale=1.1f;
    switch(index){
    case 0:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,scale,-scale));
        break;
    case 1:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,scale,0.0f));
        break;
    case 2:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,scale,scale));
        break;
    case 3:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,scale,0.0f));
        break;
    case 4:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,0.0f,-scale));
        break;
    case 5:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,0.0f,scale));
        break;
    case 6:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,0.0f,scale));
        break;
    case 7:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,0.0f,-scale));
        break;
    case 8:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,-scale,-scale));
        break;
    case 9:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,-scale,0.0f));
        break;
    case 10:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,-scale,scale));
        break;
    case 11:
        newEdge->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,-scale,0.0f));
        break;
    };
    return newEdge;
}

ICubie *CubieFactory::getCentreCubie(int index, RubikFace centre)
{
    Centre3D* newCentre = new Centre3D(m_rootEntity);
    float scale=1.1f;
    switch(index){
    case 0:
        newCentre->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,scale));
        break;
    case 1:
        newCentre->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,0.0f,-scale));
        break;
    case 2:
        newCentre->cuboid()->shapeTransform()->setTranslation(QVector3D(-scale,0.0f,0.0f));
        break;
    case 3:
        newCentre->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,0.0f,0.0f));
        break;
    case 4:
        newCentre->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,scale,0.0f));
        break;
    case 5:
        newCentre->cuboid()->shapeTransform()->setTranslation(QVector3D(0.0f,-scale,0.0f));
        break;
    };
    return newCentre;
}
