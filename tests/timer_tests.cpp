#define BOOST_TEST_MODULE TimerTest
#include <boost/test/included/unit_test.hpp>
#include "../include/timer.h"

// Test to verify timer initial state
BOOST_AUTO_TEST_CASE(test_timer_initial_state)
{
    Timer &timer = Timer::getInstance();
    BOOST_CHECK(timer.isStopped());
}