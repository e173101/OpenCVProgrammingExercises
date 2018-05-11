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
 * 2018-5-10: begin
 * 2018-5-11: add size
 */
void OpenCVProgrammingExercises::on_pushButton_imread_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "title");
    mat = imread(fileName.toStdString());
    if(0 != mat.data)
    {
        imshow("mat",mat);
        ui->textEdit->append("file name:"+fileName);
        ui->textEdit->append("mat size(cols x rows):"+QString::number(mat.cols)+'x'+QString::number(mat.rows));
        ui->textEdit->append("channels:"+QString::number(mat.channels()));
        //note: event the black & white jpeg, it has 3 channels

    }
    else
        ui->statusBar->showMessage("You select a bad file!!",1000);
}

/*
 * 2
 * get the value of the pic
 * 2018-5-11: begin
 */
void OpenCVProgrammingExercises::on_action_getPixelValue_triggered()
{
    if(0 != mat.data)
    {
        bool okCol, okRow;
        int col = QInputDialog::getInt(this, tr("input the col and row"),
                                       tr("col:"), 0, 0, mat.cols, 1, &okCol);
        int row = QInputDialog::getInt(this, tr("input the col and row"),
                                       tr("row:"), 0, 0, mat.rows, 1, &okRow);
        if (okCol && okRow)
        {
            ui->textEdit->append("at ("+QString::number(col)+','+QString::number(row)+") is:");
            if(1 == mat.channels())
                ui->textEdit->append(QString::number(mat.at<uchar>(row,col)));
            if(3 == mat.channels())
                ui->textEdit->append("0:"+QString::number(mat.at<Vec3b>(row,col)[0])+
                        " 1:"+QString::number(mat.at<Vec3b>(row,col)[1])+
                        " 2:"+QString::number(mat.at<Vec3b>(row,col)[2])
                        );
            else
                ui->textEdit->append("not corvered sitiuation");
        }
        else
            ui->statusBar->showMessage("You cancle the function",1000);
    }
    else
        ui->statusBar->showMessage("need mat",1000);

}

/*
 * 3
 * An example that traverse all pixel
 * 2018-5-11: begin
 */
void OpenCVProgrammingExercises::on_action_colorReduce_triggered()
{
    if(0!=mat.data)
    {
        Mat m=mat.clone();
        const uchar *readptr;
        uchar *writeptr;
        for(int y=0;y<m.rows;y++)
        {
            readptr = mat.ptr<uchar>(y);
            writeptr = m.ptr<uchar>(y);
            for(int x=0;x<m.cols*m.channels();x++)
                //writeptr[x]=255-readptr[x];
                writeptr[x]=readptr[x]/32*32;

        }
        imshow("reduced mat",m);
    }
    else
        ui->statusBar->showMessage("need mat",1000);
}
