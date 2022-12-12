#include <stdio.h>
#include <unity.h>
#include <unity_fixture.h>
// #include "ledDriver.h"

static void RUN_ALL_TEST(void)
{
   RUN_TEST_GROUP(LedDriver);
}

void app_main(void)
{
   UNITY_MAIN_FUNC(RUN_ALL_TEST);
}
