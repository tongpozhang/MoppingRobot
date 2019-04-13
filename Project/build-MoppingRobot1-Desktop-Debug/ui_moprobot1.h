/********************************************************************************
** Form generated from reading UI file 'moprobot1.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOPROBOT1_H
#define UI_MOPROBOT1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_moprobot1
{
public:
    QWidget *centralWidget;
    QPushButton *Manual;
    QLabel *label;
    QPushButton *Automatic;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *moprobot1)
    {
        if (moprobot1->objectName().isEmpty())
            moprobot1->setObjectName(QStringLiteral("moprobot1"));
        moprobot1->resize(400, 300);
        centralWidget = new QWidget(moprobot1);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Manual = new QPushButton(centralWidget);
        Manual->setObjectName(QStringLiteral("Manual"));
        Manual->setGeometry(QRect(140, 70, 101, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 171, 21));
        Automatic = new QPushButton(centralWidget);
        Automatic->setObjectName(QStringLiteral("Automatic"));
        Automatic->setGeometry(QRect(140, 120, 101, 31));
        moprobot1->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(moprobot1);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 27));
        moprobot1->setMenuBar(menuBar);
        mainToolBar = new QToolBar(moprobot1);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        moprobot1->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(moprobot1);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        moprobot1->setStatusBar(statusBar);

        retranslateUi(moprobot1);

        QMetaObject::connectSlotsByName(moprobot1);
    } // setupUi

    void retranslateUi(QMainWindow *moprobot1)
    {
        moprobot1->setWindowTitle(QApplication::translate("moprobot1", "moprobot1", Q_NULLPTR));
        Manual->setText(QApplication::translate("moprobot1", "Manual", Q_NULLPTR));
        label->setText(QApplication::translate("moprobot1", "Please choose a mode", Q_NULLPTR));
        Automatic->setText(QApplication::translate("moprobot1", "Automatic", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class moprobot1: public Ui_moprobot1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOPROBOT1_H
