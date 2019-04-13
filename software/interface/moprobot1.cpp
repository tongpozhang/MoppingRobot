#include "moprobot1.h"
#include "ui_moprobot1.h"

moprobot1::moprobot1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::moprobot1)
{
    ui->setupUi(this);
}

moprobot1::~moprobot1()
{
    delete ui;
}

void moprobot1::on_Manual_clicked()
{
    remoteR->show();
    this->hide();
    remoteR->exec();
    this->show();
}

void moprobot1::on_Automatic_clicked()
{
    automaticA->show();
    this->hide();
    automaticA->exec();
    this->show();
}
