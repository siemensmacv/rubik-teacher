#include "./View3DHeaders/animationhandler.h"

AnimationHandler::AnimationHandler(){

}

AnimationHandler::AnimationHandler(Qt3DCore::QTransform *cuboidTransform)
{

    XAnim = new QPropertyAnimation(m_orbitTransform->target());
    YAnim = new QPropertyAnimation(m_orbitTransform->target());
    ZAnim = new QPropertyAnimation(m_orbitTransform->target());
}

void AnimationHandler::startXAxisClockAnim()
{
    //xorbit.recalculateAngle()
    //anim start value(xorbit.getangle)
    //anim sttop value(angle + 90)
    //anim.start
}

void AnimationHandler::startXAxisCClockAnim()
{

}

void AnimationHandler::startYAxisClockAnim()
{

}

void AnimationHandler::startYAxisCClockAnim()
{

}

void AnimationHandler::startZAxisClockAnim()
{

}

void AnimationHandler::startZAxisCClockAnim()
{

}
