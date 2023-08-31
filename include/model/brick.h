#ifndef BRICK_H_ // header guard to prevent multiple inclusions of the same header file
#define BRICK_H_

class brick {
private:
    int x, y;          // Position of the top-left corner of the brick
    bool isDestroyed;    // Flag to check if the brick is destroyed
    int type; 

public:
    // Constructor
    brick(int startX, int startY);
    
    //Constructor for special bricks
    brick(int startX, int startY, int type); 

    // Getters
    int getX() const;
    int getY() const;
    bool getIsDestroyed() const;
    int getType() const; 

    // Function to destroy the brick
    void destroy();
};


#endif // end of header file
