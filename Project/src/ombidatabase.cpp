/************************************************************************
 *                                                                      *
 *                            Author: Group 4                           *
 *   OMBIDatabase.cpp - Implementation file for the OMBIDatabase class  *
 *                -Handles opening of the SQLite database file          *
 *             -Handles reading and parsing of data from database       *
 *                                                                      *
 *                           November 14th, 2013                        *
 *                                                                      *
 *                                                                      *
 ***********************************************************************/
#include "ombidatabase.h"
#include <iostream>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

using std::vector;

/**
 * OMBIDatabase
 * Constructor for the OMBIDatabase class. Initializes opening of SQLite database.
 */
OMBIDatabase::OMBIDatabase()
{

    _OMBIData = QSqlDatabase::addDatabase("QSQLITE");
    _OMBIData.setDatabaseName("/home/student/Desktop/group/asn2/src/OMBI.db");
    if (!_OMBIData.open()) {
        throw 0;
    }


    loadServices();
    loadCities();
    loadYears();
    _currentService = "";
    _currentMeasure = "";
}

/**
 * ~OMBIDatabase
 * Destructor for the OMBIDatabase class.
 */
OMBIDatabase::~OMBIDatabase() {

}

/**
 * services
 * Function to access the database table corresponding to the list of service areas.
 *
 * @return A QStringList containing all selectable service areas
 */
QStringList OMBIDatabase::services() {
    return _services;
}

/**
 * currentService
 * Function to retrieve the currently selected service area.
 *
 * @return A QString containing the name of the current service area
 */
QString OMBIDatabase::currentService() {
    return _currentService;
}

/**
 * measures
 * Function to access the database table corresponding to the list of service measures
 * for a given service area.
 *
 * @return A QStringList containing all selectable service measures
 */
QStringList OMBIDatabase::measures() {
    return _measures;
}

/**
 * currentMeasure
 * Function to retrieve the currently selected service measure
 *
 * @return A QString containing the name of the current service measure
 */
QString OMBIDatabase::currentMeasure() {
    for (std::map<QString, QString>::iterator it = _measureMap.begin(); it != _measureMap.end(); ++it) {
        QString temp1 = it->first;
        QString temp2 = it->second;

        if (temp2.compare(_currentMeasure) == 0) {
            return temp1;
        }
    }
}

/**
 * currentMeasureID
 * Function to retrieve the ID of the currently selected measure
 *
 * @return A QString containing the ID of the current service measure
 */
QString OMBIDatabase::currentMeasureID() {
    return _currentMeasure;
}

/**
 * cities
 * Function to retrieve a list of all selectable cities
 *
 * @return A QStringList containing all cities that are present in the database
 */
QStringList OMBIDatabase::cities() {
    return _cities;
}

/**
 * relevantCities
 * Function to retrieve a list of all selectable cities
 *
 * @return A QStringList containing all cities that are present in the database
 */
QStringList OMBIDatabase::relevantCities() {
    QSqlQuery query(_OMBIData);
    QString queryCommand = "SELECT DISTINCT Municipality FROM MeasureData WHERE MeasureID = '";
    queryCommand.append(_currentMeasure);
    queryCommand.append("'");

    QStringList relevantCities;
    query.exec(queryCommand);
    while(query.next()) {
         QSqlRecord record = query.record();
         relevantCities.append(record.value("Municipality").toString());
     }
     return relevantCities;
}

/**
 * years
 * Function to retrieve all years contained in the database
 *
 * @return A Vector containing all years present in the database
 */
vector<int> OMBIDatabase::years() {
    return _years;
}

/**
 * setCurrentService
 * Function to set the current service area for the purpose of querying for available
 * service measures.
 *
 * @param service The name of the service area that was selected
 */
void OMBIDatabase::setCurrentService(QString service) {
    if (service.compare("Fire Services")==0) {
        _currentService = "FIRE";
    }
    else if (service.compare("Police Services")==0) {
        _currentService = "PLCE";
    }
    else if (service.compare("Library Services")==0) {
        _currentService = "PLIB";
    }
    else if (service.compare("Parks Services")==0) {
        _currentService = "PRKS";
    }
    else if (service.compare("Waste Management Services")==0) {
        _currentService = "SWST";
    }
    else if (service.compare("Water Services")==0) {
        _currentService = "WATR";
    }
    loadMeasures();
}

