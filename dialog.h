#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QMouseEvent>

#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QPen>

#include "include/myscene.h"
#include "include/langtonant.h"

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
    MyScene *scene;

   LangtonAnt *ant;

protected:
//    void mouseMoveEvent(QMouseEvent *e);

private slots:
    void on_pushButton_clicked();
};

#endif // DIALOG_H
