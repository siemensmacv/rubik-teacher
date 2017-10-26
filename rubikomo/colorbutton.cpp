#include "colorbutton.h"

ColorButton::ColorButton(QWidget *parent,QColor color) : QWidget(parent), m_color(color)
{
    resize(70,50);
    setMinimumSize(70, 50);
    updateGeometry();
}


void ColorButton::mousePressEvent(QMouseEvent *event)
{
    emit colorSelected(qColorToEnum(m_color));
    isSelected = true;
    update();
}

void ColorButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(isSelected)
    {
        painter.fillRect(rect(), Qt::black);
        painter.setPen(m_color);
        painter.setBrush(m_color);
        painter.drawRect(rect().x()+7,rect().y()+7,rect().width()-2*7, rect().height()-2*7);
    }
    else
    {
       painter.fillRect(rect(), m_color);
    }
}

void ColorButton::setIsSelected(bool value)
{
    isSelected = value;
    update();
}

