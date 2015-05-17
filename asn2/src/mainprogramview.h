/**
 *@file MainProgramView.h
 *@author Group 4
 *@brief MainProgramView class handles main application UI functionality           
 *                                                
 *Allows users to pick service areas and measures and presents a data table with the option to filter out data. Table can be exported as a .csv file.                                                                       
 *                                                                     
 */
#ifndef MAINPROGRAMVIEW_H
#define MAINPROGRAMVIEW_H

#include <QDialog>
#include <QStandardItemModel>
#include <QStandardItem>
#include "ombidatabase.h"
#include "graphwindow.h"
#include <vector>


namespace Ui {
class MainProgramView;
}

class MainProgramView : public QDialog
{
    Q_OBJECT
    
public:

    /**
     * MainProgramView
     * @brief Constructor for MainProgramView class. Initializes the ui for this class.
     *
     * @param parent The parent widget item
     */
    explicit MainProgramView(QWidget *parent = 0);

    /**
     * ~MainProgramView
     * @brief Destructor for the MainProgramView class
     */
    ~MainProgramView();

    void loadFilters();


public slots:

    /**
     * measureSelectionPhase()
     * @brief Proceeds from selecting a municipal service area, to the selection of a specific service measure of interest to the user.
     */
    void measureSelectionPhase();

    /**
     * generateDataTable()
     * @brief displays the data table
	 *
	 * Based on the user's selection for service area and specific service measure,
     * program generates and displays a data table containing the measure data for
     * specified cities and years.
     */
    void generateDataTable();

    /**
     * restartTableCreation
     * @brief Function to allow the user to go back and select a new service area and service measure
     */
    void restartTableCreation();

    /**
     * writeCSV
     * @brief Function to export the table data to a csv file
     */
    void writeCSV();

    /**
     * measureChanged
     * @brief Slot that listens for a change in the selected measure and updates the UI accordingly
     */
    void measureChanged();

    /**
     * filtersChanged
     * @brief Slot that listens for a change in the filters and updates the UI accordingly
     */
    void filtersChanged();

    /**
     * updateFilters
     * @brief Slot that updates the filters to the profile set by the user
     */
    void updateFilters();

    /**
     * deleteFilter
     * @brief deletes filter from the list of saved filters
	 *
	 * Deletes the user specified filter from the
     * saved filters and refreshed the savedFilters
     * combo box accordingly
     */
    void deleteFilter();

    /**
     * saveFilter
     * @brief saves the filter to the list of saved filters
	 * 
	 * Prompts the user to name their selected filter set
     * and adds this set to the filter storage vectors
     */
    void saveFilter();

    /**
     * clearFilters
     * @brief Unchecks all filters
     */
    void clearFilters();

	/**
	* presentGraph()
	* @brief sends data to and Opens the graphWindow ui
	* 
	* Creates a GraphWindow and passes it a list of years, cities and the OMBI data.
	*/
    void presentGraph();
    
private:

    /**
     * ui
     * Instance of this class's ui object used to access ui elements
     */
    Ui::MainProgramView *ui;

    /**
     * _OMBIData
     * Instance of the OMBIDatabase class that interacts with the SQLite database file
     */
    OMBIDatabase *_OMBIData;

    /**
     * _currentCityFilters
     * QStringList holding the names of every currently
     * selected city filter
     */
    QStringList _currentCityFilters;

    /**
     * _currentYearFilters
     * Vector<int> holding the values of every currently
     * selected year filter
     */
    std::vector<int> _currentYearFilters;

    /**
     * _savedCityFilters
     * Map that stores all user created city filter profiles for this session
     * The maps will contain the user defined name of the filter, and a list of
     * checked cities for each named filter
     */
    std::map < QString, QStringList > _savedCityFilters;

    /**
     * _savedYearFilters
     * Map that stores all user created year filter profiles for this session
     * The maps will contain the user defined name of the filter, anda vector of
     * checked years for each named filter
     */
    std::map < QString, std::vector<int> > _savedYearFilters;

    bool graphType;
};

#endif // MAINPROGRAMVIEW_H
