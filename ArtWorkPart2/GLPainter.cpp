#include "GLPainter.h"
#include "QPainter.h"

#include <QPainter>

MyGLWidget::MyGLWidget(QWidget *parent)
    :QOpenGLWidget(parent)
{
    mypainter = new MyPainter;
}

void MyGLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    mypainter->draw(&painter, event);
    painter.end();
}

