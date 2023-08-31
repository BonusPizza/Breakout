#include "../../include/model/brick.h"

// Constructor
brick::brick(int startX, int startY)
        : x(startX), y(startY), isDestroyed(false), type(0) {}

//Constructor for special brick
brick::brick(int startX, int startY, int special)
    : x(startX), y(startY), isDestroyed(false), type(special) {}

// Getters
int brick::getX() const {
    return x;
}

int brick::getY() const {
    return y;
}


bool brick::getIsDestroyed() const {
    return isDestroyed;
}

int brick::getType() const {
    return type; 
}

// Function to destroy the brick
void brick::destroy() {
    isDestroyed = true;
}

