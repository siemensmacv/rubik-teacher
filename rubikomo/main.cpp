#include "mainwindow.h"
#include <QApplication>
#include "modelrubik.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ModelRubik mr;
    mr.matrix.getMatrixValue(RubikFace::Back, 2, 2);
    return a.exec();
}
