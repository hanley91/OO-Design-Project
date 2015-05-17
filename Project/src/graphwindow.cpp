#include "graphwindow.h"
#include "ui_graphwindow.h"
#include <iostream>
#include <QErrorMessage>
#include <ctime>

GraphWindow::GraphWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->visible, SIGNAL(pressed()), this, SLOT(visibleMean()));
    QObject::connect(ui->complete, SIGNAL(pressed()), this, SLOT(completeMean()));
    QObject::connect(ui->barGraph, SIGNAL(pressed()), this, SLOT(toggleBarGraph()));
    QObject::connect(ui->lineGraph, SIGNAL(pressed()), this, SLOT(toggleLineGraph()));
    QObject::connect(ui->exporter, SIGNAL(pressed()), this, SLOT(exportToImage()));
}

GraphWindow::~GraphWindow()
{
    delete ui;
}

void GraphWindow::setGraph(OMBIDatabase *data, vector<int> y, QStringList c)
{
    dataAccess = data;
    yearValues = y;
    cityNames = c;

    ui->graphView->clearPlottables();
    //Initialize the QCustomPlot widget, prepare for display
    ui->graphView->addGraph();

    //Set the label of the x-axis to "Cities"
    ui->graphView->xAxis->setLabel("Cities");

    //Turn off QCustomPlot's auto tick feature (will customize to needs)
    ui->graphView->xAxis->setAutoTicks(false);

    //Turn off QCustomPlot's auto label feature (will customize to needs)
    ui->graphView->xAxis->setAutoTickLabels(false);

    //Set the range of the x-axis to fit all the data in the best way possible
    ui->graphView->xAxis->setRange(0, 55);

    ui->graphView->yAxis->setRange(data->getMinForCurrent(c,y), data->getMaxForCurrent(c,y));

    //Set the number precision to 9 digits so that we don't have scientific notation
    ui->graphView->yAxis->setNumberPrecision(9);

    //Set the spacing between tick marks on the x-axis
    ui->graphView->xAxis->setTickLength(0, 1);

    //Set the city name labels to be rotated 60 degrees for readability
    ui->graphView->xAxis->setTickLabelRotation(30);

    //Set the amount of non-major ticks to be displayed to zero
    ui->graphView->xAxis->setSubTickCount(5);

    //Set the label for the y-axis to be equal to the current measure
    ui->graphView->yAxis->setLabel(data->currentMeasure());

    QVector<double> xPos;
    for (int i=0;i<=c.size();i++){
        xPos.append((5*i)+(2.5));
        //xPos.append(i);
    }

    //Set the tick marks for the x-axis to be the contents of the QVector containing the values
    //for the pre-calculated tick spacing
    ui->graphView->xAxis->setTickVector(xPos);

    //Set the labels for the x-axis to be the contents of the QVector containing all the names of all cities
    ui->graphView->xAxis->setTickVectorLabels(c.toVector());

    QCPBars *set1 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set2 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set3 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set4 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set5 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);

    QVector<double> set1positions;
    QVector<double> set2positions;
    QVector<double> set3positions;
    QVector<double> set4positions;
    QVector<double> set5positions;

    QVector<double> set1Data;
    QVector<double> set2Data;
    QVector<double> set3Data;
    QVector<double> set4Data;
    QVector<double> set5Data;

    for (int i=0;i<y.size();i++){

        if (i==0){
            ui->graphView->addPlottable(set1);
            for (int j=0; j<c.size();j++){

            set1Data.append(data->getDataPoint(c.at(j),y.at(i)));
            set1positions.append((5*j)+1);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(255, 131, 0));
            set1->setPen(pen);
            set1->setBrush(QColor(255, 131, 0, 50));

            set1->setName(QString::number(y.at(i)));
            set1->setData(set1positions, set1Data);
            }
        }
        if (i==1){
            ui->graphView->addPlottable(set2);
            for (int j=0; j<c.size();j++){
            set2Data.append(data->getDataPoint(c.at(j),y.at(i)));
            set2positions.append((5*j)+2);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(1, 92, 191));
            set2->setPen(pen);
            set2->setBrush(QColor(1, 92, 191, 50));

            set2->setName(QString::number(y.at(i)));
            set2->setData(set2positions, set2Data);
            }
        }
        if (i==2){
            ui->graphView->addPlottable(set3);
            for (int j=0; j<c.size();j++){
            set3Data.append(data->getDataPoint(c.at(j),y.at(i)));
            set3positions.append((5*j)+3);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(150, 222, 0));
            set3->setPen(pen);
            set3->setBrush(QColor(150, 222, 0, 70));

            set3->setName(QString::number(y.at(i)));
            set3->setData(set3positions, set3Data);
            }
        }
        if (i==3){
            ui->graphView->addPlottable(set4);
            for (int j=0; j<c.size();j++){
            set4Data.append(data->getDataPoint(c.at(j),y.at(i)));
            set4positions.append((5*j)+4);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(60, 222, 0));
            set4->setPen(pen);
            set4->setBrush(QColor(60, 222, 0, 70));

            set4->setName(QString::number(y.at(i)));
            set4->setData(set4positions, set4Data);
            }
        }
        if (i==4){
            ui->graphView->addPlottable(set5);
            for (int j=0; j<c.size();j++){
            set5Data.append(data->getDataPoint(c.at(j),y.at(i)));
            set5positions.append((5*j)+5);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(200, 40, 5));
            set5->setPen(pen);
            set5->setBrush(QColor(200, 40, 5, 70));

            set5->setName(QString::number(y.at(i)));
            set5->setData(set5positions, set5Data);
            }
        }

    }

    ui->graphView->legend->setVisible(true);
    ui->graphView->replot();
    if (dataAccess->meanCurrent(cityNames,yearValues) == dataAccess->meanAll()) {
        ui->complete->setEnabled(false);
        ui->complete->setStyleSheet(QString::fromUtf8("QPushButton:disabled""{ color: gray }"));
    }
}

