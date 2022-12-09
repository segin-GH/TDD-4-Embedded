#include <stdio.h>
#include <unity.h>
#include <string.h>
#include <unity_fixture.h>


void app_main(void)
{
    /* a normal test for sprintf */
    UNITY_BEGIN();
    unity_run_test_by_name("Test 1");
    UNITY_END();

    /* this test challenges sprinf() to format a string with '%s' */
    UNITY_BEGIN();
    unity_run_test_by_name("Test 2");
    UNITY_END();

    /*  the weakness in both of the test is that it does not check that is sprintf is writing
        past the string terminator
    */
    UNITY_BEGIN();
    unity_run_test_by_name("Test 3");
    UNITY_END();
}

TEST_CASE("Test 1", "Test for sprintf")
{
    char output[5] = "";
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
    }

TEST_CASE("Test 2", "Test for sprintf")
{
    char output[20] = "";
    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "world"));
    TEST_ASSERT_EQUAL_STRING("Hello world\n", output);
}

TEST_CASE("Test 3", "Test for sprintf")
{
    char output[5];
    memset(output, 0xaa, sizeof output);
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
    TEST_ASSERT_BYTES_EQUAL(0xaa,output[4]);
    // TEST_ASSERT_BYTES_EQUAL
}