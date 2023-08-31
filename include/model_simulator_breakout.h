#ifndef MODEL_BREAKOUT_H_ // header guard to prevent multiple inclusions of the same header file
#define MODEL_BREAKOUT_H_

#include "../include/observer.h" // include header file for the Observable class
#include "../include/model/ball.h"
#include "../include/model/paddle.h"
#include "../include/model/brick.h"

#include <string>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

class BreakoutModel : public Observable { // PongModel class inherits from Observable class
public:
    BreakoutModel(); // constructor

    int getGameWidth(); // returns the game's width
    int getGameHeight(); // returns the game's height
    
    int getHScore(); // returns the Highscore
    int getCScore(); // returns the Current Score
    
    bool getLost();
    bool getWon();
    bool getStart();
    int getLevel(); // returns the Current Game Level
    
    bool getSpecialBrickOneActivated(); 
    int getNumberOfCollisionsLeft(); 
    
    bool getAutoplay();
    
    ball* gameball;
    paddle* gamepaddle;
    brick* gamebricks[5*13];

    void simulate_game_step(); // simulates one step of the Pong game
    void control_game(std::string control); // updates the game depending on the user-input
    void control_paddle(std::string control); // updates player movement direction based on keyboard input
    
    float getRandomAngle(); //returns a random angle between 0 and 2*pi
    void generateRandomSpeeds(float& dx, float& dy, float speed); //set the speeds dx and dy to random speeds
private:
    int width = 41; // game width
    int height = 27; // game height
    int dir = 1; // ball direction
    
    int highscore = 0;
    int currentscore = 0;
    int level = 1;
    
    bool lost = false;
    bool won = false;
    bool start = true;
    bool autoplay = false;
    
    bool specialBrickOneActivated; 
    int numberOfCollisionsLeft; 
        
    void initializeField(); // initializes the game field
    void restart(); // resets the gameobjets to their default positons
    
};

#endif // end of header file
