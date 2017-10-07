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
#include <QPair>
#include <string>


class FaceCube2D : public QFrame
{
    Q_OBJECT
public:
    explicit FaceCube2D(QWidget *parent = nullptr);
    explicit FaceCube2D(QWidget *parent, const std::string & faceString);
    explicit FaceCube2D(QWidget *parent, const QString & faceString);
    //virtual ~FaceCube2D();

    virtual void paintEvent(QPaintEvent*pe) override;
    //virtual void resizeEvent(QResizeEvent*re) override;
    //virtual void mousePressEvent(QMouseEvent*) override;

    QPair<QRect, QColor>*& operator[](int pos);
    QString toQString() const;
    std::string toString() const;

public slots:
    void setBorderWidth(int borderWidth);
    void setFrameSize(int frameSize);
    void updateColorMatrix(const QString & faceString);
    void updateColorMatrix(const std::string & faceString);

private:
    void updateFrameSize();
    void initFaceMatrix();
    void updateRectMatrix();
    QColor getColorFromChar(char letter) const;
    char getCharFromColor(QColor color) const;

    int mBorderWidth = 5;
    int mFrameSize = 150;
    QPair<QRect, QColor> **mFaceMatrix;
};

#endif // FACEQUBE_H
