#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "delnode.h"
#include "addvector.h"

bool first = 1, press = 1;
bool first_addVector = 1;
int num = 3;
int del = 0, count = 0;
int dictance = 0;
int distance_arr[9][9];
double xNode[20], yNode[20];
int path[20];
int*** mat;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPen el_pen, line_pen;
    QBrush brush, result_brush;
    QPainter painter;
    bool intersection = 0;
    painter.begin(this);
    line_pen.setStyle(Qt::DashLine);
    brush.setColor(QColor (129, 219, 166));
    result_brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(el_pen);
    if (!press)
    {
        for (int i = 0; i < num; i++)
        {
            //painter.drawText(xNode[path[i]] + 12, yNode[path[i]] - 5, QString::number(i + 1));
        }
    }
    if (first)
    {
        for (int i = 0; i < num; i++)
        {
            xNode[i] = (200 * (i % 2)) + rand() % (200 * ((i % 2)+ 1));
            yNode[i] = 40 * (i + 1);
        }
        first = 0;
    }

    ui->error_label->setText(" ");

    if (dictance != 0)
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                    if (distance_arr[i][j] > 0)
                    {
                        double a, b;
                        intersection = 0;
                        if (xNode[i] != xNode[j])
                        {
                            if (yNode[j] > yNode[i])
                            {
                                a = (yNode[j] - yNode[i])/(xNode[j] - xNode[i]);
                            }
                            else
                            {
                                a = (yNode[i] - yNode[j])/(xNode[i] - xNode[j]);
                            }
                        }
                        else
                        {
                            a = 0;
                        }
                        b = (yNode[i] + 20) - a * (xNode[i] + 12);
                        for (int n = 0; n < num; n++)
                        {
                            if (n != i && n != j)
                            {
                                 for (int x = 0; x <= 30; x++)
                                 {
                                     for (int y = 0; y < 30; y++)
                                     {
                                         if (xNode[i] <= xNode[j] && (yNode[i] < yNode[j]))
                                         {


                                                 if (yNode[n] + y + 1 >= a * (xNode[n] + x) + b && (yNode[n] + y - 1 <= a * (xNode[n] + x) + b) && xNode[n] + x > xNode[i] + 12 && xNode[n] + x < xNode[j] + 12 && yNode[n] + y > yNode[i] + 20 && yNode[n] + y < yNode[j] + 20)
                                                 {
                                                     intersection = 1;
                                                 }
                                         }
                                         if (xNode[i] <= xNode[j] && (yNode[i] > yNode[j]))
                                         {
                                                 if (yNode[n] + y + 1 >= a * (xNode[n] + x) + b && (yNode[n] + y - 1 <= a * (xNode[n] + x) + b) && xNode[n] + x > xNode[i] + 12 && xNode[n] + x < xNode[j] + 12 && yNode[n] + y < yNode[i] + 20 && yNode[n] + y > yNode[j] + 20)
                                                 {
                                                     intersection = 1;
                                                 }
                                         }
                                         if (xNode[i] > xNode[j] && (yNode[i] < yNode[j]))
                                         {
                                                 if (yNode[n] + y + 1 >= a * (xNode[n] + x) + b && (yNode[n] + y - 1 <= a * (xNode[n] + x) + b) && xNode[n] + x < xNode[i] + 12 && xNode[n] + x > xNode[j] + 12 && yNode[n] + y > yNode[i] + 20 && yNode[n] + y < yNode[j] + 20)
                                                 {
                                                     intersection = 1;
                                                 }
                                         }
                                         if (xNode[i] > xNode[j] && (yNode[i] > yNode[j]))
                                         {
                                                 if (yNode[n] + y + 1 >= a * (xNode[n] + x) + b && (yNode[n] + y - 1 <= a * (xNode[n] + x) + b) && xNode[n] + x < xNode[i] + 12 && xNode[n] + x > xNode[j] + 12 && yNode[n] + y < yNode[i] + 20 && yNode[n] + y > yNode[j] + 20)
                                                 {
                                                     intersection = 1;
                                                 }
                                         }
                                     }
                                 }
                            }
                        }
                        if (!intersection)
                        {
                            painter.setPen(line_pen);
                            painter.drawLine(xNode[i] + 15, yNode[i] + 15, xNode[j] + 15, yNode[j] + 15);
                            if ((i - j) % 2 == 1)
                                painter.drawText((xNode[j] + xNode[i]) / 2, (yNode[i] + 15 + yNode[j] + 15) / 2, QString::number(distance_arr[i][j]));
                            else
                                painter.drawText((xNode[j] + 15 + xNode[i] + 15) / 2, (yNode[i] + yNode[j]) / 2, QString::number(distance_arr[i][j]));
                        }
                        else
                        {
                            ui->error_label->setText("Ошибка! На пути дороги присутствует ещё один город, постройте корректный маршрут, либо перерисуйте расположение городов.");
                        }
                    }
                }
            }

    }
    for (int i = 0; i < num; i++)
    {
        painter.setPen(el_pen);
        painter.setBrush(brush);
        {
            painter.drawEllipse(xNode[i], yNode[i], 30, 30);
            painter.drawText(xNode[i] + 12, yNode[i] + 20, QString::number(i + 1));
        }

    }


    painter.end();
}

