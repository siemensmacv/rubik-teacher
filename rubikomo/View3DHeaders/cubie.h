#ifndef CUBIE_H
#define CUBIE_H

#include "./View3DHeaders/cuboid.h"
#include "./View3DHeaders/icubie.h"

class Cubie : public ICubie{
public:
    Cubie();
private:
    Cuboid *m_cuboid;
};
#endif // CUBIE_H
