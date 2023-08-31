#define BOOST_TEST_MODULE ballTest
#include <boost/test/included/unit_test.hpp>
#include "../../include/model/ball.h"
#include "../../src/model/ball.cpp"

// Test Constructor and Getters
BOOST_AUTO_TEST_CASE(ConstructorAndGetters) {
    ball testball = new ball(10.0f, 20.0f, 1.0f, 2.0f);
    
    BOOST_CHECK_EQUAL(testball.getX(), 10.0f);
    BOOST_CHECK_EQUAL(testball.getY(), 20.0f);
    BOOST_CHECK_EQUAL(testball.getDx(), 1.0f);
    BOOST_CHECK_EQUAL(testball.getDy(), 2.0f);
}

// Test Movement
BOOST_AUTO_TEST_CASE(MovementTest) {
    ball testball = new ball(0.0f, 0.0f, 1.0f, 2.0f);
    testball.move();

    BOOST_CHECK_EQUAL(testball.getX(), 1.0f);
    BOOST_CHECK_EQUAL(testball.getY(), 2.0f);
}

// Test Reflection
BOOST_AUTO_TEST_CASE(ReflectionTest) {
    ball testball = new ball(0.0f, 0.0f, 1.0f, -2.0f);
    testball.reflectX();
    BOOST_CHECK_EQUAL(testball.getDx(), -1.0f);

    testball.reflectY();
    BOOST_CHECK_EQUAL(testball.getDy(), 2.0f);
}
