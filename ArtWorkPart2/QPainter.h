#ifndef MYPAINTER_H
#define MYPAINTER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class MyPainter
{
public:
    MyPainter();

public:
    void draw(QPainter *painter, QPaintEvent *event);
    void make_matrix();
    void add_node();
    void delete_node();
    QBrush front;

private:
    QBrush back;
    QFont glFont;
    QPen textPen;
    QBrush white;
};

#endif // MYPAINTER_H
