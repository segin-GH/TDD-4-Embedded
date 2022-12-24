/** @brief
 * 
 * Test's for @file ledDriver.c
 * Test's are called form @file ../../../test/main/test_runner_main.c
 */

/** @todo LED DRIVER TESTS 

*    TODO are all led's off after init
*    TODO a single led can be turned on
*    TODO a single led can be turned off
*    TODO Multiple led's can be turned off
    TODO Multiple led's can be turned on
    TODO Turn all led's on
    TODO Turn all led's off
    TODO Query Led state
    TODO check boundary value
*       TODO beyond Max Breaks nothing
*       TODO under min breaks nothing
*       TODO provides RunTime error
        TODO what should really happen?

    TODO check out-of-bound value 
*/

#include <unity.h>
#include <unity_fixture.h>
#include "ledDriver.h"
// #include "runTimeErr.h"
#include "runTimeErrStub.h"

uint16_t virtualLed;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
    ledDriverInit(&virtualLed);
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
    ledDriverTurnON(1);
    TEST_ASSERT_EQUAL_HEX16(1,virtualLed);
}

TEST(LedDriver, turn_off_led_one)
{
    ledDriverTurnON(1);
    ledDriverTurnOFF(1);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLed);
}

TEST(LedDriver, turn_on_multiple_led)
{
    ledDriverTurnON(9);
    ledDriverTurnON(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLed);
}

TEST(LedDriver, turn_on_all_led)
{
    ledDriverTurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLed);
}

TEST(LedDriver, turn_off_any_led)
{
    ledDriverTurnON(9);
    ledDriverTurnON(8);
    ledDriverTurnOFF(8);
    TEST_ASSERT_EQUAL_HEX16(0x100, virtualLed);
}

TEST(LedDriver, led_memory_is_not_readable)
{
    virtualLed = 0xffff;
    ledDriverTurnON(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtualLed);
}

TEST(LedDriver, upper_and_lower_bounds)
{
    ledDriverTurnON(1);
    ledDriverTurnON(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLed);
}

TEST(LedDriver, out_of_bound_turning_on_does_no_harm)
{
    ledDriverTurnON(-1);
    ledDriverTurnON(0);
    ledDriverTurnON(17);
    ledDriverTurnON(3141);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLed);
}

TEST(LedDriver, out_of_bound_turning_off_does_no_harm)
{
    ledDriverTurnAllOn();
    ledDriverTurnOFF(-1);
    ledDriverTurnOFF(0);
    ledDriverTurnOFF(17);
    ledDriverTurnOFF(3141);
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLed);
}

IGNORE_TEST(LedDriver, out_of_bound_value_produces_run_time_error)
{
    RUNTIME_ERROR("LED DRIVER: out-of-bounds LED",-1);

    ledDriverTurnON(-1);
    TEST_ASSERT_EQUAL_STRING("LED DRIVER: out-of-bounds LED",
         runTimeErrStub_getLastError());
    TEST_ASSERT_EQUAL(-1, runTimeErrStub_getLastParameter());
}

TEST(LedDriver, is_led_on)
{
    TEST_ASSERT_FALSE(ledDriverIsLedOn(11));
    ledDriverTurnON(11);
    TEST_ASSERT_TRUE(ledDriverIsLedOn(11));
}

TEST(LedDriver, is_led_off)
{
    TEST_ASSERT_TRUE(ledDriverIsLedOff(12));
    ledDriverTurnON(12);
    TEST_ASSERT_FALSE(ledDriverIsLedOff(12));
}

TEST(LedDriver, out_of_bound_leds_are_always_off)
{
    TEST_ASSERT_TRUE(ledDriverIsLedOff(0));
    TEST_ASSERT_TRUE(ledDriverIsLedOff(17));
    TEST_ASSERT_FALSE(ledDriverIsLedOn(0));
    TEST_ASSERT_FALSE(ledDriverIsLedOn(17));
}

TEST(LedDriver, turn_off_multiple_led)
{
    ledDriverTurnAllOn();
    ledDriverTurnOFF(9);
    ledDriverTurnOFF(8);
    TEST_ASSERT_EQUAL_HEX16((~0x180) & 0xffff, virtualLed);
}


TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, are_all_the_led_off_after_init);
    RUN_TEST_CASE(LedDriver, turn_on_led_one);
    RUN_TEST_CASE(LedDriver, turn_off_led_one);
    RUN_TEST_CASE(LedDriver, turn_on_multiple_led);
    RUN_TEST_CASE(LedDriver, turn_on_all_led);
    RUN_TEST_CASE(LedDriver, turn_off_any_led);
    RUN_TEST_CASE(LedDriver, led_memory_is_not_readable);
    RUN_TEST_CASE(LedDriver, upper_and_lower_bounds);
    RUN_TEST_CASE(LedDriver, out_of_bound_turning_on_does_no_harm);
    RUN_TEST_CASE(LedDriver, out_of_bound_turning_off_does_no_harm);
    RUN_TEST_CASE(LedDriver, out_of_bound_value_produces_run_time_error);
    RUN_TEST_CASE(LedDriver, is_led_on);
    RUN_TEST_CASE(LedDriver, is_led_off);
    RUN_TEST_CASE(LedDriver, out_of_bound_leds_are_always_off);
    RUN_TEST_CASE(LedDriver, turn_off_multiple_led);
}
