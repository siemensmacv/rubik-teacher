#include "./View3DHeaders/cubiefactory.h"


CubieFactory::CubieFactory(Qt3DCore::QEntity *rootEntity)
{
    m_rootEntity=rootEntity;
}

ICubie* CubieFactory::getCornerCubie(int index, Corner corner, CornerOrientation cornerOrient)
{
    Corner3D* neCorner = new Corner3D(m_rootEntity);
    float scale=1.1f;
    switch(index){
    case 0:
        neCorner->cuboid()->shapeTransform()->setTranslation(QVector3D(scale,scale,-scale));
        break;

    };
    return (neCorner);
}
