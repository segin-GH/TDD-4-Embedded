/** @brief
 * 
 * Test's for @file ledDriver.c
 * Test's are called form @file ../../../test/main/test_runner_main.c
 */

/** @todo LED DRIVER TESTS 
 *
 *  TODO are all led's off after init
 *  //TODO a single led can be turned on
 *  //TODO a single led can be turned off
 *  //TODO Multiple led's can be turned on/off
 *  //TODO Turn all led's on/off
 *  //TODO Query Led state
 *  //TODO check boundary value
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

TEST(LedDriver, are_all_the_led_off_after_init)
{
    uint16_t virtualLed = 0xffff;
    
    /* passing the virtualLed to the driver is called dependency injection */
    ledDriverInit(&virtualLed);

    TEST_ASSERT_EQUAL_HEX16(0,virtualLed);
}

TEST(LedDriver, turn_on_led_one)
{
    uint16_t virtualLed;
    ledDriverInit(&virtualLed);
    ledDriverTurnON(1);
    TEST_ASSERT_EQUAL_HEX16(1,virtualLed);
}

 
TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, are_all_the_led_off_after_init);
    RUN_TEST_CASE(LedDriver,turn_on_led_one);

}
