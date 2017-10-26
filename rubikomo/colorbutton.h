#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include "rubikface.h"

class ColorButton : public QWidget
{
    Q_OBJECT
public:
    explicit ColorButton(QWidget *parent = nullptr, QColor color=QColor(0,0,0));

    void setIsSelected(bool value);

signals:
    void colorSelected(RubikFace face);

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

 private:
    QColor m_color;
    bool isSelected = false;
};

#endif // COLORBUTTON_H
