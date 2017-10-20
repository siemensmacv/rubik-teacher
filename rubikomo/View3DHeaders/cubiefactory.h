#ifndef CUBIEFACTORY_H
#define CUBIEFACTORY_H

#include "./View3DHeaders/icubie.h"
#include "rubikcorner.h"
#include "rubikedge.h"
#include "rubikface.h"

class CubieFactory {
public:
    static ICubie* getCornerCubie(int index,Corner corner,CornerOrientation cornerOrient);
    static ICubie* getEdgeCubie(int index,Edge edge,EdgeOrientation edgeOrient);
    static ICubie* getCentreCubie(int index,RubikFace centre);

};
#endif // CUBIEFACTORY_H
