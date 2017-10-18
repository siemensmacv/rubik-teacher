#include "./View3DHeaders/animationhandler.h"

AnimationHandler::AnimationHandler(){

}

AnimationHandler::AnimationHandler(Qt3DCore::QTransform *cuboidTransform):
    m_cuboidTransform(cuboidTransform)
{

}
