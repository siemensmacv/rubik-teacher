#ifndef CENTRE_H
#define CENTRE_H

#include "View3DHeaders/cubie.h"
#include "View3DHeaders/plane.h"

class Centre : public Cubie
{
public:
    Centre();
private:
    Plane *m_plane;
};
#endif // CENTRE_H
