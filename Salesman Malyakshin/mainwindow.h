#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QWaitCondition>
#include <QMutex>

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

protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_addNode_clicked();
    void on_repaint_clicked();
    void on_delNode_clicked();
    void on_addVector_clicked();
    void on_result_button_clicked();
};
#endif // MAINWINDOW_H
