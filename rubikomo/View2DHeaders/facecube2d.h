#ifndef FACECUBE2D_H
#define FACECUBE2D_H

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
#include "rubikfaceutils.h"

class FaceCube2D : public QFrame
{
    Q_OBJECT
public:
    explicit FaceCube2D(QWidget *parent = nullptr, ModelRubik *model = nullptr, RubikFace representing = RubikFace::Up);
    ~FaceCube2D();
    virtual void paintEvent(QPaintEvent *pe = nullptr) override;
    virtual void mousePressEvent(QMouseEvent *event = nullptr) override;

public slots:
    void setBorderWidth(int borderWidth);
    void setFrameSize(int frameSize);

signals:
    void frameClicked(RubikFace face, int row, int column);

private:
    void updateFrameSize();
    void initRectMatrix();
    void updateRectMatrix();

    int mBorderWidth = 7;
    int mFrameSize = 250;
    QRect **mRectMatrix;
    ModelRubik *m_model;
    RubikFace m_representing;
};

#endif // FACECUBE2D_H
