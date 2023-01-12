#include <stdio.h>
#include <unity.h>
#include <unity_fixture.h>


static void RUN_ALL_TEST(void)
{
   RUN_TEST_GROUP(lightscheduler);
}

void app_main(void)
{
   UNITY_MAIN_FUNC(RUN_ALL_TEST);
}
