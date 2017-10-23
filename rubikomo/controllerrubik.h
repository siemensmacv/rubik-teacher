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
    void setModel(std::string input);
    std::string getModel();
    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);
    void rotateXAxisClockwise();
    void rotateXAxisCounterClockwise();
    void rotateYAxisClockwise();
    void rotateYAxisCounterClockwise();
    void rotateZAxisClockwise();
    void rotateZAxisCounterClockwise();
};

#endif // CONTROLLERRUBIK_H
