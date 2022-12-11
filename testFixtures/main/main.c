#include <stdio.h>
#include <string.h>
#include <unity.h>
#include <unity_fixture.h>

char output[100];
// Test group and test case names should be descriptive and descriptive
TEST_GROUP(SprintfTests);

TEST_SETUP(SprintfTests)
{
    // Clear the output buffer before each test
    memset(output, 0, sizeof output);
}

TEST_TEAR_DOWN(SprintfTests)
{
    // No tear-down needed for this test group
}

// Test the sprintf function without using any format specifiers
TEST(SprintfTests, NoFormatSpecifiers)
{
    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
}

// Test the sprintf function's ability to insert a string into the output
TEST(SprintfTests, InsertString)
{
    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "world"));
    TEST_ASSERT_EQUAL_STRING("Hello world\n", output);
}

// Run the tests in the SprintfTests group
TEST_GROUP_RUNNER(SprintfTests)
{
    RUN_TEST_CASE(SprintfTests, NoFormatSpecifiers);
    RUN_TEST_CASE(SprintfTests, InsertString);
}

// Run all of the tests in the application
static void run_all_tests(void)
{
    RUN_TEST_GROUP(SprintfTests);
}

// Entry point for the test application
void app_main(void)
{
    UNITY_MAIN_FUNC(run_all_tests);
}