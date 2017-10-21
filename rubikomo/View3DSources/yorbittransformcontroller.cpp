#include "./View3DHeaders/yorbittransformcontroller.h"

YOrbitTransformController::YOrbitTransformController(QObject *parent, bool isCorner)
    : OrbitTransformController(parent,isCorner)
{

}

void YOrbitTransformController::updateAngle()
{
    int scale = 1;

    int x =static_cast<int>(m_target->translation().x());
    int y =static_cast<int>(m_target->translation().y());
    int z =static_cast<int>(m_target->translation().z());

    if (y == scale)
    {
        if (x == scale && z == 0.0f)
            m_angle = 0.0f;

        if (x == scale && z == -scale)
            m_angle = 45.0f;

        if (x == 0.0f && z == -scale)
            m_angle = 90.0f;

        if (x == -scale && z == -scale)
            m_angle = 135.0f;

        if (x == -scale && z == 0.0f)
            m_angle = 180.0f;

        if (x == -scale && z == scale)
            m_angle = 225.0f;

        if (x == 0.0f && z == scale)
            m_angle = 270.0f;

        if (x == scale && z == scale)
            m_angle = 315.0f;
    }

    if (y == -scale)
    {
        if (x == -scale && z == 0.0f)
            m_angle = 0.0f;

        if (x == -scale && z == -scale)
            m_angle = 45.0f;

        if (x == 0.0f && z == -scale)
            m_angle = 90.0f;

        if (x == scale && z == -scale)
            m_angle = 135.0f;

        if (x == scale && z == 0.0f)
            m_angle = 180.0f;

        if (x == scale && z == scale)
            m_angle = 225.0f;

        if (x == 0.0f && z == scale)
            m_angle = 270.0f;

        if (x == -scale && z == scale)
            m_angle = 315.0f;
    }

}

void YOrbitTransformController::updateMatrix()
{
    QMatrix4x4 matrix = getCentreMatrix();

    float relativeRadius = m_radius;
    float relativeVectorAxis = 1.0f;

    if (m_target->translation().y() > 0)
    {
        //up
        matrix.rotate(m_angle, QVector3D( 0.0f, relativeVectorAxis, 0.0f));
        matrix.translate(relativeRadius, 0.0f, 0.0f);
        if(m_isCorner)
            matrix.rotate(45, QVector3D( 0.0f, relativeVectorAxis, 0.0f));
    }
    else
    {
        //down
        matrix.rotate(m_angle, QVector3D(0.0f, -relativeVectorAxis, 0.0f));
        matrix.translate(-relativeRadius, 0.0f, 0.0f);
        if(m_isCorner)
            matrix.rotate(45, QVector3D( 0.0f, -relativeVectorAxis, 0.0f));
    }

    m_target->setMatrix(matrix);
}

QMatrix4x4 YOrbitTransformController::getCentreMatrix()
{
    QMatrix4x4 matrix;
    matrix.translate(0.0f, m_target->translation().y(), 0.0f);
    return matrix;
}
