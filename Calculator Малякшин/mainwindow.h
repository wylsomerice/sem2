#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers_1();
    void digits_numbers_2();
    void on_pushButton_dot_1_clicked();
    void on_pushButton_dot_2_clicked();
    void operations_1();
    void operations_2();
    void on_pushButton_equally_1_clicked();
    void on_pushButton_equally_2_clicked();
    void on_pushButton_plus_2_clicked();
    void on_pushButton_minus_2_clicked();
    void on_pushButton_multiply_2_clicked();
    void on_pushButton_divide_2_clicked();
    void on_pushButton_clear_2_clicked();
    void on_pushButton_enter_clicked();
    void math_operations_1();
    void on_pushButton_clear_1_clicked();
};
#endif // MAINWINDOW_H
