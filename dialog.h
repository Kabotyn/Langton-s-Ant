#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QRect>
#include <QBrush>

#include <QMouseEvent>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

protected:
    void paintEvent(QPaintEvent *e);        // paint event
    void mouseMoveEvent(QMouseEvent *e);    // mouse move event
};

#endif // DIALOG_H
