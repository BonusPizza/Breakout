#define BOOST_TEST_MODULE BreakoutObjectsTests
#include <boost/test/included/unit_test.hpp>

#include "model/ball.h"
#include "model/paddle.h"
#include "model/brick.h"

// Tests for Ball Class
BOOST_AUTO_TEST_SUITE(BallTests);

// Test Constructor and Getters
BOOST_AUTO_TEST_CASE(ConstructorAndGetters) {
    ball* testball = new ball(10.0f, 20.0f, 1.0f, 2.0f);
    
    BOOST_CHECK_EQUAL(testball->getX(), 10.0f);
    BOOST_CHECK_EQUAL(testball->getY(), 20.0f);
    BOOST_CHECK_EQUAL(testball->getDx(), 1.0f);
    BOOST_CHECK_EQUAL(testball->getDy(), 2.0f);
}

// Test Movement
BOOST_AUTO_TEST_CASE(MovementTest) {
    ball* testball = new ball(0.0f, 0.0f, 1.0f, 2.0f);
    testball->move();

    BOOST_CHECK_EQUAL(testball->getX(), 1.0f);
    BOOST_CHECK_EQUAL(testball->getY(), 2.0f);
}

// Test Reflection
BOOST_AUTO_TEST_CASE(ReflectionTest) {
    ball* testball = new ball(0.0f, 0.0f, 1.0f, -2.0f);
    testball->reflectX();
    BOOST_CHECK_EQUAL(testball->getDx(), -1.0f);

    testball->reflectY();
    BOOST_CHECK_EQUAL(testball->getDy(), 2.0f);
}

BOOST_AUTO_TEST_SUITE_END()

// Tests for Paddle Class
BOOST_AUTO_TEST_SUITE(PaddleTests);

    // Test Constructor and Getters
BOOST_AUTO_TEST_CASE(ConstructorAndGetters) {
    paddle* testpaddle1 = new paddle(10.0f, 20.0f);
    
    BOOST_CHECK_EQUAL(testpaddle1->getX(), 10.0f);
    BOOST_CHECK_EQUAL(testpaddle1->getY(), 20.0f);
    BOOST_CHECK_EQUAL(testpaddle1->getDx(), 0.0f);
    }

    // Test Movement Functionality
BOOST_AUTO_TEST_CASE(MovementTest) {
    paddle* testpaddle2 = new paddle(10.0f, 20.0f);
    testpaddle2->moveLeft();
    testpaddle2->move();
    BOOST_CHECK_CLOSE(testpaddle2->getX(), 10.0f + testpaddle2->getDx(), 0.001); // Using BOOST_CHECK_CLOSE due to floating point comparisons
    
    testpaddle2->moveRight();
    testpaddle2->move();
    BOOST_CHECK_CLOSE(testpaddle2->getX(), 10.0f, 0.001); // The paddle should have moved back to its original position
}

    // Test Stop Functionality
BOOST_AUTO_TEST_CASE(StopMovementTest) {
    paddle* testpaddle3 = new paddle(10.0f, 20.0f);
    testpaddle3->moveLeft();
    testpaddle3->stop();
    testpaddle3->move();
    BOOST_CHECK_EQUAL(testpaddle3->getX(), 10.0f); // The paddle should not move because we stopped its movement
}


BOOST_AUTO_TEST_SUITE_END()

// Tests for Brick Class
BOOST_AUTO_TEST_SUITE(BrickTests);

// Test Default Constructor and Getters
BOOST_AUTO_TEST_CASE(DefaultConstructorAndGetters) {
    brick* testbrick1 = new brick(5, 10);
    
    BOOST_CHECK_EQUAL(testbrick1->getX(), 5);
    BOOST_CHECK_EQUAL(testbrick1->getY(), 10);
    BOOST_CHECK_EQUAL(testbrick1->getIsDestroyed(), false);
    BOOST_CHECK_EQUAL(testbrick1->getType(), 0);
}

// Test Special Constructor and Getters
BOOST_AUTO_TEST_CASE(SpecialConstructorAndGetters) {
    brick* testbrick2 = new brick(5, 10, 2);
    
    BOOST_CHECK_EQUAL(testbrick2->getX(), 5);
    BOOST_CHECK_EQUAL(testbrick2->getY(), 10);
    BOOST_CHECK_EQUAL(testbrick2->getIsDestroyed(), false);
    BOOST_CHECK_EQUAL(testbrick2->getType(), 2);
}

// Test Destroy Function
BOOST_AUTO_TEST_CASE(DestroyTest) {
    brick* testbrick3 = new brick(5, 10);
    testbrick3->destroy();
    
    BOOST_CHECK_EQUAL(testbrick3->getIsDestroyed(), true);
}


BOOST_AUTO_TEST_SUITE_END()