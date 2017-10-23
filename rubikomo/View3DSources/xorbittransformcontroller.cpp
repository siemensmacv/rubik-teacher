#include "./View3DHeaders/xorbittransformcontroller.h"

XOrbitTransformController::XOrbitTransformController(QObject *parent, bool isCorner)
    : OrbitTransformController(parent,isCorner), m_xRotationAngle(0.0f)
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
    float radians = qDegreesToRadians(m_angle);

    if (m_target->translation().x() > 0)
    {
        //right
        //matrix.rotate(m_angle, QVector3D(relativeVectorAxis, 0.0f, 0.0f));
        //matrix.translate(0.0f, 0.0f, -relativeRadius);

        //if(m_isCorner)
        //    matrix.rotate(45, QVector3D(relativeVectorAxis, 0.0f, 0.0f));
        // no matrix.rotate(-m_angle, QVector3D(relativeVectorAxis, 0.0f, 0.0f));
        //matrix = Qt3DCore::QTransform::rotateAround(QVector3D(1.0f, 0.0f, 0.0f),
        //m_angle,QVector3D(relativeVectorAxis, 0.0f, 0.0f));
        //matrix.translate(1.1f, 0.0f, -relativeRadius);
        //if(m_isCorner)
            //matrix.rotate(-45, QVector3D(relativeVectorAxis, 0.0f, 0.0f));
        matrix.translate(0.0f,
                         static_cast<float>(qSin(radians)) * relativeRadius,
                         static_cast<float>(qCos(radians)) * (-relativeRadius) );
        m_xRotationAngle += m_angleDifference;
        matrix.rotate(m_xRotationAngle, QVector3D(relativeVectorAxis, 0.0f, 0.0f));

    }
    else
    {
        //left
        //matrix.rotate(m_angle, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
        //matrix.translate(0.0f, 0.0f, relativeRadius);
        //if(m_isCorner)
        //    matrix.rotate(45, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
        // no matrix.rotate(-m_angle, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
        //matrix = Qt3DCore::QTransform::rotateAround(QVector3D(-1.0f, 0.0f, 0.0f),
        //m_angle,QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
        //matrix.translate(-1.1f, 0.0f, relativeRadius);
        //if(m_isCorner)
            //matrix.rotate(-45, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));
        matrix.translate(0.0f,
                         static_cast<float>(qSin(radians)) * relativeRadius,
                         static_cast<float>(qCos(radians)) * relativeRadius );
        m_xRotationAngle += m_angleDifference;
        matrix.rotate(m_xRotationAngle, QVector3D(-relativeVectorAxis, 0.0f, 0.0f));

    }

    m_target->setMatrix(matrix);
}

QMatrix4x4 XOrbitTransformController::getCentreMatrix()
{
    QMatrix4x4 matrix;
    matrix.translate(m_target->translation().x(), 0.0f, 0.0f);
    return matrix;
}
