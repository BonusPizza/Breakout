#define BOOST_TEST_MODULE PaddleTest
#include <boost/test/included/unit_test.hpp>
#include "../../include/model/paddle.h"
#include "../../src/model/paddle.cpp"

// Test Default Constructor and Getters
BOOST_AUTO_TEST_CASE(ConstructorAndGetters) {
    paddle testpaddle1(10.0f, 20.0f);
    
    BOOST_CHECK_EQUAL(testpaddle1.getX(), 10.0f);
    BOOST_CHECK_EQUAL(testpaddle1.getY(), 20.0f);
    BOOST_CHECK_EQUAL(testpaddle1.getDx(), 0.0f);
}

// Test Movement Functionality
BOOST_AUTO_TEST_CASE(MovementTest) {
    paddle testpaddle2(10.0f, 20.0f);
    testpaddle2.moveLeft();
    testpaddle2.move();
    BOOST_CHECK_CLOSE(testpaddle2.getX(), 10.0f - testpaddle2.getDx(), 0.001); // Using BOOST_CHECK_CLOSE due to floating point comparisons
    
    testpaddle2.moveRight();
    testpaddle2.move();
    BOOST_CHECK_CLOSE(testpaddle2.getX(), 10.0f, 0.001); // The paddle should have moved back to its original position
}

// Test Stop Functionality
BOOST_AUTO_TEST_CASE(StopMovementTest) {
    paddle testpaddle3(10.0f, 20.0f);
    testpaddle3.moveLeft();
    testpaddle3.stop();
    testpaddle3.move();
    BOOST_CHECK_EQUAL(testpaddle3.getX(), 10.0f); // The paddle should not move because we stopped its movement
}

