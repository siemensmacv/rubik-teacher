#include "./View3DHeaders/zorbittransformcontroller.h"

ZOrbitTransformController::ZOrbitTransformController(QObject *parent)
    : OrbitTransformController(parent)
{

}

void ZOrbitTransformController::updateAngle()
{
    float scale = 1.1f;

    float x = m_target->translation().x();
    float y = m_target->translation().y();
    float z = m_target->translation().z();

    if (qFuzzyCompare(z, scale))
    {
        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(x, scale))
            m_angle = 0.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(x, scale))
            m_angle = 45.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(x, 0.0f))
            m_angle = 90.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(x, -scale))
            m_angle = 135.0f;

        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(x, -scale))
            m_angle = 180.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(x, -scale))
            m_angle = 225.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(x, 0.0f))
            m_angle = 270.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, -scale))
            m_angle = 315.0f;
    }

    if (qFuzzyCompare(z, -scale))
    {
        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(x, -scale))
            m_angle = 0.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(x, -scale))
            m_angle = 45.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(x, 0.0f))
            m_angle = 90.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(x, scale))
            m_angle = 135.0f;

        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(x, scale))
            m_angle = 180.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(x, scale))
            m_angle = 225.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(x, 0.0f))
            m_angle = 270.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(x, -scale))
            m_angle = 315.0f;
    }
}

void ZOrbitTransformController::updateMatrix()
{
    QMatrix4x4 matrix = getCentreMatrix();

    float relativeRadius = m_radius;
    float relativeVectorAxis = 1.0f;

    if (m_target->translation().z() > 0)
    {
        matrix.rotate(m_angle, QVector3D(0.0f, 0.0f, relativeVectorAxis));
        matrix.translate(relativeRadius, 0.0f,0.0f );
    }
    else
    {
        matrix.rotate(m_angle, QVector3D(0.0f, 0.0f, -relativeVectorAxis));
        matrix.translate(-relativeRadius, 0.0f, 0.0f);
    }

    m_target->setMatrix(matrix);
}

QMatrix4x4 ZOrbitTransformController::getCentreMatrix()
{
    QMatrix4x4 matrix;
    matrix.translate(0.0f, 0.0f, m_target->translation().z());
    return matrix;
}
