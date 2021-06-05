#include "mainwindow.h"
#include "ui_mainwindow.h"

QString oper_first;
double num_first, num_second, label_result, num[10];
bool plus, minus, multiply, divide;
int i = 0;
int num_op = 0;
int oper_index[10];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_1_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_2_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_3_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_4_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_5_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_6_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_7_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_8_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_9_1, SIGNAL(clicked()), this, SLOT(digits_numbers_1()));
    connect(ui->pushButton_sign_1, SIGNAL(clicked()), this, SLOT(operations_1()));
    connect(ui->pushButton_percent_1, SIGNAL(clicked()), this, SLOT(operations_1()));
    connect(ui->pushButton_plus_1, SIGNAL(clicked()), this, SLOT(math_operations_1()));
    connect(ui->pushButton_minus_1, SIGNAL(clicked()), this, SLOT(math_operations_1()));
    connect(ui->pushButton_divide_1, SIGNAL(clicked()), this, SLOT(math_operations_1()));
    connect(ui->pushButton_multiply_1, SIGNAL(clicked()), this, SLOT(math_operations_1()));
    connect(ui->pushButton_0_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_1_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_2_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_3_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_4_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_5_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_6_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_7_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_8_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_9_2, SIGNAL(clicked()), this, SLOT(digits_numbers_2()));
    connect(ui->pushButton_sign_2, SIGNAL(clicked()), this, SLOT(operations_2()));
    connect(ui->pushButton_percent_2, SIGNAL(clicked()), this, SLOT(operations_2()));

    ui->pushButton_divide_2->setCheckable(true);
    ui->pushButton_minus_2->setCheckable(true);
    ui->pushButton_plus_2->setCheckable(true);
    ui->pushButton_multiply_2->setCheckable(true); // возможность присвоения мнимого флажка


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers_1()
{
    ui->oper_show_1_1->setText(0);
    if (ui->oper_show_1->text().contains('='))
    {
        ui->oper_show_1->setText(0);
        ui->result_show_1->setText("0");
    }

    int a = 11;

    if (ui->result_show_1->text().contains('-') != ui->result_show_1->text().contains('.'))
    {
        a = 12;
    }

    if (ui->result_show_1->text().contains('-') && ui->result_show_1->text().contains('.'))
    {
        a = 13;
    }

    if (ui->result_show_1->text().length() < a)
    {
         QPushButton *button = (QPushButton *)sender(); // отслеживание на какую кнопку нажали

         double all_numbers;
         QString new_label;

         if (ui->result_show_1->text().contains(".") && button->text() == "0")
         {
             new_label = ui->result_show_1->text() + button->text();
         }
         else
         {
             all_numbers = (ui->result_show_1->text() + button->text()).toDouble();
             new_label = QString::number(all_numbers, 'g', 11);
         }

         ui->result_show_1->setText(new_label);
     }
     else
     {
         ui->oper_show_1_1->setText("Введена максимальная длина числа");
     }
}

void MainWindow::on_pushButton_dot_1_clicked()
{
    int a = 11;
    if (ui->result_show_1->text().contains('-'))
    {
       a = 12;
    }
    if (ui->result_show_1->text().length() < a)
    {
        if (ui->oper_show_1->text().contains('='))
        {
            ui->oper_show_1->setText(0);
        }

        if ((!ui->result_show_1->text().contains('.')))
        {
            ui->result_show_1->setText(ui->result_show_1->text() + ".");
        }
    }
}

void MainWindow::operations_1()
{
    ui->oper_show_1_1->setText(0);
    if (ui->oper_show_1->text().contains('='))
    {
        ui->oper_show_1->setText(0);
    }

    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if (button->text() == "+/-")
    {
        all_numbers = (ui->result_show_1->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 11);

        ui->result_show_1->setText(new_label);
    }
    else if (button->text() == "%")
    {
        all_numbers = (ui->result_show_1->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 11);

        ui->result_show_1->setText(new_label);
    }
}

void MainWindow::on_pushButton_enter_clicked()
{
    if (ui->oper_show_1->text().contains('='))
    {
        ui->oper_show_1->setText(0);
    }

    if (ui->result_show_1->text() == "+" || ui->result_show_1->text() == "-" || ui->result_show_1->text() == "/" || ui->result_show_1->text() == "x")
    {
        if (i > num_op + 1 && i >= 2)
        {
            ui->oper_show_1->setText(ui->oper_show_1->text() + " " + ui->result_show_1->text());
            ui->result_show_1->setText("0");
            oper_index[num_op] = i - 1;
            num_op++;
         }
     }
     else
     {
         if (i <= 10)
         {
             ui->oper_show_1_1->setText(0);

             num[i] = ui->result_show_1->text().toDouble();

             ui->oper_show_1->setText(ui->oper_show_1->text() + " " + QString::number(num[i],'g', 11));

             i++;

             ui->result_show_1->setText("0");
         }
         else
         {
             ui->oper_show_1_1->setText("Введено максимальное кол-во чисел");
         }
     }
}

