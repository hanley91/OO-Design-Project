/****************************************************************************
 *                                                                          *
 *                            Author: Group 4                               *
 * MainProgramView.cpp - Implementation file for the MainProgramView class  *
 *                -Handles main application UI functionality                *
 *                                                                          *
 *                           November 14th, 2013                            *
 *                                                                          *
 *                                                                          *
 ***************************************************************************/
#include <iostream>
#include "mainprogramview.h"
#include "ui_mainprogramview.h"
#include <stdio.h>
#include <fstream>
#include <QErrorMessage>
#include <QFileDialog>
#include <QListWidget>
#include <complex>
#include <QInputDialog>

using std::vector;

/**
 * MainProgramView
 * Constructor for MainProgramView class. Initializes the ui for this class.
 *
 * @param parent The parent widget item
 */
MainProgramView::MainProgramView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainProgramView)
{   
    //Initialize the ui object
    ui->setupUi(this);

    graphType = false;

    //this->resize(606,619);

    //Hide all buttons that are user action sensitive
    ui->prompt_2->setHidden(true);
    ui->serviceMeasures->setHidden(true);
    ui->restart->setHidden(true);
    ui->exportToCSV->setHidden(true);
    ui->cityLabel->setHidden(true);
    ui->cityLister->setHidden(true);
    ui->yearLabel->setHidden(true);
    ui->yearLister->setHidden(true);
    ui->launcher->setHidden(true);
    ui->clearFilters->setHidden(true);
    ui->deleteFilter->setHidden(true);
    ui->savedFilters->setHidden(true);
    ui->saveFilter->setHidden(true);
    ui->loadFiltersLabel->setHidden(true);

    //Instantiate the instance of the database handling class
    try {
        _OMBIData = new OMBIDatabase();
    }
    catch (int e) {
        if (e == 0) {
            QErrorMessage *errorMsg = new QErrorMessage(this);
            errorMsg->showMessage("Unable to open database file.");
            errorMsg->show();
            std::cout<<"caught the 0" << std::endl;
            return;
        }
    }

    //Obtain a list of service areas
    QStringList _services = _OMBIData->services();

    //Add the list of service items to the service area combo box
    ui->serviceAreas->addItems(_services);

    //Connect the next button to its action, selecting a measure
    QObject::connect(ui->next, SIGNAL(pressed()), this, SLOT(measureSelectionPhase()));

    //Connect the restart button to its action, selecting a new service area and measure
    QObject::connect(ui->restart, SIGNAL(pressed()), this, SLOT(restartTableCreation()));

    //Connect the Export to CSV button to its action, writing the table to a CSV file
    QObject::connect(ui->exportToCSV, SIGNAL(pressed()), this, SLOT(writeCSV()));

    //Connect the QComboBox holding all of the measures to the slot that will update the UI
    QObject::connect(ui->serviceMeasures, SIGNAL(currentIndexChanged(int)), this, SLOT(measureChanged()));

    //Connect the city and year filter lists with the slot that will update the UI
    QObject::connect(ui->cityLister, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(filtersChanged()));
    QObject::connect(ui->yearLister, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(filtersChanged()));

    //Connect the graph button with the slot that will open the graph window
    QObject::connect(ui->launcher, SIGNAL(pressed()), this, SLOT(presentGraph()));

    //Connect the clearFilters button with the slot to clear the filters
    QObject::connect(ui->clearFilters, SIGNAL(pressed()), this, SLOT(clearFilters()));

    //Connect the saveFilter button with the slot to save the filters
    QObject::connect(ui->saveFilter, SIGNAL(pressed()), this, SLOT(saveFilter()));

    //Connect the deleteFilter button with the slot to delete a filter from the saved filters
    QObject::connect(ui->deleteFilter, SIGNAL(pressed()), this, SLOT(deleteFilter()));

    //Connect the savedFilters combo box to the slot that will update the filters in the GUI
    QObject::connect(ui->savedFilters, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFilters()));
}

/**
 * ~MainProgramView
 * Destructor for the MainProgramView class
 */
MainProgramView::~MainProgramView()
{
    //Delete items when MainProgramView class is no longer needed
    delete ui;
    delete _OMBIData;
}