void MainWindow::on_addNode_clicked()
{
    ui->result_label->setText(0);
    press = 1;
    ui->error_label->setText(" ");
    if (yNode[num - 1] < 360)
    {
        num++;

        xNode[num - 1] = (200 * ((num - 1) % 2)) + rand() % (200 * (((num - 1) % 2)+ 1));
        yNode[num - 1] = 40 * ((num - 1) + 1 + del);

        repaint();
    }
}

void MainWindow::on_repaint_clicked()
{
    ui->result_label->setText(0);
    press = 1;
    ui->error_label->setText(" ");
    for (int i = 0; i < num; i++)
    {
        xNode[i] = (200 * (i % 2)) + rand() % (200 * ((i % 2)+ 1));
        yNode[i] = 40 * (i + 1);
    }

    repaint();
}

void MainWindow::on_delNode_clicked()
{
    if (num > 3)
    {
        ui->result_label->setText(0);
        press = 1;
        ui->error_label->setText(" ");
        delNode window;
        window.setModal(true);
        window.exec();
        repaint();
    }
    else
        ui->error_label->setText("Минимальное кол-во вершин: 3!");
}

void MainWindow::on_addVector_clicked()
{
    ui->result_label->setText(0);
    press = 1;
    ui->error_label->setText(" ");
    addVector window;
    window.setModal(true);
    window.exec();
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (window.distance_arr[i][j] > 0)
            {
                distance_arr[i][j] = window.distance_arr[i][j];
                dictance++;
            }
        }
    }
    repaint();
}

void MainWindow::on_result_button_clicked()
{
    press = 1;
    mat = new int** [num];
    for (int i = 0; i < num; i++)
    {
        mat[i] = new int* [num];
        for (int j = 0; j < num; j++)
        {
            if(distance_arr[i][j] == 0)
            {
                mat[i][j] = nullptr;
                continue;
            }

            mat[i][j] = new int(distance_arr[i][j]);
        }
    }
    int help[20][20];
    for (int l = 0; l < num; l++)
    {

        for (int i = 0; i < num; i++)
        {

            int min = 10000;
            for (int j = 0; j < num; j++)
            {
                if (mat[i][j] && min > * mat[i][j])
                {
                    min = *mat[i][j];
                }

            }
            for (int j = 0; j < num; j++)
            {
                if (mat[i][j])
                {
                    *mat[i][j] -= min;
                }
            }
        }

        for (int j = 0; j < num; j++)
        {
            int min = 10000;
            for (int i = 0; i < num; i++)
            {
                if (mat[i][j] && min > * mat[i][j])
                {
                    min = *mat[i][j];
                }
            }

            for (int i = 0; i < num; i++)
            {
                if (mat[i][j])
                {
                    *mat[i][j] -= min;
                }
            }
        }
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                help[i][j] = 0;

        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++)
            {
                if (mat[i][j] && !*mat[i][j])
                {
                    int hmin = 10000;
                    int vmin = 10000;

                    for (int l = 0; l < num; l++)
                    {
                        if (l != i && mat[l][j] && hmin > * mat[l][j])
                            hmin = *mat[l][j];
                    }

                    for (int l = 0; l < num; l++)
                    {
                        if (l != j && mat[i][l] && vmin > * mat[i][l])
                            vmin = *mat[i][l];
                    }

                    help[i][j] = hmin + vmin;
                }
            }
        int mcost = 0, mi = 0, mj = 0;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++)
                if (mat[i][j] && mcost < help[i][j])
                {
                    mcost = help[i][j];
                    mi = i;
                    mj = j;
                }
        path[mi] = mj;
        for (int i = 0; i < num; i++)
        {
            mat[i][mj] = nullptr;
        }

        for (int i = 0; i < num; i++)
        {
            mat[mi][i] = nullptr;
        }

        mat[mj][mi] = nullptr;

    }

    int s = 0;

    for (int i = 0, j = 0; i < num; i++)
    {
        j = path[i];
        s += distance_arr[i][j];
    }

    ui->result_label->setText("Длина дороги: " + QString::number(s) + "   ");

    int temp = 0;

    for (int l = 0; l < num;)
    {
        for (int i = 0, j = 0; i < num; i++)
        {
            if (temp == 0 || i + 1 == temp)
            {
                if (temp == 0)
                    ui->result_label->setText(ui->result_label->text() + "Маршрут: " + QString::number(i + 1));
                j = path[i];
                temp = j + 1;
                if (temp > 0)
                    ui->result_label->setText(ui->result_label->text() + " -> " + QString::number(temp));
                l++;
            }

        }
    }
    press = 0;
    repaint();
}
