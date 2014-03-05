/********************************************************************************
** Form generated from reading UI file 'qtserverguiapp.ui'
**
** Created: Sat Oct 6 19:22:43 2012
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSERVERGUIAPP_H
#define UI_QTSERVERGUIAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtserverguiappClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtserverguiappClass)
    {
        if (qtserverguiappClass->objectName().isEmpty())
            qtserverguiappClass->setObjectName(QString::fromUtf8("qtserverguiappClass"));
        qtserverguiappClass->resize(600, 400);
        menuBar = new QMenuBar(qtserverguiappClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        qtserverguiappClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtserverguiappClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        qtserverguiappClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qtserverguiappClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qtserverguiappClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qtserverguiappClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        qtserverguiappClass->setStatusBar(statusBar);

        retranslateUi(qtserverguiappClass);

        QMetaObject::connectSlotsByName(qtserverguiappClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtserverguiappClass)
    {
        qtserverguiappClass->setWindowTitle(QApplication::translate("qtserverguiappClass", "qtserverguiapp", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class qtserverguiappClass: public Ui_qtserverguiappClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSERVERGUIAPP_H
