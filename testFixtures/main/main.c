#include <stdio.h>
#include <string.h>
#include <unity.h>
#include <unity_fixture.h>


TEST_GROUP(TEST_1);

static char output[100];
static const char *expected;

TEST_SETUP(TEST_1)
{
    memset(output,0xaa, sizeof output);
    expected ="";
}

TEST_TEAR_DOWN(TEST_1)
{
    //
}

TEST_GROUP_RUNNER(TEST_1)
{
    RUN_TEST_CASE(TEST_1,noFormatOperation);
    RUN_TEST_CASE(TEST_1,insertString);
}

static void run_all_tests(void)
{
    RUN_TEST_GROUP(TEST_1);
}

void app_main(void)
{
    UNITY_MAIN_FUNC(run_all_tests);
}


TEST(TEST_1,noFormatOperation)
{
    char output[5] = "";
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);

}

TEST(TEST_1,insertString)
{
    char output[20] = "";
    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "world"));
    TEST_ASSERT_EQUAL_STRING("Hello world\n", output);
}
