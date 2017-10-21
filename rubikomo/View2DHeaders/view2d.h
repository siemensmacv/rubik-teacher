#ifndef VIEW2D_H
#define VIEW2D_H

#include <QObject>
#include <QGridLayout>
#include <View2DHeaders/facecube2d.h>

class View2D : public QWidget
{
    Q_OBJECT
public:
    explicit View2D(QWidget *parent = nullptr, ModelRubik *model = nullptr);
    QLayout* getLayout() const;
private:
    ModelRubik *m_model;
    QGridLayout *gridLayout;
    FaceCube2D *mUpFace, *mDownFace,
        *mLeftFace, *mRightFace,
        *mFrontFace, *mBackFace;
    void initFaceCubes(QWidget *parent = nullptr);

private slots:
    void refresh();
};

#endif // VIEW2D_H
