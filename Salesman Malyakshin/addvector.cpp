#include "addvector.h"
#include "ui_addvector.h"
#include "mainwindow.h"
#include "delnode.h"

QString first_string, second_string, distance_string;

addVector::addVector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addVector)
{
    ui->setupUi(this);
    if (!first_add)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                distance_arr[i][j] = 0;
            }
        }
        first_add = 1;
    }

}

addVector::~addVector()
{
    delete ui;
}

void addVector::on_first_line_textEdited(const QString &arg1)
{

    first_string = arg1;
}

void addVector::on_second_line_textEdited(const QString &arg1)
{
    second_string = arg1;
}

void addVector::on_distance_line_textEdited(const QString &arg1)
{
    distance_string = arg1;
}



void addVector::on_pushButton_ok_clicked()
{
    if (first_string != second_string)
    {
        if (distance_string.toInt() > 0)
        {
            distance_arr[first_string.toInt() - 1][second_string.toInt() - 1] = distance_string.toInt();
            close();
        }
    }
}


void addVector::on_pushButton_cfncel_clicked()
{
    close();
}
