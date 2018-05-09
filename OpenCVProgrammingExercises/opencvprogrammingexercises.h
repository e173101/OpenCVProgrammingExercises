#ifndef OPENCVPROGRAMMINGEXERCISES_H
#define OPENCVPROGRAMMINGEXERCISES_H

#include <QMainWindow>

namespace Ui {
class OpenCVProgrammingExercises;
}

class OpenCVProgrammingExercises : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenCVProgrammingExercises(QWidget *parent = 0);
    ~OpenCVProgrammingExercises();

private:
    Ui::OpenCVProgrammingExercises *ui;
};

#endif // OPENCVPROGRAMMINGEXERCISES_H