void GraphWindow::visibleMean()
{
    double meanValue;
    meanValue = dataAccess->meanCurrent(cityNames,yearValues);
    ui->graphView->addGraph();

    QVector<double> xRange;
    QVector<double> yRange;

    for (int i=0;i<=ui->graphView->xAxis->tickVector().at((ui->graphView->xAxis->tickVector().size())-1);i++){
        xRange.append(i);
        yRange.append(meanValue);
    }

    int n = ui->graphView->graphCount();
    ui->graphView->graph(n-1)->setData(xRange,yRange);
    ui->graphView->replot();
}

void GraphWindow::completeMean()
{
    double meanValue;
    meanValue = dataAccess->meanAll();
    ui->graphView->addGraph();

    QVector<double> xRange;
    QVector<double> yRange;

    for (int i=0;i<=ui->graphView->xAxis->tickVector().at((ui->graphView->xAxis->tickVector().size())-1);i++){
        xRange.append(i);
        yRange.append(meanValue);
    }


    ui->graphView->graph(1)->setData(xRange,yRange);
    ui->graphView->replot();
}

void GraphWindow::toggleBarGraph()
{

    ui->graphView->clearPlottables();
    //Initialize the QCustomPlot widget, prepare for display
    ui->graphView->addGraph();

    //Set the label of the x-axis to "Cities"
    ui->graphView->xAxis->setLabel("Cities");

    //Turn off QCustomPlot's auto tick feature (will customize to needs)
    ui->graphView->xAxis->setAutoTicks(false);

    //Turn off QCustomPlot's auto label feature (will customize to needs)
    ui->graphView->xAxis->setAutoTickLabels(false);

    //Set the range of the x-axis to fit all the data in the best way possible
    ui->graphView->xAxis->setRange(0, 55);

    ui->graphView->yAxis->setRange(dataAccess->getMinForCurrent(cityNames,yearValues), dataAccess->getMaxForCurrent(cityNames,yearValues));

    //Set the number precision to 9 digits so that we don't have scientific notation
    ui->graphView->yAxis->setNumberPrecision(9);

    //Set the spacing between tick marks on the x-axis
    ui->graphView->xAxis->setTickLength(0, 1);

    //Set the city name labels to be rotated 60 degrees for readability
    ui->graphView->xAxis->setTickLabelRotation(30);

    //Set the amount of non-major ticks to be displayed to zero
    ui->graphView->xAxis->setSubTickCount(5);

    //Set the label for the y-axis to be equal to the current measure
    ui->graphView->yAxis->setLabel(dataAccess->currentMeasure());

    QVector<double> xPos;
    for (int i=0;i<=cityNames.size();i++){
        xPos.append((5*i)+(2.5));
        //xPos.append(i);
    }

    //Set the tick marks for the x-axis to be the contents of the QVector containing the values
    //for the pre-calculated tick spacing
    ui->graphView->xAxis->setTickVector(xPos);

    //Set the labels for the x-axis to be the contents of the QVector containing all the names of all cities
    ui->graphView->xAxis->setTickVectorLabels(cityNames.toVector());

    QCPBars *set1 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set2 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set3 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set4 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);
    QCPBars *set5 = new QCPBars(ui->graphView->xAxis, ui->graphView->yAxis);

    QVector<double> set1positions;
    QVector<double> set2positions;
    QVector<double> set3positions;
    QVector<double> set4positions;
    QVector<double> set5positions;

    QVector<double> set1Data;
    QVector<double> set2Data;
    QVector<double> set3Data;
    QVector<double> set4Data;
    QVector<double> set5Data;

    for (int i=0;i<yearValues.size();i++){

        if (i==0){
            ui->graphView->addPlottable(set1);
            for (int j=0; j<cityNames.size();j++){

            set1Data.append(dataAccess->getDataPoint(cityNames.at(j),yearValues.at(i)));
            set1positions.append((5*j)+1);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(255, 131, 0));
            set1->setPen(pen);
            set1->setBrush(QColor(255, 131, 0, 50));

            set1->setName(QString::number(yearValues.at(i)));
            set1->setData(set1positions, set1Data);
            }
        }
        if (i==1){
            ui->graphView->addPlottable(set2);
            for (int j=0; j<cityNames.size();j++){
            set2Data.append(dataAccess->getDataPoint(cityNames.at(j),yearValues.at(i)));
            set2positions.append((5*j)+2);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(1, 92, 191));
            set2->setPen(pen);
            set2->setBrush(QColor(1, 92, 191, 50));

            set2->setName(QString::number(yearValues.at(i)));
            set2->setData(set2positions, set2Data);
            }
        }
        if (i==2){
            ui->graphView->addPlottable(set3);
            for (int j=0; j<cityNames.size();j++){
            set3Data.append(dataAccess->getDataPoint(cityNames.at(j),yearValues.at(i)));
            set3positions.append((5*j)+3);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(150, 222, 0));
            set3->setPen(pen);
            set3->setBrush(QColor(150, 222, 0, 70));

            set3->setName(QString::number(yearValues.at(i)));
            set3->setData(set3positions, set3Data);
            }
        }
        if (i==3){
            ui->graphView->addPlottable(set4);
            for (int j=0; j<cityNames.size();j++){
            set4Data.append(dataAccess->getDataPoint(cityNames.at(j),yearValues.at(i)));
            set4positions.append((5*j)+4);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(60, 222, 0));
            set4->setPen(pen);
            set4->setBrush(QColor(60, 222, 0, 70));

            set4->setName(QString::number(yearValues.at(i)));
            set4->setData(set4positions, set4Data);
            }
        }
        if (i==4){
            ui->graphView->addPlottable(set5);
            for (int j=0; j<cityNames.size();j++){
            set5Data.append(dataAccess->getDataPoint(cityNames.at(j),yearValues.at(i)));
            set5positions.append((5*j)+5);

            QPen pen;
            pen.setWidthF(1.2);
            pen.setColor(QColor(200, 40, 5));
            set5->setPen(pen);
            set5->setBrush(QColor(200, 40, 5, 70));

            set5->setName(QString::number(yearValues.at(i)));
            set5->setData(set5positions, set5Data);
            }
        }

    }

    ui->graphView->legend->setVisible(true);
    ui->graphView->replot();
    if (dataAccess->meanCurrent(cityNames,yearValues) == dataAccess->meanAll()) {
        ui->complete->setEnabled(false);
        ui->complete->setStyleSheet(QString::fromUtf8("QPushButton:disabled""{ color: gray }"));
    }
}

