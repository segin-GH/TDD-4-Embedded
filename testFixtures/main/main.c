#include <stdio.h>
#include <string.h>
#include <unity.h>
#include <unity_fixture.h>

static char output[100];
static const char *expected;

TEST_GROUP(TEST_1);
/* similar to constructor */
TEST_SETUP(TEST_1)
{
    memset(output,0xaa, sizeof output);
    expected ="";
}

/* similar to deconstructor */
TEST_TEAR_DOWN(TEST_1){}

/* tests for sprintf */
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

/* merging similar types of test */
TEST_GROUP_RUNNER(TEST_1)
{
    RUN_TEST_CASE(TEST_1,noFormatOperation);
    RUN_TEST_CASE(TEST_1,insertString);
}

/* where all tests are called */
static void run_all_tests(void)
{
    RUN_TEST_GROUP(TEST_1);
}

/* where tests are called */
void app_main(void)
{
    UNITY_MAIN_FUNC(run_all_tests);
}

