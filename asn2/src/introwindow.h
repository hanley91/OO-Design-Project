/**
 * @file IntroWindow.h                                                              
 * @author Group 4           
 *               
 * @brief Handles the presentation of the welcome screen and handles the launching of the main program window      
 *                                                                  
 * Launches the first window the user sees when starting up the application. Window contains some "How To Get Started" help and a description of OMBI                                   
*/
 
#ifndef INTROWINDOW_H
#define INTROWINDOW_H

#include <QMainWindow>

namespace Ui {
class IntroWindow;
}

class IntroWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * IntroWindow
     * @brief Constructor for the IntroWindow class. Initializes the ui for this class.
     *
     * @param parent The parent widget item
     */
    explicit IntroWindow(QWidget *parent = 0);

    /**
      *~IntroWindow
      * @brief Destructor for IntroWindow class
      */
    ~IntroWindow();

public slots:

    /**
     * closeAndLaunch()
     * @brief Closes the current window (the welcome screen) and launches the main application window.
     */
    void closeAndLaunch();

private:

    /**
     * ui
     * @brief Instance of this class's ui object that allows for access to ui elements.
     */
    Ui::IntroWindow *ui;
};

#endif // INTROWINDOW_H
