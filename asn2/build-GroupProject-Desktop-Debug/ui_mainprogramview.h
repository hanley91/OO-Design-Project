/********************************************************************************
** Form generated from reading UI file 'mainprogramview.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPROGRAMVIEW_H
#define UI_MAINPROGRAMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_MainProgramView
{
public:
    QLabel *prompt;
    QComboBox *serviceAreas;
    QPushButton *next;
    QFrame *line;
    QLabel *prompt_2;
    QComboBox *serviceMeasures;
    QTableView *tableView;
    QPushButton *restart;
    QPushButton *exportToCSV;
    QLabel *cityLabel;
    QLabel *yearLabel;
    QListWidget *cityLister;
    QListWidget *yearLister;
    QLabel *yearLabel_3;
    QPushButton *launcher;
    QPushButton *saveFilter;
    QPushButton *clearFilters;
    QComboBox *savedFilters;
    QLabel *loadFiltersLabel;
    QPushButton *deleteFilter;

    void setupUi(QDialog *MainProgramView)
    {
        if (MainProgramView->objectName().isEmpty())
            MainProgramView->setObjectName(QStringLiteral("MainProgramView"));
        MainProgramView->setWindowModality(Qt::NonModal);
        MainProgramView->resize(1279, 673);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(0, 0, 129, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(145, 145, 145, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        MainProgramView->setPalette(palette);
        prompt = new QLabel(MainProgramView);
        prompt->setObjectName(QStringLiteral("prompt"));
        prompt->setGeometry(QRect(160, 20, 301, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        prompt->setPalette(palette1);
        prompt->setAlignment(Qt::AlignCenter);
        serviceAreas = new QComboBox(MainProgramView);
        serviceAreas->setObjectName(QStringLiteral("serviceAreas"));
        serviceAreas->setGeometry(QRect(180, 50, 271, 31));
        next = new QPushButton(MainProgramView);
        next->setObjectName(QStringLiteral("next"));
        next->setGeometry(QRect(250, 90, 121, 29));
        next->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        line = new QFrame(MainProgramView);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 140, 571, 20));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        prompt_2 = new QLabel(MainProgramView);
        prompt_2->setObjectName(QStringLiteral("prompt_2"));
        prompt_2->setGeometry(QRect(160, 170, 301, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        prompt_2->setPalette(palette2);
        prompt_2->setAlignment(Qt::AlignCenter);
        serviceMeasures = new QComboBox(MainProgramView);
        serviceMeasures->setObjectName(QStringLiteral("serviceMeasures"));
        serviceMeasures->setGeometry(QRect(10, 200, 591, 31));
        tableView = new QTableView(MainProgramView);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(610, 40, 641, 261));
        restart = new QPushButton(MainProgramView);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(260, 240, 93, 29));
        restart->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        exportToCSV = new QPushButton(MainProgramView);
        exportToCSV->setObjectName(QStringLiteral("exportToCSV"));
        exportToCSV->setGeometry(QRect(1000, 310, 111, 29));
        exportToCSV->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        cityLabel = new QLabel(MainProgramView);
        cityLabel->setObjectName(QStringLiteral("cityLabel"));
        cityLabel->setGeometry(QRect(300, 310, 301, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        cityLabel->setPalette(palette3);
        cityLabel->setAlignment(Qt::AlignCenter);
        yearLabel = new QLabel(MainProgramView);
        yearLabel->setObjectName(QStringLiteral("yearLabel"));
        yearLabel->setGeometry(QRect(590, 310, 301, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        yearLabel->setPalette(palette4);
        yearLabel->setAlignment(Qt::AlignCenter);
        cityLister = new QListWidget(MainProgramView);
        cityLister->setObjectName(QStringLiteral("cityLister"));
        cityLister->setGeometry(QRect(330, 340, 256, 192));
        yearLister = new QListWidget(MainProgramView);
        yearLister->setObjectName(QStringLiteral("yearLister"));
        yearLister->setGeometry(QRect(610, 340, 256, 192));
        yearLabel_3 = new QLabel(MainProgramView);
        yearLabel_3->setObjectName(QStringLiteral("yearLabel_3"));
        yearLabel_3->setGeometry(QRect(770, 10, 301, 21));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        yearLabel_3->setPalette(palette5);
        yearLabel_3->setAlignment(Qt::AlignCenter);
        launcher = new QPushButton(MainProgramView);
        launcher->setObjectName(QStringLiteral("launcher"));
        launcher->setGeometry(QRect(1120, 310, 131, 29));
        launcher->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        saveFilter = new QPushButton(MainProgramView);
        saveFilter->setObjectName(QStringLiteral("saveFilter"));
        saveFilter->setGeometry(QRect(600, 540, 93, 29));
        saveFilter->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        clearFilters = new QPushButton(MainProgramView);
        clearFilters->setObjectName(QStringLiteral("clearFilters"));
        clearFilters->setGeometry(QRect(490, 540, 93, 29));
        clearFilters->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));
        savedFilters = new QComboBox(MainProgramView);
        savedFilters->setObjectName(QStringLiteral("savedFilters"));
        savedFilters->setGeometry(QRect(440, 580, 301, 31));
        loadFiltersLabel = new QLabel(MainProgramView);
        loadFiltersLabel->setObjectName(QStringLiteral("loadFiltersLabel"));
        loadFiltersLabel->setGeometry(QRect(300, 580, 131, 21));
        deleteFilter = new QPushButton(MainProgramView);
        deleteFilter->setObjectName(QStringLiteral("deleteFilter"));
        deleteFilter->setGeometry(QRect(750, 580, 121, 29));
        deleteFilter->setStyleSheet(QStringLiteral("background:rgb(255, 202, 79)"));

        retranslateUi(MainProgramView);

        QMetaObject::connectSlotsByName(MainProgramView);
    } // setupUi

    void retranslateUi(QDialog *MainProgramView)
    {
        MainProgramView->setWindowTitle(QApplication::translate("MainProgramView", "OMBIView", 0));
        prompt->setText(QApplication::translate("MainProgramView", "Begin by selecting a municipal service area...", 0));
        next->setText(QApplication::translate("MainProgramView", "Next", 0));
        prompt_2->setText(QApplication::translate("MainProgramView", "Select a service measure...", 0));
        restart->setText(QApplication::translate("MainProgramView", "Restart", 0));
        exportToCSV->setText(QApplication::translate("MainProgramView", "Export to CSV", 0));
        cityLabel->setText(QApplication::translate("MainProgramView", "Select Cities to Include:", 0));
        yearLabel->setText(QApplication::translate("MainProgramView", "Select Years to Include:", 0));
        yearLabel_3->setText(QApplication::translate("MainProgramView", "Table of Values", 0));
        launcher->setText(QApplication::translate("MainProgramView", "Graphical View", 0));
        saveFilter->setText(QApplication::translate("MainProgramView", "Save filters", 0));
        clearFilters->setText(QApplication::translate("MainProgramView", "Clear filters", 0));
#ifndef QT_NO_TOOLTIP
        savedFilters->setToolTip(QApplication::translate("MainProgramView", "Your saved filters will go here", 0));
#endif // QT_NO_TOOLTIP
        savedFilters->setCurrentText(QString());
        loadFiltersLabel->setText(QApplication::translate("MainProgramView", "<html><head/><body><p><span style=\" color:#ffffff;\">Load saved filters:</span></p></body></html>", 0));
        deleteFilter->setText(QApplication::translate("MainProgramView", "Delete filter", 0));
    } // retranslateUi

};

namespace Ui {
    class MainProgramView: public Ui_MainProgramView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPROGRAMVIEW_H