/**
 * measureSelectionPhase()
 * Proceeds from selecting a municipal service area, to the selection
 * of a specific service measure of interest to the user.
 */
void MainProgramView::measureSelectionPhase()
{
    //Obtain the currently selected service area
    QString currentlySelected = ui->serviceAreas->currentText();

    //Set the current service area for the database handling class
    _OMBIData->setCurrentService(currentlySelected);

    //Obtain the list of service measures for the given service area
    QStringList _measures = _OMBIData->measures();

    //Hide the buttons, labels, and combo boxes from the previous step (Selecting the service)
    ui->prompt->setHidden(true);
    ui->serviceAreas->setHidden(true);
    ui->next->setHidden(true);

    //Show the buttons, labels, and combo boxes for the next step (Selecting the measure)
    ui->prompt_2->setHidden(false);
    ui->serviceMeasures->setHidden(false);
    ui->restart->setHidden(false);
    ui->cityLabel->setHidden(false);
    ui->cityLister->setHidden(false);
    ui->yearLabel->setHidden(false);
    ui->yearLister->setHidden(false);
    ui->clearFilters->setHidden(false);
    ui->deleteFilter->setHidden(false);
    ui->savedFilters->setHidden(false);
    ui->saveFilter->setHidden(false);
    ui->loadFiltersLabel->setHidden(false);

    _OMBIData->setCurrentMeasure(_measures.first());
    if (_currentCityFilters.isEmpty() && _currentYearFilters.empty()) {
        _currentCityFilters = _OMBIData->relevantCities();
        _currentYearFilters = _OMBIData->years();
        loadFilters();
        std::cout<<"wasEmpty"<<std::endl;
    }


    //Add the available service measures to the service measure combo box
    ui->serviceMeasures->addItems(_measures);

    //Obtain the currently selected measure
    QString currentlySelectedMeasure = ui->serviceMeasures->currentText();

    //Set the current service measure for the database handling class
    _OMBIData->setCurrentMeasure(currentlySelectedMeasure);



}

/**
 * generateDataTable()
 * Based on the user's selection for service area and specific service measure,
 * program generates and displays a data table containing the measure data for
 * specified cities and years.
 */
void MainProgramView::generateDataTable()
{

    ui->launcher->setHidden(false);
    //Obtain the list of cities
    QStringList cityList;
    for (int i = 0; i < ui->cityLister->count(); i++) {
        if (ui->cityLister->item(i)->checkState()) {
            cityList.append(ui->cityLister->item(i)->text());
        }
    }

    // obtain years from the filters
    vector<int> years;
    for (int i = 0; i < ui->yearLister->count(); i++) {
        if (ui->yearLister->item(i)->checkState()) {
            years.push_back(ui->yearLister->item(i)->text().toInt());
        }
    }

    //Create a new model for displaying data in the table view
    QStandardItemModel *model = new QStandardItemModel(cityList.size(),years.size(),this);

    //Add the row labels
    for (int i=0; i<cityList.size(); i++){
        model->setVerticalHeaderItem(i, new QStandardItem(QString(cityList.at(i))));
    }

    //add the column labels
    for (int i = 0; i < years.size(); i++) {
        model->setHorizontalHeaderItem(i, new QStandardItem(QString::number(years.at(i))));
    }
    for (int j = 0; j < years.size(); j++) {
        //Add all the data for the jth column/year
        QStringListIterator i1(cityList);
        //While iterator has a new element
            while (i1.hasNext()){
                //For all cities
                for (int i=0;i<cityList.size();i++){
                    //Create new standard item from a data point
                    QStandardItem *t1 = new QStandardItem(QString::number(_OMBIData->getDataPoint(i1.next(),years.at(j)), 'g', 9));
                    //Set the item's value
                    model->setItem(i,j,t1);
                }
            }
    }

    //Set the tableview's model
    ui->tableView->setModel(model);

    //make sure the user can't edit the table
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Show the table view
    ui->exportToCSV->setHidden(false);

    ui->tableView->repaint();
}

/**
 * restartTableCreation
 * Function to allow the user to go back and select a new service area and
 * service measure
 */
