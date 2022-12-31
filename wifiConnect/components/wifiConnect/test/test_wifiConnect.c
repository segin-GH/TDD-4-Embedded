#include <unity.h>
#include <unity_fixture.h>
#include "wifiConnect.h"

TEST_GROUP(wifi_connect);

TEST_SETUP(wifi_connect)
{
    //
}

TEST_TEAR_DOWN(wifi_connect)
{
    // clean up after test
}

TEST(wifi_connect, is_test_fixture_working)
{
    TEST_ASSERT_EQUAL_HEX16(0,0x001);
}

TEST_GROUP_RUNNER(wifi_connect)
{
    RUN_TEST_CASE(wifi_connect, is_test_fixture_working)

}