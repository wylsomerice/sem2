#ifndef ADDVECTOR_H
#define ADDVECTOR_H

#include <QDialog>

namespace Ui {
class addVector;
}

class addVector : public QDialog
{
    Q_OBJECT

public:
    explicit addVector(QWidget *parent = nullptr);
    ~addVector();
    int distance_arr[9][9];
    bool first_add;

private slots:
    void on_first_line_textEdited(const QString &arg1);

    void on_second_line_textEdited(const QString &arg1);

    void on_distance_line_textEdited(const QString &arg1);

    void on_pushButton_ok_clicked();

    void on_pushButton_cfncel_clicked();

private:
    Ui::addVector *ui;
};

#endif // ADDVECTOR_H