/**
 * setCurrentMeasure
 * Function to set the current service measure for the purpose of querying for all
 * relevant measure values. The function uses the measureMap to ensure that
 * internal representation of the measure is by ID, not title.
 *
 * @param measure The name of the service measure selected
 */
void OMBIDatabase::setCurrentMeasure(QString measure) {
    for (std::map<QString, QString>::iterator it = _measureMap.begin(); it != _measureMap.end(); ++it) {
        QString temp1 = it->first;
        QString temp2 = it->second;

        if (temp1.compare(measure) == 0) {
            _currentMeasure = temp2;
        }
    }

}

/**
 * getDataPoint
 * Function to obtain a data value for a service measure for a particular city
 * and year.
 *
 * @param city The city selected for the given data point
 * @param year The year selected for the given data point
 *
 * @return A Double value containing the actual measure for the selected city
 * and year
 */
double OMBIDatabase::getDataPoint(QString city, int year) {

    // whenever the UI needs to draw the graph, it can call this function
    // for each filter that has been checked (city, year), and draw the
    // appropriate point on the graph

    // then we need to get the value for the measureID we just obtained
    // using the given city and year
    QString queryCommand = "SELECT Value FROM MeasureData WHERE MeasureID = '";
    queryCommand.append(_currentMeasure);
    queryCommand.append("' and Municipality = '");
    queryCommand.append(city);
    queryCommand.append("' and Year = '");
    queryCommand.append(QString::number(year));
    queryCommand.append("'");

    // print statement for testing
    //std::cout << queryCommand.toStdString() << std::endl;

    QSqlQuery query(_OMBIData);
    query.exec(queryCommand);
    query.next();
    double dataPoint = query.record().value("Value").toDouble();
    // print statement for testing
    // std::cout << dataPoint << std::endl;
    return dataPoint;
}

/**
 * getAllDataPoints
 * Function to obtain all data values for a service measure
 *
 * @return A Vector of QString Vectors where each column is a
 * year and each row is a city
 */
vector< vector< QString > > OMBIDatabase::getAllDataPoints() {

    // create the vector we will return
    vector< vector< QString> > allData;

    // create a vector that will be the header row
    // add the years and a blank to the vector
    vector<QString> firstRow;
    firstRow.push_back("");
    for (int i = 0; i < _years.size(); i++) {
        firstRow.push_back(QString::number(_years.at(i)));
    }

    // push this vector onto the final vector
    allData.push_back(firstRow);

    QSqlQuery query(_OMBIData);

    QStringList relevantCities = this->relevantCities();
    // loop through rows
    for (int i = 0; i < relevantCities.size(); i++) {
        vector<QString> newRow;
        newRow.push_back(relevantCities.at(i));
        // loop through columns
        for (int j = 0; j < _years.size(); j++) {

            //generate the SQL query for this city and year
            QString queryCommand = "SELECT Value FROM MeasureData WHERE MeasureID = '";
            queryCommand.append(_currentMeasure);
            queryCommand.append("' and Municipality = '");
            queryCommand.append(relevantCities.at(i));
            queryCommand.append("' and Year = '");
            queryCommand.append(QString::number(_years.at(j)));
            queryCommand.append("'");
            query.exec(queryCommand);
            query.next();

            //push the data from the query onto the vector
            // report double in standard format up to 9 digits before scientific notation is used
            newRow.push_back(QString::number(query.record().value("Value").toDouble(),'g',9));
            query.finish();
        }
        // push the new row onto the final vector
        allData.push_back(newRow);
    }

    // prints the vector as we would write it to CSV for testing
    /*
    QString temp;
    for (int h = 0; h < allData.size(); h++)
    {
        for (int i = 0; i < allData[h].size(); i++)
        {
            if (i == allData[h].size() -1)
            {
                temp = allData[h][i];
                std::cout<< temp.toStdString() << std::endl;
            }
            else
            {
                temp = allData[h][i] + ",";
                std::cout<< temp.toStdString();
            }
        }
    }
    */

    return allData;
}

