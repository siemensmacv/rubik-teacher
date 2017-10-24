#include "./View3DHeaders/axishandler.h"

AxisHandler::AxisHandler()
{
    // x
    axis.push_back(QVector3D(1.0f, 0.0f, 0.0f));
    // -x
    axis.push_back(QVector3D(-1.0f, 0.0f, 0.0f));
    // y
    axis.push_back(QVector3D(0.0f, 1.0f, 0.0f));
    // -y
    axis.push_back(QVector3D(0.0f, -1.0f, 0.0f));
    // z
    axis.push_back(QVector3D(0.0f, 0.0f, 1.0f));
    // -z
    axis.push_back(QVector3D(0.0f, 0.0f, -1.0f));
}

void AxisHandler::xCounterClock()
{

    std::iter_swap(axis.begin() + 4, axis.begin() + 2);
    std::iter_swap(axis.begin() + 2, axis.begin() + 5);
    std::iter_swap(axis.begin() + 5, axis.begin() + 3);
}

void AxisHandler::yCounterClock()
{
    std::iter_swap(axis.begin() + 0, axis.begin() + 4);
    std::iter_swap(axis.begin() + 4, axis.begin() + 1);
    std::iter_swap(axis.begin() + 1, axis.begin() + 5);
}

void AxisHandler::zCounterClock()
{
    std::iter_swap(axis.begin() + 2, axis.begin() + 0);
    std::iter_swap(axis.begin() + 0, axis.begin() + 3);
    std::iter_swap(axis.begin() + 3, axis.begin() + 1);
}

void AxisHandler::xClock()
{
    std::iter_swap(axis.begin() + 4, axis.begin() + 3);
    std::iter_swap(axis.begin() + 3, axis.begin() + 5);
    std::iter_swap(axis.begin() + 5, axis.begin() + 2);
}

void AxisHandler::yClock()
{
    std::iter_swap(axis.begin() + 0, axis.begin() + 5);
    std::iter_swap(axis.begin() + 5, axis.begin() + 1);
    std::iter_swap(axis.begin() + 1, axis.begin() + 4);
}

void AxisHandler::zClock()
{
    std::iter_swap(axis.begin() + 2, axis.begin() + 1);
    std::iter_swap(axis.begin() + 1, axis.begin() + 3);
    std::iter_swap(axis.begin() + 3, axis.begin() + 0);
}
