#ifndef AXISHANDLER_H
#define AXISHANDLER_H

#include <vector>
#include <QVector3D>
#include <algorithm>

class AxisHandler
{
public:
    AxisHandler();

    void xClock();
    void yClock();
    void zClock();

    void xCounterClock();
    void yCounterClock();
    void zCounterClock();

    std::vector<QVector3D> axis;
};

#endif // AXISHANDLER_H
