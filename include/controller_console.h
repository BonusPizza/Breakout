#ifndef CONTROLLER_BREAKOUT_H_ // header guard to prevent multiple includes
#define CONTROLLER_BREAKOUT_H_

#include "./model_simulator_breakout.h" // include the Pong Model header file
#include <ncurses.h> // include the ncurses library for console input/output
#include <string> //include strings

class Controller
{
public:
    // You should consider how to keep this as general as possible. And should set the type accordingly.
    virtual wchar_t getInput()=0; // declare a pure virtual function for getting user input
};



class ConsoleController : public Controller // derive ConsoleController class from the Controller base class
{
    BreakoutModel* model; // pointer to the BreakoutModel object

public:
    ConsoleController(BreakoutModel* model); // constructor that takes a BreakoutModel pointer as parameter
    
    wchar_t getInput(); // override the getInput() function to get input from the console
    
    bool getAutoplay();
private:
    bool autoplay = false;
    
    std::string getControl(wchar_t ch);
    
    std::string getAutoplayInput(wchar_t ch); // uses model to calculate paddle movement
};



#endif  // end of header guard
