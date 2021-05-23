#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<string.h>
#include"globals.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    // Инициализируем второе окно
    sWindow = new AnotherWindow();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(sWindow, &AnotherWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем третье окно
    thirdWindow = new AnotherWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(thirdWindow, &AnotherWindow::firstWindow, this, &MainWindow::show);

    connect(ui->bar, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->bav, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->sev, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->rea, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->juv, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->che, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->atl, SIGNAL(clicked()),this,SLOT(gp_clicked()));
    connect(ui->man, SIGNAL(clicked()),this,SLOT(gp_clicked()));

    int goals1 = rand()% 5;
    int goals2 = rand()% 5;
    while(goals2 > goals1)
    {
        goals2 = rand()% 5;
    }

    if(goals1>goals2){win1++; lose2++;
    }
    else if((goals1 = goals2)){draw1++; draw2++;
    }

    //MATCH_2

     int goals3 = rand()% 5;
     int goals4 = rand()% 5;
    while(goals3 > goals4)
    {
        goals4 = rand()% 5;
    }

    if(goals3<goals4){win4++; lose3++;
    }
    else if((goals3 = goals4)){draw3++; draw4++;
    }

    //MATCH_3

     int goals5 = rand()% 5;
     int goals6 = rand()% 5;
    while(goals5 > goals6)
    {
        goals6 = rand()% 5;
    }

    if(goals5<goals6){win6++; lose5++;
    }
    else if((goals5 = goals6)){draw5++; draw6++;
    }

    //MATCH_4

     int goals7 = rand()% 5;
     int goals8 = rand()% 5;
    while(goals7 > goals8)
    {
        goals8 = rand()% 5;
    }

    if(goals7>goals8){win7++; lose8++;
    }
    else if((goals7 = goals8)){draw7++; draw8++;
    }

    //MATCH_5

     int goals9 = rand()% 5;
     int goals10 = rand()% 5;
    while(goals9 < goals10)
    {
        goals10 = rand()% 5;
    }

    if(goals9>goals10){win1++; lose7++;
    }
    else if((goals9 = goals10)){draw1++; draw7++;
    }

    //MATCH_6

     int goals11 = rand()% 5;
     int goals12 = rand()% 5;
    while(goals11 < goals12)
    {
        goals12 = rand()% 5;
    }

    if(goals11>goals12){win4++; lose6++;
    }
    else if((goals11 = goals12)){draw4++; draw6++;
    }

    //MATCH_7

     int goals13 = rand()% 5;
     int goals14 = rand()% 5;
    while(goals13 < goals14)
    {
        goals14 = rand()% 5;
    }

    if(goals13>goals14){win4++; lose1++;
    }
    else if((goals13 = goals14)){draw1++; draw4++;
    }

     int global_goals1 = goals1 + goals9 + goals13;
     int global_goals2 = goals2;
     int global_goals3 = goals3;
     int global_goals4 = goals4 + goals9 + goals14;
     int global_goals5 = goals5;
     int global_goals6 = goals6 + goals12;
     int global_goals7 = goals7 + goals9;
     int global_goals8 = goals8;

     int global_passes1 = goals2 + goals10 + goals14;
     int global_passes2 = goals1;
     int global_passes3 = goals4;
     int global_passes4 = goals3 + goals12 + goals13;
     int global_passes5 = goals6;
     int global_passes6 = goals5 + goals11;
     int global_passes7 = goals8 + goals9;
     int global_passes8 = goals7;

}
QString goals = "Goals:";
QString passes = "/nПропуски:";



void MainWindow::on_pushButton_clicked()
{
    sWindow->show();  // Показываем второе окно
    this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow->show();  // Показываем третье окно
    this->close();    // Закрываем основное окно
}

void MainWindow::gp_clicked()
{
    if(ui->gp->isChecked() && ui->bar->isChecked())
        {
       ui->result->setText(QString( "%1" ).arg(global_goals1));
        }
        else if(ui->gp->isChecked() && ui->rea->isChecked()){
            ui->result->setText(QString( "%1" ).arg(global_goals2));
        }
        else if(ui->gp->isChecked() && ui->sev->isChecked()){
            ui->result->setText(QString( "%1" ).arg(global_goals3));
        }
        else if(ui->gp->isChecked() && ui->che->isChecked()){
            ui->result->setText(QString( "%1" ).arg(global_goals4));
        }
        else if(ui->gp->isChecked() && ui->man->isChecked()){
            ui->result->setText(QString( "%1" ).arg(global_goals5));
        }
        else if(ui->gp->isChecked() && ui->atl->isChecked()){
            ui->result->setText(QString( "%1" ).arg(global_goals6));
        }
        else if(ui->gp->isChecked() && ui->bav->isChecked()){
            ui->result->setText(QString( "%1" ).arg(global_goals7));
        }
        else if(ui->gp->isChecked() && ui->juv->isChecked()){
        ui->result->setText(QString( "%1" ).arg(global_goals8));
    }

        else if(ui->score->isChecked() && ui->bar->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score1));
        }
        else if(ui->score->isChecked() && ui->rea->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score2));
        }
        else if(ui->score->isChecked() && ui->sev->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score3));
        }
        else if(ui->score->isChecked() && ui->che->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score4));
        }
        else if(ui->score->isChecked() && ui->man->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score5));
        }
        else if(ui->score->isChecked() && ui->atl->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score6));
        }
        else if(ui->score->isChecked() && ui->bav->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score7));
        }
        else if(ui->score->isChecked() && ui->juv->isChecked()){
            ui->result->setText(QString( "%1" ).arg(score8));
        }
    else if(ui->winlose->isChecked() && ui->bar->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win1));
    }
    else if(ui->winlose->isChecked() && ui->rea->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win2));
    }
    else if(ui->winlose->isChecked() && ui->sev->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win3));
    }
    else if(ui->winlose->isChecked() && ui->che->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win4));
    }
    else if(ui->winlose->isChecked() && ui->man->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win5));
    }
    else if(ui->winlose->isChecked() && ui->atl->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win6));
    }
    else if(ui->winlose->isChecked() && ui->bav->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win7));
    }
    else if(ui->winlose->isChecked() && ui->juv->isChecked()){
        ui->result->setText(QString( "%1" ).arg(win8));
    }
}

void MainWindow::bar_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::bav_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::rea_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::sev_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::che_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::man_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::atl_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}
void MainWindow::juv_clicked()
{
   QPushButton *button = (QPushButton *) sender();

   ui->result->setText(button->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}