void MainWindow::math_operations_1()
{
    if (i > num_op + 1 && i >= 2)
    {
        QPushButton *button = (QPushButton *)sender();
        ui->result_show_1->setText(0);
        ui->result_show_1->setText(ui->result_show_1->text() + button->text());
    }
    else
    {
        ui->oper_show_1_1->setText("Слишком мало чисел");
    }

}

void MainWindow::on_pushButton_equally_1_clicked()
{
    QString oper_string;
    int m = 0;
    bool error = 0;
    if ((!ui->oper_show_1->text().contains('=')))
    {
        if (num_op == i - 1 && i >= 2)
        {
            ui->oper_show_1_1->setText(0);
            ui->oper_show_1->setText(ui->oper_show_1->text() + " = ");
            oper_string = ui->oper_show_1->text();

            for (int j = 0; j < oper_string.length(); j++)
            {
                if (oper_string[j] == '+')
                {
                    num[oper_index[m] - 1 - m] += (num[oper_index[m] - m]);

                    for (int n = oper_index[m] - m; n < i; n++)
                    {
                        num[n] = num[n + 1];
                    }
                    m++;
                }
                if (oper_string[j] == '-' && oper_string[j + 1] == ' ')
                {
                    num[oper_index[m] - 1 - m] -= num[oper_index[m] - m];

                    for (int n = oper_index[m] - m; n < i; n++)
                    {
                        num[n] = num[n + 1];
                    }
                    m++;
                }
                if (oper_string[j] == '/')
                {
                    if (num[oper_index[m] - m] != 0)
                    {
                        num[oper_index[m] - 1 - m] /= num[oper_index[m] - m];

                        for (int n = oper_index[m] - m; n < i; n++)
                        {
                            num[n] = num[n + 1];
                        }
                        m++;
                    }
                    else
                    {
                        ui->oper_show_1_1->setText("Ошибка! Деление на 0");
                        error = 1;
                    }
                }
                if (oper_string[j] == 'x')
                {
                    num[oper_index[m] - 1 - m] *= num[oper_index[m] - m];

                    for (int n = oper_index[m] - m; n < i; n++)
                    {
                        num[n] = num[n + 1];
                    }
                    m++;
                }
            }
            if (!error)
            {
                ui->result_show_1->setText(QString::number(num[0], 'g', 11));
            }
            else
            {
                ui->result_show_1->setText("0");
            }

            i = 0;
            num_op = 0;
            for (int j = 0; j < 10; j++)
            {
                oper_index[j] = 0;
                num[j] = 0;
            }
        }
        else
        {
            ui->oper_show_1_1->setText("Введите корректный пример");
        }
    }
}

void MainWindow::on_pushButton_clear_1_clicked()
{
    ui->oper_show_1->setText(0);
    ui->result_show_1->setText("0");
    ui->oper_show_1_1->setText(0);
    i = 0;
    num_op = 0;
    for (int j = 0; j < 10; j++)
    {
        oper_index[j] = 0;
        num[j] = 0;
    }
}

void MainWindow::digits_numbers_2()
{
    ui->oper_show_2_2->setText(0);

    int a = 11;

    if (ui->result_show_2->text().contains('-') != ui->result_show_2->text().contains('.'))
    {
        a = 12;
    }

    if (ui->result_show_2->text().contains('-') && ui->result_show_2->text().contains('.'))
    {
        a = 13;
    }

    if (ui->result_show_2->text().length() < a)
    {
        QPushButton *button = (QPushButton *)sender(); // отслеживание на какую кнопку нажали

        double all_numbers;
        QString new_label;

        if (ui->oper_show_2->text().contains('='))
        {
            ui->oper_show_2->setText(0);
            ui->result_show_2->setText("0");
        }

        if (ui->result_show_2->text().contains(".") && button->text() == "0")
        {
            new_label = ui->result_show_2->text() + button->text();
        }
        else
        {
            all_numbers = (ui->result_show_2->text() + button->text()).toDouble();
            new_label = QString::number(all_numbers, 'g', 11);
        }

        ui->result_show_2->setText(new_label);
    }
    else
    {
        ui->oper_show_2_2->setText("Введена максимальная длина числа");
    }
}

void MainWindow::on_pushButton_dot_2_clicked()
{
    int a = 11;

    if (ui->result_show_2->text().contains('-'))
    {
        a = 12;
    }

    if (ui->result_show_2->text().length() < a)
    {
        if (ui->oper_show_2->text().contains('='))
        {
            ui->oper_show_2->setText(0);
        }

        if ((!ui->result_show_2->text().contains('.')))
        {
            ui->result_show_2->setText(ui->result_show_2->text() + ".");
        }
    }
}

void MainWindow::operations_2()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if (ui->oper_show_2->text().contains('='))
    {
        ui->oper_show_2->setText(0);
    }

    ui->oper_show_2_2->setText(0);
    if (button->text() == "+/-")
    {
        all_numbers = (ui->result_show_2->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 11);

        ui->result_show_2->setText(new_label);
    }
    else if (button->text() == "%")
    {
        all_numbers = (ui->result_show_2->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 11);

        ui->result_show_2->setText(new_label);
    }
}

