/********************************************************************************
** Form generated from reading UI file 'introwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROWINDOW_H
#define UI_INTROWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QPushButton *nextWindow;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IntroWindow)
    {
        if (IntroWindow->objectName().isEmpty())
            IntroWindow->setObjectName(QStringLiteral("IntroWindow"));
        IntroWindow->resize(711, 581);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(0, 0, 129, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        IntroWindow->setPalette(palette);
        centralWidget = new QWidget(IntroWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPalette palette1;
        QBrush brush2(QColor(255, 187, 76, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        QBrush brush3(QColor(145, 145, 145, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        centralWidget->setPalette(palette1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(216, 10, 301, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label->setPalette(palette2);
        QFont font;
        font.setFamily(QStringLiteral("Loma"));
        font.setPointSize(18);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(217, 180, 301, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_2->setPalette(palette3);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(25, 210, 671, 141));
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        nextWindow = new QPushButton(centralWidget);
        nextWindow->setObjectName(QStringLiteral("nextWindow"));
        nextWindow->setGeometry(QRect(310, 510, 93, 29));
        QPalette palette4;
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        QBrush brush5(QColor(255, 202, 79, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        nextWindow->setPalette(palette4);
        nextWindow->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(242, 40, 251, 121));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/ombi-logo.png")));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(208, 360, 301, 21));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        label_4->setPalette(palette5);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(25, 390, 670, 101));
        IntroWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IntroWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        IntroWindow->setStatusBar(statusBar);

        retranslateUi(IntroWindow);

        QMetaObject::connectSlotsByName(IntroWindow);
    } // setupUi

    void retranslateUi(QMainWindow *IntroWindow)
    {
        IntroWindow->setWindowTitle(QApplication::translate("IntroWindow", "OMBIView", 0));
        label->setText(QApplication::translate("IntroWindow", "Welcome to OMBIView", 0));
        label_2->setText(QApplication::translate("IntroWindow", "What is OMBI?", 0));
        textBrowser->setHtml(QApplication::translate("IntroWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The Ontario Municipal Benchmarking Initiative (OMBI) is a groundbreaking initiative collecting data for more than 850 measures across thirty-seven (37) municipal service areas. The purpose of OMBI is to foster and support a culture of service excellence in municipal government by creating new ways to measure, share and compare performance data and operational practices. OMBI acts as a source of credible information to assist Council, Senior Management, Staff and Citizens to understand how their municipality is performing over time and in relati"
                        "on to others.</p></body></html>", 0));
        nextWindow->setText(QApplication::translate("IntroWindow", "Continue", 0));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("IntroWindow", "Quick Start Guide", 0));
        textBrowser_2->setHtml(QApplication::translate("IntroWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Once the main window is launched for OMBIView, select the desired service area of interest. Within each service area, there are a variety of specific measures that can be selected for comparison purposes. The data presentation can be selected from a total of 3 options, line graph, bar graph, and data table.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class IntroWindow: public Ui_IntroWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROWINDOW_H
