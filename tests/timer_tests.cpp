#define BOOST_TEST_MODULE TimerTest
#include <boost/test/included/unit_test.hpp>
#include "timer.h"

// Basic test case to verify timer initial state
BOOST_AUTO_TEST_CASE(test_timer_initial_state)
{
    Timer &timer = Timer::getInstance();
    BOOST_CHECK(timer.isStopped());
}

// Test to verify that the Timer starts correctly
BOOST_AUTO_TEST_CASE(test_timer_start)
{
    Timer &timer = Timer::getInstance();
    timer.start(1500, 300); // Start the timer with 25 minutes work, 5 minutes break
    BOOST_CHECK(timer.isWorkTime());
}

// Test to verify that the Timer can be paused
BOOST_AUTO_TEST_CASE(test_timer_pause)
{
    Timer &timer = Timer::getInstance();
    timer.start(1500, 300);     // Start the timer
    BOOST_CHECK(timer.pause()); // Pause the timer and check if the pause operation was successful
    BOOST_CHECK(timer.isPaused());
}

// Test to verify that the Timer can be resumed from a paused state
BOOST_AUTO_TEST_CASE(test_timer_resume)
{
    Timer &timer = Timer::getInstance();
    timer.start(1500, 300);      // Start the timer
    timer.pause();               // Pause the timer
    BOOST_CHECK(timer.resume()); // Resume the timer and check if the resume operation was successful
    BOOST_CHECK(timer.isWorkTime());
}

// Test to verify that the Timer can be reset
BOOST_AUTO_TEST_CASE(test_timer_reset)
{
    Timer &timer = Timer::getInstance();
    timer.start(1500, 300);     // Start the timer
    BOOST_CHECK(timer.reset()); // Reset the timer and check if the reset operation was successful
    BOOST_CHECK(timer.isStopped());
}