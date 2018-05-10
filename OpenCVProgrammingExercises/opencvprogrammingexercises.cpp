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

/*
 * 1
 * This button is test the base and most used function:
 * imread imshow and base struction of mat
 * 2018-5-10
 */
void OpenCVProgrammingExercises::on_pushButton_imread_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "title");
    mat = imread(fileName.toStdString());
    if(0 != mat.data)
    {
        imshow("mat",mat);
        ui->textEdit->append(fileName);
    }
    else
        ui->statusBar->showMessage("You select a bad file!!",1000);
}
