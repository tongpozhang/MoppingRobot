#ifndef MOPROBOT1_H
#define MOPROBOT1_H

#include <QMainWindow>
#include "remote.h"
#include "automatic.h"
namespace Ui {
class moprobot1;
}

class moprobot1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit moprobot1(QWidget *parent = 0);
    ~moprobot1();

private slots:
    void on_Manual_clicked();

    void on_Automatic_clicked();

private:
    Ui::moprobot1 *ui;
    Remote *remoteR=new Remote;
    automatic *automaticA=new automatic;

};

#endif // MOPROBOT1_H