void GraphWindow::toggleLineGraph()
{
    ui->graphView->clearPlottables();

    //Set the label of the x-axis to "Cities"
    ui->graphView->xAxis->setLabel("Years");

    //Turn off QCustomPlot's auto tick feature (will customize to needs)
    ui->graphView->xAxis->setAutoTicks(false);

    //Turn off QCustomPlot's auto label feature (will customize to needs)
    ui->graphView->xAxis->setAutoTickLabels(false);

    //Set the range of the x-axis to fit all the data in the best way possible
    ui->graphView->xAxis->setRange(0, 7);

    ui->graphView->yAxis->setRange(dataAccess->getMinForCurrent(cityNames,yearValues), dataAccess->getMaxForCurrent(cityNames,yearValues));

    //Set the number precision to 9 digits so that we don't have scientific notation
    ui->graphView->yAxis->setNumberPrecision(9);

    //Set the spacing between tick marks on the x-axis
    ui->graphView->xAxis->setTickLength(0, 2.5);

    //Set the city name labels to be rotated 60 degrees for readability
    ui->graphView->xAxis->setTickLabelRotation(30);

    //Set the amount of non-major ticks to be displayed to zero
    ui->graphView->xAxis->setSubTickCount(5);

    //Set the label for the y-axis to be equal to the current measure
    ui->graphView->yAxis->setLabel(dataAccess->currentMeasure());

    QVector<double> xPos;
    for (int i=0;i<yearValues.size();i++){
        xPos.append(i);
    }

    //Set the tick marks for the x-axis to be the contents of the QVector containing the values
    //for the pre-calculated tick spacing
    ui->graphView->xAxis->setTickVector(xPos);

    QVector<QString> xLabels;
    for (int a=0;a<yearValues.size();a++){
        xLabels.append(QString::number(yearValues.at(a)));
    }

    //Set the labels for the x-axis to be the contents of the QVector containing all the names of all cities
    ui->graphView->xAxis->setTickVectorLabels(xLabels);

    bool notDone = false;

    do{
    QVector<double> xRange;
    QVector<double> yRange;

    for (int i=0;i<cityNames.size();i++){
        ui->graphView->addGraph();
    }

    for (int j=0;j<cityNames.size();j++){
        for (int k=0;k<yearValues.size();k++){
            xRange.append(k);
            yRange.append(dataAccess->getDataPoint(cityNames.at(j),yearValues.at(k)));
        }
        ui->graphView->graph(j)->setData(xRange,yRange);
        ui->graphView->graph(j)->setName(cityNames.at(j));
        xRange.clear();
        yRange.clear();
    }
        notDone = true;
    }while(notDone==false);

    if (ui->graphView->graph(0)){
        ui->graphView->graph(0)->setPen(QPen(QColor(255, 131, 0)));
    }

    if (ui->graphView->graph(1)){
        ui->graphView->graph(1)->setPen(QPen(QColor(1, 92, 191)));
    }

    if (ui->graphView->graph(2)){
        ui->graphView->graph(2)->setPen(QPen(QColor(150, 222, 0)));
    }

    if (ui->graphView->graph(3)){
        ui->graphView->graph(3)->setPen(QPen(QColor(60, 222, 0)));
    }

    if (ui->graphView->graph(4)){
        ui->graphView->graph(4)->setPen(QPen(QColor(200, 40, 5)));
    }

    if (ui->graphView->graph(5)){
        ui->graphView->graph(5)->setPen(QPen(QColor(80, 90, 73)));
    }

    if (ui->graphView->graph(6)){
        ui->graphView->graph(6)->setPen(QPen(QColor(32, 40, 80)));
    }

    if (ui->graphView->graph(7)){
        ui->graphView->graph(7)->setPen(QPen(QColor(20, 37, 20)));
    }

    if (ui->graphView->graph(8)){
        ui->graphView->graph(8)->setPen(QPen(QColor(160, 10, 2)));
    }

    if (ui->graphView->graph(9)){
        ui->graphView->graph(9)->setPen(QPen(QColor(5, 40, 59)));
    }

    ui->graphView->legend->setVisible(true);
    ui->graphView->replot();

}

