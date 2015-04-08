#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QVector>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new MyScene(606, 441);

    ui->graphicsView->setScene(scene);      // add MyScene to graphicVie

    ant = new LangtonAnt(55, 40);

    scene->changeTileColor(ant->getCurrentTile());
    scene->putRedRectInPos(ant->getCurrentTile());

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));

    connect(scene, SIGNAL(mouseClickOnTile(int)), ant, SLOT(onMouseChaneTile(int)));

}

Dialog::~Dialog()
{
    delete ui;
    delete ant;
    delete scene;
}

void Dialog::on_pushButton_clicked()
{
    if(timer->isActive()) {
        timer->stop();
        ui->pushButton->setText("Start");
    }  else {
        timer->start( ui->intervalBox->value() );
        ui->pushButton->setText("Stop");
    }

}

void Dialog::onTimer() {

    scene->changeTileColor(ant->getCurrentTile());

    ant->move();

    scene->putRedRectInPos(ant->getCurrentTile());

    if(scene->isTileHasColor(ant->getCurrentTile()) == false) {
        scene->changeTileColor(ant->getCurrentTile());
    }

}

void Dialog::on_clearButton_clicked()
{
    if(timer->isActive()) {
        timer->stop();
        ui->pushButton->setText("Start");
    }

    scene->clear();
    ant->restart();

    scene->changeTileColor(ant->getCurrentTile());
    scene->putRedRectInPos(ant->getCurrentTile());
}

void Dialog::on_intervalBox_valueChanged(int arg1)
{
    timer->setInterval(arg1);
}