void MainProgramView::restartTableCreation()
{
    ui->cityLister->clear();
    ui->yearLister->clear();

    //Hide the table view
    ui->exportToCSV->setHidden(true);
    ui->launcher->setHidden(true);
    ui->cityLabel->setHidden(true);
    ui->cityLister->setHidden(true);
    ui->yearLabel->setHidden(true);
    ui->yearLister->setHidden(true);
    ui->launcher->setHidden(true);
    ui->clearFilters->setHidden(true);
    ui->deleteFilter->setHidden(true);
    ui->savedFilters->setHidden(true);
    ui->saveFilter->setHidden(true);
    ui->loadFiltersLabel->setHidden(true);

    //this->resize(606,619);

    //Clear the service measures combo box
    ui->serviceMeasures->clear();

    //Clear the service areas combo box
    ui->serviceAreas->clear();

    //Obtain the list of service areas
    QStringList _services = _OMBIData->services();

    //Repopulate service areas into the combo box
    ui->serviceAreas->addItems(_services);

    //Reset the current list of service measures in the database handling class
    _OMBIData->resetMeasures();

    //Show the ui elements from the first step (Service area selection)
    ui->prompt->setHidden(false);
    ui->serviceAreas->setHidden(false);
    ui->next->setHidden(false);

    //Hide the ui elements from the second step (Service measure selection)
    ui->prompt_2->setHidden(true);
    ui->serviceMeasures->setHidden(true);
    ui->restart->setHidden(true);

}

/**
 * writeCSV
 * Function to export the table data to a csv file
 */
void MainProgramView::writeCSV()
{

    //Get file name and path from the user
    QString filename = QFileDialog::getSaveFileName(this, tr("Save Table As"), "/home/untitled.csv", tr("CSV (*.csv)"));

    QString temp;
    //Open a new file for the csv document
    FILE *f = fopen(filename.toStdString().c_str(), "w");
    if (f == NULL) {
        QErrorMessage *errorMsg = new QErrorMessage(this);
        errorMsg->showMessage("Could not save file to: " + filename + ".");
        errorMsg->show();
        return;
    }

    //write the initial blank column header to file
    fprintf(f, "%s", ",");

    QAbstractItemModel *model2 = ui->tableView->model();

    // first we need to write the horizontal header to the file
    for (int i = 0; i < model2->columnCount(); i++){
        // if the current header item is not the last, append a comma
        if (i < model2->columnCount() - 1) {
            temp = model2->headerData(i,Qt::Horizontal,0).toString() + ",";
            fprintf(f, "%s", temp.toStdString().c_str());
        }
        // if the current header item is the last, append a new line
        else {
            temp = model2->headerData(i,Qt::Horizontal,0).toString() + "\n";
            fprintf(f, "%s", temp.toStdString().c_str());
        }
    }


    // now we need to write the data and the vertical header to file
    for (int i = 0; i < model2->rowCount(); i++) {

        // write the vertical header data to file for each row
        temp = model2->headerData(i,Qt::Vertical,0).toString() + ",";
        fprintf(f, "%s", temp.toStdString().c_str());

        // write the data for each row
        for (int j = 0; j < model2->columnCount(); j++) {

            // if the current item is not the last in the row, append a comma
            if (j < model2->columnCount() - 1) {
                temp = model2->data(model2->index(i,j)).toString() + ",";
                fprintf(f, "%s", temp.toStdString().c_str());
            }

            // if the current item is the last in the row, append a new line
            else {
                temp = model2->data(model2->index(i,j)).toString() + "\n";
                fprintf(f, "%s", temp.toStdString().c_str());
            }
        }
    }

    //Close the file
    fclose(f);
    std::cout << filename.toStdString() + "has been written to build directory" << std::endl;
    //File is written to the build directory
    QErrorMessage *confirmationMsg = new QErrorMessage(this);
    confirmationMsg->showMessage("CSV File Successfully Exported To" + filename + "!");
    confirmationMsg->show();

}

/**
 * loadFilters
 * Pulls the possible cities and years for this measure from the
 * database and uses them to create a list of filters for the user
 * to choose from
 */
