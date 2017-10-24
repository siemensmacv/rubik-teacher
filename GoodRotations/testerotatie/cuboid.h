#ifndef CUBOID_H
#define CUBOID_H

#include <Qt3DExtras>
#include <Qt3DCore>
#include <QPropertyAnimation>
#include <QObject>
#include "axishandler.h"

class Cuboid : public QObject
{
    Q_OBJECT
public:
    Cuboid(Qt3DCore::QEntity *);

    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity *m_cuboidEntity;
    Qt3DCore::QTransform *m_cuboidTransform;
    Qt3DExtras::QPhongMaterial *m_cuboidMaterial;

    AxisHandler *relativeAxis;
    Qt3DExtras::QCuboidMesh *m_cuboidMesh;



public slots:
    void newTranslation();

};

#endif // CUBOID_H
