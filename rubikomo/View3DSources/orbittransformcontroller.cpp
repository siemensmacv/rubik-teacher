#include "./View3DHeaders/orbittransformcontroller.h"

OrbitTransformController::OrbitTransformController(QObject *parent)
    : QObject(parent)
    , m_target(nullptr)
    , m_matrix()
    , m_radius(1.0f)
    , m_angle(0.0f)
{
}

void OrbitTransformController::setTarget(Qt3DCore::QTransform *target)
{
    if (m_target != target) {
        m_target = target;
        emit targetChanged();
    }
}

Qt3DCore::QTransform *OrbitTransformController::target() const
{
    return m_target;
}

void OrbitTransformController::setRadius(float radius)
{
    if (!qFuzzyCompare(radius, m_radius)) {
        m_radius = radius;
        updateMatrix();
        emit radiusChanged();
    }
}

float OrbitTransformController::radius() const
{
    return m_radius;
}

void OrbitTransformController::setAngle(float angle)
{
    if (!qFuzzyCompare(angle, m_angle)) {
        m_angle = angle;
        updateMatrix();
        emit angleChanged();
    }
}

float OrbitTransformController::angle() const
{
    return m_angle;
}

void OrbitTransformController::setPreviousMatrix(const QMatrix4x4 &previousMatrix)
{
    if (m_previousMatrix != previousMatrix)
        m_previousMatrix = previousMatrix;
}

QMatrix4x4 OrbitTransformController::previousMatrix() const
{
    return m_previousMatrix;
}

void OrbitTransformController::updateMatrix()
{
    m_matrix.setToIdentity();
    m_matrix.rotate(m_angle, QVector3D(0.0f, 0.0f, 1.0f));
    m_matrix.translate(m_radius, 0.0f, 0.0f);
    m_target->setMatrix(m_matrix);
}