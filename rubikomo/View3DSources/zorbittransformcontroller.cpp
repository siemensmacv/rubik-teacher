#include "./View3DHeaders/zorbittransformcontroller.h"

ZOrbitTransformController::ZOrbitTransformController(QObject *parent, bool isCorner)
    : OrbitTransformController(parent,isCorner), m_zRotationAngle(0.0f)
{

}

void ZOrbitTransformController::updateAngle()
{
    int scale = 1;

    int x =static_cast<int>(m_target->translation().x());
    int y =static_cast<int>(m_target->translation().y());
    int z =static_cast<int>(m_target->translation().z());

    if ( z  == scale)
    {
        if ( y  == 0.0f &&  x  == scale)
            m_angle = 0.0f;

        if ( y  == scale &&  x  == scale)
            m_angle = 45.0f;

        if ( y  == scale &&  x  == 0.0f)
            m_angle = 90.0f;

        if ( y  == scale &&  x  == -scale)
            m_angle = 135.0f;

        if ( y  == 0.0f &&  x  == -scale)
            m_angle = 180.0f;

        if ( y  == -scale &&  x  == -scale)
            m_angle = 225.0f;

        if ( y  == -scale &&  x  == 0.0f)
            m_angle = 270.0f;

        if ( y  == -scale &&  x  == scale)
            m_angle = 315.0f;
    }

    if ( z  == -scale)
    {
        if ( y  == 0.0f &&  x  == -scale)
            m_angle = 0.0f;

        if ( y  == scale &&  x  == -scale)
            m_angle = 45.0f;

        if ( y  == scale &&  x  == 0.0f)
            m_angle = 90.0f;

        if ( y  == scale &&  x  == scale)
            m_angle = 135.0f;

        if ( y  == 0.0f &&  x  == scale)
            m_angle = 180.0f;

        if ( y  == -scale &&  x  == scale)
            m_angle = 225.0f;

        if ( y  == -scale &&  x  == 0.0f)
            m_angle = 270.0f;

        if ( y  == -scale &&  x  == -scale)
            m_angle = 315.0f;
    }

}

void ZOrbitTransformController::updateMatrix()
{
    QMatrix4x4 matrix = getCentreMatrix();

    float relativeRadius = m_radius;
    float relativeVectorAxis = 1.0f;
    float radians = qDegreesToRadians(m_angle);

    if (m_target->translation().z() > 0)
    {
        //front
        //matrix.rotate(m_angle, QVector3D(0.0f, 0.0f, relativeVectorAxis));
        //matrix.translate(relativeRadius, 0.0f,0.0f );
        //ajustare de 45 pe colturi
        //if(m_isCorner)
            //matrix.rotate(45.0f, QVector3D(0.0f, 0.0f, relativeVectorAxis));
        matrix.translate(static_cast<float>(qCos(radians)) * relativeRadius,
                         static_cast<float>(qSin(radians)) * relativeRadius,
                          0.0f);
        m_zRotationAngle += m_angleDifference;
        matrix.rotate(m_zRotationAngle, QVector3D(0.0f, 0.0f, relativeVectorAxis));
    }
    else
    {
        //back
        //matrix.rotate(m_angle, QVector3D(0.0f, 0.0f, -relativeVectorAxis));
        //matrix.translate(-relativeRadius, 0.0f, 0.0f);
        //if(m_isCorner)
            //matrix.rotate(45.0f, QVector3D(0.0f, 0.0f, -relativeVectorAxis));
        matrix.translate(static_cast<float>(qCos(radians)) * (-relativeRadius),
                         static_cast<float>(qSin(radians)) * relativeRadius,
                          0.0f);
        m_zRotationAngle += m_angleDifference;
        matrix.rotate(m_zRotationAngle, QVector3D(0.0f, 0.0f, -relativeVectorAxis));
    }

    m_target->setMatrix(matrix);
}

QMatrix4x4 ZOrbitTransformController::getCentreMatrix()
{
    QMatrix4x4 matrix;
    matrix.translate(0.0f, 0.0f, m_target->translation().z());
    return matrix;
}
