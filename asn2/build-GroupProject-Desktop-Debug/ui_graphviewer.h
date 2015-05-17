/********************************************************************************
** Form generated from reading UI file 'graphviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHVIEWER_H
#define UI_GRAPHVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graphViewer
{
public:
    QWidget *centralwidget;
    QCustomPlot *graphView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphViewer)
    {
        if (graphViewer->objectName().isEmpty())
            graphViewer->setObjectName(QStringLiteral("graphViewer"));
        graphViewer->resize(800, 600);
        centralwidget = new QWidget(graphViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        graphView = new QCustomPlot(centralwidget);
        graphView->setObjectName(QStringLiteral("graphView"));
        graphView->setGeometry(QRect(10, 10, 781, 511));
        graphViewer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(graphViewer);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        graphViewer->setStatusBar(statusbar);

        retranslateUi(graphViewer);

        QMetaObject::connectSlotsByName(graphViewer);
    } // setupUi

    void retranslateUi(QMainWindow *graphViewer)
    {
        graphViewer->setWindowTitle(QApplication::translate("graphViewer", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class graphViewer: public Ui_graphViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHVIEWER_H
