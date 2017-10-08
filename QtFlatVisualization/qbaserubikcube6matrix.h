#ifndef QRUBIKCUBE6MATRIX_H
#define QRUBIKCUBE6MATRIX_H

#include <QObject>

class QBaseRubikCube6Matrix : public QObject
{
    Q_OBJECT
public:
    explicit QBaseRubikCube6Matrix(QObject *parent = nullptr);

signals:

public slots:
    virtual QBaseRubikCube6Matrix& frontClock();
    virtual QBaseRubikCube6Matrix& frontCounterClock();
    virtual QBaseRubikCube6Matrix& backClock();
    virtual QBaseRubikCube6Matrix& backCounterClock();
    virtual QBaseRubikCube6Matrix& upClock();
    virtual QBaseRubikCube6Matrix& upCounterClock();
    virtual QBaseRubikCube6Matrix& downClock();
    virtual QBaseRubikCube6Matrix& downCounterClock();
    virtual QBaseRubikCube6Matrix& leftClock();
    virtual QBaseRubikCube6Matrix& leftCounterClock();
    virtual QBaseRubikCube6Matrix& rightClock();
    virtual QBaseRubikCube6Matrix& rightCounterClock();
    virtual QBaseRubikCube6Matrix& xAxisClock();
    virtual QBaseRubikCube6Matrix& xAxisCounterClock();
    virtual QBaseRubikCube6Matrix& yAxisClock();
    virtual QBaseRubikCube6Matrix& yAxisCounterClock();
    virtual QBaseRubikCube6Matrix& zAxisClock();
    virtual QBaseRubikCube6Matrix& zAxisCounterClock();

};

#endif // QRUBIKCUBE6MATRIX_H
