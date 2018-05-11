#ifndef OPENCVPROGRAMMINGEXERCISES_H
#define OPENCVPROGRAMMINGEXERCISES_H

#include <QMainWindow>

#include <QtGui>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

namespace Ui {
class OpenCVProgrammingExercises;
}

class OpenCVProgrammingExercises : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenCVProgrammingExercises(QWidget *parent = 0);
    ~OpenCVProgrammingExercises();

private slots:
    void on_pushButton_imread_clicked();

    void on_action_getPixelValue_triggered();

    void on_action_colorReduce_triggered();

    void on_action_iterator_triggered();

private:
    Ui::OpenCVProgrammingExercises *ui;
    Mat mat;                //origin mat
    Mat matA, matB, matC;   //temp mat
};

#endif // OPENCVPROGRAMMINGEXERCISES_H
