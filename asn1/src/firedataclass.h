/*******************************************************************************
 *                               Author: Group 4                               *
 *                   firedata.h-Header File for the fireDataClass              *
 *                        -Handles the hard coded data points                  *
 *                         -Functions for retrieval of data                    *
 *                                                                             *
 *                               October 23rd, 2013                            *
 *                                                                             *
 *                                                                             *
 ******************************************************************************/



#ifndef FIREDATACLASS_H
#define FIREDATACLASS_H

#include <QVector>
#include <string>
#include <QString>

class fireDataClass
{
public:

    /**
     * fireDataClass Constructor
     * Creates a new instance of the fireDataClass object, initializes data members
     */
    fireDataClass();

    /**
     * cityListRetrievalAll()
     * Function to retrieve a list of numbers for the purpose of
     * spacing labels on the x-axis
     * @return QVector containing the number sequence for the cities
     */
    QVector<double> cityListRetrievalAll();

    /**
     * cityListRetrievalAllNames()
     * Function to retrieve a list of numbers for the purpose of
     * labelling the x-axis on the bar graph
     * @return  QVector containing all the cities' names in order
     */
    QVector<QString> cityListRetrievalAllNames();

    /**
     * retrieveAll2009()
     * Function to retrieve a list of all data points for all cities,
     * for the year 2009
     * @return QVector containing all data points for the year 2009
     */
    QVector<double> retrieveAll2009();

    /**
     * retrieveAll2010()
     * Function to retrieve a list of all data points for all cities,
     * for the year 2010
     * @return QVector containing all data points for the year 2010
     */
    QVector<double> retrieveAll2010();

    /**
     * retrieveAll2011()
     * Function to retrieve a list of all data points for all cities,
     * for the year 2011
     * @return QVector containing all data points for the year 2011
     */
    QVector<double> retrieveAll2011();

private:

    /**
     * allCities
     * QVector that stores the x axis values for spacing labels (hard coded)
     */
    QVector<double> allCities;

    /**
     * allCities2
     * QVector that stores all city names in sequence for labelling the x-axis (hard coded)
     */
    QVector<QString> allCities2;

    /**
     * allData09
     * QVector that stores all data points for all cities for the year 2009 (hard coded)
     */
    QVector<double> allData09;

    /**
     * allData10
     * QVector that stores all data points for all cities for the year 2010 (hard coded)
     */
    QVector<double> allData10;

    /**
     * allData11
     * QVector that stores all data points for all cities for the year 2011 (hard coded)
     */
    QVector<double> allData11;

};

#endif // FIREDATACLASS_H
