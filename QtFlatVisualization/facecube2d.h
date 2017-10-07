#ifndef FACEQUBE_H
#define FACEQUBE_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QRect>
#include <QPoint>
#include <QColor>
#include <QPainter>

class FaceCube2D : public QFrame
{
    Q_OBJECT
public:
    explicit FaceCube2D(QWidget *parent = nullptr);
    explicit FaceCube2D(QWidget *parent, const QString & faceString);
    virtual ~FaceCube2D();

    virtual void paintEvent(QPaintEvent*pe) override;
    virtual void resizeEvent(QResizeEvent*re) override;
    //virtual void mousePressEvent(QMouseEvent*) override;

public slots:
    void setFaceString(const QString &faceString);
    void setBorderWidth(int borderWidth);

private:
    void initRectMatrix();
    void recalculateDrawingPoint();
    void updateRectMatrix();
    QColor determineColorFromStringPosition(int pos);

    int mBorderWidth = 5;
    QString mFace;
    QRect **mRect;
    QPoint mMatrixDrawingPoint;
};

#endif // FACEQUBE_H
