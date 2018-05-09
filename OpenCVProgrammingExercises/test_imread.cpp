#include "test_imread.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>


Test_imread::Test_imread(QWidget *parent) : QMessageBox(parent)
{

}

Test_imread::Test_imread(QString imgLoc)
{
    using namespace cv;
    qDebug("ha");
    Mat mat=imread(imgLoc.toStdString());
    imshow("test",mat);
}
