#ifndef BALL_H_ // header guard to prevent multiple inclusions of the same header file
#define BALL_H_


class ball {
private:
    float x, y;          // Position of the ball
    float dx, dy;        // Velocity in x and y direction
    float speed = 1.0f;      // speed of the ball
public:
    // Constructor
    ball(float startX, float startY, float startDx, float startDy);

    // Getters
    float getX() const;
    float getY() const;
    float getDx() const;
    float getDy() const;
    float getSpeed() const;

    // Setters
    void setX(float newX);
    void setY(float newY);
    void setDx(float newDx);
    void setDy(float newDy);

    // Movement function
    void move();

    // Reflect the ball when it hits a wall or paddle
    void reflectX(); // Reflect in X direction
    void reflectY(); // Reflect in Y direction
    
    // Function to stop moving
    void stop();
};

#endif // end of header file
