#ifndef CUBIEFACTORY_H
#define CUBIEFACTORY_H

#include "./View3DHeaders/icubie.h"
#include "rubikcorner.h"
#include "rubikedge.h"
#include "rubikface.h"
#include "./View3DHeaders/corner3d.h"
#include "./View3DHeaders/edge3d.h"
#include "./View3DHeaders/centre3d.h"

#include <Qt3DCore>

class CubieFactory {
public:
    CubieFactory(Qt3DCore::QEntity *rootEntity);
    ICubie* getCornerCubie(int index,Corner corner,CornerOrientation cornerOrient);
    ICubie* getEdgeCubie(int index,Edge edge,EdgeOrientation edgeOrient);
    ICubie* getCentreCubie(int index,RubikFace centre);

    Qt3DCore::QEntity *m_rootEntity;


};
#endif // CUBIEFACTORY_H
