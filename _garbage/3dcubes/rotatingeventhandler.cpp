#include "rotatingeventhandler.h"

RotatingEventHandler::RotatingEventHandler(QPushButton *buton, QPushButton *buton2, OrbitTransformController *cube2)
    : m_button{buton}, m_button2{buton2}, cube2controller{cube2}
{
}

void RotatingEventHandler::addAnimation(QPropertyAnimation *anim)
{
    if (!vectAnimation.contains(anim))
        vectAnimation.push_back(anim);
}

void RotatingEventHandler::buttonPressed()
{
    m_button->setEnabled(false);
    m_button2->setEnabled(false);
    for (auto animation : vectAnimation)
    {
        cube2controller->setAngle(static_cast<int>(cube2controller->angle()) % 360);
        animation->setStartValue(QVariant::fromValue(cube2controller->angle()));
        animation->setEndValue(QVariant::fromValue(cube2controller->angle() + 90));
        animation->start();
    }
}

void RotatingEventHandler::button2Pressed()
{
    m_button->setEnabled(false);
    m_button2->setEnabled(false);
    for (auto animation : vectAnimation)
    {
        cube2controller->setAngle(static_cast<int>(cube2controller->angle()) % 360);
        animation->setStartValue(QVariant::fromValue(cube2controller->angle()));
        animation->setEndValue(QVariant::fromValue(cube2controller->angle() - 90));
        animation->start();
    }
}

void RotatingEventHandler::animationEnded()
{
    m_button->setEnabled(true);
    m_button2->setEnabled(true);
}
