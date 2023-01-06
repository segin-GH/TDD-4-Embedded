
/** @todo Test List

TODO  does wifi init returns ESP_OK
TODO  throw a error if wifi init is not called
TODO  

  */


#include <unity.h>
#include <unity_fixture.h>
#include "wifiConnect.h"
#include <cmock.h>

TEST_GROUP(wifi_connect);

TEST_SETUP(wifi_connect)
{
    //
}

TEST_TEAR_DOWN(wifi_connect)
{
    // clean up after test
}

TEST(wifi_connect, is_init_wifi_function_working)
{
    TEST_ASSERT_EQUAL(0,0);
}

TEST_GROUP_RUNNER(wifi_connect)
{
    RUN_TEST_CASE(wifi_connect, is_init_wifi_function_working)

}