void MainWindow::on_pushButton_equally_2_clicked()
{
    if (ui->oper_show_2->text().contains('='))
    {
        ui->oper_show_2_2->setText("Введите новый пример");
    }

    else if (!ui->oper_show_2->text().contains('='))
    {
        ui->oper_show_2_2->setText(0);
        QString new_label;
        num_second = ui->result_show_2->text().toDouble();

        if (plus)
        {
            label_result = num_first + num_second;
            new_label = QString::number(label_result, 'g', 11);

            ui->result_show_2->setText(new_label);
            plus = 0;
        }
        else if (minus)
        {
            label_result = num_first - num_second;
            new_label = QString::number(label_result, 'g', 11);

            ui->result_show_2->setText(new_label);
            minus = 0;
        }
        else if (divide)
        {
            if (num_second == 0)
            {
                ui->oper_show_2_2->setText("Ошибка! Деление на 0");
            }
            else
            {
                label_result = num_first / num_second;
                new_label = QString::number(label_result, 'g', 11);

                ui->result_show_2->setText(new_label);
             }

             divide = 0;
        }
        else if (multiply)
        {
            label_result = num_first * num_second;
            new_label = QString::number(label_result, 'g', 11);

            ui->result_show_2->setText(new_label);
            multiply = 0;
        }
        ui->oper_show_2->setText(ui->oper_show_2->text() + QString::number(num_second, 'g', 11) + " = ");
        num_first = 0;
        num_second = 0;
    }
    else
    {
        ui->oper_show_2_2->setText("Введите корректный пример");
    }
}

void MainWindow::on_pushButton_plus_2_clicked()
{
    if (num_first == 0)
    {
        num_first = ui->result_show_2->text().toDouble();
        ui->oper_show_2->setText(ui->result_show_2->text() + " + ");
    }
    else
    {
        num_second = ui->result_show_2->text().toDouble();
        if (plus)
        {
            num_first += num_second;
            plus = 0;
        }
        else if (minus)
        {
            num_first -= num_second;
            minus = 0;
        }
        else if (multiply)
        {
            num_first *= num_second;
            multiply = 0;
        }
        else if (divide)
        {
            num_first /= num_second;
            divide = 0;
        }
        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show_2->setText(oper_first + " + ");
    }
    ui->result_show_2->setText("0");
    plus = 1;
}

void MainWindow::on_pushButton_minus_2_clicked()
{
    if (num_first == 0)
    {
        num_first = ui->result_show_2->text().toDouble();
        ui->oper_show_2->setText(ui->result_show_2->text() + " - ");
    }
    else
    {
        num_second = ui->result_show_2->text().toDouble();
        if (plus)
        {
            num_first += num_second;
            plus = 0;
        }
        else if (minus)
        {
            num_first -= num_second;
            minus = 0;
        }
        else if (multiply)
        {
            num_first *= num_second;
            multiply = 0;
        }
        else if (divide)
        {
            num_first /= num_second;
            divide = 0;
        }
        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show_2->setText(oper_first + " - ");
    }
    ui->result_show_2->setText("0");
    minus = 1;
}

void MainWindow::on_pushButton_multiply_2_clicked()
{
    if (num_first == 0)
    {
        num_first = ui->result_show_2->text().toDouble();
        ui->oper_show_2->setText(ui->result_show_2->text() + " * ");
    }
    else
    {
        num_second = ui->result_show_2->text().toDouble();
        if (plus)
        {
            num_first += num_second;
            plus = 0;
        }
        else if (minus)
        {
            num_first -= num_second;
            minus = 0;
        }
        else if (multiply)
        {
            num_first *= num_second;
            multiply = 0;
        }
        else if (divide)
        {
            num_first /= num_second;
            divide = 0;
        }
        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show_2->setText(oper_first + " * ");
    }
    ui->result_show_2->setText("0");
    multiply = 1;
}

void MainWindow::on_pushButton_divide_2_clicked()
{
    if (num_first == 0)
    {
        num_first = ui->result_show_2->text().toDouble();
        ui->oper_show_2->setText(ui->result_show_2->text() + " / ");
    }
    else
    {
        num_second = ui->result_show_2->text().toDouble();
        if (plus)
        {
            num_first += num_second;
            plus = 0;
        }
        else if (minus)
        {
            num_first -= num_second;
            minus = 0;
        }
        else if (multiply)
        {
            num_first *= num_second;
            multiply = 0;
        }
        else if (divide)
        {
            num_first /= num_second;
            divide = 0;
        }
        oper_first = QString::number(num_first, 'g', 10);
        ui->oper_show_2->setText(oper_first + " / ");
    }
    ui->result_show_2->setText("0");
    divide = 1;
}

void MainWindow::on_pushButton_clear_2_clicked()
{
    plus = 0;
    minus = 0;
    multiply = 0;
    divide = 0;

    ui->result_show_2->setText("0");
    ui->oper_show_2->setText(0);
    ui->oper_show_2_2->setText(0);
}
