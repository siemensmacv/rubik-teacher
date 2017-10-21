#ifndef COLORINPUT_H
#define COLORINPUT_H

#include <QWidget>
#include <QList>

class ColorInput : public QWidget
{

public:
    Q_OBJECT
    QList<QColor>colorList;
    QList<int> rectColor;
    QList<QRect> rectangles;
public:
    explicit ColorInput(QWidget *parent = nullptr);
    void ColorInput::paintEvent(QPaintEvent *event) override;
    void ColorInput::mousePressEvent(QMouseEvent *event) override;

signals:

public slots:
};

#endif // COLORINPUT_H
