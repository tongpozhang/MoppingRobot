#include "remote.h"
#include "ui_remote.h"
#include <iostream>
#include <wiringPi.h>

#define left1 27
#define left2 28
#define right1 29
#define right2 25  //a motor being connected to GPIO 6
#define enable1 21
#define enable2 22

Remote::Remote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Remote)
{
    ui->setupUi(this);
    connect(ui->BackR,SIGNAL(clicked()),this,SLOT(close()));
}

Remote::~Remote()
{
    delete ui;
}

void Remote::on_W_clicked()
{
    ui->OutputR->setText("Forward");
    wiringPiSetup();
        int motor[4];
        motor[0]=left1;
        motor[1]=right1;
        motor[2]=left2;
        motor[3]=right2;
        int i=0;
        for(i=0;i<4;i++){
            pinMode (motor[i],OUTPUT);
            digitalWrite(motor[i],LOW);
            }
            digitalWrite(left1,HIGH);
            digitalWrite(right1,LOW);
            digitalWrite(left2,LOW);
            digitalWrite(right2,HIGH);
}

void Remote::on_A_clicked()
{
    ui->OutputR->setText("Left");
    wiringPiSetup();
        int motor[4];
        motor[0]=left1;
        motor[1]=right1;
        motor[2]=left2;
        motor[3]=right2;
        int i=0;
        for(i=0;i<4;i++){
            pinMode (motor[i],OUTPUT);
            digitalWrite(motor[i],LOW);
            }
            digitalWrite(left1,HIGH);
            digitalWrite(right1,LOW);
            digitalWrite(left2,LOW);
            digitalWrite(right2,LOW);
}

void Remote::on_D_clicked()
{
    ui->OutputR->setText("Right");
    wiringPiSetup();
        int motor[4];
        motor[0]=left1;
        motor[1]=right1;
        motor[2]=left2;
        motor[3]=right2;
        int i=0;
        for(i=0;i<4;i++){
            pinMode (motor[i],OUTPUT);
            digitalWrite(motor[i],LOW);
            }
            digitalWrite(left1,LOW);
            digitalWrite(right1,LOW);
            digitalWrite(left2,LOW);
            digitalWrite(right2,HIGH);
}

void Remote::on_X_clicked()
{
    ui->OutputR->setText("STOP");
    wiringPiSetup();
        int motor[4];
        motor[0]=left1;
        motor[1]=right1;
        motor[2]=left2;
        motor[3]=right2;
        int i=0;
        for(i=0;i<4;i++){
            pinMode (motor[i],OUTPUT);
            digitalWrite(motor[i],LOW);
            }
            digitalWrite(left1,LOW);
            digitalWrite(right1,LOW);
            digitalWrite(left2,LOW);
            digitalWrite(right2,LOW);
}

void Remote::on_S_clicked()
{
    ui->OutputR->setText("Backward");
    wiringPiSetup();
        int motor[4];
        motor[0]=left1;
        motor[1]=right1;
        motor[2]=left2;
        motor[3]=right2;
        int i=0;
        for(i=0;i<4;i++){
            pinMode (motor[i],OUTPUT);
            digitalWrite(motor[i],LOW);
            }
    digitalWrite(left1, LOW);
    digitalWrite(right1, HIGH);
    digitalWrite(left2,HIGH);
    digitalWrite(right2,LOW);
}
