/** @brief
 * 
 * Test's for @file ledDriver.c
 * Test's are called form @file ../../../test/main/test_runner_main.c
 */

/** @todo LED DRIVER TESTS 
 *
 *  //TODO are all leds off after init
 *  //TODO a single led can be turned on
 *  //TODO a single led can be turned off
 *  //TODO Multiple leds can be turned on/off
 *  //TODO Turn all leds on/off
 *  //TODO Query Led state
 *  //TODO check bouddary value
 *  //TODO check out-of-bound value 
 */

#include <unity.h>
#include <unity_fixture.h>
#include "ledDriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
    // do something before every test
}

TEST_TEAR_DOWN(LedDriver)
{
    // clean up after test
}

TEST(LedDriver, is_leds_off_after_init)
{
    // TEST_FAIL_MESSAGE("start here");
}

 
TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, is_leds_off_after_init);
}
