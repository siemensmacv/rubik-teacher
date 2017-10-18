#ifndef CONTROLLERRUBIK_H
#define CONTROLLERRUBIK_H

#include <QObject>

class ControllerRubik : public QObject
{
    Q_OBJECT
public:
    explicit ControllerRubik(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONTROLLERRUBIK_H