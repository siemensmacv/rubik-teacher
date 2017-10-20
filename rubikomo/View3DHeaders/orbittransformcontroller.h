#ifndef ORBITTRANSFORMCONTROLLER_H
#define ORBITTRANSFORMCONTROLLER_H

#include <QObject>
#include <QMatrix4x4>

#include <Qt3DCore>

class OrbitTransformController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Qt3DCore::QTransform* target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(float radius READ radius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(float angle READ angle WRITE setAngle NOTIFY angleChanged)

public:
    OrbitTransformController(QObject *parent = 0);

    void setTarget(Qt3DCore::QTransform *target);
    Qt3DCore::QTransform *target() const;

    void setRadius(float radius);
    float radius() const;

    void setAngle(float angle);
    float angle() const;

    virtual void updateAngle() = 0;

signals:
    void targetChanged();
    void radiusChanged();
    void angleChanged();

protected:
    virtual QMatrix4x4 getCentreMatrix() = 0;
    virtual void updateMatrix() = 0;


    Qt3DCore::QTransform *m_target;
    float m_radius;
    float m_angle;
};

#endif // ORBITTRANSFORMCONTROLLER_H
