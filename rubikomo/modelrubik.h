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
    ModelRubik_Matrix matrix;
    ModelRubik_CornersEdges corners_edges;

signals:

public slots:
};

#endif // MODELRUBIK_H
