#include "opencvprogrammingexercises.h"
#include "ui_opencvprogrammingexercises.h"

OpenCVProgrammingExercises::OpenCVProgrammingExercises(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenCVProgrammingExercises)
{
    ui->setupUi(this);
}

OpenCVProgrammingExercises::~OpenCVProgrammingExercises()
{
    delete ui;
}