void GraphWindow::exportToImage()
{
      //file browser to save image
        QString filename = QFileDialog::getSaveFileName(this, tr("Save Image As"), "/home/student/untitled.jpg", tr("Images (*.bmp *.png *.jpg)"));
        //set buttons to invisible so they wont show in the image
        ui->visible->setVisible(false);
        ui->complete->setVisible(false);
        ui->barGraph->setVisible(false);
        ui->lineGraph->setVisible(false);
        ui->exporter->setVisible(false);
        //take a picture of GraphWindow
        QPixmap pixmap(this->size());
        this->render(&pixmap);
        pixmap.save(filename);
        //make buttons visible again
        ui->visible->setVisible(true);
        ui->complete->setVisible(true);
        ui->barGraph->setVisible(true);
        ui->lineGraph->setVisible(true);
        ui->exporter->setVisible(true);
        
        //User feedback
        QFile f(filename);
        if(f.exists())
        {
            std::cout << filename.toStdString() + " has been saved to file" << std::endl;
            QErrorMessage *confirmationMsg = new QErrorMessage(this);
            confirmationMsg->showMessage("Graph Successfully Exported To" + filename + "!");
            confirmationMsg->show();
        }
        else
        {
            std::cout << "There was an error when saving the file." << std::endl;
            QErrorMessage *errorMsg = new QErrorMessage(this);
            errorMsg->showMessage("Error! File did not save.");
            errorMsg->show();
        }
}
