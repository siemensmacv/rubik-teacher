#include "./View3DHeaders/xorbittransformcontroller.h"

XOrbitTransformController::XOrbitTransformController(QObject *parent, bool isCorner)
    : OrbitTransformController(parent,isCorner)
{

}

void XOrbitTransformController::updateAngle()
{
    int scale = 1;

    int x = static_cast<int>( m_target->translation().x());
    int y = static_cast<int>(  m_target->translation().y());
    int z = static_cast<int>( m_target->translation().z());

    if (x == scale)
    {
        if (y== 0.0f && z==-scale)
            m_angle = 0.0f;

        if (y==scale && z== -scale)
            m_angle = 45.0f;

        if (y== scale && z== 0.0f)
            m_angle = 90.0f;

        if (y== scale && z== scale)
            m_angle = 135.0f;

        if (y== 0.0f && z== scale)
            m_angle = 180.0f;

        if (y== -scale && z== scale)
            m_angle = 225.0f;

        if (y== -scale && z== 0.0f)
            m_angle = 270.0f;

        if (y== -scale && z== -scale)
            m_angle = 315.0f;
    }

    if (x== -scale)
    {
        if (y== 0.0f && z== scale)
            m_angle = 0.0f;

        if (y== scale && z== scale)
            m_angle = 45.0f;

        if (y== scale && z== 0.0f)
            m_angle = 90.0f;

        if (y== scale && z== -scale)
            m_angle = 135.0f;

        if (y== 0.0f && z== -scale)
            m_angle = 180.0f;

        if (y== -scale && z== -scale)
            m_angle = 225.0f;

        if (y== -scale && z== 0.0f)
            m_angle = 270.0f;

        if (y== -scale && z== scale)
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
    //matrix.translate(0.0f, -m_target->translation().y(), -m_target->translation().z());
    return matrix;
}
