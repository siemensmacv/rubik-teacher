#include "colorinput.h"
#include <QPainter>
#include <cmath>

ColorInput::ColorInput(QWidget *parent) : QWidget(parent)
{

    colorList.push_back(Qt::yellow);
    colorList.push_back(Qt::green);
    colorList.push_back(Qt::red);
    colorList.push_back(Qt::darkMagenta);
    colorList.push_back(Qt::blue);
    colorList.push_back(Qt::white);

    rectColor.push_back(0);
    rectColor.push_back(1);
    rectColor.push_back(2);
    rectColor.push_back(3);
    rectColor.push_back(4);
    rectColor.push_back(5);

}

void ColorInput::paintEvent(QPaintEvent *event)
{
    if(rectangles.size() == 0)
    {
        auto width = rect().width();
        auto height = rect().height();
        rectangles.push_back(QRect(0, 0, width/3, height/3));
        rectangles.push_back(QRect(width/3, 0, 2*width/3, height/3));
        rectangles.push_back(QRect(2*width/3, 0, width, height/3));

        rectangles.push_back(QRect(2*width/3, height/3, width, 2*height/3));
        rectangles.push_back(QRect(width/3, height/3, 2*width/3, 2*height/3));
        rectangles.push_back(QRect(0, height/3, width/3, 2*height/3));

        rectangles.push_back(QRect(0, 2*height/3, width/3, height));
        rectangles.push_back(QRect(width/3, 2*height/3, 2*width/3, height));
        rectangles.push_back(QRect(2*width/3, 2*height/3, width, height));
    }

    QPainter painter(this);

    for(auto pos=0; pos < rectangles.size(); ++pos)
        painter.fillRect(rectangles[pos], colorList[rectColor[pos]]);
}

void ColorInput::mousePressEvent(QMouseEvent *event)
{
    for(auto pos=0; pos < rectangles.size(); ++pos)
    {
        if(rectangles[pos].contains(event->pos()))
        {
            rectColor[pos] = ++rectColor[pos]%colorList.size();
            break;
        }
    }
    update();
}
