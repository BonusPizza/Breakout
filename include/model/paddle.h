#ifndef PADDLE_H_ // header guard to prevent multiple inclusions of the same header file
#define PADDLE_H_

class paddle {
private:
    float x, y;          // Position of the top-left corner of the paddle
    float width = 5;     // Dimensions of the paddle
    float height = 1;    // height of the paddle
    float dx;            // Velocity in x direction (for paddle movement)
    float speed = 1.0f;  // paddle movement speed
public:
    // Constructor
    paddle(float startX, float startY);

    // Getters
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getDx() const;
    float getHeight() const;
    
    // Setters
    void setX(float newX);
    void setDx(float newDx);
    void setWidth(float width); 

    // Movement function
    void move();

    // Functions to start moving left or right
    void moveLeft();
    void moveRight();

    // Function to stop moving
    void stop();
};

#endif // end of header file
