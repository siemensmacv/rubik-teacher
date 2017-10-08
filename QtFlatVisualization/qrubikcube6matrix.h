#ifndef QRUBIKCUBE6MATRIX_H
#define QRUBIKCUBE6MATRIX_H

#include <QObject>
#include "qbaserubikcube6matrix.h"
#include "Cub_Rubik.h"

template <class T>
class QRubikCube6Matrix : public QBaseRubikCube6Matrix
{
public:
    QRubikCube6Matrix(QObject *parent) : QBaseRubikCube6Matrix(parent)
    {}

    QRubikCube6Matrix(QObject *parent, Cub_Rubik<T> *cube)
        : QBaseRubikCube6Matrix(parent), mCube{cube}
    {}

public slots:
    void setCube(Cub_Rubik<T> *cube)
    {
        if (mCube != cube)
            mCube = cube;
    }

    virtual QBaseRubikCube6Matrix& frontClock() override
    {
        if (mcube)
            mCube->frontClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& frontCounterClock() override
    {
        if (mcube)
            mCube->frontCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& backClock() override
    {
        if (mcube)
            mCube->backClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& backCounterClock() override
    {
        if (mcube)
            mCube->backCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& upClock() override
    {
        if (mcube)
            mCube->upClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& upCounterClock() override
    {
        if (mcube)
            mCube->upCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& downClock() override
    {
        if (mcube)
            mCube->downClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& downCounterClock() override
    {
        if (mcube)
            mCube->downCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& leftClock() override
    {
        if (mcube)
            mCube->leftClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& leftCounterClock() override
    {
        if (mcube)
            mCube->leftCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& rightClock() override
    {
        if (mcube)
            mCube->rightClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& rightCounterClock() override
    {
        if (mcube)
            mCube->rightCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& xAxisClock() override
    {
        if (mcube)
            mCube->xAxisClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& xAxisCounterClock() override
    {
        if (mcube)
            mCube->xAxisCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& yAxisClock() override
    {
        if (mcube)
            mCube->yAxisClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& yAxisCounterClock() override
    {
        if (mcube)
            mCube->yAxisCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& zAxisClock() override
    {
        if (mcube)
            mCube->zAxisClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& zAxisCounterClock()override
    {
        if (mcube)
            mCube->zAxisCounterClock();
        return *this;
    }

private:
    Cub_Rubik<T> *mCube = nullptr;
};

#endif // QRUBIKCUBE6MATRIX_H
