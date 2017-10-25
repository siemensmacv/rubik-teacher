#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QWidget>
#include <QPainter>

class ColorButton : public QWidget
{
    Q_OBJECT
public:
    explicit ColorButton(QWidget *parent = nullptr, QColor color=QColor(0,0,0));

signals:
    void mousePressed();

public slots:

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

 private:
    QColor m_color;
};

#endif // COLORBUTTON_H
