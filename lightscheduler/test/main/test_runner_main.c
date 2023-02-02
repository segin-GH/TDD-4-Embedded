#include <stdio.h>
#include <unity.h>
// #include <lightscheduler.h>


void app_main(void)
{
    UNITY_BEGIN();
    // unity_run_tests_by_tag("test_one", false);
    unity_run_all_tests();
    UNITY_END();
}