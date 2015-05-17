/*******************************************************************************
 *                                Author: Group 4                              *
 *             mainwindow.m-Implementation File for the mainwindow class       *
 *                         -Handles the majority of the UI                     *
 *                     -Handles the plotting of hard coded data                *
 *                                                                             *
 *                               October 23rd, 2013                            *
 *                                                                             *
 *                                                                             *
 ******************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * MainWindow Constructor
 * Initializes the MainWindow class and its data members
 *
 * @param parent The parent widget item
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize dataSet to a new instance of the FireDataClass
    dataSet = new fireDataClass();

    //Connect the press action of the "Update Plot" button to the updatePlotGraphics() slot
    QObject::connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(updatePlotGraphics()));

    //Initialize the QCustomPlot widget, prepare for display
    ui->graph->addGraph();

    //Set the label of the x-axis to "Cities"
    ui->graph->xAxis->setLabel("Cities");

    //Turn off QCustomPlot's auto tick feature (will customize to needs)
    ui->graph->xAxis->setAutoTicks(false);

    //Turn off QCustomPlot's auto label feature (will customize to needs)
    ui->graph->xAxis->setAutoTickLabels(false);

    //Set the range of the x-axis to fit all the data in the best way possible
    ui->graph->xAxis->setRange(0, 33);

    //Set the spacing between tick marks on the x-axis
    ui->graph->xAxis->setTickLength(0, 10);

    //Set the city name labels to be rotated 60 degrees for readability
    ui->graph->xAxis->setTickLabelRotation(60);

    //Set the amount of non-major ticks to be displayed to zero
    ui->graph->xAxis->setSubTickCount(0);

    //Set the label for the y-axis to be "# Res. Structural Fires with Losses / 1000 Households"
    ui->graph->yAxis->setLabel("# Res. Structural Fires with Losses / 1000 Households");

    //Set the tick marks for the x-axis to be the contents of the QVector containing the values
    //for the pre-calculated tick spacing
    ui->graph->xAxis->setTickVector(dataSet->cityListRetrievalAll());

    //Set the labels for the x-axis to be the contents of the QVector containing all the names of all cities
    ui->graph->xAxis->setTickVectorLabels(dataSet->cityListRetrievalAllNames());

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * updatePlotGraphics()
 * Slot function to handle "Update Plot" button click action. Determines the display function to call.
 */
void MainWindow::updatePlotGraphics()
{

    //Check to see if every box has been checked...
    if (
            ui->c1->isChecked() &&
            ui->c2->isChecked() &&
            ui->c3->isChecked() &&
            ui->c4->isChecked() &&
            ui->c5->isChecked() &&
            ui->c6->isChecked() &&
            ui->c7->isChecked() &&
            ui->c8->isChecked() &&
            ui->c9->isChecked() &&
            ui->c10->isChecked() &&
            ui->y1->isChecked() &&
            ui->y2->isChecked() &&
            ui->y3->isChecked()
            ){

        //If yes, then call the function to display the graph containing all bars
        setAndDisplayAll(dataSet->cityListRetrievalAll(), dataSet->retrieveAll2009(), dataSet->retrieveAll2010(),
                         dataSet->retrieveAll2011(), dataSet->cityListRetrievalAllNames());

    }

    else{
        //Otherwise, call the function to decide dynamically which bars should be displayed
        setAndDisplayDynamic(dataSet->cityListRetrievalAll(), dataSet->retrieveAll2009(), dataSet->retrieveAll2010(),
                         dataSet->retrieveAll2011(), dataSet->cityListRetrievalAllNames());
    }
}

/**
 * setAndDisplayAll(QVector<double> nms, QVector<double> d1, QVector<double> d2, QVector<double> d3, QVector<QString> l);
 *
 * Sets the relevant plot settings and plots it to the QCustomPlot widget. Specifically used to display all cities
 * and all years.
 *
 * @param nms QVector containing the values for the x-axis
 * @param d1 QVector containing the data points for all cities for 2009
 * @param d2 QVector containing the data points for all cities for 2010
 * @param d3 QVector containing the data points for all cities for 2011
 * @param l QVector coontaining all citie names for labelling the x-axis
 */
