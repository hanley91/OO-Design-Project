/*******************************************************************************
 *                                Author: Group 4                              *
 *               firedata.m-Implementation File for the fireDataClass          *
 *                        -Handles the hard coded data points                  *
 *                         -Functions for retrieval of data                    *
 *                                                                             *
 *                               October 23rd, 2013                            *
 *                                                                             *
 *                                                                             *
 ******************************************************************************/

#include "firedataclass.h"

/**
 * fireDataClass Constructor
 * Creates a new instance of the fireDataClass object, initializes data members
 */
fireDataClass::fireDataClass()
{

    //Initalize the allCities QVector with values for tick mark locations

    //This will ensure each city has its potential group
    //of three bars labelled by one label placed at the middle bar (second possible bar)

    allCities.append(2);
    allCities.append(5);
    allCities.append(8);
    allCities.append(11);
    allCities.append(14);
    allCities.append(17);
    allCities.append(20);
    allCities.append(23);
    allCities.append(26);
    allCities.append(29);

    //Initialize allCities with all the city names, used for labelling each group of bars

    allCities2.append("Barrie");
    allCities2.append("Calgary");
    allCities2.append("Hamilton");
    allCities2.append("London");
    allCities2.append("Ottawa");
    allCities2.append("Sudbury");
    allCities2.append("Thunder Bay");
    allCities2.append("Toronto");
    allCities2.append("Windsor");
    allCities2.append("Winnipeg");

    //Initialize allData09 with all data points for all cities from 2009

    allData09.append(0.843);
    allData09.append(0.630);
    allData09.append(0.661);
    allData09.append(1.033);
    allData09.append(0.841);
    allData09.append(1.312);
    allData09.append(1.797);
    allData09.append(0.901);
    allData09.append(1.381);
    allData09.append(1.666);

    //Initialize allData10 with all data points for all cities from 2010

    allData10.append(0.780);
    allData10.append(0.594);
    allData10.append(0.984);
    allData10.append(1.073);
    allData10.append(0.932);
    allData10.append(1.378);
    allData10.append(1.475);
    allData10.append(0.953);
    allData10.append(1.640);
    allData10.append(0.0);

    //Initialize allData11 with all data points for all cities from 2011

    allData11.append(0.843);
    allData11.append(0.630);
    allData11.append(0.661);
    allData11.append(1.033);
    allData11.append(0.841);
    allData11.append(1.312);
    allData11.append(1.797);
    allData11.append(0.901);
    allData11.append(1.381);
    allData11.append(1.666);

}

/**
 * cityListRetrievalAll()
 * Function to retrieve a list of numbers for the purpose of
 * arranging the cities in order
 * @return QVector containing the number sequence for the cities
 */
QVector<double> fireDataClass::cityListRetrievalAll()
{
    return allCities;
}

/**
 * cityListRetrievalAllNames()
 * Function to retrieve a list of numbers for the purpose of
 * labelling the x-axis on the bar graph
 * @return  QVector containing all the cities' names in order
 */
QVector<QString> fireDataClass::cityListRetrievalAllNames()
{
    return allCities2;
}

/**
 * retrieveAll2009()
 * Function to retrieve a list of all data points for all cities,
 * for the year 2009
 * @return QVector containing all data points for the year 2009
 */
QVector<double> fireDataClass::retrieveAll2009()
{
    return allData09;
}

/**
 * retrieveAll2010()
 * Function to retrieve a list of all data points for all cities,
 * for the year 2010
 * @return QVector containing all data points for the year 2010
 */
QVector<double> fireDataClass::retrieveAll2010()
{
    return allData10;
}

/**
 * retrieveAll2011()
 * Function to retrieve a list of all data points for all cities,
 * for the year 2011
 * @return QVector containing all data points for the year 2011
 */
QVector<double> fireDataClass::retrieveAll2011()
{
    return allData11;
}
