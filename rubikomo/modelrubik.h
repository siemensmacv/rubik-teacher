#ifndef MODELRUBIK_H
#define MODELRUBIK_H

#include <QObject>
#include "modelrubik_matrix.h"
#include "modelrubik_cornersedges.h"
#include "rubikcorner.h"
#include "rubikedge.h"
#include "rubikface.h"

class ModelRubik : public QObject
{
    Q_OBJECT
public:
    explicit ModelRubik(QObject *parent = nullptr);

    int getMatrixValue(const RubikFace &face, const int &row, const int &column) const;

    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);
    void rotateXAxisClockwise();
    void rotateXAxisCounterClockwise();
    void rotateYAxisClockwise();
    void rotateYAxisCounterClockwise();
    void rotateZAxisClockwise();
    void rotateZAxisCounterClockwise();

    Corner getCorner(const Corner &position) const;
    CornerOrientation getCornerOrientation(const Corner &position) const;

    Edge getEdge(const Edge &position) const;
    EdgeOrientation getEdgeOrientation(const Edge &position) const;

    RubikFace getCenter(const RubikFace &position) const;

private:
    ModelRubik_Matrix matrix;
    ModelRubik_CornersEdges corners_edges;

signals:
    void cubeChanged();

public slots:
};

#endif // MODELRUBIK_H