void MainProgramView::loadFilters()
{
    // get the cities for this measure
    QStringList cities;
    cities = _OMBIData->relevantCities();

    // add these cities to the QListWidget storing city filters
    QStringListIterator i1(cities);
    ui->cityLister->clear();
    while (i1.hasNext()){
        ui->cityLister->addItem(i1.next());
    }
    ui->cityLister->update();

    // set all filters to checked by default (when the program is first run)
    for (int i=0;i<ui->cityLister->count();i++){
        QListWidgetItem *item = ui->cityLister->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Checked);
    }

    // get the years from the database
    vector<int> yrs;
    yrs = _OMBIData->years();

    // add these years to the QListWidget storing year filters
    ui->yearLister->clear();
    for (int i=0;i<yrs.size();i++){
        ui->yearLister->addItem(QString::number(yrs.at(i)));
    }
    ui->yearLister->update();

    // set all filters to checked by default
    for (int i=0;i<ui->yearLister->count();i++){
        QListWidgetItem *item = ui->yearLister->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Checked);
    }
}

/**
 * measureChanged
 * Reloads the table for the new measure and carries over all checked filters
 * from the previous measure that are still applicable
 */
void MainProgramView::measureChanged() {
    _OMBIData->setCurrentMeasure(ui->serviceMeasures->currentText());
    loadFilters();

    // loop through filter checkboxes
    for (int i = 0; i < ui->cityLister->count(); i++) {
        QListWidgetItem *item = ui->cityLister->item(i);
        QString temp = item->text();
        bool wasChecked = false;

        // loop through list of previous filter selections
        // and check any filters that were checked previously
        for (int j = 0; j < _currentCityFilters.size(); j++) {
            if (temp.compare(_currentCityFilters.at(j)) == 0) {
                wasChecked = true;
            }
        }
        if (wasChecked) {
            item->setCheckState(Qt::Checked);
        }
        else {
            item->setCheckState(Qt::Unchecked);
        }
    }

    // do the same as above but for the year filters
    for (int i = 0; i < ui->yearLister->count(); i++) {
        QListWidgetItem *item = ui->yearLister->item(i);
        int temp = item->text().toInt();
        bool wasChecked = false;
        for (int j = 0; j < _currentYearFilters.size(); j++) {
            if (temp == _currentYearFilters.at(j)) {
                wasChecked = true;
            }
        }
        if (wasChecked) {
            item->setCheckState(Qt::Checked);
        }
        else {
            item->setCheckState(Qt::Unchecked);
        }
    }

    generateDataTable();
}

/**
 * filtersChanged
 * Slot that listens for changes in the filters and reloads the table
 * whenever they are changed
 */
void MainProgramView::filtersChanged() {
    // start tracking user filter changes
    // save the current city filters
    _currentCityFilters.clear();
    for (int i = 0; i < ui->cityLister->count(); i++) {
        if (ui->cityLister->item(i)->checkState()) {
            _currentCityFilters.append(ui->cityLister->item(i)->text());
        }
    }

    // save the current year filters
    _currentYearFilters.clear();
    for (int i = 0; i < ui->yearLister->count(); i++) {
        if (ui->yearLister->item(i)->checkState()) {
            _currentYearFilters.push_back(ui->yearLister->item(i)->text().toInt());
        }
    }
    generateDataTable();
}

/**
 * updateFilters
 * Slot that updates the filters to the profile
 * set by the user
 */
void MainProgramView::updateFilters() {

    QString toExtract = ui->savedFilters->currentText();
    QStringList savedCityFilters;
    std::vector<int> savedYearFilters;

    // extract the city list associated with the currently selected filter
    for (std::map< QString, QStringList >::iterator it = _savedCityFilters.begin(); it != _savedCityFilters.end(); ++it) {
        QString name = it->first;
        if (name.compare(toExtract) == 0) {
            savedCityFilters = it->second;
        }
     }

    // extract the year vector associated with the currently selected filter
    for (std::map< QString, std::vector<int> >::iterator it = _savedYearFilters.begin(); it != _savedYearFilters.end(); ++it) {
        QString name = it->first;
        if (name.compare(toExtract) == 0) {
            savedYearFilters = it->second;
        }
     }

    // update the city filters on the UI to correspond with those
    // in the saved profile
    for (int i = 0; i < ui->cityLister->count(); i++) {
        QListWidgetItem *item = ui->cityLister->item(i);
        QString temp = item->text();
        bool wasChecked = false;
        for (int j = 0; j < savedCityFilters.size(); j++) {
            if (temp.compare(savedCityFilters.at(j)) == 0) {
                wasChecked = true;
            }
        }
        if (wasChecked) {
            item->setCheckState(Qt::Checked);
        }
        else {
            item->setCheckState(Qt::Unchecked);
        }
    }

    // update the year filters on the UI to correspond with those
    // in the saved profile
    for (int i = 0; i < ui->yearLister->count(); i++) {
        QListWidgetItem *item = ui->yearLister->item(i);
        int temp = item->text().toInt();
        bool wasChecked = false;
        for (int j = 0; j < savedYearFilters.size(); j++) {
            if (temp == savedYearFilters.at(j)) {
                wasChecked = true;
            }
        }
        if (wasChecked) {
            item->setCheckState(Qt::Checked);
        }
        else {
            item->setCheckState(Qt::Unchecked);
        }
    }

    // tell the UI that the filters have changed
    filtersChanged();
}

