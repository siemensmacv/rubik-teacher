#ifndef VIEW3D_H
#define VIEW3D_H

#include <QWidget>
#include <QObject>

#include "./View3DHeaders/cube3d.h"
#include "modelrubik_cornersedges.h"
#include <QHBoxLayout>

class View3D : public QObject{
    Q_OBJECT
public:
    View3D(ModelRubik_CornersEdges *model3D);

    QWidget *getContainer() const;

    //to be destroyed
public slots:
    void UpC();
    void RC();
private:
    void initCube3D();
    Cube3D *theCube;
    ModelRubik_CornersEdges* m_model3D;
    QWidget * container;

};
#endif // VIEW3D_H
