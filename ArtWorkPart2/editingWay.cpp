#include "editingWay.h"
#include "ui_editingWay.h"

#include <QFile>
#include <QTextStream>

QFile ESize("C:/Qt/Kommyvoyager/MatrixSize.txt");
QTextStream EstreamSize(&ESize);
QFile EMatrix("C:/Qt/Kommyvoyager/Matrix.txt");
QTextStream EstreamMatrix(&EMatrix);

int Elen;
int** ematrix;

EditWindow::EditWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditWindow)
{
    ui->setupUi(this);

    ESize.open(QFile::ReadOnly | QFile::Text);
    Elen = EstreamSize.readLine().toInt(0, 10);
    ESize.flush();
    ESize.close();
    ESize.open(QFile::WriteOnly | QFile::Text);
    EstreamSize << QString::number(Elen);
    ESize.flush();
    ESize.close();
    ematrix = new int* [Elen];
    for (int i = 0; i < Elen; i++)
    {
        ematrix[i] = new int [Elen];
    }

    for (int i = 0; i < Elen; i++)
    {
        for (int j = 0; j < Elen; j++)
        {
            ematrix[i][j] = 0;
        }
    }

    EMatrix.close();
    EMatrix.open(QFile::ReadOnly | QFile::Text);
    for (int i = 0; i < Elen; i++)
    {
        for (int j = 0; j < Elen; j++)
        {
            ematrix[i][j] = EstreamMatrix.readLine().toInt(0, 10);
        }
    }
    EMatrix.flush();
    EMatrix.close();

    connect(ui->btnEditRoad, &QPushButton::clicked, this, &EditWindow::EditRoad);
    connect(ui->btnEdit, &QPushButton::clicked, this, &EditWindow::EditNode);
}

void EditWindow::EditRoad()
{
    bool isWritten;
    if (ui->startNode->toPlainText().toInt(&isWritten, 10) && ui->endNode->toPlainText().toInt(&isWritten, 10) && (ui->normalLength->toPlainText().toInt(&isWritten, 10) ||  ui->normalLength->toPlainText() == "0") && (ui->reverseLength->toPlainText().toInt(&isWritten, 10) ||  ui->reverseLength->toPlainText() == "0"))
    {
        int i = ui->startNode->toPlainText().toInt(0, 10) - 1,
            j = ui->endNode->toPlainText().toInt(0, 10) - 1;

        ematrix [i][j] = ui->normalLength->toPlainText().toInt(0, 10);
        ematrix [j][i] = ui->reverseLength->toPlainText().toInt(0, 10);
        if (ui->normalLength->toPlainText() == 0)
        {
            ematrix [i][j] = 0;
        }
        if (ui->reverseLength->toPlainText() == 0)
        {
            ematrix [j][i] = 0;
        }

        ui->endNode->setText("");
        ui->normalLength->setText("");
        ui->reverseLength->setText("");
    }
}

void EditWindow::EditNode()
{
    EditRoad();
    EMatrix.open(QFile::WriteOnly | QFile::Text);
    for (int i = 0; i < Elen; i++)
    {
        for (int j = 0; j < Elen; j++)
        {
            EstreamMatrix << QString::number(ematrix[i][j]) << "\n";
        }
    }
    EMatrix.close();
    close();
}

EditWindow::~EditWindow()
{
    delete ui;
}
