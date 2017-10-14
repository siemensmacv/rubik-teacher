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
        if (mCube)
            mCube->frontClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& frontCounterClock() override
    {
        if (mCube)
            mCube->frontCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& backClock() override
    {
        if (mCube)
            mCube->backClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& backCounterClock() override
    {
        if (mCube)
            mCube->backCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& upClock() override
    {
        if (mCube)
            mCube->upClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& upCounterClock() override
    {
        if (mCube)
            mCube->upCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& downClock() override
    {
        if (mCube)
            mCube->downClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& downCounterClock() override
    {
        if (mCube)
            mCube->downCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& leftClock() override
    {
        if (mCube)
            mCube->leftClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& leftCounterClock() override
    {
        if (mCube)
            mCube->leftCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& rightClock() override
    {
        if (mCube)
            mCube->rightClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& rightCounterClock() override
    {
        if (mCube)
            mCube->rightCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& xAxisClock() override
    {
        if (mCube)
            mCube->xAxisClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& xAxisCounterClock() override
    {
        if (mCube)
            mCube->xAxisCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& yAxisClock() override
    {
        if (mCube)
            mCube->yAxisClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& yAxisCounterClock() override
    {
        if (mCube)
            mCube->yAxisCounterClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& zAxisClock() override
    {
        if (mCube)
            mCube->zAxisClock();
        return *this;
    }
    virtual QBaseRubikCube6Matrix& zAxisCounterClock()override
    {
        if (mCube)
            mCube->zAxisCounterClock();
        return *this;
    }

private:
    Cub_Rubik<T> *mCube = nullptr;
};

#endif // QRUBIKCUBE6MATRIX_H
