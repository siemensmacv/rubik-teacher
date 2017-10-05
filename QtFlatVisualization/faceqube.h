#ifndef FACEQUBE_H
#define FACEQUBE_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QRect>

class FaceQube : public QFrame
{
    Q_OBJECT
public:
    explicit FaceQube(QWidget *parent = nullptr);
    virtual ~FaceQube();

    virtual void paintEvent(QPaintEvent*) override;
    virtual void resizeEvent(QResizeEvent*) override;
    virtual void mousePressEvent(QMouseEvent*) override;

public slots:
    void setFaceString(const QString &faceString);
    void setBorderWidth(int borderWidth);

private:
    int mBorderWidth = 5;
    QString mFace;
    QRect **mRect;
};

#endif // FACEQUBE_H
