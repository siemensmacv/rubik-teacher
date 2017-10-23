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
#include <controllerrubik.h>
#include <QMouseEvent>

class FaceCube2D : public QFrame
{
    Q_OBJECT
public:
    explicit FaceCube2D(QWidget *parent = nullptr, ModelRubik *model = nullptr, RubikFace representing = RubikFace::Up);
    ~FaceCube2D();
    virtual void paintEvent(QPaintEvent *pe) override;
    virtual void mousePressEvent(QMouseEvent *event) override;

public slots:
    void setBorderWidth(int borderWidth);
    void setFrameSize(int frameSize);

signals:
    void frameClicked(RubikFace face, int row, int column);

private:
    void updateFrameSize();
    void initRectMatrix();
    void updateRectMatrix();
    QColor getColorFromValue(int value) const;

    int mBorderWidth = 5;
    int mFrameSize = 150;
    QRect **mRectMatrix;
    ModelRubik *m_model;
    RubikFace m_representing;
};
