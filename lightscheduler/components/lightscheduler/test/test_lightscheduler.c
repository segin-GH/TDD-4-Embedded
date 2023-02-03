#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

int count = 0;

void setUp(void)
{
    count = 10;
}

void tearDown(void)
{
    //
}

TEST_CASE("what_a_test","test_one")
{
    TEST_ASSERT_EQUAL(10,count);
    TEST_ASSERT_EQUAL_HEX16(0x1000,0x1000);
    count++;
}

TEST_CASE("what_a_test_two","test_one")
{
    TEST_ASSERT_EQUAL(10,count);
    TEST_ASSERT_EQUAL_HEX16(0x1000,0x1000);
}
