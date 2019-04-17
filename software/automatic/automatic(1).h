#ifndef AUTOMATIC_H
#define AUTOMATIC_H

#include <QDialog>

namespace Ui {
class automatic;
}

class automatic : public QDialog
{
    Q_OBJECT

public:
    explicit automatic(QWidget *parent = 0);
    ~automatic();

private slots:
    void on_StartA_clicked();

    void on_BackA_clicked();

    void on_StopA_clicked();

private:
    Ui::automatic *ui;
};

#endif // AUTOMATIC_H
