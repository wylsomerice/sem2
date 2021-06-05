#include "delnode.h"
#include "ui_delnode.h"
#include "mainwindow.h"
#include "mainwindow.cpp"

QString string;

delNode::delNode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delNode)
{
    ui->setupUi(this);
}

delNode::~delNode()
{
    delete ui;
}

void delNode::on_lineEdit_textEdited(const QString &arg1)
{
    string = arg1;
}

void delNode::on_pushButton_ok_clicked()
{
    for (int i = 0; i < num; i++)
    {
        if (string == QString::number(i + 1))
        {
            for (int j = i; j < num; j++)
            {
                xNode[j] = xNode[j + 1];
                yNode[j] = yNode[j + 1];
            }
            num--;
            del++;
            close();
        }
    }
}

void delNode::on_pushButton_cancel_clicked()
{
    close();
}
