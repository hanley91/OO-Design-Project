/**
* @file GraphWindow.h
* @author Group4
* @brief This class contains all the code associated with graphs. Setting up the Graph UI Window, drawing the graphs, and saving them as images on the filesystem 
*
* The program allows for the data to be generated as a Bar Graph or a Line Graph. Filters can be applied to sort out any data the user does not wish to view.
* The user can also save the graph as an image to the filesystem as a PNG, BMP or JPG.
*/
#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include "ombidatabase.h"
#include <vector>
#include <QFileDialog>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog
{
    Q_OBJECT
    
public:
/**
 * GraphWindow
 * @brief Constructor for the GraphWindow class. Initializes the ui for this class
 * 
 * @param parent The parent widget item
 */
    explicit GraphWindow(QWidget *parent = 0);
    ~GraphWindow();
	
	/**
	 * setGraph
	* @brief prepares the data for graphing and draws the graph
	*
	* Draws a graph based on currently selected data and filters using QCustomPlot. 
	* 
	* @param data    The OMBIDatabase data
	* @param y       A vector of years
	* @param c       QStringList of cities
	*/
    void setGraph(OMBIDatabase *data, vector<int> y, QStringList c);

public slots:
	/**
	 * visibleMean
	* @brief displays mean of filtered data on the graph
	*
	* called from a button. Displays the mean of the data after filters have been applied.
	*/
    void visibleMean();
	
	/**
	 * completeMean
	* @brief Displays a mean line of the unfiltered data on the graph
	*
	* called from a button. Displays the mean of the unfiltered data on the graph.
	*/
    void completeMean();
	
	/**
	 * toggleLineGraph
	* @brief Switches the current graph to a Line Graph format
	*
	* called from a button to switch the current graph to a Line Graph from the default Bar Graph.
	*/
    void toggleLineGraph();
	
	/**
	 * toggleBarGraph
	* @brief Switches the current graph to a Bar Graph format.
	* 
	* called from a button to switch back to a bar graph format from the line graph. 
	*/
    void toggleBarGraph();
	
	/**
	 * exportToImage
	* @brief saves the graph as an image file on the filesystem at a user specified destination
	*
	* Uses QFileDialog as a file browser so user can select a destination for the file. Saves as JPG, PNG or BMP.
	* QPixmap is used to take a picture of the current active window(in this case the graph window). Buttons set to invisible so they wont show in the picture.
	*/
    void exportToImage();
    
private:
    Ui::GraphWindow *ui;
    OMBIDatabase *dataAccess;
    vector<int> yearValues;
    QStringList cityNames;
};

#endif // GRAPHWINDOW_H
