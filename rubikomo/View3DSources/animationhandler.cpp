#include "./View3DHeaders/animationhandler.h"

AnimationHandler::AnimationHandler(Qt3DCore::QTransform *cuboidTransform, bool isCorner)
{
    m_XOrbitTransform = new XOrbitTransformController(cuboidTransform,isCorner);
    m_YOrbitTransform = new YOrbitTransformController(cuboidTransform,isCorner);
    m_ZOrbitTransform = new ZOrbitTransformController(cuboidTransform,isCorner);

    m_XOrbitTransform->setTarget(cuboidTransform);
    m_YOrbitTransform->setTarget(cuboidTransform);
    m_ZOrbitTransform->setTarget(cuboidTransform);

    XAnim = new QPropertyAnimation( m_XOrbitTransform->target());
    YAnim = new QPropertyAnimation( m_YOrbitTransform->target());
    ZAnim = new QPropertyAnimation( m_ZOrbitTransform->target());

    XAnim->setTargetObject(m_XOrbitTransform);
    XAnim->setPropertyName("angle");
    XAnim->setDuration(1000);
    XAnim->setLoopCount(1);

    YAnim->setTargetObject(m_YOrbitTransform);
    YAnim->setPropertyName("angle");
    YAnim->setDuration(1000);
    YAnim->setLoopCount(1);

    ZAnim->setTargetObject(m_ZOrbitTransform);
    ZAnim->setPropertyName("angle");
    ZAnim->setDuration(1000);
    ZAnim->setLoopCount(1);

    //connect(XAnim, &QPropertyAnimation::finished,
     //                m_view3D, &View3D::onAnimationEnded);
}

void AnimationHandler::startXAxisClockAnim()
{

    m_XOrbitTransform->updateAngle();

    XAnim->setStartValue(m_XOrbitTransform->angle() );

    XAnim->setEndValue(m_XOrbitTransform->angle() - 90);

    XAnim->start();
}

void AnimationHandler::startXAxisCClockAnim()
{

    m_XOrbitTransform->updateAngle();

    XAnim->setStartValue(m_XOrbitTransform->angle() );

    XAnim->setEndValue(m_XOrbitTransform->angle() + 90);

    XAnim->start();
}

void AnimationHandler::startYAxisClockAnim()
{

    m_YOrbitTransform->updateAngle();

    YAnim->setStartValue(m_YOrbitTransform->angle() );

    YAnim->setEndValue(m_YOrbitTransform->angle() - 90);

    YAnim->start();
}

void AnimationHandler::startYAxisCClockAnim()
{
    m_YOrbitTransform->updateAngle();

    YAnim->setStartValue(m_YOrbitTransform->angle() );

    YAnim->setEndValue(m_YOrbitTransform->angle() + 90);

    YAnim->start();
}

void AnimationHandler::startZAxisClockAnim()
{
    m_ZOrbitTransform->updateAngle();

    ZAnim->setStartValue(m_ZOrbitTransform->angle() );

    ZAnim->setEndValue(m_ZOrbitTransform->angle() - 90);

    ZAnim->start();
}

void AnimationHandler::startZAxisCClockAnim()
{
    m_ZOrbitTransform->updateAngle();

    ZAnim->setStartValue(m_ZOrbitTransform->angle() );

    ZAnim->setEndValue(m_ZOrbitTransform->angle() + 90);

    ZAnim->start();
}

XOrbitTransformController *AnimationHandler::XOrbitTransform() const
{
    return m_XOrbitTransform;
}

YOrbitTransformController *AnimationHandler::YOrbitTransform() const
{
    return m_YOrbitTransform;
}

ZOrbitTransformController *AnimationHandler::ZOrbitTransform() const
{
    return m_ZOrbitTransform;
}
