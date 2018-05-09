#ifndef TEST_IMREAD_H
#define TEST_IMREAD_H

#include <QWidget>
#include <QMessageBox>
class Test_imread : public QMessageBox
{
    Q_OBJECT
public:
    explicit Test_imread(QWidget *parent = 0);
    Test_imread(QString imgLoc);

signals:

public slots:
};

#endif // TEST_IMREAD_H
