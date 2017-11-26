#ifndef VIEW2D_H
#define VIEW2D_H

#include <QObject>
#include <QGridLayout>
#include <QLabel>
#include <View2DHeaders/facecube2d.h>

class View2D : public QWidget
{
    Q_OBJECT
public:
    explicit View2D(QWidget *parent = nullptr, ModelRubik *model = nullptr, bool enableInput = false);
    QLayout* getLayout() const;
    void setInputColor(RubikFace color);
private:
    ModelRubik *m_model;
    QGridLayout *gridLayout;
    FaceCube2D *mUpFace, *mDownFace,
        *mLeftFace, *mRightFace,
        *mFrontFace, *mBackFace;
    int m_inputColor = -1;
    void initFaceCubes(QWidget *parent = nullptr);

    QLabel* mLabelCubeCubiecubeRepresentation[17];
    void refreshRepresentations();

private slots:
    void refresh();
    void onFaceCubeClicked(RubikFace face, int row, int column);
};

#endif // VIEW2D_H
