/**
 *@file OMBIDatabase.h                                                             
 *@author Group 4                         
 *        
 *@brief OMBIDatabase class handles opening of the SQLite database file, also handles reading and parsing of data from database
 *                                                                                                                                                          
 */
#ifndef OMBIDATABASE_H
#define OMBIDATABASE_H

#include <QObject>
#include <QApplication>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QString>
#include <QStringList>
#include <vector>
#include <map>

using std::vector;

class OMBIDatabase : public QObject{

    Q_OBJECT

public:

    /**
     * OMBIDatabase
     * @brief Constructor for the OMBIDatabase class. Initializes opening of SQLite database.
     */
    OMBIDatabase();

    /**
     * ~OMBIDatabase
     * @brief Destructor for the OMBIDatabase class.
     */
    ~OMBIDatabase();

    /**
     * services
     * @brief Function to access the database table corresponding to the list of service areas.
     *
     * @return A QStringList containing all selectable service areas
     */
    QStringList services();

    /**
     * currentService
     * @brief Function to retrieve the currently selected service area.
     *
     * @return A QString containing the name of the current service area
     */
    QString currentService();

    /**
     * measures
     * @brief Function to access the database table corresponding to the list of service measures for a given service area.
     *
     * @return A QStringList containing all selectable service measures
     */
    QStringList measures();

    /**
     * currentMeasure
     * @brief Function to retrieve the currently selected service measure
     *
     * @return A QString containing the name of the current service measure
     */
    QString currentMeasure();

    /**
     * currentMeasureID
     * @brief Function to retrieve the measure ID associated with the currently selected measure
     *
	 * @return A QString containing the ID of the current measure
     */
    QString currentMeasureID();

    /**
     * cities
     * @brief Function to retrieve a list of all selectable cities
     *
     * @return A QStringList containing all cities that are present in the database
     */
    QStringList cities();

    /**
     * relevantCities
     * @brief Function to retrieve a list of all selectable cities for current measure
     *
     * @return A QStringList containing all cities that are available under the current measure
     */
    QStringList relevantCities();

    /**
     * years
     * @brief Function to retrieve all years contained in the database
     *
     * @return A Vector containing all years present in the database
     */
    vector<int> years();

    /**
     * getDataPoint
     * @brief Function to obtain a data value for a service measure for a particular city and year.
     *
     * @param city The city selected for the given data point
     * @param year The year selected for the given data point
     *
     * @return A Double value containing the actual measure for the selected city
     * and year
     */
    double getDataPoint(QString city, int year);

    /**
     * getDataPoint
     * @brief Function to obtain all data for the current service and measure
     *
     *
     * @return A vector containing all data points for the current measure
     */
    vector< vector< QString > > getAllDataPoints();

    /**
     * meanAll
     * @brief Function to calculate the mean across all cities and years selected for a given service area's service measure.
     *
     * @return A Double value describing the mean value for all selected measure values
     */
    double meanAll();

    /**
     * meanCurrent
     * @brief Function to calculate the mean across specified cities and years for a given service area's service measure.
     *
     * @return A Double value describing the mean value for all selected measure values
     */
    double meanCurrent(QStringList cities, vector<int> years);

    /**
     * getMaxForCurrent
     * @brief Function that gets the max value for the given list of cities and years
	 *
     * @param cities list of cities
     * @param years vector of years
	 *
     * @return double containing the maximum value for these given cities and years
     */
    double getMaxForCurrent(QStringList cities, vector<int> years);

    /**
     * getMinForCurrent
     * @brief Function that gets the min value for the given list of cities and years
     * 
     * @param cities list of cities
     * @param years vector of years
	 *
     * @return double containing the minimum value for these given cities and years
     */
    double getMinForCurrent(QStringList cities, vector<int> years);

    /**
     * setCurrentService
     * @brief Function to set the current service area for the purpose of querying for available service measures.
     *
     * @param service The name of the service area that was selected
     */
    void setCurrentService(QString service);

    /**
     * setCurrentMeasure
     * @brief Function to set the current service measure for the purpose of querying for all relevant measure values.
     *
     * @param measure The name of the service measure selected
     */
    void setCurrentMeasure(QString measure);

    /**
     * resetMeasures
     * @brief Function to reset the list of service measures
     */
    void resetMeasures();


public slots:

signals:

private:

    /**
     * _services
     * QStringList to store the list of all available service areas
     */
    QStringList _services;

    /**
     * _currentService
     * QString to store the name of the currently selected service area
     */
    QString _currentService;

    /**
     * _measures
     * QStringList to store the list of all available service measures
     * for a given service area
     */
    QStringList _measures;

    /**
     * _measureMap
     *  map that stores the QString description of a measure and the
     *  QString ID of a measure as a pair
     */
    std::map<QString, QString> _measureMap;

    /**
     * _currentMeasure
     * QString to store the name of the currently selected service measure
     */
    QString _currentMeasure;

    /**
     * _cities
     * QStringList to store the list of all available cities
     */
    QStringList _cities;

    /**
     * _years
     * A Vector containing all years available for measure data
     */
    vector<int> _years;

    /**
     * _OMBIData
     * QSqlDatabase item to hold the database containing all OMBI data
     */
    QSqlDatabase _OMBIData;

    /**
     * loadServices
     * @brief Function to load all available service areas from the database file
     */
    void loadServices();

    /**
     * loadMeasures
     * @brief Function to load all available service measures for a given service area from the database file
     */
    void loadMeasures();

    /**
     * loadCities
     * @brief Function to load all available cities present in the service measure table in the database file
     */
    void loadCities();

    /**
     * loadYears
     * @brief Function to load all available years present in the service measure table in the database file
     */
    void loadYears();
};

#endif // OMBIDATABASE_H
