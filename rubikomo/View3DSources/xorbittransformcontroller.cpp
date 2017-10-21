#include "./View3DHeaders/xorbittransformcontroller.h"

XOrbitTransformController::XOrbitTransformController(QObject *parent, bool isCorner)
    : OrbitTransformController(parent,isCorner)
{

}

void XOrbitTransformController::updateAngle()
{
    float scale = 1.1f;

    float x = m_target->translation().x();
    float y = m_target->translation().y();
    float z = m_target->translation().z();

    if (qFuzzyCompare(x, scale))
    {
        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(z, -scale))
            m_angle = 0.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(z, -scale))
            m_angle = 45.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(z, 0.0f))
            m_angle = 90.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(z, scale))
            m_angle = 135.0f;

        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(z, scale))
            m_angle = 180.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, scale))
            m_angle = 225.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, 0.0f))
            m_angle = 270.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, -scale))
            m_angle = 315.0f;
    }

    if (qFuzzyCompare(x, -scale))
    {
        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(z, scale))
            m_angle = 0.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(z, scale))
            m_angle = 45.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(z, 0.0f))
            m_angle = 90.0f;

        if (qFuzzyCompare(y, scale) && qFuzzyCompare(z, -scale))
            m_angle = 135.0f;

        if (qFuzzyCompare(y, 0.0f) && qFuzzyCompare(z, -scale))
            m_angle = 180.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, -scale))
            m_angle = 225.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, 0.0f))
            m_angle = 270.0f;

        if (qFuzzyCompare(y, -scale) && qFuzzyCompare(z, scale))
            m_angle = 315.0f;
    }

}

void XOrbitTransformController::updateMatrix()
{
    QMatrix4x4 matrix = getCentreMatrix();

    float relativeRadius = m_radius;
    float relativeVectorAxis = 1.0f;

    if (m_target->translation().x() > 0)
    {
        //right
        matrix.rotate(m_angle, QVector3D(relativeVectorAxis, 0.0f, 0.0f));
        matrix.translate(0.0f, 0.0f, -relativeRadius);
        if(m_isCorner)
            matrix.rotate(45, QVector3D(relativeVectorAxis, 0.0f, 0.0f));
    }
    else
    {
        //left
        matrix.rotate(m_angle, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
        matrix.translate(0.0f, 0.0f, relativeRadius);
        if(m_isCorner)
            matrix.rotate(45, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
    }

    m_target->setMatrix(matrix);
}

QMatrix4x4 XOrbitTransformController::getCentreMatrix()
{
    QMatrix4x4 matrix;
    matrix.translate(m_target->translation().x(), 0.0f, 0.0f);
    return matrix;
}
