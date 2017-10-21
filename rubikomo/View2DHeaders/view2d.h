#ifndef VIEW2D_H
#define VIEW2D_H

#include <QObject>
#include <modelrubik_matrix.h>
#include <QGridLayout>
#include <View2DHeaders/facecube2d.h>

class View2D : public QWidget
{
    Q_OBJECT
public:
    explicit View2D(QWidget *parent = nullptr, ModelRubik_Matrix *model2D = nullptr);
    QLayout* getLayout() const;
private:
    ModelRubik_Matrix *m_model2D;
    QGridLayout *gridLayout;
    FaceCube2D *mUpFace, *mDownFace,
        *mLeftFace, *mRightFace,
        *mFrontFace, *mBackFace;
    void initFaceCubes(QWidget *parent = nullptr);
};

#endif // VIEW2D_H
