#include "../../include/model/ball.h"

// Constructor
ball::ball(float startX, float startY, float startDx, float startDy)
        : x(startX), y(startY), dx(startDx), dy(startDy) {}

// Getters
float ball::getX() const {
    return x;
}

float ball::getY() const {
    return y;
}

float ball::getDx() const {
    return dx;
}

float ball::getDy() const {
    return dy;
}

float ball::getSpeed() const{
    return speed;
}

// Setters
void ball::setX(float newX) {
    x = newX;
}

void ball::setY(float newY) {
    y = newY;
}

void ball::setDx(float newDx) {
    dx = newDx;
}

void ball::setDy(float newDy) {
    dy = newDy;
}

// Movement function
void ball::move() {
    x += dx;
    y += dy;
}

// Reflect the ball when it hits a wall or paddle
void ball::reflectX() {
    dx = -dx;
}

void ball::reflectY() {
    dy = -dy;
}

// Function to stop moving
void ball::stop() {
    dx = 0.0f;
    dy = 0.0f;
}
