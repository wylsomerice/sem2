#ifndef QTWINDOW_H
#define QTWINDOW_H

#include <QMainWindow>
#include "GLPainter.h"
#include "addingNode.h"
#include "editingWay.h"
#include "deletingNode.h"
#include "settingWay.h"

QT_BEGIN_NAMESPACE

namespace Ui { class QtWindow; }

QT_END_NAMESPACE

class QtWindow : public QMainWindow
{
    Q_OBJECT

public:
    QtWindow(QWidget *parent = nullptr);
    ~QtWindow();

private slots:
    void CreateGraph();
    void ButtonAdd();
    void ButtonEdit();
    void ButtonDelete();
    void GetResult();

    void on_gridWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::QtWindow *ui;
    MyGLWidget *openGLW;
    TravellerSalesMan man;
};

#endif // QTWINDOW_H