/**
 * meanAll
 * Function to calculate the mean across all cities and years selected for
 * a given service area's service measure.
 *
 * @return A Double value describing the mean value for all selected measure values
 */
double OMBIDatabase::meanAll() {
    QSqlQuery query(_OMBIData);
    QString queryCommand = "SELECT Value FROM MeasureData WHERE MeasureID = '";
    queryCommand.append(_currentMeasure);
    queryCommand.append("'");

    int count = 0;
    double sum = 0;
    query.exec(queryCommand);

    // calculate average of all values
    while (query.next()) {
        QSqlRecord record = query.record();
        sum = sum + record.value("Value").toDouble();

        // only take the average of recorded values
        if (!record.value("Value").isNull()) {
            count++;
        }

    }
    return sum/count;
}


double OMBIDatabase::meanCurrent(QStringList cities, vector<int> years) {
    QSqlQuery query(_OMBIData);
    QString queryCommand;

    int count = 0;
    double sum = 0;

    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < years.size(); j++) {

            // generate SQL query for each city and year
            queryCommand = "SELECT Value FROM MeasureData WHERE MeasureID = '";
            queryCommand.append(_currentMeasure);
            queryCommand.append("' and Municipality = '");
            queryCommand.append(cities.at(i));
            queryCommand.append("' and Year = '");
            queryCommand.append(QString::number(years.at(j)));
            queryCommand.append("'");
            query.exec(queryCommand);
            query.next();

            QSqlRecord record = query.record();
            sum = sum + record.value("Value").toDouble();

            // only take the average of recorded values
            if (!record.value("Value").isNull()) {
                count++;
            }
        }
    }
    return sum/count;
}

/**
 * getMaxForCurrent
 * Function that gets the max value for the given list of cities
 * and years
 * @param cities list of cities
 * @param years vector of years
 * @return double containing the maximum value for these given cities and years
 */
double OMBIDatabase::getMaxForCurrent(QStringList cities, vector<int> years) {
    QSqlQuery query(_OMBIData);
    QString queryCommand;

    double max;
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < years.size(); j++) {

            // generate SQL query for each city and year
            queryCommand = "SELECT Value FROM MeasureData WHERE MeasureID = '";
            queryCommand.append(_currentMeasure);
            queryCommand.append("' and Municipality = '");
            queryCommand.append(cities.at(i));
            queryCommand.append("' and Year = '");
            queryCommand.append(QString::number(years.at(j)));
            queryCommand.append("'");
            query.exec(queryCommand);
            query.next();

            QSqlRecord record = query.record();
            double temp = record.value("Value").toDouble();
            if (i == 0 && j == 0) {
                max = temp;
            }
            if (temp > max) {
                max = temp;
            }
        }
    }
    return max;
}

/**
 * getMinForCurrent
 * Function that gets the min value for the given list of cities
 * and years
 * @param cities list of cities
 * @param years vector of years
 * @return double containing the minimum value for these given cities and years
 */
double OMBIDatabase::getMinForCurrent(QStringList cities, vector<int> years) {
    QSqlQuery query(_OMBIData);
    QString queryCommand;

    double min;
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < years.size(); j++) {

            // generate SQL query for each city and year
            queryCommand = "SELECT Value FROM MeasureData WHERE MeasureID = '";
            queryCommand.append(_currentMeasure);
            queryCommand.append("' and Municipality = '");
            queryCommand.append(cities.at(i));
            queryCommand.append("' and Year = '");
            queryCommand.append(QString::number(years.at(j)));
            queryCommand.append("'");
            query.exec(queryCommand);
            query.next();

            QSqlRecord record = query.record();
            double temp = record.value("Value").toDouble();
            if (i == 0 && j == 0) {
                min = temp;
            }
            if (temp < min) {
                min = temp;
            }
        }
    }
    return min;
}


/**
 * loadServices
 * Function to load all available service areas from the database file
 */
