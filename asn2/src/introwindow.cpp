/************************************************************************
 *                                                                      *
 *                            Author: Group 4                           *
 *     IntroWindow.cpp - Implementation file for the IntroWindow class  *
 *              -Handles the presentation of the welcome screen         *
 *             -Handles the launching of the main program window        *
 *                                                                      *
 *                           November 14th, 2013                        *
 *                                                                      *
 *                                                                      *
 ***********************************************************************/
#include "introwindow.h"
#include "ui_introwindow.h"
#include "mainprogramview.h"

/**
 * IntroWindow
 * Constructor for the IntroWindow class. Initializes the ui for this class.
 *
 * @param parent The parent widget item
 */
IntroWindow::IntroWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntroWindow)
{
    //Initialize the UI
    ui->setupUi(this);

    //Connect the button press event to its slot, closeAndLaunch
    QObject::connect(ui->nextWindow, SIGNAL(pressed()), this, SLOT(closeAndLaunch()));
}

/**
  *~IntroWindow
  * Destructor for IntroWindow class
  */
IntroWindow::~IntroWindow()
{
    //Delete the ui object when class is no longer needed
    delete ui;
}

/**
 * closeAndLaunch()
 * Closes the current window (the welcome screen) and launches the
 * main application window.
 */
void IntroWindow::closeAndLaunch()
{
    //Close the current window
    this->close();

    //Instantiate the MainProgramWindow class
    MainProgramView m;
    //Launch the MainProgramWindow user interface
    m.exec();
}
