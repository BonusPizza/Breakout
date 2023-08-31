#define BOOST_TEST_MODULE BrickTest
#include <boost/test/included/unit_test.hpp>
#include "../../include/model/brick.h"
#include "../../src/model/brick.cpp"

// Test Default Constructor and Getters
BOOST_AUTO_TEST_CASE(DefaultConstructorAndGetters) {
    brick testbrick1(5, 10);
    
    BOOST_CHECK_EQUAL(testbrick1.getX(), 5);
    BOOST_CHECK_EQUAL(testbrick1.getY(), 10);
    BOOST_CHECK_EQUAL(testbrick1.getIsDestroyed(), false);
    BOOST_CHECK_EQUAL(testbrick1.getType(), 0);
}

// Test Special Constructor and Getters
BOOST_AUTO_TEST_CASE(SpecialConstructorAndGetters) {
    brick testbrick2(5, 10, 2);
    
    BOOST_CHECK_EQUAL(testbrick2.getX(), 5);
    BOOST_CHECK_EQUAL(testbrick2.getY(), 10);
    BOOST_CHECK_EQUAL(testbrick2.getIsDestroyed(), false);
    BOOST_CHECK_EQUAL(testbrick2.getType(), 2);
}

// Test Destroy Function
BOOST_AUTO_TEST_CASE(DestroyTest) {
    brick testbrick3(5, 10);
    testbrick3.destroy();
    
    BOOST_CHECK_EQUAL(testbrick3.getIsDestroyed(), true);
}
