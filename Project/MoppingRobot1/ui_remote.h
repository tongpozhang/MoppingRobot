/********************************************************************************
** Form generated from reading UI file 'remote.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTE_H
#define UI_REMOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Remote
{
public:
    QLineEdit *OutputR;
    QPushButton *W;
    QPushButton *BackR;
    QPushButton *A;
    QPushButton *D;
    QPushButton *X;
    QPushButton *S;

    void setupUi(QDialog *Remote)
    {
        if (Remote->objectName().isEmpty())
            Remote->setObjectName(QStringLiteral("Remote"));
        Remote->resize(400, 300);
        OutputR = new QLineEdit(Remote);
        OutputR->setObjectName(QStringLiteral("OutputR"));
        OutputR->setGeometry(QRect(120, 30, 113, 33));
        W = new QPushButton(Remote);
        W->setObjectName(QStringLiteral("W"));
        W->setGeometry(QRect(160, 80, 41, 31));
        BackR = new QPushButton(Remote);
        BackR->setObjectName(QStringLiteral("BackR"));
        BackR->setGeometry(QRect(290, 240, 101, 31));
        A = new QPushButton(Remote);
        A->setObjectName(QStringLiteral("A"));
        A->setGeometry(QRect(100, 120, 41, 31));
        D = new QPushButton(Remote);
        D->setObjectName(QStringLiteral("D"));
        D->setGeometry(QRect(220, 120, 41, 31));
        X = new QPushButton(Remote);
        X->setObjectName(QStringLiteral("X"));
        X->setGeometry(QRect(150, 120, 61, 31));
        S = new QPushButton(Remote);
        S->setObjectName(QStringLiteral("S"));
        S->setGeometry(QRect(160, 160, 41, 31));

        retranslateUi(Remote);

        QMetaObject::connectSlotsByName(Remote);
    } // setupUi

    void retranslateUi(QDialog *Remote)
    {
        Remote->setWindowTitle(QApplication::translate("Remote", "Dialog", Q_NULLPTR));
        W->setText(QApplication::translate("Remote", "W", Q_NULLPTR));
        BackR->setText(QApplication::translate("Remote", "Back", Q_NULLPTR));
        A->setText(QApplication::translate("Remote", "A", Q_NULLPTR));
        D->setText(QApplication::translate("Remote", "D", Q_NULLPTR));
        X->setText(QApplication::translate("Remote", "X", Q_NULLPTR));
        S->setText(QApplication::translate("Remote", "S", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Remote: public Ui_Remote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTE_H
