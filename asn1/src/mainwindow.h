/*******************************************************************************
 *                                Author: Group 4                              *
 *                 mainwindow.h-Header File for the mainwindow class           *
 *                         -Handles the majority of the UI                     *
 *                     -Handles the plotting of hard coded data                *
 *                                                                             *
 *                               October 23rd, 2013                            *
 *                                                                             *
 *                                                                             *
 ******************************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "firedataclass.h"
#include <QVector>
#include <string>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    /**
     * MainWindow Constructor
     * Initializes the MainWindow class and its data members
     *
     * @param parent The parent widget item
     */
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

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
    void setAndDisplayAll(QVector<double> nms, QVector<double> d1, QVector<double> d2, QVector<double> d3, QVector<QString> l);

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
    void setAndDisplayDynamic(QVector<double> nms, QVector<double> d1, QVector<double> d2, QVector<double> d3,
                              QVector<QString> l);

public slots:

    /**
     * updatePlotGraphics()
     * Slot function to handle "Update Plot" button click action. Determines the display function to call.
     */
    void updatePlotGraphics();
    
private:

    /**
     * ui
     * Instance of the ui for accessing individual or entire UI elements
     */
    Ui::MainWindow *ui;

    /**
     * dataSet
     * Instance of the fireDataClass, used for retrieving the hard coded data elemnets
     */
    fireDataClass *dataSet;

};

#endif // MAINWINDOW_H
