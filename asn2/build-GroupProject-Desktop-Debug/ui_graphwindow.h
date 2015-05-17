/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_GraphWindow
{
public:
    QCustomPlot *graphView;
    QPushButton *lineGraph;
    QPushButton *barGraph;
    QPushButton *visible;
    QPushButton *exporter;
    QPushButton *complete;

    void setupUi(QDialog *GraphWindow)
    {
        if (GraphWindow->objectName().isEmpty())
            GraphWindow->setObjectName(QStringLiteral("GraphWindow"));
        GraphWindow->resize(1276, 707);
        GraphWindow->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        graphView = new QCustomPlot(GraphWindow);
        graphView->setObjectName(QStringLiteral("graphView"));
        graphView->setGeometry(QRect(10, 10, 1261, 651));
        lineGraph = new QPushButton(GraphWindow);
        lineGraph->setObjectName(QStringLiteral("lineGraph"));
        lineGraph->setGeometry(QRect(400, 670, 93, 29));
        lineGraph->setStyleSheet(QLatin1String("background:rgb(0, 0, 129);\n"
"color:rgb(255, 202, 79)"));
        barGraph = new QPushButton(GraphWindow);
        barGraph->setObjectName(QStringLiteral("barGraph"));
        barGraph->setGeometry(QRect(500, 670, 93, 29));
        barGraph->setStyleSheet(QLatin1String("background:rgb(0, 0, 129);\n"
"color:rgb(255, 202, 79)"));
        visible = new QPushButton(GraphWindow);
        visible->setObjectName(QStringLiteral("visible"));
        visible->setGeometry(QRect(600, 670, 93, 29));
        visible->setStyleSheet(QLatin1String("background:rgb(0, 0, 129);\n"
"color:rgb(255, 202, 79)"));
        exporter = new QPushButton(GraphWindow);
        exporter->setObjectName(QStringLiteral("exporter"));
        exporter->setGeometry(QRect(830, 670, 93, 29));
        exporter->setStyleSheet(QLatin1String("background:rgb(0, 0, 129);\n"
"color:rgb(255, 202, 79)"));
        complete = new QPushButton(GraphWindow);
        complete->setObjectName(QStringLiteral("complete"));
        complete->setGeometry(QRect(710, 670, 111, 29));
        complete->setStyleSheet(QLatin1String("background:rgb(0, 0, 129);\n"
"color:rgb(255, 202, 79)"));
        complete->setAutoDefault(false);

        retranslateUi(GraphWindow);

        QMetaObject::connectSlotsByName(GraphWindow);
    } // setupUi

    void retranslateUi(QDialog *GraphWindow)
    {
        GraphWindow->setWindowTitle(QApplication::translate("GraphWindow", "Dialog", 0));
        lineGraph->setText(QApplication::translate("GraphWindow", "Line Graph", 0));
        barGraph->setText(QApplication::translate("GraphWindow", "Bar Graph", 0));
        visible->setText(QApplication::translate("GraphWindow", "Visible Mean", 0));
        exporter->setText(QApplication::translate("GraphWindow", "Export...", 0));
        complete->setText(QApplication::translate("GraphWindow", "Complete Mean", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphWindow: public Ui_GraphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
