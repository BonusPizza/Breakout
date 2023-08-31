#include "../../include/model/paddle.h"

// Constructor
paddle::paddle(float startX, float startY)
        : x(startX), y(startY), dx(0.0f) {}

// Getters
float paddle::getX() const {
    return x;
}

float paddle::getY() const {
    return y;
}

float paddle::getWidth() const {
    return width;
}

float paddle::getHeight() const {
    return height;
}

float paddle::getDx() const {
    return dx;
}

// Setters
void paddle::setX(float newX) {
    x = newX;
}

void paddle::setDx(float newDx) {
    dx = newDx;
}

void paddle::setWidth(float newWidth) {
    width = newWidth; 
}

// Movement function
void paddle::move() {
    x += dx;
}

// Functions to start moving left or right
void paddle::moveLeft() {
    dx = -speed;
}

void paddle::moveRight() {
    dx = speed;
}

// Function to stop moving
void paddle::stop() {
    dx = 0.0f;
}
