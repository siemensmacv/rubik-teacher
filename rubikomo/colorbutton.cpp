#include "colorbutton.h"

ColorButton::ColorButton(QWidget *parent,QColor color) : QWidget(parent), m_color(color)
{
   resize(70,50);
   setMinimumSize(70, 50);
   updateGeometry();
}


void ColorButton::mousePressEvent(QMouseEvent *event)
{
    emit mousePressed();
}

void ColorButton::paintEvent(QPaintEvent *event)
{
   QPainter painter;
   painter.fillRect(rect(),m_color);

}

