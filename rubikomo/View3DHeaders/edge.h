#ifndef EDGE_H
#define EDGE_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Edge : public Cubie
{
public:
    Edge();
private:
    Plane *m_plane,*m_plane2;
};
#endif // EDGE_H
