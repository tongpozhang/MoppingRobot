/********************************************************************************
** Form generated from reading UI file 'automatic.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOMATIC_H
#define UI_AUTOMATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_automatic
{
public:
    QPushButton *StartA;
    QLineEdit *OutputA;
    QPushButton *BackA;

    void setupUi(QDialog *automatic)
    {
        if (automatic->objectName().isEmpty())
            automatic->setObjectName(QStringLiteral("automatic"));
        automatic->resize(400, 300);
        StartA = new QPushButton(automatic);
        StartA->setObjectName(QStringLiteral("StartA"));
        StartA->setGeometry(QRect(130, 200, 101, 31));
        OutputA = new QLineEdit(automatic);
        OutputA->setObjectName(QStringLiteral("OutputA"));
        OutputA->setGeometry(QRect(120, 70, 113, 33));
        BackA = new QPushButton(automatic);
        BackA->setObjectName(QStringLiteral("BackA"));
        BackA->setGeometry(QRect(280, 250, 101, 31));

        retranslateUi(automatic);

        QMetaObject::connectSlotsByName(automatic);
    } // setupUi

    void retranslateUi(QDialog *automatic)
    {
        automatic->setWindowTitle(QApplication::translate("automatic", "Dialog", Q_NULLPTR));
        StartA->setText(QApplication::translate("automatic", "Start", Q_NULLPTR));
        BackA->setText(QApplication::translate("automatic", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class automatic: public Ui_automatic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOMATIC_H
