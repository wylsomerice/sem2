#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include "QPainter.h"
#include <QOpenGLWidget>

class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    MyGLWidget( QWidget *parent);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    MyPainter *mypainter;
};


#endif // MYGLWIDGET_H

