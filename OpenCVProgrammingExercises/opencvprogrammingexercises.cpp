#include "opencvprogrammingexercises.h"
#include "ui_opencvprogrammingexercises.h"
#include "test_imread.h"

#include <QtGui>

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

void OpenCVProgrammingExercises::on_pushButton_imread_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "title");
    Test_imread a(fileName);
    a.exec();
}
