#include "axisfactory.h"

AxisFactory::AxisFactory()
{
   addMapEntry(RubikFace::Right,Edge::RF,EdgeOrientation::Normal,QVector3D(0.0f,0.0f,-1.0f));
   addMapEntry(RubikFace::Left,Edge::RF,EdgeOrientation::Normal,QVector3D(0.0f,0.0f,-1.0f));

   addMapEntry(RubikFace::Front,Edge::RF,EdgeOrientation::Normal,QVector3D(-1.0f,0.0f,0.0f));
   addMapEntry(RubikFace::Back,Edge::RF,EdgeOrientation::Normal,QVector3D(-1.0f,0.0f,0.0f));

   addMapEntry(RubikFace::Up,Edge::RF,EdgeOrientation::Normal,QVector3D());
   addMapEntry(RubikFace::Down,Edge::RF,EdgeOrientation::Normal,QVector3D());

}

void AxisFactory::addMapEntry(RubikFace face, Corner corner, CornerOrientation cOrient, QVector3D vect)
{
    axisMap.insert(std::make_pair(getKey(face,corner,cOrient),vect));
}
