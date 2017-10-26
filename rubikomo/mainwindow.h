#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "./View3DHeaders/view3d.h"
#include "controllerrubik.h"

#include "ui_mainwindow.h"

#include "./View2DHeaders/view2d.h"
#include "rubikvalidator.h"
#include <QMessageBox>
#include <random>
#include <chrono>
#include "formulahandler.h"
#include "ckociemba/search.h"
#include <QWidget>
#include "colorbutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    View2D* m_view2D;
    View3D* m_view3D;
    View2D* m_colorinput;
    FormulaHandler* m_viewFormula;
    ControllerRubik *controllerRubik;
    ModelRubik m_inputmodel;

    ControllerRubik *teachingControllerRubik;
    View3D* m_teachingView3D;
    FormulaHandler* m_teachingViewFormula;


    ColorButton *yellowButton, *blueButton, *greenButton, *redButton, *orangeButton, *whiteButton;

    void connectFlatButtonsToSlots();
    void connectWidgetsToSlots();
    void connect3DButtonsToSlots();

private slots:
    void handleButton();
    void handleInputWidget();
    void validateAndLoadInput();
    void openFileButtonClicked();
    void saveFileButtonClicked();
    void shuffleRubikCube();
    void handleSolve();
    void selectFace(RubikFace face);
    void LoadTeachingInput();

signals:
    void formulaChanged(Formula);
    void teachingFormulaChanged(Formula);

};

#endif // MAINWINDOW_H
