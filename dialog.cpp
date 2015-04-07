#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QVector>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

//    scene = new MyScene(this, 606, 441);
    scene = new MyScene(this, 11*11+1, 11*11+1);

    ui->graphicsView->setScene(scene);      // add MyScene to graphicVie

//    ant = new LangtonAnt(55, 40);
    ant = new LangtonAnt(11, 11);


    scene->changeTileColor(ant->getCurrentTile());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start(10);



}

Dialog::~Dialog()
{
    delete ui;
    delete ant;
    delete scene;
}

void Dialog::on_pushButton_clicked()
{
//    scene->clear();
    if(timer->isActive()) {
        timer->stop();
    }  else {
        timer->start();
    }

}

void Dialog::onTimer() {

    scene->changeTileColor(ant->getCurrentTile());

    //scene->changeTileColor(ant->nextTile());
    ant->move();

    if(scene->isTileHasColor(ant->getCurrentTile()) == false) {
        scene->changeTileColor(ant->getCurrentTile());
    }

}
