#ifndef DELNODE_H
#define DELNODE_H

#include <QDialog>

namespace Ui {
class delNode;
}

class delNode : public QDialog
{
    Q_OBJECT

public:
    explicit delNode(QWidget *parent = nullptr);
    ~delNode();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::delNode *ui;
};

#endif // DELNODE_H
