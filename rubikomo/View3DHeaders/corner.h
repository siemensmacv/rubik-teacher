#ifndef CORNER_H
#define CORNER_H

#include "./View3DHeaders/cubie.h"
#include "./View3DHeaders/plane.h"

class Corner : public Cubie
{
public:
      Corner();
private:
      Plane *m_plane,m_plane2,*m_plane3;
};
#endif // CORNER_H
