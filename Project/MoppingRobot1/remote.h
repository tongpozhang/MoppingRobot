#ifndef REMOTE_H
#define REMOTE_H

#include <QDialog>

namespace Ui {
class Remote;
}

class Remote : public QDialog
{
    Q_OBJECT

public:
    explicit Remote(QWidget *parent = 0);
    ~Remote();

private slots:
    void on_W_clicked();

    void on_A_clicked();

    void on_D_clicked();

    void on_X_clicked();

    void on_S_clicked();

private:
    Ui::Remote *ui;


};

#endif // REMOTE_H
