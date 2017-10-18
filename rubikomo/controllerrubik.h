#ifndef CONTROLLERRUBIK_H
#define CONTROLLERRUBIK_H

#include <QObject>
#include "rubikface.h"
#include "modelrubik.h"

class ControllerRubik : public QObject
{
    Q_OBJECT
public:
    ModelRubik model;

    explicit ControllerRubik(QObject *parent = nullptr);

    int getMatrixValue(const RubikFace &face, const int &row, const int &column) const;
    void setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value);

    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);
    void rotateXAxisClockwise();
    void rotateXAxisCounterClockwise();
    void rotateYAxisClockwise();
    void rotateYAxisCounterClockwise();
    void rotateZAxisClockwise();
    void rotateZAxisCounterClockwise();
signals:

public slots:
};

#endif // CONTROLLERRUBIK_H
