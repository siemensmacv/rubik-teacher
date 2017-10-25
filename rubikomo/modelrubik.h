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

    std::string nextStepInSolution();
    void setSolution(std::string solution);
    std::string getSolution() const;
    ModelRubik_Matrix* getMatrix();
    int getMatrixValue(const RubikFace &face, const int &row, const int &column) const;
    void setMatrixValue(const RubikFace &face, const int &row, const int &column, const int &value);
    void setModel(std::string input);
    std::string getModel();
    void rotateFaceClockwise(const RubikFace &face);
    void rotateFaceCounterClockwise(const RubikFace &face);

    Corner getCorner(const Corner &position) const;
    CornerOrientation getCornerOrientation(const Corner &position) const;

    Edge getEdge(const Edge &position) const;
    EdgeOrientation getEdgeOrientation(const Edge &position) const;

    RubikFace getCenter(const RubikFace &position) const;

private:
    ModelRubik_Matrix matrix;
    ModelRubik_CornersEdges corners_edges;
    std::string solution;

signals:
    void cubeChanged(int load);

public slots:
};

#endif // MODELRUBIK_H