/**
 * deleteFilter
 * Deletes the user specified filter from the
 * saved filters and refreshed the savedFilters
 * combo box accordingly
 */
void MainProgramView::deleteFilter() {
    QString toDelete = ui->savedFilters->currentText();
    std::map< QString,QStringList > temp;

    // loop through the city map and add the map entries that are not
    // keyed with the string filter name we want to delete to a temporary map
    for (std::map< QString, QStringList >::iterator it = _savedCityFilters.begin(); it != _savedCityFilters.end(); ++it) {
        QString name = it->first;
        QStringList cities = it->second;
        if (!name.compare(toDelete) == 0) {
            temp[name] = cities;
        }
    }

    // set the filter map to the temporary map that was just populated.
    _savedCityFilters=temp;

    // clear the combo box holding the filters and repopulate it
    ui->savedFilters->clear();
    for (std::map< QString, QStringList >::iterator it = _savedCityFilters.begin(); it != _savedCityFilters.end(); ++it) {
        ui->savedFilters->addItem(it->first);
    }
}

/**
 * saveFilter
 * Prompts the user to name their selected filter set
 * and adds this set to the filter storage vectors
 */
void MainProgramView::saveFilter() {

    // get current filters for cities and years
    QStringList temp = _currentCityFilters;
    std::vector<int> temp2 = _currentYearFilters;
    bool ok;
    QString saveName;

    // get the filter name from the user
    QString text = QInputDialog::getText(this,tr("File saving"),tr("Filter name:"), QLineEdit::Normal, QDir::home().dirName(), &ok);

    // if the user clicks ok and the text inputted was not empty
    // add this entry to the filter combobox and add the filter
    // lists to the filter map
    if (ok && !text.isEmpty()){
        saveName = text;
        _savedCityFilters[saveName] = temp;
        _savedYearFilters[saveName] = temp2;
        ui->savedFilters->addItem(saveName);
    }
    // set the QComboBox to highlight the newly saved profile
    ui->savedFilters->setCurrentIndex(ui->savedFilters->findText(saveName));
}

/**
 * clearFilters
 * Unchecks all filters
 */
void MainProgramView::clearFilters() {

    // loop through city filters and clear them all
    for (int i = 0; i < ui->cityLister->count(); i++) {
        ui->cityLister->item(i)->setCheckState(Qt::Unchecked);
    }

    // loop through year filters and clear them all
    for (int i = 0; i < ui->yearLister->count(); i++) {
        ui->yearLister->item(i)->setCheckState(Qt::Unchecked);
    }

    filtersChanged();
}


void MainProgramView::presentGraph()
{
    //Obtain the list of cities
    QStringList cityList;
    for (int i = 0; i < ui->cityLister->count(); i++) {
        if (ui->cityLister->item(i)->checkState()) {
            cityList.append(ui->cityLister->item(i)->text());
        }
    }

    // loop through the years in the database to create
    // headers for the columns
    vector<int> years;
    for (int i = 0; i < ui->yearLister->count(); i++) {
        if (ui->yearLister->item(i)->checkState()) {
            years.push_back(ui->yearLister->item(i)->text().toInt());
        }
    }

    GraphWindow newView;
    newView.setGraph(_OMBIData, years, cityList);
    newView.exec();
}