void MainWindow::setAndDisplayAll(QVector<double> nms, QVector<double> d1, QVector<double> d2, QVector<double> d3,
QVector<QString> l){

    //Clear the QCustomPlot widget of any pre-existing graphs
    ui->graph->clearPlottables();

    //Create a new set of bars for the year 2009
    QCPBars *set1 = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);

    //Create a new set of bars for the year 2010
    QCPBars *set2 = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);

    //Create a new set of bars for the year 2011
    QCPBars *set3 = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);

    //Add set1 as a plottable on the QCustomPlot widget item
    ui->graph->addPlottable(set1);

    //Add set2 as a plottable on the QCustomPlot widget item
    ui->graph->addPlottable(set2);

    //Add set3 as a plottable on the QCustomPlot widget item
    ui->graph->addPlottable(set3);

    //Update both the tick mark positions and labels
    ui->graph->xAxis->setTickVector(nms);
    ui->graph->xAxis->setTickVectorLabels(l);

    //Create a QVector to describe the positions for the 2009 data point bars
    QVector<double> set1positioning;
    set1positioning.append(1);
    set1positioning.append(4);
    set1positioning.append(7);
    set1positioning.append(10);
    set1positioning.append(13);
    set1positioning.append(16);
    set1positioning.append(19);
    set1positioning.append(22);
    set1positioning.append(25);
    set1positioning.append(28);

    //Create a QVector to describe the positions for the 2010 data point bars
    QVector<double> set2positioning;
    set2positioning.append(2);
    set2positioning.append(5);
    set2positioning.append(8);
    set2positioning.append(11);
    set2positioning.append(14);
    set2positioning.append(17);
    set2positioning.append(20);
    set2positioning.append(23);
    set2positioning.append(26);
    set2positioning.append(29);

    //Create a QVector to describe the positions for the 2011 data point bars
    QVector<double> set3positioning;
    set3positioning.append(3);
    set3positioning.append(6);
    set3positioning.append(9);
    set3positioning.append(12);
    set3positioning.append(15);
    set3positioning.append(18);
    set3positioning.append(21);
    set3positioning.append(24);
    set3positioning.append(27);
    set3positioning.append(30);

    //Set the name and data elements for set1
    set1->setName("2009");
    set1->setData(set1positioning, d1);

    //Set the name and data elements for set2
    set2->setName("2010");
    set2->setData(set2positioning, d2);

    //Set the name and data elements for set3
    set3->setName("2011");
    set3->setData(set3positioning, d3);

    //Initialize a QPen object to set unique colours for each bar set
    QPen pen;
    pen.setWidthF(1.2);
    pen.setColor(QColor(255, 131, 0));

    //Set the colour for bars from set1
    set1->setPen(pen);
    set1->setBrush(QColor(255, 131, 0, 50));

    //Set the colour for bars from set2
    pen.setColor(QColor(1, 92, 191));
    set2->setPen(pen);
    set2->setBrush(QColor(1, 92, 191, 50));

    //Set the colour for bars from set3
    pen.setColor(QColor(150, 222, 0));
    set3->setPen(pen);
    set3->setBrush(QColor(150, 222, 0, 70));

    //Update the QCustomPlot widget item to display the new graph
    ui->graph->replot();
}

/**
 * setAndDisplayDynamic(QVector<double> nms, QVector<double> d1, QVector<double> d2, QVector<double> d3, QVector<QString> l);
 *
 * Sets the relevant plot settings and plots it to the QCustomPlot widget. Specifically used to handle dynamic
 * city and year selection combinations.
 *
 * @param nms QVector containing the values for the x-axis
 * @param d1 QVector containing the data points for all cities for 2009
 * @param d2 QVector containing the data points for all cities for 2010
 * @param d3 QVector containing the data points for all cities for 2011
 * @param l QVector coontaining all citie names for labelling the x-axis
 */
