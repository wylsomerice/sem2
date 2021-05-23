#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <anotherwindow.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // Слоты от кнопок главного окна
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void bar_clicked();
    void bav_clicked();
    void sev_clicked();
    void che_clicked();
    void man_clicked();
    void atl_clicked();
    void rea_clicked();
    void juv_clicked();
    void gp_clicked();

private:
    Ui::MainWindow *ui;
    // второе и третье окна
    AnotherWindow *sWindow;
    AnotherWindow *thirdWindow;
};


#endif // MAINWINDOW_H
