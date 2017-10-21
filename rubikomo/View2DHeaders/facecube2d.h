#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QRect>
#include <QPoint>
#include <QColor>
#include <QPainter>
#include <QPair>
#include <string>
#include <modelrubik_matrix.h>

class FaceCube2D : public QFrame
{
    Q_OBJECT
public:
    explicit FaceCube2D(QWidget *parent = nullptr, ModelRubik_Matrix *model2D = nullptr, RubikFace representing = RubikFace::Up);
    ~FaceCube2D();
    virtual void paintEvent(QPaintEvent *pe) override;

public slots:
    void setBorderWidth(int borderWidth);
    void setFrameSize(int frameSize);

private:
    void updateFrameSize();
    void initRectMatrix();
    void updateRectMatrix();
    QColor getColorFromValue(int value) const;

    int mBorderWidth = 5;
    int mFrameSize = 150;
    QRect **mRectMatrix;
    ModelRubik_Matrix *m_model2D;
    RubikFace m_representing;
};
