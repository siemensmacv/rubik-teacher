#ifndef AXISFACTORY_H
#define AXISFACTORY_H
#include <map>
#include "rubikface.h"
#include "rubikcorner.h"
#include "rubikedge.h"
#include <QVector3D>
#include <utility>

class AxisFactory{
public:
    AxisFactory();

    QString getKey(RubikFace face,Corner corner,CornerOrientation cOrient);
    QString getKey(RubikFace face,Edge edge,EdgeOrientation eOrient);

    void addMapEntry(RubikFace face,Corner corner,CornerOrientation cOrient,QVector3D vect);
    void addMapEntry(RubikFace face,Edge edge,EdgeOrientation eOrient,QVector3D vect);

    static std::map<QString,QVector3D> axisMap;

};
#endif // AXISFACTORY_H
