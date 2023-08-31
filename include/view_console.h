#pragma once  // #pragma once directive added to avoid multiple inclusions of header files

#include "observer.h"  // Include Observer header file
#include "model_simulator_breakout.h"  // Include PongModel header file
#include <ncurses.h>

class ConsoleView : public Observer  // Inheriting from Observer class
{
    BreakoutModel* model;  // Pointer variable of BreakoutModel class

public:
    ConsoleView(BreakoutModel* model);  // Constructor of ConsoleView class

    virtual ~ConsoleView();  // Virtual destructor of ConsoleView class
    
    void update();  // Function to update the screen

private:
    // Textures
    char wallTexture = '|';  // Wall texture character
    char ceilingTexture = '_'; // Ceiling texture character
    
    void drawBounds(); // draw the bounds
    void drawScore(); // draw the gamescore
    void drawConditions(); // draw the gamepromts 
    
    void drawPaddle(); // draw the gamepaddle
    void drawBall(); // draw the gameball
    void drawBricks(); // draw the bricks

    void setup_view();  // Function to set up the view
};
