#include "MainWindow.h"
#include "ui_MainWindow.h"
#include"settingWay.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QProcess>
#include <QFile>

QFile fSize("C:/Qt/Kommyvoyager/MatrixSize.txt");
QFile fMatrix("C:/Qt/Kommyvoyager/Matrix.txt");

QtWindow::QtWindow(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::QtWindow)
{
    ui->setupUi(this);

    fSize.open(QFile::WriteOnly | QFile::Truncate);
    fMatrix.open(QFile::WriteOnly | QFile::Truncate);

    openGLW = new MyGLWidget(this);
    ui->grid->addWidget(openGLW, 0, 0);
    connect(ui->btnCreate, &QPushButton::clicked, this, &QtWindow::CreateGraph);
    connect(ui->btnAdd, &QPushButton::clicked, this, &QtWindow::ButtonAdd);
    connect(ui->btnEdit, &QPushButton::clicked, this, &QtWindow::ButtonEdit);
    connect(ui->btnDelete, &QPushButton::clicked, this, &QtWindow::ButtonDelete);
    connect(ui->btnAnswer, &QPushButton::clicked, this, &QtWindow::GetResult);
}

void QtWindow::CreateGraph()
{
    ui->wayText->setText("");
    ui->lengthText->setText("");

    QProcess process(this);
    process.startDetached("C:/Qt/Kommyvoyager/run.bat");
}

void QtWindow::ButtonAdd()
{
    ui->wayText->setText("");
    ui->lengthText->setText("");
    AddWindow window;
    window.setModal(true);
    window.exec();
}

void QtWindow::ButtonEdit()
{
    ui->wayText->setText("");
    ui->lengthText->setText("");
    EditWindow window;
    window.setModal(true);
    window.exec();
}

void QtWindow::ButtonDelete()
{
    ui->wayText->setText("");
    ui->lengthText->setText("");
    DeleteWindow window;
    window.setModal(true);
    window.exec();
}

void QtWindow::GetResult()
{
    ui->wayText->setText(man.GetResult(ui->rootText->toPlainText()));
    ui->lengthText->setText(man.WayLength(ui->rootText->toPlainText()));
}

QtWindow::~QtWindow()
{
    delete ui;
}

void QtWindow::on_gridWidget_customContextMenuRequested(const QPoint &pos)
{

}