void MainWindow::setAndDisplayDynamic(QVector<double> nms, QVector<double> d1, QVector<double> d2,
QVector<double> d3, QVector<QString> l)
{
    //Clear the QCustomPlot widget of any pre-existing graphs
    ui->graph->clearPlottables();

    //Initialize a QPen object for setting the colours of the different bar sets
    QPen pen;
    pen.setWidthF(1.2);

    //If the first city is not checked, set all years' QVector element at index 0 to 0
    if (!ui->c1->isChecked()){
        d1[0] = 0;
        d2[0] = 0;
        d3[0] = 0;
    }

    //If the second city is not checked, set all years' QVector element at index 1 to 0
    if (!ui->c2->isChecked()){
        d1[1] = 0;
        d2[1] = 0;
        d3[1] = 0;
    }

    //If the third city is not checked, set all years' QVector element at index 2 to 0
    if (!ui->c3->isChecked()){
        d1[2] = 0;
        d2[2] = 0;
        d3[2] = 0;
    }

    //If the fourth city is not checked, set all years' QVector element at index 3 to 0
    if (!ui->c4->isChecked()){
        d1[3] = 0;
        d2[3] = 0;
        d3[3] = 0;
    }

    //If the fifth city is not checked, set all years' QVector element at index 4 to 0
    if (!ui->c5->isChecked()){
        d1[4] = 0;
        d2[4] = 0;
        d3[4] = 0;
    }

    //If the sixth city is not checked, set all years' QVector element at index 5 to 0
    if (!ui->c6->isChecked()){
        d1[5] = 0;
        d2[5] = 0;
        d3[5] = 0;
    }

    //If the seventh city is not checked, set all years' QVector element at index 6 to 0
    if (!ui->c7->isChecked()){
        d1[6] = 0;
        d2[6] = 0;
        d3[6] = 0;
    }

    //If the eighth city is not checked, set all years' QVector element at index 7 to 0
    if (!ui->c8->isChecked()){
        d1[7] = 0;
        d2[7] = 0;
        d3[7] = 0;
    }

    //If the ninth city is not checked, set all years' QVector element at index 8 to 0
    if (!ui->c9->isChecked()){
        d1[8] = 0;
        d2[8] = 0;
        d3[8] = 0;
    }

    //If the tenth city is not checked, set all years' QVector element at index 9 to 0
    if (!ui->c10->isChecked()){
        d1[9] = 0;
        d2[9] = 0;
        d3[9] = 0;
    }

    //If the year 2009 is selected...
    if (ui->y1->isChecked()){

        //Create the set of bars for the 2009 data points (with unselected cities already omitted)
        QCPBars *set1 = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);

        //Add set1 as a plottable to the QCustomPlot widget
        ui->graph->addPlottable(set1);

        //Create a vector for the positioning of all 2009 data point bars
        QVector<double> set1positioning;
        set1positioning.append(1);
        set1positioning.append(4);
        set1positioning.append(7);
        set1positioning.append(10);
        set1positioning.append(13);
        set1positioning.append(16);
        set1positioning.append(19);
        set1positioning.append(22);
        set1positioning.append(25);
        set1positioning.append(28);

        //Set the name and the data elements for set1
        set1->setName("2009");
        set1->setData(set1positioning, d1);

        //Set the bar colour for set1
        pen.setColor(QColor(255, 131, 0));
        set1->setPen(pen);
        set1->setBrush(QColor(255, 131, 0, 50));
    }

    //If the year 2010 is selected...
    if (ui->y2->isChecked()){

        //Create the set of bars for the 2010 data points (with unselected cities already omitted)
        QCPBars *set2 = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);

        //Add set2 as a plottable to the QCustomPlot widget
        ui->graph->addPlottable(set2);

        //Create a vector for the positioning of all 2010 data point bars
        QVector<double> set2positioning;
        set2positioning.append(2);
        set2positioning.append(5);
        set2positioning.append(8);
        set2positioning.append(11);
        set2positioning.append(14);
        set2positioning.append(17);
        set2positioning.append(20);
        set2positioning.append(23);
        set2positioning.append(26);
        set2positioning.append(29);

        //Set the name and the data elements for set2
        set2->setName("2010");
        set2->setData(set2positioning, d2);

        //Set the bar colour for set2
        pen.setColor(QColor(1, 92, 191));
        set2->setPen(pen);
        set2->setBrush(QColor(1, 92, 191, 50));
    }

    //If the year 2011 is selected...
    if (ui->y3->isChecked()){

        //Create the set of bars for the 2011 data points (with unselected cities already omitted)
        QCPBars *set3 = new QCPBars(ui->graph->xAxis, ui->graph->yAxis);

        //Add set3 as a plottable to the QCustomPlot widget
        ui->graph->addPlottable(set3);

        //Create a vector for the positioning of all 2011 data point bars
        QVector<double> set3positioning;
        set3positioning.append(3);
        set3positioning.append(6);
        set3positioning.append(9);
        set3positioning.append(12);
        set3positioning.append(15);
        set3positioning.append(18);
        set3positioning.append(21);
        set3positioning.append(24);
        set3positioning.append(27);
        set3positioning.append(30);

        //Set the name and the data elements for set3
        set3->setName("2011");
        set3->setData(set3positioning, d3);

        //Set the bar colour for set3
        pen.setColor(QColor(150, 222, 0));
        set3->setPen(pen);
        set3->setBrush(QColor(150, 222, 0, 70));
    }

    //Update both the tick mark positions and labels
    ui->graph->xAxis->setTickVector(nms);
    ui->graph->xAxis->setTickVectorLabels(l);

    //Update the QCustomPlot widget's contents
    ui->graph->replot();
}
