#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    // Реализация кнопок

    void EditRoad();
    void EditNode();

private:
    Ui::EditWindow *ui;
};

#endif // EDITWINDOW_H