void OMBIDatabase::loadServices() {
    QSqlQuery query(_OMBIData);
    query.exec("SELECT MeasureID FROM Measures");
    QString lastTag = "";
    while(query.next()) {
        QSqlRecord record = query.record();
        QString current = record.value("MeasureID").toString();
        QString tag = current.left(4);
        if (!(tag.compare(lastTag)==0)) {
            if (tag.compare("FIRE")==0) {
                _services.append("Fire Services");
            }
            else if (tag.compare("PLCE")==0) {
                _services.append("Police Services");
            }
            else if (tag.compare("PLIB")==0) {
                _services.append("Library Services");
            }
            else if (tag.compare("PRKS")==0) {
                _services.append("Parks Services");
            }
            else if (tag.compare("SWST")==0) {
                _services.append("Waste Management Services");
            }
            else if (tag.compare("WATR")==0) {
                _services.append("Water Services");
            }
        }
        lastTag = tag;
    }

    // print loop for testing
    //for (QStringList::Iterator it = _services.begin(); it != _services.end(); ++it) {
        //QString temp = *it;
       // std::cout<< temp.toStdString() << std::endl;
    //}
}

/**
 * loadMeasures
 * Function to load all available service measures for a given service
 * area from the database file. The measureMap stores the title of a
 * measure for the UI, and the measure ID for accessing the measure
 * again from the database
 */
void OMBIDatabase::loadMeasures() {

    // We want to fill _measureMap, so we need to grab both the
    // measureID and the Title from the SQL data file
    QSqlQuery query(_OMBIData);
    QString queryCommand = "SELECT Title FROM Measures WHERE MeasureID LIKE '%";
    queryCommand.append(_currentService);
    queryCommand.append("%'");

    QStringList *temp1 = new QStringList();
    // print for testing
    //std::cout << queryCommand.toStdString() << std::endl;
    query.exec(queryCommand);
     while(query.next()) {
         QSqlRecord record = query.record();
         temp1->append(record.value("Title").toString());
     }

     query.finish();

     queryCommand = "SELECT MeasureID FROM Measures WHERE MeasureID LIKE '%";
     queryCommand.append(_currentService);
     queryCommand.append("%'");

     QStringList *temp2 = new QStringList();
     // print for testing
     //std::cout << queryCommand.toStdString() << std::endl;
     query.exec(queryCommand);
      while(query.next()) {
          QSqlRecord record = query.record();
          temp2->append(record.value("MeasureID").toString());
      }

      // we populate _measureMap by iterating through both QStringLists
      // generated by our query, the map will be of the form:
      // map<Measure Title, MeasureID).
      for (QStringList::Iterator it1 = temp1->begin(), it2 = temp2->begin(); (it1 != temp1->end() && it2 != temp2->end()); ++it1, ++it2) {
          QString temp1 = *it1;
          QString temp2 = *it2;
          //std::cout<< temp1.toStdString()<< std::endl;
          //std::cout<< temp2.toStdString()<< std::endl;
          _measureMap[temp1] = temp2;
      }

      _measures = *temp1;
     // prints for testing:
     //std::cout << _measures.size() << std::endl;
     //for (std::map<QString, QString>::iterator it = _measureMap.begin(); it != _measureMap.end(); ++it) {
         //QString temp = it->first;
         //QString temp2 = it->second;
         //std::cout<< temp.toStdString() << std::endl;
         //std::cout<< temp2.toStdString() << std::endl;
     //}
}

/**
 * resetMeasures
 * Function to reset the list of service measures
 */
void OMBIDatabase::resetMeasures()
{
    _measures.clear();
}

/**
 * loadCities
 * Function to load all available cities present in the service measure table
 * in the database file
 */
void OMBIDatabase::loadCities() {
    QSqlQuery query(_OMBIData);
    QString queryCommand = "SELECT DISTINCT Municipality FROM MeasureData";

    query.exec(queryCommand);
     while(query.next()) {
         QSqlRecord record = query.record();
         _cities.append(record.value("Municipality").toString());
     }
}

/**
 * loadYears
 * Function to load all available years present in the service measure table
 * in the database file
 */
void OMBIDatabase::loadYears() {
    QSqlQuery query(_OMBIData);
    QString queryCommand = "SELECT DISTINCT Year FROM MeasureData";

    query.exec(queryCommand);
     while(query.next()) {
         QSqlRecord record = query.record();
         _years.push_back(record.value("Year").toInt());
     }
}
