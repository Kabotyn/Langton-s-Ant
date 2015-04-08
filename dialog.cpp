#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QVector>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new MyScene(this, 606, 441);
//    scene = new MyScene(this, 11*11+1, 11*11+1);

    ui->graphicsView->setScene(scene);      // add MyScene to graphicVie

    ant = new LangtonAnt(55, 40);
//    ant = new LangtonAnt(11, 11);


    scene->changeTileColor(ant->getCurrentTile());
    scene->putRedRectInPos(ant->getCurrentTile());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));



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
        ui->pushButton->setText("Start");
    }  else {
        timer->start(2);
        ui->pushButton->setText("Stop");
    }

}

void Dialog::onTimer() {

    scene->changeTileColor(ant->getCurrentTile());

    //scene->changeTileColor(ant->nextTile());
    ant->move();

    scene->putRedRectInPos(ant->getCurrentTile());

    if(scene->isTileHasColor(ant->getCurrentTile()) == false) {
        scene->changeTileColor(ant->getCurrentTile());
    }

}
